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

	std::vector<Team> loadedTeams;

signals:
	void moveToTripSelectClicked();

	void moveToSouvenirClicked();
public slots:
    void addItem(int row, int col);
    void removeItem(int row, int col);

private slots:
	void on_moveToTripSelect_clicked();

	void on_moveToSouvenir_clicked();

	void on_NuggetsCombobox_currentIndexChanged(const QString &arg1);

private:
	Ui::TripWindow *ui;
    int customTableIndex = 0;
	int planNumber;
	QString comboValue;
};

#endif // TRIPWINDOW_H
