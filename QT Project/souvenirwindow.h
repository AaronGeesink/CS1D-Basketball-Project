#ifndef SOUVENIRWINDOW_H
#define SOUVENIRWINDOW_H

#include <QWidget>
#include "Team.h"
#include "QSpinBox"
#include "qDebug"

namespace Ui {
class SouvenirWindow;
}

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
	void moveToTripClicked();
	void moveToResultsClicked();

private slots:
	void on_moveToTrip_clicked();

	void on_moveToResults_clicked();

private:
	Ui::SouvenirWindow *ui;
	std::vector<Team>* loadedTeams;		/// A vector containing the currently loaded teams
};

#endif // SOUVENIRWINDOW_H
