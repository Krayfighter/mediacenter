
#include <QtWidgets>
// #include <QVector>

#include <vector>


// using namespace std;




class MainWindow: public QWidget {
    private:
        QVBoxLayout *imageLayout;
        std::vector<QLabel*> imageLabels;
    public:
        MainWindow();
        void addImage(const char *filename);
};
MainWindow::MainWindow() {
    resize(640, 480);
    setWindowTitle("MediaCenter App");
    imageLayout = new QVBoxLayout();
}
void MainWindow::addImage(const char *filename) {
    QPixmap pixelMap(filename);

    auto label = new QLabel();

    // label->setText(QString("filler text here"));
    label->setScaledContents(true);
    label->setPixmap(pixelMap);
    // label->setSize()

    imageLayout->addWidget(label);

    imageLabels.push_back(new QLabel);
}


// void setLabelImage(QLabel *label, const char *filename) {
//     QPixmap pixelMap(QString::fromUtf8(filename));
//     label->setPixmap(pixelMap);
//     // label->setMask(pixelMap.mask());
// }


int main(int argc, char **argv) {
    QApplication app(argc, argv);
    MainWindow window;

    window.addImage("/home/aidenk/Desktop/mediacenter/test.jpg");

    window.show();


    return app.exec();
}