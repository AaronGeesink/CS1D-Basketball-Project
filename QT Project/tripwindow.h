#ifndef TRIPWINDOW_H
#define TRIPWINDOW_H

#include <QWidget>
#include <QCheckBox>
#include <QRadioButton>
#include <QSpinBox>
#include "team.h"
#include "database.h"

namespace Ui {
class TripWindow;
}

class TripWindow : public QWidget
{
	Q_OBJECT

public:
	explicit TripWindow(QWidget *parent = nullptr);
	~TripWindow();

	void setNuggetsTrip();

	void setSpecifiedTrip();

	void setPistonsTrip();

	void setShortestTrip();

signals:
	void moveToTripSelectClicked();

	void moveToSouvenirClicked();

private slots:
	void on_moveToTripSelect_clicked();

	void on_moveToSouvenir_clicked();

private:
	Ui::TripWindow *ui;
};

#endif // TRIPWINDOW_H
