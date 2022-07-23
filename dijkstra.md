# Dijkstra Algorithm Edge Relaxation Problem

## Problem Statement

Using Dijkstra's algorithm, find the shortest path from A to all other vertices in this fully connected directed and weighted graph.

[Imgur](https://i.imgur.com/07A2amK.png)

During this procedure, how many times is edge relaxation done towards vertex E? In other words, on how many occasions do we compare the current distance from A to E with a new calculated distance from A to E?

A) 0
B) 1
C) 2
D) 3

## Solution

By applying Dijkstra's algorithm to the graph with A as the root, we can count the number of times edge relaxation is performed from other vertices towards vertex E. Let's step through the algorithm.

### Step 0: Initialise

We start by initialising three arrays of information to use for the algorithm:
- one to track visited vertices,
- one to track the shortest-path predecessor of each vertex,
- and one to track the shortest-path distance from A to each vertex.

All vertices start off as unvisited (0).
It is important to initialise the distance from A to A itself as 0, as we'll be using this value to calculate the shortest-path distance from A to all other vertices.
T he predecessor of A does not matter for this algorithm, so we will simply set it as A itself.

Here's our initial table of information representing the three arrays:

|             | A | B | C | D | E |
|-------------|---|---|---|---|---|
| Visited     | 0 | 0 | 0 | 0 | 0 |
| Predecessor | A | - | - | - | - |
| Distance    | 0 | ∞ | ∞ | ∞ | ∞ |

### Step 1: Visit vertex A

We now choose to visit vertex A as it is the unvisited vertex with the current shortest distance from the root (A).

To "visit" a vertex in the algorithm means to relax the edge from this vertex to each of its unvisted neighbours.

A has two unvisited neighbours, B and C.

Relaxing along A-B, we get dist(A) + edge(A, B) = 0 + 5 = 5 which is less than the previous distance to B (∞). So we update the distance to B to be 5 and its predecessor to be A.

Doing the same for A-C, we update the distance to C to be 3 and its predecessor to be A.

After that, we mark A as visited. This means we have found its shortest path distance from the root (A) and we no longer need to visit it in the future. Our table now looks like this:

|             | A | B | C | D | E |
|-------------|---|---|---|---|---|
| Visited     | 1 | 0 | 0 | 0 | 0 |
| Predecessor | A | A | A | - | - |
| Distance    | 0 | 5 | 3 | ∞ | ∞ |

### Step 2: Visit vertex C

We now choose to visit vertex C as it is the unvisited vertex with the current shortest distance from the root (A).

C has two unvisited neighbours, D and E.

Relaxing along C-D, we get dist(C) + edge(C, D) = 3 + 4 = 7 which is less than the previous distance to D (∞). So we update the distance to D to be 7 and its predecessor to be C.

Similirly, we relax along the edge C-E to get a new distance of 3 + 7 = 10 which is less than the previous distance to E (∞). So we update the distance to E to be 10 and its predecessor to be C. This makes one relaxation towards vertex E.

We now mark C as visited, and our table looks like this:

|             | A | B | C | D | E |
|-------------|---|---|---|---|---|
| Visited     | 1 | 0 | 1 | 0 | 0 |
| Predecessor | A | A | A | C | C |
| Distance    | 0 | 5 | 3 | 7 | 10 |

### Step 3: Visit vertex B

We now choose to visit vertex B as it is the unvisited vertex with the current shortest distance from the root (A).

B has one unvisited neighbour, E. Relaxing along edge B-E we get dist(B) + edge(B, E) = 5 + 1 = 6 which is less than the previous calculated distance to E (10). So we update the distance to E to be 6 and its predecessor to be B. This makes a second relaxation towards vertex E.

We now mark B as visited, and our table looks like this:

|             | A | B | C | D | E |
|-------------|---|---|---|---|---|
| Visited     | 1 | 1 | 1 | 0 | 0 |
| Predecessor | A | A | A | C | B |
| Distance    | 0 | 5 | 3 | 7 | 6 |

### Step 4: Visit vertex E

We now choose to visit vertex E as it is the unvisited vertex with the current shortest distance from the root (A). E actually has no unvisited neighbours, and no reachable neighbours at all, for that fact (no directed edge from E to any other vertex). So nothing will change and we can simply mark it as visited.

|             | A | B | C | D | E |
|-------------|---|---|---|---|---|
| Visited     | 1 | 1 | 1 | 0 | 1 |
| Predecessor | A | A | A | C | B |
| Distance    | 0 | 5 | 3 | 7 | 6 |

### Step 5: Visit vertex D

Our last step is to visit the last unvisited vertex, D.

D has a single reachable neighbour E, but at this stage, E has already been marked as visited (the shortest path from root to E has already been found) so we do not relax along the edge D-E.

We mark D as visited, and our table looks like this:

|             | A | B | C | D | E |
|-------------|---|---|---|---|---|
| Visited     | 1 | 1 | 1 | 1 | 1 |
| Predecessor | A | A | A | C | B |
| Distance    | 0 | 5 | 3 | 7 | 6 |

So now we have completed Dijkstra's algorithm on this graph with root A and we have found the shortest path from A to all other vertices.

To answer the question, we counted 2 times that edge relaxation was performed towards vertex E: steps 2 and 3.