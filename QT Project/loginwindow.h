#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QWidget>
#include <QtSql>
#include <QMessageBox>

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QWidget
{
	Q_OBJECT

public:
	explicit LoginWindow(QWidget *parent = nullptr);
	~LoginWindow();

signals:
	void moveToEditClicked();

private slots:
	void on_loginButton_clicked();

private:
	Ui::LoginWindow *ui;
};

#endif // LOGINWINDOW_H
