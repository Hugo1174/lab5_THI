#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QColor>
#include <QBrush>
#include <QPen>

// Включаем заголовок конкретной фабрики, чтобы создать её
#include "../../lab4/lab4_7/IPixelFactory.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 1. Инициализация Фабрики и Bitmap (ядро)
    // Используется Фабричный метод для создания объекта Bitmap,
    // который получает конкретную фабрику (StandardPixelFactory)
    std::unique_ptr<IPixelFactory> factory = std::make_unique<StandardPixelFactory>();
    bitmap = std::make_unique<Bitmap>(std::move(factory));

    // 2. Настройка QGraphicsScene
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    // Установка размеров сцены (100x100 пикселей * размер отрисовки)
    int sceneWidth = bitmap->getWidth() * PIXEL_RENDER_SIZE;
    int sceneHeight = bitmap->getHeight() * PIXEL_RENDER_SIZE;
    scene->setSceneRect(0, 0, sceneWidth, sceneHeight);

    // Установка подсказок
    ui->xLineEdit->setPlaceholderText("0-99");
    ui->yLineEdit->setPlaceholderText("0-99");

    drawBitmap(); // Изначальная отрисовка
}

MainWindow::~MainWindow()
{
    delete ui;
}

// --- Вспомогательные методы ---

QColor MainWindow::qtColorFromEnum(Color color)
{
    // Преобразование цвета ядра (enum) в цвет Qt (QColor)
    switch(color) {
    case Color::RED: return QColor(0, 255, 0);
    case Color::GREEN: return QColor(0, 0, 255);
    case Color::BLUE: return QColor(255, 0, 0);
    default: return QColor(0, 0, 0);
    }
}

void MainWindow::drawBitmap()
{
    scene->clear();

    // Получаем данные от объекта Bitmap через метод getPixels()
    std::vector<PixelData> pixels = bitmap->getPixels();

    for (const auto& p : pixels) {
        QColor color = qtColorFromEnum(p.color);

        // Отрисовка пикселя (квадрата) на основе его координат и размера
        scene->addRect(
            p.x * PIXEL_RENDER_SIZE,
            p.y * PIXEL_RENDER_SIZE,
            PIXEL_RENDER_SIZE,
            PIXEL_RENDER_SIZE,
            QPen(color), QBrush(color));
    }

    ui->statusLabel->setText(QString("Bitmap (%1x%2). Total Pixels: %3")
                                 .arg(bitmap->getWidth())
                                 .arg(bitmap->getHeight())
                                 .arg(pixels.size()));
}

// --- Слоты Кнопок ---

void MainWindow::on_addPixelButton_clicked()
{
    bool xOk, yOk;
    int x = ui->xLineEdit->text().toInt(&xOk);
    int y = ui->yLineEdit->text().toInt(&yOk);
    int colorIndex = ui->colorComboBox->currentIndex();

    // Валидация ввода (Qt-сторона)
    if (!xOk || !yOk || x < 0 || x >= bitmap->getWidth() || y < 0 || y >= bitmap->getHeight()) {
        ui->statusLabel->setText("<font color='red'>Error: Invalid coordinates (0-99).</font>");
        return;
    }

    // Преобразование индекса ComboBox в Color
    Color color;
    switch(colorIndex) {
    case 0: color = Color::RED; break;
    case 1: color = Color::GREEN; break;
    case 2: color = Color::BLUE; break;
    default:
        ui->statusLabel->setText("<font color='red'>Error: Select a color.</font>");
        return;
    }

    try {
        // Вызов метода ядра. Ядро само обрабатывает логику замены пикселя.
        bitmap->addPixel(x, y, color);
        ui->statusLabel->setText(QString("Pixel added/replaced at (%1, %2) with %3.")
                                     .arg(x).arg(y).arg(ui->colorComboBox->currentText()));
        drawBitmap(); // Перерисовка
    } catch (const std::exception& e) {
        ui->statusLabel->setText(QString("<font color='red'>Core Error: %1</font>").arg(e.what()));
    }
}

void MainWindow::on_clearButton_clicked()
{
    ui->statusLabel->setText("All pixels cleared.");
}
