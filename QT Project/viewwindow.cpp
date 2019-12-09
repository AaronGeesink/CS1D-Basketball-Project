#include "viewwindow.h"
#include "ui_viewwindow.h"

ViewWindow::ViewWindow(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::ViewWindow)
{
	ui->setupUi(this);
}

ViewWindow::~ViewWindow()
{
	delete ui;
}

void ViewWindow::populateCombo()
{
	QStringList teams;		/// Create QStringList (Doubly Linked List of strings)

	QSqlQuery query;
	query.exec("SELECT teamName FROM teams WHERE active='1'");

	/// Populate cities QStringList with cities from city table
	if(!query.exec())
	{
		qDebug("Failed to populate comboBox");
	}
	else
	{
	while(query.next())
		{
			teams.push_back(query.value(0).toString());
		}
	}

	for(int i = 0; i < teams.size(); ++i)
		ui->teamComboBox->addItem(teams.at(i));
}

void ViewWindow::on_teamButton_clicked()
{
	ui->totalCapLabel->setText("");
	QString team;
	team = ui->teamComboBox->currentText();

	model = new QSqlQueryModel;

	checkConnection();
	QSqlQuery query(QSqlDatabase::database());

	query.exec("select * from teams WHERE teamName='"+team+"'");
	model->setQuery(query);
	ui->databaseView->setModel(model);
}

void ViewWindow::on_allTeamsButton_clicked()
{
	ui->totalCapLabel->setText("");
	model = new QSqlQueryModel;

	checkConnection();
	QSqlQuery query(QSqlDatabase::database());

	query.exec("SELECT teamName FROM teams WHERE active='1' ORDER BY teamName");
	model->setQuery(query);
	ui->databaseView->setModel(model);
}

void ViewWindow::on_arenaButton_clicked()
{
	ui->totalCapLabel->setText("");
	model = new QSqlQueryModel;

	checkConnection();
	QSqlQuery query(QSqlDatabase::database());

	query.exec("SELECT arena, teamName FROM teams WHERE active='1' ORDER BY arena");
	model->setQuery(query);
	ui->databaseView->setModel(model);
}

void ViewWindow::on_seatButton_clicked()
{
	model = new QSqlQueryModel;

	checkConnection();
	QSqlQuery query(QSqlDatabase::database());
	totalCap = 0;

	query.prepare("SELECT arenaCap FROM teams WHERE active='1'");
	if(query.exec())
	{
		while(query.next())
		{
			totalCap += query.value(0).toInt();
		}
	}
	QString tmp = QString::number(totalCap);
	ui->totalCapLabel->setText("Total Seating Capacity: " + tmp);

	query.exec("SELECT arena, arenaCap FROM teams WHERE active='1' ORDER BY arenaCap");
	model->setQuery(query);
	ui->databaseView->setModel(model);
}

void ViewWindow::on_eastTeamButton_clicked()
{
	ui->totalCapLabel->setText("");
	model = new QSqlQueryModel;

	checkConnection();
	QSqlQuery query(QSqlDatabase::database());

	query.exec("select * from teams WHERE conference='Eastern' AND active='1' ORDER BY teamName");
	model->setQuery(query);
	ui->databaseView->setModel(model);
}

void ViewWindow::on_southeastTeamButton_clicked()
{
	ui->totalCapLabel->setText("");
	model = new QSqlQueryModel;

	checkConnection();
	QSqlQuery query(QSqlDatabase::database());

	query.exec("select * from teams WHERE division='Southeast' AND active='1' ORDER BY teamName");
	model->setQuery(query);
	ui->databaseView->setModel(model);
}

void ViewWindow::on_coachButton_clicked()
{
	ui->totalCapLabel->setText("");
	model = new QSqlQueryModel;

	checkConnection();
	QSqlQuery query(QSqlDatabase::database());

	query.exec("select teamName, coach from teams WHERE active='1' ORDER BY teamName");
	model->setQuery(query);
	ui->databaseView->setModel(model);
}

void ViewWindow::on_yearButton_clicked()
{
	ui->totalCapLabel->setText("");
	model = new QSqlQueryModel;

	checkConnection();
	QSqlQuery query(QSqlDatabase::database());

	query.exec("select teamName, arena, joinYear from teams WHERE active='1' ORDER BY joinYear");
	model->setQuery(query);
	ui->databaseView->setModel(model);
}

void ViewWindow::on_souvenirButton_clicked()
{
	ui->totalCapLabel->setText("");
	QString team;
	team = ui->teamComboBox->currentText();

	model = new QSqlQueryModel;

	checkConnection();
	QSqlQuery query(QSqlDatabase::database());

	query.exec("select * from souvenirs WHERE teamName='"+team+"'");
	model->setQuery(query);
	ui->databaseView->setModel(model);
}
