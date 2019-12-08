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
public slots:
    void addItem(int row, int col);
    void removeItem(int row, int col);

private slots:
	void on_moveToTripSelect_clicked();

	void on_moveToSouvenir_clicked();

private:
	Ui::TripWindow *ui;
    int customTableIndex = 0;
};

#endif // TRIPWINDOW_H
