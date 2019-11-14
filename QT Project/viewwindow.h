#ifndef VIEWWINDOW_H
#define VIEWWINDOW_H

#include <QWidget>
#include <QtSql>
#include "database.h"

namespace Ui {
class ViewWindow;
}

class ViewWindow : public QWidget
{
	Q_OBJECT

public:
	explicit ViewWindow(QWidget *parent = nullptr);
	~ViewWindow();
	void populateCombo();

private slots:
	void on_teamButton_clicked();

	void on_eastTeamButton_clicked();

	void on_allTeamsButton_clicked();

	void on_arenaButton_clicked();

	void on_seatButton_clicked();

	void on_southeastTeamButton_clicked();

	void on_coachButton_clicked();

	void on_yearButton_clicked();

private:
	Ui::ViewWindow *ui;
	QSqlQueryModel * model;	/// A model used to display SQL tables
};

#endif // VIEWWINDOW_H
