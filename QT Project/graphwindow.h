#ifndef GRAPHWINDOW_H
#define GRAPHWINDOW_H

#include <QWidget>
#include <vector>
#include "database.h"

namespace Ui {
class GraphWindow;
}

/**
 * @brief EditWindow
 * This class generates the window which allows admins to display graph traversals
 */
class GraphWindow : public QWidget
{
	Q_OBJECT

public:
	/**
	 * @author Aaron Geesink
	 * @brief GraphWindow(QWidget *parent = nullptr)
	 * GraphWindow constructor
	 * @param QWidget *parent
	 */
	explicit GraphWindow(QWidget *parent = nullptr);

	/**
	 * @author Aaron Geesink
	 * @brief ~GraphWindow()
	 * GraphWindow destructor
	 */
	~GraphWindow();

	/**
	 * @author Faris Hijazi
	 * @brief displayDFS(std::vector<Edge<QString>> edges)
	 * Displays any traversal to the program window
	 * @param std::vector<Edge<QString>> edges
	 */
    void displayDFS(std::vector<Edge<QString>> edges);

private slots:
	/**
	 * @author Faris Hijazi
	 * @brief on_dfsBtn_clicked()
	 * Displays a DFS traversal to the program window
	 */
    void on_dfsBtn_clicked();

	/**
	 * @author Faris Hijazi
	 * @brief on_bfsBtn_clicked()
	 * Displays a BFS traversal to the program window
	 */
    void on_bfsBtn_clicked();

	/**
	 * @author Faris Hijazi
	 * @brief on_bfsBtn_clicked()
	 * Displays an MST to the program window
	 */
    void on_mstBtn_clicked();

private:
	Ui::GraphWindow *ui;			/// Ui object for graphWindow
	MatrixGraph<QString> *graph1;	/// Graph of teams for performing traversals
	QString *teamsAr;				/// An array of teamNames
};

#endif // GRAPHWINDOW_H
