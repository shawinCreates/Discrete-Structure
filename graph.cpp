#include <stdio.h>
#include <limits.h>

#define V 5

void displayGraph(int graph[V][V]) {
    printf("Graph Representation:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

void findShortestPath(int graph[V][V], int source) {
    int distance[V];
    int visited[V];

    for (int i = 0; i < V; i++) {
        distance[i] = INT_MAX;
        visited[i] = 0;
    }

    distance[source] = 0;

    for (int count = 0; count < V - 1; count++) {
        int minDistance = INT_MAX, currentVertex;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && distance[v] <= minDistance) {
                minDistance = distance[v];
                currentVertex = v;
            }
        }

        visited[currentVertex] = 1;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[currentVertex][v] && distance[currentVertex] != INT_MAX &&
                distance[currentVertex] + graph[currentVertex][v] < distance[v]) {
                distance[v] = distance[currentVertex] + graph[currentVertex][v];
            }
        }
    }

    printf("\nShortest Paths from Source (Vertex %d):\n", source);
    for (int i = 0; i < V; i++) {
        printf("Vertex %d: Distance = %d\n", i, distance[i]);
    }
}

void generateMST(int graph[V][V]) {
    int parent[V];
    int key[V];
    int mstSet[V];

    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int minKey = INT_MAX, currentVertex;

        for (int v = 0; v < V; v++) {
            if (!mstSet[v] && key[v] < minKey) {
                minKey = key[v];
                currentVertex = v;
            }
        }

        mstSet[currentVertex] = 1;

        for (int v = 0; v < V; v++) {
            if (graph[currentVertex][v] && !mstSet[v] && graph[currentVertex][v] < key[v]) {
                parent[v] = currentVertex;
                key[v] = graph[currentVertex][v];
            }
        }
    }

    printf("\nMinimum Spanning Tree (Prim's Algorithm):\n");
    for (int i = 1; i < V; i++) {
        printf("Edge %d - %d\n", parent[i], i);
    }
}

int main() {
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    displayGraph(graph);

    findShortestPath(graph, 0);

    generateMST(graph);

    return 0;
}
  
