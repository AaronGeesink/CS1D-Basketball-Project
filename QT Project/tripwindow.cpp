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
	std::vector<Team> teams = queryTeams();

	// Table Setup
	ui->nuggetsTable->setRowCount(teams.size());
	ui->nuggetsTable->setColumnCount(3);

	ui->nuggetsTable->setHorizontalHeaderItem(0, new QTableWidgetItem("Start"));
	ui->nuggetsTable->setHorizontalHeaderItem(1, new QTableWidgetItem("End"));
	ui->nuggetsTable->setHorizontalHeaderItem(2, new QTableWidgetItem("Distance"));

	ui->nuggetsTable->setSelectionMode(QAbstractItemView::NoSelection);

	ui->stackedWidget->setCurrentIndex(0);
}

void TripWindow::setSpecifiedTrip()
{
	std::vector<Team> teams = queryTeams();
	qDebug() << teams.size();

	// Table Setup
	ui->custom1Table->setRowCount(teams.size());
	ui->custom1Table->setColumnCount(4);

	ui->custom1Table->setHorizontalHeaderItem(0, new QTableWidgetItem("Name"));
	ui->custom1Table->setHorizontalHeaderItem(1, new QTableWidgetItem("Teams to Add"));
	ui->custom1Table->setHorizontalHeaderItem(2, new QTableWidgetItem("Starting City"));
	ui->custom1Table->setHorizontalHeaderItem(3, new QTableWidgetItem("Order to Visit"));

	ui->custom1Table->setSelectionMode(QAbstractItemView::NoSelection);

	QLabel *name;
	for (int i = 0; i < teams.size(); i++)
	{
		name = new QLabel();
		name->setText(teams[i].getTeamName());
		ui->custom1Table->setCellWidget(i, 0, name);

		ui->custom1Table->setCellWidget(i, 1, new QCheckBox());
		ui->custom1Table->setCellWidget(i, 2, new QRadioButton());
		ui->custom1Table->setCellWidget(i, 3, new QSpinBox());
	}

	ui->stackedWidget->setCurrentIndex(1);
}

void TripWindow::setPistonsTrip()
{
	std::vector<Team> teams = queryTeams();
	qDebug() << teams.size();

	// Table Setup
	ui->pistonsTable->setRowCount(teams.size());
	ui->pistonsTable->setColumnCount(3);

	ui->pistonsTable->setHorizontalHeaderItem(0, new QTableWidgetItem("Start Team"));
	ui->pistonsTable->setHorizontalHeaderItem(1, new QTableWidgetItem("End Team"));
	ui->pistonsTable->setHorizontalHeaderItem(2, new QTableWidgetItem("Distance"));

	ui->pistonsTable->setSelectionMode(QAbstractItemView::NoSelection);

	QLabel *name;
	for (int i = 0; i < teams.size(); i++)
	{
		name = new QLabel();
		name->setText(teams[i].getTeamName());
		ui->pistonsTable->setCellWidget(i, 0, name);
		//ui->pistonsTable->setCellWidget(i, 1, new QCheckBox());
		//ui->pistonsTable->setCellWidget(i, 2, new QRadioButton());
	}

	ui->stackedWidget->setCurrentIndex(2);
}

void TripWindow::setShortestTrip()
{
	std::vector<Team> teams = queryTeams();

	// Table Setup
	ui->custom2Table->setRowCount(teams.size());
	ui->custom2Table->setColumnCount(3);

	ui->custom2Table->setHorizontalHeaderItem(0, new QTableWidgetItem("Name"));
	ui->custom2Table->setHorizontalHeaderItem(1, new QTableWidgetItem("Teams to Add"));
	ui->custom2Table->setHorizontalHeaderItem(2, new QTableWidgetItem("Starting City"));

	ui->custom2Table->setSelectionMode(QAbstractItemView::NoSelection);

	QLabel *name;
	for (int i = 0; i < teams.size(); i++)
	{
		name = new QLabel();
		name->setText(teams[i].getTeamName());
		ui->custom2Table->setCellWidget(i, 0, name);

		ui->custom2Table->setCellWidget(i, 1, new QCheckBox());
		ui->custom2Table->setCellWidget(i, 2, new QRadioButton());
	}

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
