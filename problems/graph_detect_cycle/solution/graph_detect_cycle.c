
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"

// Declare any helper functions you need here.
bool stackHasNode(int stack[], int stackSize, int node);

/**
 * Determines whether the given graph has a cycle.
 * 
 * Input:
 *   - Graph g: An unweighted, undirected, connected graph
 *      represented using an adjacency matrix. Has at least one vertex.
 * Output:
 *   - bool: true if the graph has a cycle, false otherwise.
 */
bool graphDetectCycle(Graph g) {
    bool hasCycle = false;
    // declare visited array
    bool visited[MAX_NUM_VERTICES] = {};
    // declare stack and initialise with first node
    int toVisitStack[4*MAX_NUM_VERTICES] = {};
    toVisitStack[0] = 0;
    int stackTop = 1;
    // while stack is not empty:
    while (!hasCycle && stackTop > 0) {
        int node = toVisitStack[--stackTop];
        // printf("\nVisiting node %d\n", node);
        if (!visited[node]) {
            // mark node as visited
            visited[node] = true;
            // for each neighbour of node:
            for (int otherNode = 0; otherNode < numVertices(g); otherNode++) {
                if (otherNode == node || !adjacent(g, node, otherNode)) {
                    continue;
                }

                // printf("Checking %d's neighbour %d\n", node, otherNode);
                if (!visited[otherNode]) {
                    if (stackHasNode(toVisitStack, stackTop, otherNode)) {
                        // If we plan to visit a node that we already planned
                        // to visit from a different node, we have a cycle.
                        // printf("Planning to visit %d which we already planned to visit from a different node. Has cycle.\n", otherNode);
                        hasCycle = true;
                        break;
                    } else {
                        // Neighbour has not been visited yet and there is
                        // presently no plan to visit it - make a plan
                        // to visit it.
                        // printf("Plan to visit %d\n", otherNode);
                        toVisitStack[stackTop++] = otherNode;

                    }
                }
            }
        }
    }
    return hasCycle;
}

bool stackHasNode(int stack[], int stackSize, int node) {
    for (int i = 0; i < stackSize; i++) {
        if (stack[i] == node) {
            return true;
        }
    }
    return false;
}