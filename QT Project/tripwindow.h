#ifndef TRIPWINDOW_H
#define TRIPWINDOW_H

#include <QWidget>
#include <QCheckBox>
#include <QRadioButton>
#include <QSpinBox>
#include <QComboBox>
#include "team.h"
#include "database.h"

namespace Ui {
class TripWindow;
}

/**
 * @brief TripWindow
 * This class generates the window for a given trip plan
 */
class TripWindow : public QWidget
{
	Q_OBJECT

public:
	explicit TripWindow(QWidget *parent = nullptr);
	~TripWindow();

	/**
	 * @author Aaron Geesink
	 * @brief setNuggetsTrip()
	 * Sets the window to the Denver Nuggets trip
	 */
	void setNuggetsTrip();

	/**
	 * @author Aaron Geesink
	 * @brief setSpecifiedTrip()
	 * Sets the window to the Specified trip
	 */
	void setSpecifiedTrip();

	/**
	 * @author Aaron Geesink
	 * @brief setPistonsTrip()
	 * Sets the window to the Pistons trip
	 */
	void setPistonsTrip();

	/**
	 * @author Aaron Geesink
	 * @brief setShortestTrip()
	 * Sets the window to the Shortest trip
	 */
	void setShortestTrip();

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
	 * @brief moveToTripSelectClicked()
	 * Proceeds to the trip select window
	 */
	void moveToTripSelectClicked();

	/**
	 * @author Aaron Geesink
	 * @brief moveToSouvenirClicked()
	 * Proceeds to the souvenir window
	 */
	void moveToSouvenirClicked();
public slots:
	void addItem1(int row, int col);	/// QT Ui function allowing users to select custom teams for a trip
	void removeItem1(int row, int col);	/// QT Ui function allowing users to select custom teams for a trip
	void addItem2(int row, int col);	/// QT Ui function allowing users to select custom teams for a trip
	void removeItem2(int row, int col);	/// QT Ui function allowing users to select custom teams for a trip

private slots:
	/**
	 * @author Aaron Geesink
	 * @brief on_moveToTripSelect_clicked()
	 * Proceeds to the trip select window
	 */
	void on_moveToTripSelect_clicked();

	/**
	 * @author Aaron Geesink
	 * @brief on_moveToSouvenir_clicked()
	 * Proceeds to the souvenir window
	 */
	void on_moveToSouvenir_clicked();

	/**
	 * @author Aaron Geesink
	 * @brief on_NuggetsCombobox_currentIndexChanged(const QString &arg1)
	 * Changes the combobox on the Denver Nuggets plan
	 * @param const QString &arg1
	 */
	void on_NuggetsCombobox_currentIndexChanged(const QString &arg1);

private:
	Ui::TripWindow *ui;
	std::vector<Team> loadedTeams;	/// All loaded teams for a plan
	int customTableIndex1 = 0;		/// Index of the QTtable
	int customTableIndex2 = 0;		/// Index of the QTable
	int planNumber;					/// Number of the current trip plan
	QString comboValue;				/// Value inside the Shortest trip comboBox
};

#endif // TRIPWINDOW_H
