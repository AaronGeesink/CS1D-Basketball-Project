#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <viewwindow.h>
#include <loginwindow.h>
#include <editwindow.h>
#include <tripselectwindow.h>
#include <tripwindow.h>
#include <souvenirwindow.h>
#include <resultswindow.h>
#include <graphwindow.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/**
 * @brief LoginWindow
 * This class generates the main menu, and includes functions which control all other windows
 */
class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
	/**
	 * @author Aaron Geesink
	 * @brief on_exitButton_clicked()
	 * Closes the program
	 */
	void on_exitButton_clicked();

	/**
	 * @author Aaron Geesink
	 * @brief on_mainButton_clicked()
	 * Sends a signal to move to the mainWindow
	 */
	void on_mainButton_clicked();

	/**
	 * @author Aaron Geesink
	 * @brief on_moveToView_clicked()
	 * Sends a signal to move to the viewWindow
	 */
	void on_moveToView_clicked();

	/**
	 * @author Aaron Geesink
	 * @brief on_moveToEdit_clicked()
	 * Sends a signal to move to the EditWindow
	 */
	void on_moveToEdit_clicked();

	/**
	 * @author Aaron Geesink
	 * @brief moveToEdit()
	 * Proceeds to the EditWindow
	 */
	void moveToEdit();

	/**
	 * @author Aaron Geesink
	 * @brief on_moveTo11Cities_clicked()
	 * Sends a signal to move to the 11 cities trip plan
	 */
	void on_moveToTripSelect_clicked();

	/**
	 * @author Aaron Geesink
	 * @brief moveToTripSelect()
	 * Proceeds to the trip select window
	 */
	void moveToTripSelect();

	/**
	 * @author Aaron Geesink
	 * @brief moveToNuggetsTrip()
	 * Proceeds to the Denver Nuggets trip plan
	 */
	void moveToNuggetsTrip();

	/**
	 * @author Aaron Geesink
	 * @brief moveToSpecifiedTrip()
	 * Proceeds to the Specified Dream trip plan
	 */
	void moveToSpecifiedTrip();

	/**
	 * @author Aaron Geesink
	 * @brief moveToPistonsTrip()
	 * Proceeds to the Pistons trip plan
	 */
	void moveToPistonsTrip();

	/**
	 * @author Aaron Geesink
	 * @brief moveToShortestTrip()
	 * Proceeds to the Shortest specified trip plan
	 */
	void moveToShortestTrip();

	/**
	 * @author Aaron Geesink
	 * @brief moveToTrip()
	 * Proceeds to the selected trip plan
	 */
	void moveToTrip();

	/**
	 * @author Aaron Geesink
	 * @brief moveToSouvenir()
	 * Proceeds to the souvenir window
	 */
	void moveToSouvenir();

	/**
	 * @author Aaron Geesink
	 * @brief moveToResults()
	 * Proceeds to the results window
	 */
	void moveToResults();

	/**
	 * @author Aaron Geesink
	 * @brief on_moveToGraph_clicked()
	 * Proceeds to the graph window
	 */
	void on_moveToGraph_clicked();

private:
    Ui::MainWindow *ui;

	ViewWindow viewWind;	/// ViewWindow object
	LoginWindow loginWind;	/// LoginWindow object
	EditWindow editWind;	/// EditWindow Object
	TripSelectWindow tripSelectWind;	///TripSelectWindow object
	TripWindow tripWind;	///FoodSelectWindow object
	SouvenirWindow souvenirWind;	///SouvenirWindow object
	ResultsWindow resultsWind;		/// ResultsWindow object
	GraphWindow graphWind;	///GraphWindow object
};

#endif // MAINWINDOW_H
