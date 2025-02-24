#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <QAction>

#include "ImageViewer.h"

class MainWindow final : public QMainWindow {
public:
    MainWindow() : m_imageViewer(std::make_unique<ImageViewer>(this)) {
        createMenuBar();
        resize(800, 600);

        setCentralWidget(m_imageViewer.get());
    }

private:
    std::unique_ptr<QMenuBar> m_menuBar;
    std::unique_ptr<ImageViewer> m_imageViewer;

    void createMenuBar() {
        m_menuBar = std::make_unique<QMenuBar>(this);
        const auto fileMenu = m_menuBar->addMenu("File");
        const auto openAction = fileMenu->addAction("Open");
        const auto exitAction = fileMenu->addAction("Exit");

        connect(openAction, &QAction::triggered, this, [this]() {
            m_imageViewer->openImage();
        });
        connect(exitAction, &QAction::triggered, qApp, &QApplication::quit);

        setMenuBar(m_menuBar.get());
    }
};

#endif //MAINWINDOW_H
