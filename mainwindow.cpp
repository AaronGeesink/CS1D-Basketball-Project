#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::MainWindow)
{
    ui->setupUi(this);

	ui->stackedWidget->insertWidget(1,&viewWind);
	ui->stackedWidget->insertWidget(2,&loginWind);
	ui->stackedWidget->insertWidget(3,&editWind);
	ui->stackedWidget->insertWidget(4,&tripSelectWind);
	ui->stackedWidget->insertWidget(5,&tripWind);
	ui->stackedWidget->insertWidget(6,&souvenirWind);
	ui->stackedWidget->insertWidget(7,&resultsWind);
	ui->stackedWidget->insertWidget(8,&graphWind);

	connect(&tripSelectWind, SIGNAL(moveToNuggetsTripClicked()), this, SLOT(moveToNuggetsTrip()));
	connect(&tripSelectWind, SIGNAL(moveToSpecifiedTripClicked()), this, SLOT(moveToSpecifiedTrip()));
	connect(&tripSelectWind, SIGNAL(moveToPistonsTripClicked()), this, SLOT(moveToPistonsTrip()));
	connect(&tripSelectWind, SIGNAL(moveToShortestTripClicked()), this, SLOT(moveToShortestTrip()));

	connect(&tripWind, SIGNAL(moveToSouvenirClicked()), this, SLOT(moveToSouvenir()));
	connect(&tripWind, SIGNAL(moveToTripSelectClicked()), this, SLOT(moveToTripSelect()));

	connect(&souvenirWind, SIGNAL(moveToResultsClicked()), this, SLOT(moveToResults()));
	connect(&souvenirWind, SIGNAL(moveToTripClicked()), this, SLOT(moveToTrip()));

	connect(&resultsWind, SIGNAL(moveToTripSelectClicked()), this, SLOT(moveToTripSelect()));
	connect(&resultsWind, SIGNAL(moveToSouvenirClicked()), this, SLOT(moveToSouvenir()));

	connect(&loginWind, SIGNAL(moveToEditClicked()), this, SLOT(moveToEdit()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_exitButton_clicked()
{
	this->close();
}

void MainWindow::on_mainButton_clicked()
{
	//Stacked Widget index 0: Main Menu
	ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_moveToView_clicked()
{
	//Stacked Widget index 1: View Window
	ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_moveToEdit_clicked()
{
	//Stacked Widget index 2: Login Window
	ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::moveToEdit()
{
	//Stacked Widget index 3: Edit Window
	ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_moveToTripSelect_clicked()
{
	//Stacked Widget index 4: Trip Select Window
	ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::moveToTripSelect()
{
	//Stacked Widget index 4: Trip Select Window
	ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::moveToNuggetsTrip()
{
	tripWind.setNuggetsTrip();
	//Stacked Widget index 5: Trip Window
	ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::moveToSpecifiedTrip()
{
	tripWind.setSpecifiedTrip();
	//Stacked Widget index 5: Trip Window
	ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::moveToPistonsTrip()
{
	tripWind.setPistonsTrip();
	//Stacked Widget index 5: Trip Window
	ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::moveToShortestTrip()
{
	tripWind.setShortestTrip();
	//Stacked Widget index 5: Trip Window
	ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::moveToTrip()
{
	//Stacked Widget index 5: Trip Window
	ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::moveToSouvenir()
{
	//Stacked Widget index 6: Souvenir Window
	ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::moveToResults()
{
	//Stacked Widget index 7: Results Window
	ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_moveToGraph_clicked()
{
	//Stacked Widget index 8: Graph Traversal Window
	ui->stackedWidget->setCurrentIndex(8);
}


