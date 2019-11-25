#ifndef EDITWINDOW_H
#define EDITWINDOW_H

#include <QWidget>
#include <QMessageBox>
#include "database.h"

namespace Ui {
class EditWindow;
}

class EditWindow : public QWidget
{
	Q_OBJECT

public:
	explicit EditWindow(QWidget *parent = nullptr);
	~EditWindow();

	void populateCombo();

private slots:
	void on_loadTeams_clicked();

	void on_loadSouvenirs_clicked();

	void on_addSouvenirButton_clicked();

	void on_deleteSouvenirItem_clicked();

	void on_submitButton_clicked();

	void on_revertButton_clicked();

private:
	Ui::EditWindow *ui;
	QSqlTableModel * model;			/// Table Model for rendering SQL table to the window
	QSqlQueryModel * queryModel;	/// Query Model for rendering SQL table to the window
	int currentTable = 1;			/// Specifies the current loaded table
};

#endif // EDITWINDOW_H
