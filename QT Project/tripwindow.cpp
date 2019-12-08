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
	loadedTeams.clear();
	planNumber = 0;

	std::vector<QString> teamNames = queryTeamNames();


	for (auto it = teamNames.begin(); it != teamNames.end(); it++)
	{
		if (*it == "Denver Nuggets")
			teamNames.erase(it);
	}

	// Table Setup
	ui->nuggetsTable->setRowCount(loadedTeams.size());
	ui->nuggetsTable->setColumnCount(3);

	ui->nuggetsTable->setHorizontalHeaderItem(0, new QTableWidgetItem("Start"));
	ui->nuggetsTable->setHorizontalHeaderItem(1, new QTableWidgetItem("End"));
	ui->nuggetsTable->setHorizontalHeaderItem(2, new QTableWidgetItem("Distance"));

	ui->nuggetsTable->setSelectionMode(QAbstractItemView::NoSelection);

	for(int i = 0; i < teamNames.size(); ++i)
		ui->NuggetsCombobox->addItem(teamNames[i]);

	ui->stackedWidget->setCurrentIndex(0);
}

void TripWindow::setSpecifiedTrip()
{
	loadedTeams.clear();
	loadedTeams = queryTeams();
	planNumber = 1;

	// Table Setup
	ui->custom1Table->setRowCount(loadedTeams.size());
	ui->custom1Table->setColumnCount(4);

	ui->custom1Table->setHorizontalHeaderItem(0, new QTableWidgetItem("Name"));
	ui->custom1Table->setHorizontalHeaderItem(1, new QTableWidgetItem("Teams to Add"));
	ui->custom1Table->setHorizontalHeaderItem(2, new QTableWidgetItem("Starting City"));
	ui->custom1Table->setHorizontalHeaderItem(3, new QTableWidgetItem("Order to Visit"));

	ui->custom1Table->setSelectionMode(QAbstractItemView::NoSelection);

	QLabel *name;
	for (int i = 0; i < loadedTeams.size(); i++)
	{
		name = new QLabel();
		name->setText(loadedTeams[i].getTeamName());
		ui->custom1Table->setCellWidget(i, 0, name);

		ui->custom1Table->setCellWidget(i, 1, new QCheckBox());
		ui->custom1Table->setCellWidget(i, 2, new QRadioButton());
		ui->custom1Table->setCellWidget(i, 3, new QSpinBox());
	}

	ui->stackedWidget->setCurrentIndex(1);
}

void TripWindow::setPistonsTrip()
{
	loadedTeams.clear();
	loadedTeams = queryTeams();
	planNumber = 2;

	// Table Setup
	ui->pistonsTable->setRowCount(loadedTeams.size());
	ui->pistonsTable->setColumnCount(3);

	ui->pistonsTable->setHorizontalHeaderItem(0, new QTableWidgetItem("Start Team"));
	ui->pistonsTable->setHorizontalHeaderItem(1, new QTableWidgetItem("End Team"));
	ui->pistonsTable->setHorizontalHeaderItem(2, new QTableWidgetItem("Distance"));

	ui->pistonsTable->setSelectionMode(QAbstractItemView::NoSelection);

	QLabel *name;
	for (int i = 0; i < loadedTeams.size(); i++)
	{
		name = new QLabel();
		name->setText(loadedTeams[i].getTeamName());
		ui->pistonsTable->setCellWidget(i, 0, name);
		//ui->pistonsTable->setCellWidget(i, 1, new QCheckBox());
		//ui->pistonsTable->setCellWidget(i, 2, new QRadioButton());
	}

	ui->stackedWidget->setCurrentIndex(2);
}

void TripWindow::setShortestTrip()
{
	loadedTeams.clear();
	loadedTeams = queryTeams();
	planNumber = 3;

	// Table Setup
	ui->custom2Table->setRowCount(loadedTeams.size());
	ui->custom2Table->setColumnCount(3);

	ui->custom2Table->setHorizontalHeaderItem(0, new QTableWidgetItem("Name"));
	ui->custom2Table->setHorizontalHeaderItem(1, new QTableWidgetItem("Teams to Add"));
	ui->custom2Table->setHorizontalHeaderItem(2, new QTableWidgetItem("Starting City"));

	ui->custom2Table->setSelectionMode(QAbstractItemView::NoSelection);

	QLabel *name;
	for (int i = 0; i < loadedTeams.size(); i++)
	{
		name = new QLabel();
		name->setText(loadedTeams[i].getTeamName());
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
	// Denver Nuggets plan
	if (planNumber == 0)
	{
		/*
		for (auto it = loadedTeams.begin(); it != loadedTeams.end(); it++)
		{
			if (!(it->getTeamName() == comboValue || it->getTeamName() == "Denver Nuggets"))
			{
				loadedTeams.erase(it);
			}
		}
		qDebug() << loadedTeams[0].getTeamName() << " --> " << loadedTeams[1].getTeamName();
		*/
	}
	// custom specified plan
	else if (planNumber == 1)
	{

	}
	// Detroit Pistons Plan
	else if (planNumber == 2)
	{

	}
	// Custom Shortest plan
	else if (planNumber == 3)
	{

	}

	emit moveToSouvenirClicked();
}

void TripWindow::on_NuggetsCombobox_currentIndexChanged(const QString &arg1)
{
	comboValue = arg1;
}
