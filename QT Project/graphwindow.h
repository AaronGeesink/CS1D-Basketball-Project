#ifndef GRAPHWINDOW_H
#define GRAPHWINDOW_H

#include <QWidget>
#include <vector>
#include "team.h"


namespace Ui {
class GraphWindow;
}

class GraphWindow : public QWidget
{
	Q_OBJECT

public:
	explicit GraphWindow(QWidget *parent = nullptr);
	~GraphWindow();
    void displayMST(std::vector<Edge> edges);
    void displayDFS(std::vector<Edge> edges);
    void displayBFS(std::vector<Edge> edges);

private:
	Ui::GraphWindow *ui;
};

#endif // GRAPHWINDOW_H
