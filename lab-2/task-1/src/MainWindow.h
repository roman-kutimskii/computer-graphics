#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>

class MainWindow final : public QMainWindow {
public:
    MainWindow() {
        createMenuBar();
        resize(800, 600);
    }

private:
    std::unique_ptr<QMenuBar> menuBar;

    void createMenuBar() {
        menuBar = std::make_unique<QMenuBar>(this);
        const auto fileMenu = menuBar->addMenu("File");
        const auto openAction = fileMenu->addAction("Open");
        const auto exitAction = fileMenu->addAction("Exit");

        connect(openAction, &QAction::triggered, this, []() {
            qDebug() << "Opening file";
        });
        connect(exitAction, &QAction::triggered, qApp, &QApplication::quit);

        setMenuBar(menuBar.get());
    }
};

#endif //MAINWINDOW_H
