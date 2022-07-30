# Graph Cycle Detection

Given an undirected, unweighted graph with at least one edge, write a function that returns true if the graph contains a cycle, and false otherwise.




 * Build an undirected unweighted graph with at least one edge
 * from stdin.
 * First line: n the number of vertices in your graph
 * Following lines: each line contains the two vertices connected
 * by an edge. Vertices are numbered 0 to n-1 inclusive.
 *
 * Usage:
    $ dcc test_graph_detect_cycle.c graph_detect_cycle.c Graph.c -o test_graph_detect_cycle
    $ ./test_graph_detect_cycle

Ctrl + D to end input.


### Sample 1

Input:

```bash
3
0 <-> 1
1 <-> 2

```

Output:

```bash
false
```

Explanation: The graph `0 <-> 1 <-> 2` does not contain any cycles.
    