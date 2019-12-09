#ifndef VIEWWINDOW_H
#define VIEWWINDOW_H

#include <QWidget>
#include <QtSql>
#include <QDebug>
#include "database.h"

namespace Ui {
class ViewWindow;
}

/**
 * @brief LoginWindow
 * This class generates the window which allows the user to view team and souvenir data
 */
class ViewWindow : public QWidget
{
	Q_OBJECT

public:
	explicit ViewWindow(QWidget *parent = nullptr);
	~ViewWindow();

	/**
	 * @author Garrett Geesink
	 * @brief populateCombo()
	 * Populates a comboBox with all currently active teams
	 */
	void populateCombo();

private slots:
	/**
	 * @author Garrett Geesink
	 * @brief on_teamButton_clicked()
	 * Displays a team from the SQL database
	 */
	void on_teamButton_clicked();

	/**
	 * @author Garrett Geesink
	 * @brief on_eastTeamButton_clicked()
	 * Displays eastern conference teams from the SQL database
	 */
	void on_eastTeamButton_clicked();

	/**
	 * @author Garrett Geesink
	 * @brief on_allTeamsButton_clicked()
	 * Displays all teams from the SQL database
	 */
	void on_allTeamsButton_clicked();

	/**
	 * @author Garrett Geesink
	 * @brief on_arenaButton_clicked()
	 * Displays arenas from the SQL database
	 */
	void on_arenaButton_clicked();

	/**
	 * @author Garrett Geesink
	 * @brief on_seatButton_clicked()
	 * Displays seating capacites from the SQL database
	 */
	void on_seatButton_clicked();

	/**
	 * @author Garrett Geesink
	 * @brief on_southeastTeamButton_clicked()
	 * Displays southeast eastern teams from the SQL database
	 */
	void on_southeastTeamButton_clicked();

	/**
	 * @author Garrett Geesink
	 * @brief on_coachButton_clicked()
	 * Displays coaches from the SQL database
	 */
	void on_coachButton_clicked();

	/**
	 * @author Garrett Geesink
	 * @brief on_yearButton_clicked()
	 * Displays joinYear's from the SQL database
	 */
	void on_yearButton_clicked();

	/**
	 * @author Garrett Geesink
	 * @brief on_souvenirButton_clicked()
	 * Displays souvenirs from the SQL database
	 */
	void on_souvenirButton_clicked();

private:
	Ui::ViewWindow *ui;
	QSqlQueryModel * model;	/// A model used to display SQL tables
	int totalCap;		/// The total seating capacity
};

#endif // VIEWWINDOW_H
