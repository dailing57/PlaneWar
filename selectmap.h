#ifndef SELECTMAP_H
#define SELECTMAP_H

#include <QWidget>

namespace Ui {
class selectmap;
}

class selectmap : public QWidget
{
    Q_OBJECT

public:
    explicit selectmap(QWidget *parent = nullptr);
    ~selectmap();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();
signals:
    void choosed();
private:
    Ui::selectmap *ui;
};

#endif // SELECTMAP_H
