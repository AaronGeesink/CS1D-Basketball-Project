#ifndef RESULTSWINDOW_H
#define RESULTSWINDOW_H

#include <QWidget>

namespace Ui {
class ResultsWindow;
}

class ResultsWindow : public QWidget
{
	Q_OBJECT

public:
	explicit ResultsWindow(QWidget *parent = nullptr);
	~ResultsWindow();

signals:
	void moveToSouvenirClicked();
	void moveToTripSelectClicked();

private slots:
	void on_moveToSouvenir_clicked();

	void on_moveToTripSelect_clicked();

private:
	Ui::ResultsWindow *ui;
};

#endif // RESULTSWINDOW_H
