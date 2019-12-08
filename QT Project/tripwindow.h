#ifndef TRIPWINDOW_H
#define TRIPWINDOW_H

#include <QWidget>
#include <QCheckBox>
#include <QRadioButton>
#include <QSpinBox>
#include <QComboBox>
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

	void on_NuggetsCombobox_currentIndexChanged(const QString &arg1);

private:
	Ui::TripWindow *ui;
	std::vector<Team> loadedTeams;
	int planNumber;
	QString comboValue;
};

#endif // TRIPWINDOW_H
