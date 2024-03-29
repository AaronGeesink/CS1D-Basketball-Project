#include "editwindow.h"
#include "ui_editwindow.h"

EditWindow::EditWindow(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::EditWindow)
{
	ui->setupUi(this);
	ui->databaseView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
}

EditWindow::~EditWindow()
{
	delete ui;
}

void EditWindow::populateCombo()
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

	ui->teamComboBox->clear();
	for(int i = 0; i < teams.size(); ++i)
		ui->teamComboBox->addItem(teams.at(i));
}

void EditWindow::on_loadTeams_clicked()
{
	currentTable = 1;
	model = new QSqlTableModel(this);
	model->setTable("teams");
	model->setEditStrategy(QSqlTableModel::OnManualSubmit);
	model->select();

	ui->databaseView->verticalHeader()->setVisible(false);
	ui->databaseView->setModel(model);
}

void EditWindow::on_loadSouvenirs_clicked()
{
	currentTable = 2;

	model = new QSqlTableModel(this);
	model->setTable("souvenirs");
	model->setEditStrategy(QSqlTableModel::OnManualSubmit);
	model->select();

	ui->databaseView->verticalHeader()->setVisible(false);
	ui->databaseView->setModel(model);
}

void EditWindow::on_addSouvenirButton_clicked()
{
	if(checkConnection())
	{
		QSqlQuery query(QSqlDatabase::database());
		if(currentTable != 2)
		{
			QMessageBox::information(this, tr("Error adding"), tr("Please load Souvenirs before adding"));
		}
		else
		{
			QString teamName, souvenirName, souvenirPrice;
			teamName = ui->teamComboBox->currentText();
			souvenirName = ui->souvenirLineEdit->text();
			souvenirPrice = ui->priceLineEdit->text();

			bool isFloat;
			souvenirPrice.toFloat(&isFloat);
			if (isFloat == true)
			{
				query.prepare("INSERT INTO souvenirs VALUES(NULL,'"+teamName+"','"+souvenirName+"','"+souvenirPrice+"')");
			}
			else
			{
				QMessageBox::information(this, tr("Error adding"), tr("Invalid Price"));
			}

		}
		if(!query.exec())
		{
			qDebug("Failed to add new record");
		}
		else
		{
			ui->souvenirLineEdit->setText("");
			ui->priceLineEdit->setText("");
		}
		model->select();
		ui->databaseView->setModel(model);
	}
}

void EditWindow::on_deleteSouvenirItem_clicked()
{
	if(checkConnection())
	{
		QSqlQuery query(QSqlDatabase::database());
		if(currentTable != 2)
		{
			QMessageBox::information(this, tr("Error deleting"), tr("Please load Souvenirs before deleting"));
		}
		else
		{
			QString souvenirValue;
			souvenirValue = ui->deleteLineEdit->text();
			QSqlQuery query(QSqlDatabase::database());
			query.prepare("DELETE FROM souvenirs WHERE souvenirID='"+souvenirValue+"'");
			if(!query.exec())
			{
				qDebug("Failed to delete");
			}
			else
			{
				ui->deleteLineEdit->setText("");
			}
			model->select();
			ui->databaseView->setModel(model);
		}
	}
}

void EditWindow::on_submitButton_clicked()
{
	model->database().transaction();
	if (model->submitAll())
	{
		model->database().commit();
		QMessageBox::information(this, tr("Database updated"), tr("Database updated!"));
	}
	else
	{
		model->database().rollback();
		QMessageBox::information(this, tr("Update Error"), tr("A cell contains an invalid parameter"));
		qDebug("Failed to update SQL Database");
	}
}

void EditWindow::on_revertButton_clicked()
{
	model->QSqlTableModel::revertAll();
}

void EditWindow::on_changeArenaButton_clicked()
{
	if(checkConnection())
	{
		QSqlQuery query(QSqlDatabase::database());
		if(currentTable != 1)
		{
			QMessageBox::information(this, tr("Error adding"), tr("Please load Teams before changing"));
		}
		else
		{
			QString teamName, arenaName, souvenirPrice;
			teamName = ui->teamComboBox->currentText();
			arenaName = ui->arenaLineEdit->text();

			query.prepare("UPDATE teams SET arena='"+arenaName+"' WHERE teamName='"+teamName+"'");
			if (query.exec())
			{
				QMessageBox::information(this, tr("Success"), tr("Arena successfully changed"));
			}
			else
			{
				QMessageBox::information(this, tr("Error Changing arenas"), tr("Error Changing arenas"));
			}

			query.prepare("UPDATE distances SET startArena='"+arenaName+"' WHERE startTeam='"+teamName+"'");
			if (query.exec())
			{
				QMessageBox::information(this, tr("Success"), tr("Arena successfully changed"));
			}
			else
			{
				QMessageBox::information(this, tr("Error Changing arenas"), tr("Error Changing arenas"));
			}


		}
		if(!query.exec())
		{
			qDebug("Failed to add new record");
		}
		else
		{
			ui->souvenirLineEdit->setText("");
			ui->priceLineEdit->setText("");
		}
		model->select();
		ui->databaseView->setModel(model);
	}

}

void EditWindow::on_loadDistances_clicked()
{
	currentTable = 3;

	model = new QSqlTableModel(this);
	model->setTable("distances");
	model->setEditStrategy(QSqlTableModel::OnManualSubmit);
	model->select();

	ui->databaseView->verticalHeader()->setVisible(false);
	ui->databaseView->setModel(model);
}

void EditWindow::on_addDistanceButton_clicked()
{
	if(checkConnection())
	{
		QSqlQuery query(QSqlDatabase::database());
		if(currentTable != 3)
		{
			QMessageBox::information(this, tr("Error adding"), tr("Please load Distances before adding"));
		}
		else
		{
			QString teamName;
			teamName = ui->teamComboBox->currentText();
			query.prepare("INSERT INTO distances VALUES('"+teamName+"', NULL, NULL, NULL)");
			if (query.exec())
			{
				QMessageBox::information(this, tr("Distance added"), tr("Distance added"));
			}
			else
			{
				QMessageBox::information(this, tr("Error adding"), tr("Distance Error"));
			}
		}
		model->select();
		ui->databaseView->setModel(model);
	}
}
