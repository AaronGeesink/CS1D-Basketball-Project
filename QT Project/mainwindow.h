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

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
	void on_exitButton_clicked();

	void on_mainButton_clicked();

	void on_moveToView_clicked();

	void on_moveToEdit_clicked();

	void moveToEdit();

	void on_moveToTripSelect_clicked();

	void moveToTripSelect();

	void moveToNuggetsTrip();

	void moveToSpecifiedTrip();

	void moveToPistonsTrip();

	void moveToShortestTrip();

	void moveToTrip();

	void moveToSouvenir();

	void moveToResults();

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
