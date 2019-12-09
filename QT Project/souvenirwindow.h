#ifndef SOUVENIRWINDOW_H
#define SOUVENIRWINDOW_H

#include <QWidget>
#include "Team.h"

namespace Ui {
class SouvenirWindow;
}

class SouvenirWindow : public QWidget
{
	Q_OBJECT

public:
	explicit SouvenirWindow(QWidget *parent = nullptr);
	~SouvenirWindow();

	std::vector<Team> loadedTeams;

signals:
	void moveToTripClicked();
	void moveToResultsClicked();

private slots:
	void on_moveToTrip_clicked();

	void on_moveToResults_clicked();

private:
	Ui::SouvenirWindow *ui;
};

#endif // SOUVENIRWINDOW_H
