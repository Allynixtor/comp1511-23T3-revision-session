
#include <stdlib.h>
#include <stdio.h>

#include "other_files.h"

bool functionTheyNeedToImplement(Graph g);

int main(void) {
    // Add anything you want to read in before reading in the graph here.
    // ...

    Graph g = buildGraph();

    // Add anything you want to read in after reading in the graph here.
    // ...

    // Call the function they have to implement.
    // If it returns something, capture that return value.
    bool hasCycle = functionTheyNeedToImplement(g);

    // Print the return value from the function if there is one.
    // The stdout output of this program will be used by autotest.
    if (hasCycle) {
		printf("Has cycle\n");
	} else {
		printf("Does not have cycle\n");
	}

    // Do any cleanup needed here.
    freeGraph(g);
    
    return EXIT_SUCCESS;
}