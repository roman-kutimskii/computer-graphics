#ifndef IMAGEEDITOR_H
#define IMAGEEDITOR_H

#include <QLabel>

class ImageEditor final : public QLabel {
public:
    explicit ImageEditor(QWidget *parent = nullptr) : QLabel(parent) {
        setAlignment(Qt::AlignCenter);
        setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        setMouseTracking(true);
    }

    void createImage() {
    }

    void openImage() {
    }

    void saveImage() {
    }

private:
    std::unique_ptr<QImage> m_image = std::make_unique<QImage>();
};

#endif //IMAGEEDITOR_H
