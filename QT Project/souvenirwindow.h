#ifndef SOUVENIRWINDOW_H
#define SOUVENIRWINDOW_H

#include <QWidget>
#include "team.h"
#include "QSpinBox"
#include <QDebug>

namespace Ui {
class SouvenirWindow;
}

/**
 * @brief SouvenirWindow
 * This class generates the window which allows admins to display souvenirs
 */
class SouvenirWindow : public QWidget
{
	Q_OBJECT

public:
	explicit SouvenirWindow(QWidget *parent = nullptr);
	~SouvenirWindow();

	/**
	 * @author Aaron Geesink
	 * @brief setSouvenirSelection(std::vector<Team>& loadedTeams)
	 * Sets the Souvenir selection of the SouvenirWindow
	 * @param vector<Team>& loadedTeams
	 */
	void setSouvenirSelection(std::vector<Team>& loadedTeams);

	/**
	 * @author Aaron Geesink
	 * @brief loadSouvenirQuantities()
	 * Loads the quantities of Souvenir on the SouvenirWindow
	 */
	void loadSouvenirQuantities();

	/**
	 * @author Aaron Geesink
	 * @brief getLoadedTeams()
	 * Returns a vector containing the currently loaded Teams
	 * @return vector<Team>
	 */
	std::vector<Team>& getLoadedTeams();

signals:
	/**
	 * @author Aaron Geesink
	 * @brief moveToTripClicked()
	 * Proceeds to the Trip window
	 */
	void moveToTripClicked();

	/**
	 * @author Aaron Geesink
	 * @brief moveToResultsClicked()
	 * Proceeds to the results window
	 */
	void moveToResultsClicked();

private slots:
	/**
	 * @author Aaron Geesink
	 * @brief on_moveToTrip_clicked()
	 * Proceeds to the Trip window
	 */
	void on_moveToTrip_clicked();

	/**
	 * @author Aaron Geesink
	 * @brief on_moveToResults_clicked()
	 * Proceeds to the Results window
	 */
	void on_moveToResults_clicked();

private:
	Ui::SouvenirWindow *ui;
	std::vector<Team>* loadedTeams;		/// A vector containing the currently loaded teams
};

#endif // SOUVENIRWINDOW_H
