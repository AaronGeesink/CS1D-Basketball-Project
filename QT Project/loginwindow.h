#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QWidget>
#include <QtSql>
#include <QMessageBox>

namespace Ui {
class LoginWindow;
}

/**
 * @brief LoginWindow
 * This class allows the user to input a username and password, and verifies if their login information is valid
 * If the login is valid, it opens the Edit Window
 * If the login is invalid, the user is given an "Invalid Username or Password" message
 */
class LoginWindow : public QWidget
{
	Q_OBJECT

public:
	explicit LoginWindow(QWidget *parent = nullptr);
	~LoginWindow();

signals:
	/**
	 * @brief moveToEditClicked()
	 * Redirects the window to the edit window of the program
	 */
	void moveToEditClicked();

private slots:
	/**
	 * @author Garrett Geesink
	 * @brief on_loginButton_clicked()
	 * This method verifies if the user's login info is correct.
	 * If the login is valid, it opens the Edit Window
	 * If the login is invalid, the user is given an "Invalid Username or Password" message
	 */
	void on_loginButton_clicked();

private:
	Ui::LoginWindow *ui;
};

#endif // LOGINWINDOW_H
