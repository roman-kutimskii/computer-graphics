#ifndef IMAGEVIEWER_H
#define IMAGEVIEWER_H

#include <QLabel>
#include <QFileDialog>
#include <QImageReader>
#include <QImage>
#include <QStandardPaths>
#include <QPainter>

class ImageViewer final : public QLabel {
public:
    explicit ImageViewer(QWidget *parent = nullptr): QLabel(parent) {
        setAlignment(Qt::AlignCenter);
        setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    }

    void openImage() {
        const auto picturesPath = QStandardPaths::writableLocation(QStandardPaths::PicturesLocation);
        const auto filename = QFileDialog::getOpenFileName(this, "Open Image", picturesPath, "Images (*.png)");
        if (!filename.isEmpty()) {
            QImageReader reader(filename);
            reader.setAutoTransform(true);

            if (auto image = reader.read(); !image.isNull()) {
                m_image = std::make_unique<QImage>(image);
                updateImageDisplay();
            }
        }
    }

protected:
    void resizeEvent(QResizeEvent *event) override {
        QLabel::resizeEvent(event);
        updateImageDisplay();
    }

private:
    std::unique_ptr<QImage> m_image = std::make_unique<QImage>();

    void updateImageDisplay() {
        if (m_image->isNull()) {
            return;
        }

        auto pixmap = QPixmap::fromImage(*m_image);

        const auto windowSize = size();
        if (pixmap.width() > windowSize.width() || pixmap.height() > windowSize.height()) {
            pixmap = pixmap.scaled(windowSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        }

        if (m_image->hasAlphaChannel()) {
            QPixmap checkerboardPixmap(pixmap.size());

            QPainter painter(&checkerboardPixmap);
            drawCheckerboard(painter, pixmap.size());
            painter.end();

            QPainter finalPainter(&checkerboardPixmap);
            finalPainter.drawPixmap(0, 0, pixmap);
            finalPainter.end();

            setPixmap(checkerboardPixmap);
        } else {
            setPixmap(pixmap);
        }
    }

    static void drawCheckerboard(QPainter &painter, const QSize &size) {
        constexpr int tileSize = 20;
        for (int y = 0; y < size.height(); y += tileSize) {
            for (int x = 0; x < size.width(); x += tileSize) {
                QRect rect(x, y, tileSize, tileSize);
                painter.fillRect(rect, (x / tileSize + y / tileSize) % 2 ? Qt::lightGray : Qt::white);
            }
        }
    }
};

#endif //IMAGEVIEWER_H
