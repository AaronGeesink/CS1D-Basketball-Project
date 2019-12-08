#include "graphwindow.h"
#include "ui_graphwindow.h"
#include <QDebug>

GraphWindow::GraphWindow(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::GraphWindow)
{
    QTableWidgetItem *item1 = new QTableWidgetItem("Start");
    QTableWidgetItem *item2 = new QTableWidgetItem("End");
    QTableWidgetItem *item3 = new QTableWidgetItem("Distance");
    ui->setupUi(this);
    ui->travList->setColumnCount(3);
    ui->travList->setHorizontalHeaderItem(0, item1);
    ui->travList->setHorizontalHeaderItem(1, item2);
    ui->travList->setHorizontalHeaderItem(2, item3);
    ui->Image->setPixmap(QDir::currentPath() + "/resources/map.jpg");
}

void GraphWindow::displayMST(std::vector<Edge<QString>> edges)
{

    int row = 0;

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

    }
}

void GraphWindow::displayDFS(std::vector<Edge<QString>> edges)
{
    double totalDistance = 0;
    ui->travList->setRowCount(int(edges.size())+1);
    int row = 0;
    for(auto i: edges)
    {
        qDebug() << "start: " << i.start;
        qDebug() << "end: " <<i.end;
        QTableWidgetItem *item1 = new QTableWidgetItem(i.start);
        QTableWidgetItem *item2 = new QTableWidgetItem(i.end);
        QTableWidgetItem *item3 = new QTableWidgetItem(QString::number(i.weight));
        totalDistance += i.weight;
        ui->travList->setItem(row, 0, item1);
        ui->travList->setItem(row, 1, item2);
        ui->travList->setItem(row, 2, item3);
        row++;
    }
    QTableWidgetItem *lable = new QTableWidgetItem("Total Distance");
    QTableWidgetItem *distance = new QTableWidgetItem(QString::number(totalDistance));
    ui->travList->setItem(row, 1, lable);
    ui->travList->setItem(row, 2, distance);
}

void GraphWindow::on_dfsBtn_clicked()
{
    std::vector<QString> teams = queryTeamNames();
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
    std::vector<QString> teams = queryTeamNames();
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

    std::vector<Edge<QString>> edges = graph1.kruskalMST();
    qDebug() << edges.size();
    displayDFS(edges);
}

GraphWindow::~GraphWindow()
{
	delete ui;
}


