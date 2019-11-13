#include "souvenirwindow.h"
#include "ui_souvenirwindow.h"

SouvenirWindow::SouvenirWindow(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::SouvenirWindow)
{
	ui->setupUi(this);
}

SouvenirWindow::~SouvenirWindow()
{
	delete ui;
}

void SouvenirWindow::on_moveToTrip_clicked()
{
	emit moveToTripClicked();
}

void SouvenirWindow::on_moveToResults_clicked()
{
	emit moveToResultsClicked();
}
