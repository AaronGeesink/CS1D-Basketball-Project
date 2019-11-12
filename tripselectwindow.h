#ifndef TRIPSELECTWINDOW_H
#define TRIPSELECTWINDOW_H

#include <QWidget>

namespace Ui {
class TripSelectWindow;
}

class TripSelectWindow : public QWidget
{
	Q_OBJECT

public:
	explicit TripSelectWindow(QWidget *parent = nullptr);
	~TripSelectWindow();

signals:
	void moveToNuggetsTripClicked();

	void moveToSpecifiedTripClicked();

	void moveToPistonsTripClicked();

	void moveToShortestTripClicked();

private slots:
	void on_moveToNuggetsTrip_clicked();

	void on_moveToSpecifiedTrip_clicked();

	void on_moveToPistonsTrip_clicked();

	void on_moveToShortestTrip_clicked();

private:
	Ui::TripSelectWindow *ui;
};

#endif // TRIPSELECTWINDOW_H
