#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QMainWindow>
#include <QMenuBar>
#include <QAction>

#include "ImageEditor.h"

class MainWindow final : public QMainWindow {
public:
    MainWindow() {
        createMenuBar();
        resize(800, 600);

        setCentralWidget(m_imageEditor.get());
    }

private:
    std::unique_ptr<QMenuBar> m_menuBar;
    std::unique_ptr<ImageEditor> m_imageEditor = std::make_unique<ImageEditor>(this);

    void createMenuBar() {
        m_menuBar = std::make_unique<QMenuBar>(this);

        const auto fileMenu = m_menuBar->addMenu("File");
        const auto newAction = fileMenu->addAction("New");
        const auto openAction = fileMenu->addAction("Open");
        const auto saveAsAction = fileMenu->addAction("Save As");
        const auto exitAction = fileMenu->addAction("Exit");

        connect(newAction, &QAction::triggered, this, [this]() {
            m_imageEditor->createImage();
        });
        connect(openAction, &QAction::triggered, this, [this]() {
            m_imageEditor->openImage();
        });
        connect(saveAsAction, &QAction::triggered, this, [this]() {
            m_imageEditor->saveImage();
        });
        connect(exitAction, &QAction::triggered, qApp, &QApplication::quit);

        const auto editMenu = m_menuBar->addMenu("Edit");
        const auto chooseColorAction = editMenu->addAction("Choose Drawing Color");

        connect(chooseColorAction, &QAction::triggered, this, [this]() {
            m_imageEditor->chooseColor();
        });

        setMenuBar(m_menuBar.get());
    }
};

#endif //MAINWINDOW_H
