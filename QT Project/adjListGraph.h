/**************************
* Faris Hijazi
* CS1D
* Assignment 9
**************************/

#ifndef ADJLISTGRAPH_H
#define ADJLISTGRAPH_H

#include "team.h"
#include <QDebug>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <algorithm>

struct vertex{
    std::vector<Edge> adjL;
    QString vertex;
    int startTime = 0;
    int endTime = 0;
};

struct comparator{
  bool operator() (Edge i, Edge j)
  { return (i.distance < j.distance);}
};

class graphAdjList
{
    public:
        graphAdjList();

        ~graphAdjList();

        graphAdjList(std::map<QString, vertex> *newG);
        void addEdge( QString v1, QString v2, int distance );
        void DFS1(QString u);
        void checkConnection();
        void printGraph();
        void sortByDist();
        
    
    private:
        void addTeamEdges();

        void check_con_DFS(int u, std::vector<bool> &visited);
        void DFS2(QString u, std::map<QString, bool> &visited,
                  std::vector<QString>& discEdges, std::vector<QString>& backEdges,
                  std::vector<QString>& forwardEdges, std::vector<QString>& crossEdges);
        //int numVerts = 0;
        //int numEdges = 0;
        int deDist = 0;
        //int beDist = 0;
        int t = 0;
        int listSize;
        std::map<QString, vertex> *g;
};

#endif
