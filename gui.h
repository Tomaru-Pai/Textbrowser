#ifndef GUI_H
#define GUI_H

#include "ui_gui.h"
#include "httpclient.h"

class Gui : public QWidget, private Ui::Gui
{
    Q_OBJECT

public:
    explicit Gui(QWidget *parent = nullptr);

private slots:
    void on_goButton_clicked(); // from user
    void showResult(quint16 port, QString status); // from scanner

private:
    HttpClient m_scanner;
};

#endif // GUI_H
