#include "tripwindow.h"
#include "ui_tripwindow.h"

TripWindow::TripWindow(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::TripWindow)
{
	ui->setupUi(this);
}

TripWindow::~TripWindow()
{
	delete ui;
}

void TripWindow::setNuggetsTrip()
{
	ui->stackedWidget->setCurrentIndex(0);
}

void TripWindow::setSpecifiedTrip()
{
	ui->stackedWidget->setCurrentIndex(1);
}

void TripWindow::setPistonsTrip()
{
	ui->stackedWidget->setCurrentIndex(2);
}

void TripWindow::setShortestTrip()
{
	ui->stackedWidget->setCurrentIndex(3);
}

void TripWindow::on_moveToTripSelect_clicked()
{
	emit moveToTripSelectClicked();
}

void TripWindow::on_moveToSouvenir_clicked()
{
	emit moveToSouvenirClicked();
}
