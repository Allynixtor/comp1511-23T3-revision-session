# Kruskal's Algorithm Minimal Spanning Tree

## Problem Statement

Using Kruskal's algorithm, find the minimum spanning tree of this fully connected and weighted graph.

[Imgur](https://i.imgur.com/78SHIrs.png)

During this procedure, how many times do you encounter a cycle before you find the MST?

A) 0
B) 1
C) 2
D) 3

## Solution

The Kruskal's algorithm is a greedy algorithm that finds the minimum spanning tree of a graph. It works by choosing edges in sorted order by lowest weight (unless it forms a cycle) until all vertices are included.

Let's walk through applying Kruskal's algorithm to the graph.

We start with an empty set of edges which represents the MST we want to build. We also keep a count of the number of vertices that have been included in the MST so we can stop when we have included all vertices.

We sort the existing edges in the graph by weight and start to choose them by lowest weight edge to add to the MST.

We choose the first edge E-G with weight 1 and add it to our MST. We then check that our new MST does not form a cycle after this addition and keep the edge.

[Imgur](https://i.imgur.com/tQxZSzH.png)

Next add the edge G-F with weight 2 to our MST. We check that it does not form a cycle and keep the edge.

[Imgur](https://i.imgur.com/1DgtJGV.png)

Next add the edge A-C with weight 3 to our MST. We check that it does not form a cycle and keep the edge.

[Imgur](https://i.imgur.com/pWk6eb2.png)

Next add the edge E-F with weight 4 to our MST. We find that after this addtion our MST now has a cycle, so we remove the edge.

[Imgur](https://i.imgur.com/te21CM1.png)

Next add the edge E-D with weight 5 to our MST. We check that it does not form a cycle and keep the edge.

[Imgur](https://i.imgur.com/ruMBsMN.png)

Next we find two edges with the same weigth 6: A-D and F-D. We can choose these edges to add to the MST in arbitrary order since it would not make a difference to the minimum weight of our MST.

We'll add the edge A-D first. We check that it does not form a cycle and keep the edge.

[Imgur](https://i.imgur.com/mED0IRd.png)

Next we add the edge F-D; the remaining edge with weigth 6. We find that after this addtion our MST now has a cycle, so we remove the edge.

[Imgur](https://i.imgur.com/zNM0uo2.png)

Next add the edge C-F with weight 7 to our MST. We find that after this addtion our MST now has a cycle, so we remove the edge.

[Imgur](https://i.imgur.com/Zk0qOEl.png)

Next we add the edge A-B with weight 8 to our MST. We check that it does not form a cycle and keep the edge.

[Imgur](https://i.imgur.com/KSTqyfQ.png)

At this point our MST contains all the vertices from the original graph, and hence we have found the minimum spanning tree.

To answer the question, there were three instances where we added an edge and found that it formed a cycle in our MST.