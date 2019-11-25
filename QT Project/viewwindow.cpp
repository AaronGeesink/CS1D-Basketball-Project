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
	query.exec("SELECT teamName FROM teams");

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
	model = new QSqlQueryModel;

	checkConnection();
	QSqlQuery query(QSqlDatabase::database());

	query.exec("select teamName from teams ORDER BY teamName");
	model->setQuery(query);
	ui->databaseView->setModel(model);
}

void ViewWindow::on_arenaButton_clicked()
{
	model = new QSqlQueryModel;

	checkConnection();
	QSqlQuery query(QSqlDatabase::database());

	query.exec("SELECT arena, teamName FROM teams ORDER BY arena");
	model->setQuery(query);
	ui->databaseView->setModel(model);
}

void ViewWindow::on_seatButton_clicked()
{
	model = new QSqlQueryModel;

	checkConnection();
	QSqlQuery query(QSqlDatabase::database());

	query.exec("SELECT arena, arenaCap FROM teams ORDER BY arenaCap");
	model->setQuery(query);
	ui->databaseView->setModel(model);
}

void ViewWindow::on_eastTeamButton_clicked()
{
	model = new QSqlQueryModel;

	checkConnection();
	QSqlQuery query(QSqlDatabase::database());

	query.exec("select * from teams WHERE conference='Eastern' ORDER BY teamName");
	model->setQuery(query);
	ui->databaseView->setModel(model);
}

void ViewWindow::on_southeastTeamButton_clicked()
{
	model = new QSqlQueryModel;

	checkConnection();
	QSqlQuery query(QSqlDatabase::database());

	query.exec("select * from teams WHERE division='Southeast' ORDER BY teamName");
	model->setQuery(query);
	ui->databaseView->setModel(model);
}

void ViewWindow::on_coachButton_clicked()
{
	model = new QSqlQueryModel;

	checkConnection();
	QSqlQuery query(QSqlDatabase::database());

	query.exec("select teamName, coach from teams ORDER BY teamName");
	model->setQuery(query);
	ui->databaseView->setModel(model);
}

void ViewWindow::on_yearButton_clicked()
{
	model = new QSqlQueryModel;

	checkConnection();
	QSqlQuery query(QSqlDatabase::database());

	query.exec("select teamName, arena, joinYear from teams ORDER BY joinYear");
	model->setQuery(query);
	ui->databaseView->setModel(model);
}

void ViewWindow::on_souvenirButton_clicked()
{
	QString team;
	team = ui->teamComboBox->currentText();

	model = new QSqlQueryModel;

	checkConnection();
	QSqlQuery query(QSqlDatabase::database());

	query.exec("select * from souvenirs WHERE teamName='"+team+"'");
	model->setQuery(query);
	ui->databaseView->setModel(model);
}
