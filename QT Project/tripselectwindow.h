#ifndef TRIPSELECTWINDOW_H
#define TRIPSELECTWINDOW_H

#include <QWidget>

namespace Ui {
class TripSelectWindow;
}

/**
 * @brief TripSelectWindow
 * This class generates the window which allows for trips to be planned
 */
class TripSelectWindow : public QWidget
{
	Q_OBJECT

public:
	explicit TripSelectWindow(QWidget *parent = nullptr);
	~TripSelectWindow();

signals:
	/**
	 * @author Aaron Geesink
	 * @brief moveToNuggetsTripClicked()
	 * Proceeds to the Denver Nuggets trip window
	 */
	void moveToNuggetsTripClicked();

	/**
	 * @author Aaron Geesink
	 * @brief moveToSpecifiedTripClicked()
	 * Proceeds to the Specified trip window
	 */
	void moveToSpecifiedTripClicked();

	/**
	 * @author Aaron Geesink
	 * @brief moveToPistonsTripClicked()
	 * Proceeds to the Pistons trip window
	 */
	void moveToPistonsTripClicked();

	/**
	 * @author Aaron Geesink
	 * @brief moveToShortestTripClicked()
	 * Proceeds to the Shortest trip window
	 */
	void moveToShortestTripClicked();

private slots:
	/**
	 * @author Aaron Geesink
	 * @brief on_moveToNuggetsTrip_clicked()
	 * Proceeds to the Denver Nuggets trip window
	 */
	void on_moveToNuggetsTrip_clicked();

	/**
	 * @author Aaron Geesink
	 * @brief on_moveToSpecifiedTrip_clicked()
	 * Proceeds to the Specified trip window
	 */
	void on_moveToSpecifiedTrip_clicked();

	/**
	 * @author Aaron Geesink
	 * @brief on_moveToPistonsTrip_clicked()
	 * Proceeds to the Pistons trip window
	 */
	void on_moveToPistonsTrip_clicked();

	/**
	 * @author Aaron Geesink
	 * @brief on_moveToShortestTrip_clicked()
	 * Proceeds to the Shortest trip window
	 */
	void on_moveToShortestTrip_clicked();

private:
	Ui::TripSelectWindow *ui;
};

#endif // TRIPSELECTWINDOW_H
