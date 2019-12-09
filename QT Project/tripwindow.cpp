#include "tripwindow.h"
#include "ui_tripwindow.h"

TripWindow::TripWindow(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::TripWindow)
{
	ui->setupUi(this);
}

TripWindow::~TripWindow()
{
	delete ui;
}

void TripWindow::setNuggetsTrip()
{
	loadedTeams.clear();
	planNumber = 0;

	std::vector<QString> teamNames = queryTeamNames();


	for (auto it = teamNames.begin(); it != teamNames.end(); it++)
	{
		if (*it == "Denver Nuggets")
			teamNames.erase(it);
	}

	// Table Setup
	ui->nuggetsTable->setRowCount(loadedTeams.size());
	ui->nuggetsTable->setColumnCount(3);

	ui->nuggetsTable->setHorizontalHeaderItem(0, new QTableWidgetItem("Start"));
	ui->nuggetsTable->setHorizontalHeaderItem(1, new QTableWidgetItem("End"));
	ui->nuggetsTable->setHorizontalHeaderItem(2, new QTableWidgetItem("Distance"));

    ui->nuggetsTable->setSelectionMode(QAbstractItemView::NoSelection);

	for(int i = 0; i < teamNames.size(); ++i)
		ui->NuggetsCombobox->addItem(teamNames[i]);

	ui->stackedWidget->setCurrentIndex(0);
}


void TripWindow::addItem(int row, int col)
{
    ui->custom1OrderedTable->setRowCount(customTableIndex+1);
    qDebug() << "item pressed: " << row << " " << col;
    QTableWidgetItem *item = ui->custom1Table->item(row,col);
    ui->custom1OrderedTable->setItem(customTableIndex, 0, new QTableWidgetItem(*item));
    ui->custom1Table->removeRow(row);
    customTableIndex++;
}

void TripWindow::removeItem(int row, int col)
{
    ui->custom1Table->setRowCount(ui->custom1Table->rowCount()+1);
    qDebug() << "item pressed: " << row << " " << col;
    QTableWidgetItem *item = ui->custom1OrderedTable->item(row,col);
    ui->custom1Table->setItem(ui->custom1Table->rowCount()-1, 0, new QTableWidgetItem(*item));
    ui->custom1OrderedTable->removeRow(row);
    customTableIndex--;
}

void TripWindow::setSpecifiedTrip()
{
    loadedTeams.clear();
	planNumber = 1;

	std::vector<Team> teams = queryTeams();
	qDebug() << teams.size();
	// Table Setup
	ui->custom1Table->setRowCount(teams.size());
    //ui->custom1OrderedTable->setRowCount(teams.size());
    ui->custom1Table->setColumnCount(1);
    ui->custom1OrderedTable->setColumnCount(1);

	ui->custom1Table->setHorizontalHeaderItem(0, new QTableWidgetItem("Name"));
    //ui->custom1Table->setHorizontalHeaderItem(1, new QTableWidgetItem("Teams to Add"));
    ui->custom1OrderedTable->setHorizontalHeaderItem(0, new QTableWidgetItem("Name"));
    //ui->custom1OrderedTable->setHorizontalHeaderItem(1, new QTableWidgetItem("Remove"));
    //ui->custom1Table->setHorizontalHeaderItem(2, new QTableWidgetItem("Starting City"));
    //ui->custom1Table->setHorizontalHeaderItem(3, new QTableWidgetItem("Order to Visit"));
            //->setSelectionMode(QAbstractItemView::NoSelection);
    QObject::connect(ui->custom1Table, SIGNAL(cellPressed(int, int)), this, SLOT(addItem(int,int)));
    QObject::connect(ui->custom1OrderedTable, SIGNAL(cellPressed(int, int)), this, SLOT(removeItem(int,int)));
    //QLabel *name;
	for (int i = 0; i < teams.size(); i++)
	{
        //name = new QLabel();
        //name->setText(teams[i].getTeamName());
        //ui->custom1Table->setCellWidget(i, 0, name);
        //QTableWidgetItem *it = ;
        //it->setText(teams[i].getTeamName());
        ui->custom1Table->setItem(i, 0, new QTableWidgetItem);
        ui->custom1Table->item(i,0)->setText(teams[i].getTeamName());
        //delete it;
        //addBox = new QCheckBox;
        //ui->custom1Table->setCellWidget(i, 1, addBox);
        //ui->custom1Table->setCellWidget(i, 2, new QRadioButton());
        //ui->custom1Table->setCellWidget(i, 3, new QSpinBox());
	}

	ui->stackedWidget->setCurrentIndex(1);
}

