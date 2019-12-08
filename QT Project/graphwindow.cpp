#include "graphwindow.h"
#include "ui_graphwindow.h"
#include <QDebug>

GraphWindow::GraphWindow(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::GraphWindow)
{
    QTableWidgetItem *item1 = new QTableWidgetItem("Start");
    QTableWidgetItem *item2 = new QTableWidgetItem("End");
    ui->setupUi(this);
    ui->mstList->setColumnCount(2);
    ui->travList->setColumnCount(2);
    ui->mstList->setHorizontalHeaderItem(0, item1);
    ui->mstList->setHorizontalHeaderItem(1, item2);
    ui->travList->setHorizontalHeaderItem(0, item1);
    ui->travList->setHorizontalHeaderItem(1, item2);
}

void GraphWindow::displayMST(std::vector<Edge<QString>> edges)
{
    ui->mstList->setRowCount(int(edges.size()));
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
    ui->travList->setRowCount(int(edges.size()));
    int row = 0;
    for(auto i: edges)
    {
        QTableWidgetItem *startItem = new QTableWidgetItem(i.start);
        qDebug() << startItem;
        QTableWidgetItem *endItem = new QTableWidgetItem(i.start);
        qDebug() <<endItem;
        ui->mstList->setItem(row, 0, startItem);
        ui->mstList->setItem(row, 1, endItem);
        row++;
    }
}

void GraphWindow::displayDFS(std::vector<Edge<QString>> edges)
{
    ui->travList->setRowCount(int(edges.size()));
    int row = 0;
    for(auto i: edges)
    {
        qDebug() << "start: " << i.start;
        qDebug() << "end: " <<i.end;
        QTableWidgetItem *item1 = new QTableWidgetItem(i.start);
        QTableWidgetItem *item2 = new QTableWidgetItem(i.end);
        //item->setText(i.start);
        ui->travList->setItem(row, 0, item1);
        ui->travList->setItem(row, 1, item2);
        row++;
    }
}

void GraphWindow::on_dfsBtn_clicked()
{
    std::vector<QString> teams = queryTeamNames();
    //QString teamsAr[teams.size()];
    int in = 0;
    for(auto i = teams.begin(); i!=teams.end(); i++)
    {
        teamsAr[in] = *i;
        qDebug() << "Team name:" << teamsAr[in];
        in++;
    }


    qDebug() << "BFS CLICKED";
    MatrixGraph<QString> graph1(teamsAr, 30);
    for(auto i = teams.begin(); i!=teams.end(); i++)
    {
        std::vector<Edge<QString>> edges = queryEdges(*i);
        for(auto e: edges)
            graph1.addEdge(e.start, e.end, e.weight);
    }

    std::vector<Edge<QString>> edges = graph1.DFS("Miami Heat");
    qDebug() << edges.size();
    displayDFS(edges);

}

void GraphWindow::on_bfsBtn_clicked()
{
    std::vector<QString> teams = queryTeamNames();
    //QString teamsAr[teams.size()];
    int in = 0;
    for(auto i = teams.begin(); i!=teams.end(); i++)
    {
        teamsAr[in] = *i;
        qDebug() << "Team name:" << teamsAr[in];
        in++;
    }


    qDebug() << "BFS CLICKED";
    MatrixGraph<QString> graph1(teamsAr, 30);
    for(auto i = teams.begin(); i!=teams.end(); i++)
    {
        std::vector<Edge<QString>> edges = queryEdges(*i);
        for(auto e: edges)
            graph1.addEdge(e.start, e.end, e.weight);
    }

    std::vector<Edge<QString>> edges = graph1.BFS("Miami Heat");
    qDebug() << edges.size();
    displayDFS(edges);
}


void GraphWindow::on_mstBtn_clicked()
{


}

GraphWindow::~GraphWindow()
{
	delete ui;
}


