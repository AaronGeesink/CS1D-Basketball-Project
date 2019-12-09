#ifndef EDITWINDOW_H
#define EDITWINDOW_H

#include <QWidget>
#include <QMessageBox>
#include "database.h"

namespace Ui {
class EditWindow;
}

/**
 * @brief EditWindow
 * This class generates the window which allows admins to edit the SQL database
 */
class EditWindow : public QWidget
{
	Q_OBJECT

public:
	explicit EditWindow(QWidget *parent = nullptr);
	~EditWindow();

	/**
	 * @author Garrett Geesink
	 * @brief populateCombo()
	 * Populates a comboBox with all currently active teams
	 */
	void populateCombo();

private slots:
	/**
	 * @author Garrett Geesink
	 * @brief on_loadTeams_clicked()
	 * Queries the database for the team table and displays it to the EditWindow
	 */
	void on_loadTeams_clicked();

	/**
	 * @author Garrett Geesink
	 * @brief on_loadSouvenirs_clicked()
	 * Queries the database for the souvenirs table and displays it to the EditWindow
	 */
	void on_loadSouvenirs_clicked();

	/**
	 * @author Garrett Geesink
	 * @brief on_addSouvenirButton_clicked()
	 * Adds a user-specified food item
	 */
	void on_addSouvenirButton_clicked();

	/**
	 * @author Garrett Geesink
	 * @brief on_eleteSouvenirItem_clicked()
	 * Deletes a user-specified food item
	 */
	void on_deleteSouvenirItem_clicked();

	/**
	 * @author Garrett Geesink
	 * @brief on_submitButton_clicked()
	 * Pushes all changes in the editWindow to the database
	 */
	void on_submitButton_clicked();

	/**
	 * @author Garrett Geesink
	 * @brief on_revertButton_clicked()
	 * Reverts all changes in the editWindow
	 */
	void on_revertButton_clicked();

private:
	Ui::EditWindow *ui;
	QSqlTableModel * model;			/// Table Model for rendering SQL table to the window
	QSqlQueryModel * queryModel;	/// Query Model for rendering SQL table to the window
	int currentTable = 1;			/// Specifies the current loaded table
};

#endif // EDITWINDOW_H