void TripWindow::setPistonsTrip()
{
	loadedTeams.clear();
	loadedTeams = queryTeams();
	planNumber = 2;

	// Table Setup
	ui->pistonsTable->setRowCount(loadedTeams.size());
	ui->pistonsTable->setColumnCount(3);
	ui->pistonsTable->setHorizontalHeaderItem(0, new QTableWidgetItem("Start Team"));
	ui->pistonsTable->setHorizontalHeaderItem(1, new QTableWidgetItem("End Team"));
	ui->pistonsTable->setHorizontalHeaderItem(2, new QTableWidgetItem("Distance"));

	ui->pistonsTable->setSelectionMode(QAbstractItemView::NoSelection);

	QLabel *name;
	for (int i = 0; i < loadedTeams.size(); i++)
	{
		name = new QLabel();
		name->setText(loadedTeams[i].getTeamName());
		ui->pistonsTable->setCellWidget(i, 0, name);
		//ui->pistonsTable->setCellWidget(i, 1, new QCheckBox());
		//ui->pistonsTable->setCellWidget(i, 2, new QRadioButton());
	}

	ui->stackedWidget->setCurrentIndex(2);
}

void TripWindow::setShortestTrip()
{
	loadedTeams.clear();
	planNumber = 3;

	// Table Setup
	ui->custom2Table->setRowCount(loadedTeams.size());
	ui->custom2Table->setColumnCount(3);

	ui->custom2Table->setHorizontalHeaderItem(0, new QTableWidgetItem("Name"));
	ui->custom2Table->setHorizontalHeaderItem(1, new QTableWidgetItem("Teams to Add"));
	ui->custom2Table->setHorizontalHeaderItem(2, new QTableWidgetItem("Starting City"));

	ui->custom2Table->setSelectionMode(QAbstractItemView::NoSelection);

	QLabel *name;
	for (int i = 0; i < loadedTeams.size(); i++)
	{
		name = new QLabel();
		name->setText(loadedTeams[i].getTeamName());
		ui->custom2Table->setCellWidget(i, 0, name);

		ui->custom2Table->setCellWidget(i, 1, new QCheckBox());
		ui->custom2Table->setCellWidget(i, 2, new QRadioButton());
	}

	ui->stackedWidget->setCurrentIndex(3);
}

std::vector<Team> &TripWindow::getLoadedTeams()
{
	return loadedTeams;
}

void TripWindow::on_moveToTripSelect_clicked()
{
	emit moveToTripSelectClicked();
}

