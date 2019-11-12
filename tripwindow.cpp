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

void TripWindow::on_moveToTripSelect_clicked()
{
	emit moveToTripSelectClicked();
}

void TripWindow::on_moveToSouvenir_clicked()
{
	emit moveToSouvenirClicked();
}
