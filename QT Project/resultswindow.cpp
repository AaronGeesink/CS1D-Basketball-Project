#include "resultswindow.h"
#include "ui_resultswindow.h"

ResultsWindow::ResultsWindow(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::ResultsWindow)
{
	ui->setupUi(this);
}

ResultsWindow::~ResultsWindow()
{
	delete ui;
}

void ResultsWindow::on_moveToSouvenir_clicked()
{
	emit moveToSouvenirClicked();
}

void ResultsWindow::on_moveToTripSelect_clicked()
{
	emit moveToTripSelectClicked();
}