void TripWindow::on_moveToSouvenir_clicked()
{
	// Denver Nuggets plan
	if (planNumber == 0)
	{
		loadedTeams.clear();

		loadedTeams.push_back(queryTeam("Denver Nuggets"));
		loadedTeams.push_back(queryTeam(comboValue));

		qDebug() << loadedTeams[0].getTeamName() << " --> " << loadedTeams[1].getTeamName();
	}
	// custom specified plan
	else if (planNumber == 1)
	{
        for(int i = 0; i<ui->custom1OrderedTable->rowCount();i++)
        {
            loadedTeams.push_back(queryTeam(ui->custom1OrderedTable->item(i,0)->text()));
            qDebug() << loadedTeams[i].getTeamName();
            for(auto i: loadedTeams[i].getEdges())
            {
                qDebug() << "start: " << i.start;
                qDebug() << "end: " << i.end;
                qDebug() << "weight: " << i.weight;
            }
            qDebug() << "\n\n";
        }
	}
	// Detroit Pistons Plan
	else if (planNumber == 2)
	{
        std::vector<Team> visited;
        std::vector<Team> notVisited = queryTeams();
        std::vector<Vertex<QString>> astarVertex;
        struct testNode
        {
            QString start;
            QString end;
            double weight;
        };

        struct comparator
        {
            bool operator()(const testNode & n1, const testNode & n2) const
            {
                if (n1.weight < n2.weight)
                    return true;
                if (n2.weight < n1.weight)
                    return false;
                return true;
            }
        };


        std::vector<testNode> testNodes;

        // Construct graph
        std::vector<QString> teams = queryTeamNames();
        MatrixGraph<QString> *graph1;
        QString* teamsAr = new QString[teams.size()];
        int in = 0;
        for(auto i = teams.begin(); i!=teams.end(); i++)
        {
            teamsAr[in] = *i;
            qDebug() << "Team name:" << teamsAr[in];
            in++;
        }
        graph1 = new MatrixGraph<QString>(teamsAr, teams.size());
        for(auto i = teams.begin(); i!=teams.end(); i++)
        {
            std::vector<Edge<QString>> edges = queryEdges(*i);
            for(auto e: edges)
                graph1->addEdge(e.start, e.end, e.weight);
        }

        visited.push_back(queryTeam("Detroit Pistons"));

        for(auto i = notVisited.begin(); i != notVisited.end(); i++)
            if(i->getTeamName() == "Detroit Pistons")
            {
                notVisited.erase(i);
                break;
            }
        for(int k = 0; k!=visited.size(); k++)
        {
        for(auto i = notVisited.begin(); i!=notVisited.end(); i++)
        {
            //find cost of each node
            astarVertex = graph1->aStar(visited[k].getTeamName(), i->getTeamName());
            double pathCost = 0;
            for (int i = astarVertex.size() - 2; i >= 0; i--)
            {
                for (int j = 0; j < astarVertex[i].edges.size(); j++)
                {
                    if (astarVertex[i].edges[j].pEndVertex->value == astarVertex[i].parent->value)
                    {
                        //cout << " --> " << astarVertex[i].value << " (" << astarVertex[i].edges[j].weight << ")";
                        pathCost += astarVertex[i].edges[j].weight;
                    }
                }
            }

            testNode node;
            node.start = visited[k].getTeamName();
            node.end = i->getTeamName();
            node.weight = pathCost;
            testNodes.push_back(node);
        }
        std::sort(testNodes.begin(), testNodes.end(), comparator());

        for(auto i: testNodes)
        {
            bool stop = true;
            for(auto k: visited)
            {
                if(k.getTeamName() == i.end)
                {
                    stop = false;
                }
            }
            if(stop)
            {
                visited.push_back(queryTeam(i.end));
                break;
            }
        }
        for(auto i = notVisited.begin(); i!=notVisited.end(); i++)
        {
            if(i->getTeamName() == visited.back().getTeamName())
            {
                notVisited.erase(i);
                break;
            }
        }
        for(auto i: testNodes)
        {
            //qDebug() << "start: " << i.start << ", end: "<< i.end;
            //qDebug() << "distance: " << i.weight;
        }
        }
        for (auto i : visited) {
            qDebug() << "Team: " << i.getTeamName();
        }
        loadedTeams = visited;
	}
	// Custom Shortest plan
	else if (planNumber == 3)
	{

	}

	emit moveToSouvenirClicked();
}

void TripWindow::on_NuggetsCombobox_currentIndexChanged(const QString &arg1)
{
	comboValue = arg1;
}
