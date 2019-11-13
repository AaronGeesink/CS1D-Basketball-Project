#ifndef SOUVENIRWINDOW_H
#define SOUVENIRWINDOW_H

#include <QWidget>

namespace Ui {
class SouvenirWindow;
}

class SouvenirWindow : public QWidget
{
	Q_OBJECT

public:
	explicit SouvenirWindow(QWidget *parent = nullptr);
	~SouvenirWindow();

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
