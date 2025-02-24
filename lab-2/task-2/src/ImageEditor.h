#ifndef IMAGEEDITOR_H
#define IMAGEEDITOR_H

#include <QLabel>
#include <QFileDialog>
#include <QImageReader>
#include <QImage>
#include <QStandardPaths>
#include <QPainter>
#include <QMouseEvent>
#include <QPen>
#include <QMessageBox>

class ImageEditor final : public QLabel {
public:
    explicit ImageEditor(QWidget *parent = nullptr) : QLabel(parent) {
        setAlignment(Qt::AlignCenter);
        setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        setMouseTracking(true);
    }

    void createImage() {
        m_image = std::make_unique<QImage>(size(), QImage::Format_RGB888);
        m_image->fill(Qt::white);

        updateImageDisplay();
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

    void saveImage() {
        if (m_image->isNull()) return;

        const auto picturesPath = QStandardPaths::writableLocation(QStandardPaths::PicturesLocation);
        auto fileName = QFileDialog::getSaveFileName(this, "Save Image", picturesPath + "/untitled.jpg",
                                                     "Images (*.png *.bmp *.jpg *.jpeg)");

        if (!fileName.isEmpty()) {
            auto format = QFileInfo(fileName).suffix().toLower();
            if (format.isEmpty()) {
                format = "jpg";
                fileName += ".jpg";
            }

            QImage imageToSave = *m_image;
            if (format == "jpg" || format == "jpeg") {
                imageToSave = imageToSave.convertToFormat(QImage::Format_RGB888);
            }

            if (imageToSave.save(fileName, format.toStdString().c_str(), 90)) {
                QMessageBox::information(nullptr, "Success", "Image saved successfully!");
            } else {
                QMessageBox::critical(nullptr, "Error", "Failed to save the image!");
            }

        }
    }

protected:
    void resizeEvent(QResizeEvent *event) override {
        QLabel::resizeEvent(event);
        updateImageDisplay();
    }

    void mousePressEvent(QMouseEvent *event) override {
        if (m_image->isNull()) return;

        m_isDrawing = true;
        m_lastPos = mapToPixmap(event->pos());
    }

    void mouseMoveEvent(QMouseEvent *event) override {
        if (m_image->isNull() || !m_isDrawing) return;

        QPoint currentPos = mapToPixmap(event->pos());

        QPainter painter(m_image.get());
        painter.setPen(QPen(Qt::red, 5));
        painter.drawLine(m_lastPos, currentPos);
        m_lastPos = currentPos;
        updateImageDisplay();
    }

    void mouseReleaseEvent(QMouseEvent *event) override {
        if (m_image->isNull() || !m_isDrawing) return;

        m_isDrawing = false;
    }

private:
    std::unique_ptr<QImage> m_image = std::make_unique<QImage>();
    bool m_isDrawing = false;
    QPoint m_lastPos;

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

    [[nodiscard]] QPoint mapToPixmap(const QPoint &pos) const {
        if (m_image->isNull()) return {0, 0};


        const auto offsetX = (size().width() - pixmap().width()) / 2;
        const auto offsetY = (size().height() - pixmap().height()) / 2;

        const auto scale = static_cast<float>(pixmap().width()) / m_image->width();

        const QPoint newPos((pos.x() - offsetX) / scale, (pos.y() - offsetY) / scale);

        return newPos;
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

#endif //IMAGEEDITOR_H
