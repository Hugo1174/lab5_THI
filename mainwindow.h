#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <memory>

// Подключение файлов ядра, используя путь, указанный в .pro файле (../lab4_7)
#include "../../lab4/lab4_7/Bitmap.h"
#include "../../lab4/lab4_7/IPixelFactory.h"
#include "../../lab4/lab4_7/Pixel.h"

// Объявляем класс конкретной фабрики, чтобы использовать ее в конструкторе
class StandardPixelFactory;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // Слоты для кнопок, связанных через Qt Designer
    void on_addPixelButton_clicked();
    void on_clearButton_clicked();

private:
    Ui::MainWindow *ui;
    std::unique_ptr<Bitmap> bitmap; // Клиент, работающий с ядром
    QGraphicsScene *scene;

    // Размер пикселя на экране
    const int PIXEL_RENDER_SIZE = 8;

    // Вспомогательные методы
    QColor qtColorFromEnum(Color color); // Преобразование цвета enum в QColor
    void drawBitmap(); // Метод для отрисовки всех пикселей
};

#endif // MAINWINDOW_H
