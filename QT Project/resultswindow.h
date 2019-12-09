#ifndef RESULTSWINDOW_H
#define RESULTSWINDOW_H

#include <QWidget>
#include <QDebug>
#include "team.h"

namespace Ui {
class ResultsWindow;
}

class ResultsWindow : public QWidget
{
	Q_OBJECT

public:
	explicit ResultsWindow(QWidget *parent = nullptr);
	~ResultsWindow();

	/**
	 * @author Aaron Geesink
	 * @brief setResults(std::vector<Team>& loadedTeams)
	 * Sets the results screen to the currently loaded teams
	 * @param vector<Team>& loadedTeams
	 */
	void setResults(std::vector<Team>& loadedTeams);

signals:
	/**
	 * @author Aaron Geesink
	 * @brief moveToSouvenirClicked
	 * Proceeds to the souvenir window
	 */
	void moveToSouvenirClicked();

	/**
	 * @author Aaron Geesink
	 * @brief moveToSouvenirClicked()
	 * Proceeds to the tripSelectWindow
	 */
	void moveToTripSelectClicked();

private slots:
	/**
	 * @author Aaron Geesink
	 * @brief on_moveToSouvenir_clicked()
	 * Proceeds to the souvenir window
	 */
	void on_moveToSouvenir_clicked();

	/**
	 * @author Aaron Geesink
	 * @brief on_moveToTripSelect_clicked()
	 * Proceeds to the tripSelectWindow
	 */
	void on_moveToTripSelect_clicked();

private:
	Ui::ResultsWindow *ui;	/// Ui for the results window
};

#endif // RESULTSWINDOW_H
