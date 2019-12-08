#include "graphwindow.h"
#include "ui_graphwindow.h"

GraphWindow::GraphWindow(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::GraphWindow)
{
	ui->setupUi(this);
    ui->mstList->setRowCount(2);
    ui->travList->setRowCount(1);
}

void GraphWindow::displayMST(std::vector<Edge> edges)
{
    ui->mstList->setColumnCount(int(edges.size()));
    int row = 0;
    for(auto i: edges)
    {
        QTableWidgetItem *startItem = new QTableWidgetItem(i.startTeam);
        QTableWidgetItem *endItem = new QTableWidgetItem(i.startTeam);
        ui->mstList->setItem(row, 0, startItem);
        ui->mstList->setItem(row, 1, endItem);
        row++;
    }
}

void GraphWindow::displayBFS(std::vector<Edge> edges)
{
    ui->travList->setColumnCount(int(edges.size()));
    int row = 0;
    for(auto i: edges)
    {
        QTableWidgetItem *startItem = new QTableWidgetItem(i.startTeam);
        QTableWidgetItem *endItem = new QTableWidgetItem(i.startTeam);
        ui->mstList->setItem(row, 0, startItem);
        ui->mstList->setItem(row, 1, endItem);
        row++;
    }
}

void GraphWindow::displayDFS(std::vector<Edge> edges)
{
    ui->travList->setColumnCount(int(edges.size()));
    int row = 0;
    for(auto i: edges)
    {
        QTableWidgetItem *item = new QTableWidgetItem(i.startTeam);
        ui->mstList->setItem(row, 0, item);
        row++;
    }
}

GraphWindow::~GraphWindow()
{
	delete ui;
}
