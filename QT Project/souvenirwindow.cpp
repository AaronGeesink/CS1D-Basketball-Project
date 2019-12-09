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

void SouvenirWindow::setSouvenirSelection(std::vector<Team> &loadedTeams)
{
	ui->souvenirTable->clear();

	this->loadedTeams = &loadedTeams;

	// Table Setup
	int numSouvenirs = 0;
	for (unsigned int i = 0; i < loadedTeams.size(); i++)
	{
		numSouvenirs = numSouvenirs + loadedTeams[i].getSouvenirs().getSize();
	}

	ui->souvenirTable->setRowCount(numSouvenirs);
	ui->souvenirTable->setColumnCount(4);

	ui->souvenirTable->setHorizontalHeaderItem(0, new QTableWidgetItem("City"));
	ui->souvenirTable->setHorizontalHeaderItem(1, new QTableWidgetItem("Food"));
	ui->souvenirTable->setHorizontalHeaderItem(2, new QTableWidgetItem("Price"));
	ui->souvenirTable->setHorizontalHeaderItem(3, new QTableWidgetItem("Quantity to Buy"));

	ui->souvenirTable->setSelectionMode(QAbstractItemView::NoSelection);

	QLabel *label;
	int foodsLoaded = 0;
	Souvenir souvenir;

	for (unsigned int i = 0; i < loadedTeams.size(); i++)
	{
		// set the name of the team
		label = new QLabel();
		label->setText(loadedTeams[i].getTeamName());
		ui->souvenirTable->setCellWidget(foodsLoaded, 0, label);

		for (unsigned int j = 0; j < loadedTeams[i].getKeys().size(); j++)
		{
			int key = loadedTeams[i].getKeys()[j];
			// set the name of the souvenir
			label = new QLabel();
			loadedTeams[i].getSouvenirs().get(key, souvenir);
			label->setText(souvenir.getName());
			ui->souvenirTable->setCellWidget(foodsLoaded, 1, label);

			// set the price of the souvenir
			label = new QLabel();
			loadedTeams[i].getSouvenirs().get(key, souvenir);
			label->setText("$" + QString::number(souvenir.getPrice()));
			ui->souvenirTable->setCellWidget(foodsLoaded, 2, label);

			// add QLineEdit objects for quantity input
			ui->souvenirTable->setCellWidget(foodsLoaded, 3, new QSpinBox());

			foodsLoaded++;
		}
	}
}

void SouvenirWindow::loadSouvenirQuantities()
{
	int souvenirsLoaded = 0;
	Souvenir souvenir;

	for (int i = 0; i < loadedTeams->size(); i++)
	{
		for (int j = 0; j < loadedTeams->at(i).getKeys().size(); j++)
		{
			QSpinBox *spinBox = qobject_cast<QSpinBox *>(ui->souvenirTable->cellWidget(souvenirsLoaded, 3));
			if (spinBox)
			{
				(*loadedTeams)[i].getSouvenirs().get(loadedTeams->at(i).getKeys()[j], souvenir);
				//(*loadedTeams)[i].getSouvenirs()[loadedTeams->at(i).getKeys()[j]].setQuantity(spinBox->value());
			}
			souvenirsLoaded++;
		}
	}
}

std::vector<Team> &SouvenirWindow::getLoadedTeams()
{
	return *loadedTeams;
}

void SouvenirWindow::on_moveToTrip_clicked()
{
	emit moveToTripClicked();
}

void SouvenirWindow::on_moveToResults_clicked()
{
	loadSouvenirQuantities();
	emit moveToResultsClicked();
}
