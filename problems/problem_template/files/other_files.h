// Header file for your problem

#ifndef PROBLEM_TEMPLATE
#define PROBLEM_TEMPLATE

#include <stdbool.h>

// Constants

#define MAX_NUM_VERTICES 1024


// Structures and typedefs
typedef struct graph *Graph;
struct graph {
    bool **_adjMatrix;
    int    _nV;
};


/** All vertices in the graph are nonnegative integers. */
typedef unsigned int Vertex;


// Functions

Graph buildGraph(void);
void  freeGraph(Graph g);

int   numVertices(Graph g);
bool  adjacent(Graph g, Vertex u, Vertex v);

#endif