#include "graphwindow.h"
#include "ui_graphwindow.h"

GraphWindow::GraphWindow(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::GraphWindow)
{
	ui->setupUi(this);
    ui->mstList->setRowCount(2);
    ui->travList->setRowCount(1);
    std::vector<Team> teams = queryTeams();
    //QString teamsAr[teams.size()];
    int in = 0;
    for(auto i: teams)
    {
        teamsAr[in] = i.getTeamName();
    }
}

void GraphWindow::displayMST(std::vector<Edge<QString>> edges)
{
    ui->mstList->setColumnCount(int(edges.size()));
    int row = 0;
    for(auto i: edges)
    {
        QTableWidgetItem *startItem = new QTableWidgetItem(i.start);
        QTableWidgetItem *endItem = new QTableWidgetItem(i.start);
        ui->mstList->setItem(row, 0, startItem);
        ui->mstList->setItem(row, 1, endItem);
        row++;
    }
}

void GraphWindow::displayBFS(std::vector<Edge<QString>> edges)
{
    ui->travList->setColumnCount(int(edges.size()));
    int row = 0;
    for(auto i: edges)
    {
        QTableWidgetItem *startItem = new QTableWidgetItem(i.start);
        QTableWidgetItem *endItem = new QTableWidgetItem(i.start);
        ui->mstList->setItem(row, 0, startItem);
        ui->mstList->setItem(row, 1, endItem);
        row++;
    }
}

void GraphWindow::displayDFS(std::vector<Edge<QString>> edges)
{
    ui->travList->setColumnCount(int(edges.size()));
    int row = 0;
    for(auto i: edges)
    {
        QTableWidgetItem *item = new QTableWidgetItem(i.start);
        ui->mstList->setItem(row, 0, item);
        row++;
    }
}

void GraphWindow::on_dfsBtn_clicked()
{
    MatrixGraph<QString> graph1(teamsAr, 30);
    graph1.DFS("Los Angeles Lakers");
}

void GraphWindow::on_bfsBtn_clicked()
{

}


void GraphWindow::on_mstBtn_clicked()
{

}

GraphWindow::~GraphWindow()
{
	delete ui;
}


