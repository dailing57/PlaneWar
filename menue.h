#ifndef MENUE_H
#define MENUE_H

#include <QWidget>
#include "mainscene.h"
#include "selectmap.h"

namespace Ui {
class menue;
}

class menue : public QWidget
{
    Q_OBJECT

public:
    explicit menue(QWidget *parent = nullptr);
    ~menue();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::menue *ui;
};

#endif // MENUE_H
