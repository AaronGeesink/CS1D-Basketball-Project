#ifndef TRIPWINDOW_H
#define TRIPWINDOW_H

#include <QWidget>
#include <QCheckBox>
#include <QRadioButton>
#include <QSpinBox>
#include <QComboBox>
#include <QMessageBox>
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

	/**
	 * @author Aaron Geesink
	 * @brief getLoadedTeams()
	 * Returns a vector containing the currently loaded Teams
	 * @return vector<Team>
	 */
	std::vector<Team>& getLoadedTeams();

signals:
	void moveToTripSelectClicked();

	void moveToSouvenirClicked();
public slots:
    void addItem1(int row, int col);
    void removeItem1(int row, int col);
    void addItem2(int row, int col);
    void removeItem2(int row, int col);

private slots:
	void on_moveToTripSelect_clicked();

	void on_moveToSouvenir_clicked();

	void on_NuggetsCombobox_currentIndexChanged(const QString &arg1);

private:
	Ui::TripWindow *ui;
	std::vector<Team> loadedTeams;
    int customTableIndex1 = 0;
    int customTableIndex2 = 0;
	int planNumber;
	QString comboValue;
};

#endif // TRIPWINDOW_H
