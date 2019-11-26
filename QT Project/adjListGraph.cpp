#include "adjListGraph.h"
#include "database.h"

static comparator lessthan;

graphAdjList::graphAdjList()
{
    g = new std::map<QString, vertex>;
    addTeamEdges();
}

graphAdjList::~graphAdjList()
{
    delete g;
}

void graphAdjList::addEdge( QString v1, QString v2, int distance )
{
    Edge e1{v1,v2,distance};
    Edge e2{v2,v1,distance};
    vertex first;
    vertex second;
    first.adjL.push_back(e1);
    first.vertex = v1;
    second.adjL.push_back(e1);
    second.vertex = v1;
    g->insert( std::pair<QString, vertex>(v1, first) );
    g->insert( std::pair<QString, vertex>(v2, second) );
}

void graphAdjList::addTeamEdges()
{

    std::vector<QString> teams = queryTeamNames();
    for(auto i = teams.begin(); i != teams.end(); i++)
    {
        vertex *v = new vertex;
        v->adjL = queryEdges(*i);
        v->vertex = *i;
        g->insert( std::pair<QString, vertex>(*i, *v) );
        delete v;
    }

}

graphAdjList::graphAdjList(std::map<QString, vertex> *newG)
{
    g = newG;
}

// Print adjacency list representaion ot graph
void graphAdjList::printGraph()
{
    QString s;
    int w;
    for (std::map<QString, vertex>::iterator i = g->begin(); i!=g->end(); i++)
    {
        qDebug() << "Node " << i->second.vertex << " makes an edge with \n";
        for (auto j = i->second.adjL.begin(); j!=i->second.adjL.end(); j++)
        {
            s = j->endTeam;
            w = j->distance;
            qDebug() << "\tNode " << s << " with weight = "
                 << w << "\n";
        }
        std::cout << "\n";
    }
}

/*
graph *graphAdjList::reverseEdges()
{
    graph *t = new graph[LIST_SIZE];
    for(int i=0; i< LIST_SIZE; i++)
    {
        for(std::vector<std::pair<int, int>>::iterator j = g[i].adjL.begin(); j != g[i].adjL.end(); j++)
        {
            t[j->first].adjL.push_back(std::make_pair(i, j->second));
            t[j->first].name = findName(j->first);
        }
    }
    return t;
}

void graphAdjList::checkConnection()
{
    std::vector<bool> visited(LIST_SIZE, false);
    check_con_DFS(0, visited);
    bool connected = true;
    for(std::vector<bool>::iterator i = visited.begin(); i!=visited.end(); i++)
    {
        if(!*i)
            connected = false;
    }
    for(std::vector<bool>::iterator i = visited.begin(); i!=visited.end(); i++)
    {
        *i = false;
    }
    if(connected)
    {
        graphAdjList g2(this->reverseEdges());
        //g2.printGraph();
        g2.check_con_DFS(0, visited);
        for(std::vector<bool>::iterator i = visited.begin(); i!=visited.end(); i++)
        {
            if(!*i)
                connected = false;
        }
    }
    if(connected)
    {
        std::cout << "\n\nThe graph is strongly connected\n";
    }
    else
    {
        std::cout << "\n\nThe graph is not strongly connected\n";
    }

}
*/

void graphAdjList::sortByDist()
{
    for(std::map<QString, vertex>::iterator i = g->begin(); i!=g->end(); i++)
    {
        std::sort(i->second.adjL.begin(), i->second.adjL.end(), lessthan);
    }
}

// A utility function to do DFS of graph
// recursively from a given vertex u.
void graphAdjList::DFS2(QString u, std::map<QString, bool> &visited,
                        std::vector<QString>& discEdges, std::vector<QString>& backEdges,
                        std::vector<QString>& forwardEdges, std::vector<QString>& crossEdges)
{
    QString edge;
    visited[u] = true;
    t++;
    g->at(u).startTime += t;
    for (auto i = g->at(u).adjL.begin(); i!=g->at(u).adjL.end(); i++)
    {
        if (!visited[i->endTeam])
        {
            deDist += i->distance;
            edge = i->startTeam;
            edge += " -> ";
            edge += i->endTeam;
            discEdges.push_back(edge);
            qDebug() << '\n' << i->startTeam << " -> " << i->endTeam << " ("<<deDist<<") \n";
            DFS2(i->endTeam, visited, discEdges, backEdges, forwardEdges, crossEdges);

        }
        else
        {
            edge = i->startTeam;
            edge += " -> ";
            edge += i->endTeam;

            if(g->at(i->endTeam).endTime == 0)
            {
                backEdges.push_back(edge);
            }
            else if(g->at(i->startTeam).startTime > g->at(i->endTeam).startTime)
            {
                crossEdges.push_back(edge);
            }
            else
            {
                forwardEdges.push_back(edge);
            }

        }
    }
    t+=1;
    g->at(u).endTime += t;
}

/*
void graphAdjList::check_con_DFS(QString u, std::map<QString, bool> &visited)
{
    visited[u] = true;
    for (int i=0; i < g[u].adjL.size(); i++)
    {
        if (!visited[g[u].adjL.at(i).first])
        {
            check_con_DFS(g[u].adjL.at(i).first, visited);
        }
    }
}
*/

void graphAdjList::DFS1(QString u)
{
    std::map<QString, bool> visited;

    for(auto i = g->begin(); i!=g->end(); i++)
        visited[i->first] = false;

    std::vector<QString> discEdges;
    std::vector<QString> backEdges;
    std::vector<QString> forwardEdges;
    std::vector<QString> crossEdges;
    DFS2(u, visited, discEdges, backEdges, forwardEdges, crossEdges);
    qDebug() << "DISCOVERY DISTANCE: " << deDist << "\n\n";
    qDebug() << "DISCOVERY EDGES:\n";
    for(auto de = discEdges.begin(); de!=discEdges.end(); de++)
    {
        qDebug() << "(" << *de << ") \n";
    }
    qDebug() << "\nBACK EDGES:\n";
    for(auto be = backEdges.begin(); be!=backEdges.end(); be++)
    {
        qDebug() << "(" << *be << ") \n";
    }
    qDebug() << "\nFORWARD EDGES:\n";
    for(auto fe = forwardEdges.begin(); fe!=forwardEdges.end(); fe++)
    {
        qDebug() << "(" << *fe << ") \n";
    }
    qDebug() << "\nCROSS EDGES:\n";
    for(auto ce = crossEdges.begin(); ce!=crossEdges.end(); ce++)
    {
        qDebug() << "(" << *ce << ") \n";
    }
}
