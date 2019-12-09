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
	void moveToSouvenirClicked();
	void moveToTripSelectClicked();

private slots:
	void on_moveToSouvenir_clicked();

	void on_moveToTripSelect_clicked();

private:
	Ui::ResultsWindow *ui;
};

#endif // RESULTSWINDOW_H
