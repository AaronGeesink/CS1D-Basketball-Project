#ifndef GRAPHWINDOW_H
#define GRAPHWINDOW_H

#include <QWidget>
#include <vector>
#include "database.h"

namespace Ui {
class GraphWindow;
}

class GraphWindow : public QWidget
{
	Q_OBJECT

public:
	explicit GraphWindow(QWidget *parent = nullptr);
	~GraphWindow();
    void displayMST(std::vector<Edge<QString>> edges);
    void displayDFS(std::vector<Edge<QString>> edges);
    void displayBFS(std::vector<Edge<QString>> edges);

private slots:
    void on_dfsBtn_clicked();
    void on_bfsBtn_clicked();
    void on_mstBtn_clicked();

private:
	Ui::GraphWindow *ui;
    QString teamsAr[30];
};

#endif // GRAPHWINDOW_H
