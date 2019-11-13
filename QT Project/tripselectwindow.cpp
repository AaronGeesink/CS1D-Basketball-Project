#include "tripselectwindow.h"
#include "ui_tripselectwindow.h"

TripSelectWindow::TripSelectWindow(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::TripSelectWindow)
{
	ui->setupUi(this);
}

TripSelectWindow::~TripSelectWindow()
{
	delete ui;
}

void TripSelectWindow::on_moveToNuggetsTrip_clicked()
{
	emit moveToNuggetsTripClicked();
}

void TripSelectWindow::on_moveToSpecifiedTrip_clicked()
{
	emit moveToSpecifiedTripClicked();
}

void TripSelectWindow::on_moveToPistonsTrip_clicked()
{
	emit moveToPistonsTripClicked();
}

void TripSelectWindow::on_moveToShortestTrip_clicked()
{
	emit moveToShortestTripClicked();
}
