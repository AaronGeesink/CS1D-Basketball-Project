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

void ResultsWindow::setResults(std::vector<Team> &loadedTeams)
{
	qDebug() << "num souvenirs: " << loadedTeams[0].getSouvenirs()[0].getQuantity();
	qDebug() << "num nonZero souvenirs: " << loadedTeams[0].getNumNonZeroSouvenirs();
	// setup for the distance table
	ui->travelTable->clear();
	ui->travelTable->setRowCount(loadedTeams.size());
	ui->travelTable->setColumnCount(3);

	ui->travelTable->setHorizontalHeaderItem(0, new QTableWidgetItem("Start"));
	ui->travelTable->setHorizontalHeaderItem(1, new QTableWidgetItem("End"));
	ui->travelTable->setHorizontalHeaderItem(2, new QTableWidgetItem("Distance"));
	ui->travelTable->setSelectionMode(QAbstractItemView::NoSelection);

	// setup for the souvenir table
	ui->souvenirTable->clear();
	int numSouvenirs = 0;
	std::vector<QString> souvenirTeams;

	for (unsigned int i = 0; i < loadedTeams.size(); i++)
	{
		if (loadedTeams[i].getNumNonZeroSouvenirs() > 0)
		{
			qDebug() << "Souvenir number: " << souvenirTeams.size();
			numSouvenirs = numSouvenirs + loadedTeams[i].getNumNonZeroSouvenirs();
			souvenirTeams.push_back(loadedTeams[i].getTeamName());
		}
	}
	//qDebug() << "Souvenir number: " << souvenirTeams.size();

	ui->souvenirTable->setRowCount(numSouvenirs + souvenirTeams.size() + 2);
	ui->souvenirTable->setColumnCount(5);

	ui->souvenirTable->setHorizontalHeaderItem(0, new QTableWidgetItem("Team"));
	ui->souvenirTable->setHorizontalHeaderItem(1, new QTableWidgetItem("Souvenir"));
	ui->souvenirTable->setHorizontalHeaderItem(2, new QTableWidgetItem("Price"));
	ui->souvenirTable->setHorizontalHeaderItem(3, new QTableWidgetItem("Quantity"));
	ui->souvenirTable->setHorizontalHeaderItem(4, new QTableWidgetItem("Total"));

	ui->souvenirTable->setSelectionMode(QAbstractItemView::NoSelection);

	// Displaying data to the distance table
	QLabel *name;

	std::vector<QString> visited;
	//City city = getStartingCity(loadedTeams);
	QString current;

	int totalDistance = 0;
/*
	for (int i = 0; i < loadedTeams.size() - 1; i++)
	{
		for (int j = 0; j < visited.size(); j++)
		{
			city.removeCityDistance(visited[j]);
		}

		name = new QLabel();
		name->setText(city.getName());
		ui->travelTable->setCellWidget(i, 0, name);

		name = new QLabel();
		name->setText(city.getShortestDistance().endCity);
		ui->travelTable->setCellWidget(i, 1, name);

		name = new QLabel();
		name->setText(QString::number(city.getShortestDistance().distance));
		ui->travelTable->setCellWidget(i, 2, name);
		totalDistance = totalDistance + city.getShortestDistance().distance;

		visited.push_back(city.getShortestDistance().endCity);
		if (i == 0)
			visited.push_back(city.getName());

		city = getClosestCity(loadedTeams, city.getShortestDistance().endCity);
	}

	name = new QLabel();
	name->setText("Total Distance: ");
	ui->travelTable->setCellWidget(numCities - 1, 1, name);

	name = new QLabel();
	name->setText(QString::number(totalDistance));
	ui->travelTable->setCellWidget(numCities - 1, 2, name);
*/
	// Displaying data to the food table
	QLabel *label;
	int souvenirsLoaded = 0;
	double grandTotal = 0;
	std::vector<double> souvenirTotals;

	for (unsigned int i = 0; i < loadedTeams.size(); i++)
	{
		// set the name of the city if a food was purchases there
		if (loadedTeams[i].getNumNonZeroSouvenirs() > 0)
		{
			qDebug() << souvenirsLoaded;
			label = new QLabel();
			label->setText(loadedTeams[i].getTeamName());
			ui->souvenirTable->setCellWidget(souvenirsLoaded, 0, label);

			double souvenirTotal = 0;

			for (unsigned int j = 0; j < loadedTeams[i].getNonZeroSouvenirs().size(); j++)
			{
				// set the name of the food
				label = new QLabel();
				label->setText(loadedTeams[i].getNonZeroSouvenirs()[j].getName());
				ui->souvenirTable->setCellWidget(souvenirsLoaded, 1, label);

				// set the price for an individual food item
				label = new QLabel();
				label->setText("$" + QString::number(loadedTeams[i].getNonZeroSouvenirs()[j].getPrice()));
				ui->souvenirTable->setCellWidget(souvenirsLoaded, 2, label);

				// set the quantity purchases
				label = new QLabel();
				label->setText("x" + QString::number(loadedTeams[i].getNonZeroSouvenirs()[j].getQuantity()));
				ui->souvenirTable->setCellWidget(souvenirsLoaded, 3, label);

				// display total Price for the food items
				label = new QLabel();
				label->setText("$" + QString::number(loadedTeams[i].getNonZeroSouvenirs()[j].calculateTotal()));
				ui->souvenirTable->setCellWidget(souvenirsLoaded, 4, label);

				grandTotal = grandTotal + loadedTeams[i].getNonZeroSouvenirs()[j].calculateTotal();
				souvenirTotal = souvenirTotal + loadedTeams[i].getNonZeroSouvenirs()[j].calculateTotal();
				souvenirsLoaded++;
			}
			souvenirTotals.push_back(souvenirTotal);
		}
	}

	label = new QLabel();
	label->setText("Price per City:");
	ui->souvenirTable->setCellWidget(souvenirsLoaded, 3, label);
	souvenirsLoaded++;

	for (int i = 0; i < souvenirTeams.size(); i++)
	{
		label = new QLabel();
		label->setText(souvenirTeams[i]  + ":");
		ui->souvenirTable->setCellWidget(souvenirsLoaded + i, 3, label);

		label = new QLabel();
		label->setText("$" + QString::number(souvenirTotals[i]));
		ui->souvenirTable->setCellWidget(souvenirsLoaded + i, 4, label);
	}

	label = new QLabel();
	label->setText("Grand Total: ");
	ui->souvenirTable->setCellWidget(souvenirsLoaded + souvenirTeams.size(), 3, label);

	label = new QLabel();
	label->setText("$" + QString::number(grandTotal));
	ui->souvenirTable->setCellWidget(souvenirsLoaded + souvenirTeams.size(), 4, label);
}

void ResultsWindow::on_moveToSouvenir_clicked()
{
	emit moveToSouvenirClicked();
}

void ResultsWindow::on_moveToTripSelect_clicked()
{
	emit moveToTripSelectClicked();
}
