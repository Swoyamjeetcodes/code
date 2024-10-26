#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define INF 99999

typedef struct {
    int u, v, weight;
} Edge;

typedef struct {
    int parent[MAX];
    int rank[MAX];
} DisjointSet;

Edge edges[MAX];
int numEdges, numVertices;

// Function to compare edges (used for sorting)
int compareEdges(const void *a, const void *b) {
    return ((Edge *)a)->weight - ((Edge *)b)->weight;
}

// Disjoint Set Functions
void initializeDisjointSet(DisjointSet *ds, int n) {
    for (int i = 0; i < n; i++) {
        ds->parent[i] = i;
        ds->rank[i] = 0;
    }
}

int find(DisjointSet *ds, int v) {
    if (ds->parent[v] != v) {
        ds->parent[v] = find(ds, ds->parent[v]); // Path compression
    }
    return ds->parent[v];
}

void unionSets(DisjointSet *ds, int u, int v) {
    int rootU = find(ds, u);
    int rootV = find(ds, v);
    
    if (rootU != rootV) {
        // Union by rank
        if (ds->rank[rootU] > ds->rank[rootV]) {
            ds->parent[rootV] = rootU;
        } else if (ds->rank[rootU] < ds->rank[rootV]) {
            ds->parent[rootU] = rootV;
        } else {
            ds->parent[rootV] = rootU;
            ds->rank[rootU]++;
        }
    }
}

// Function to implement Kruskal's Algorithm
void kruskal() {
    DisjointSet ds;
    initializeDisjointSet(&ds, numVertices);
    
    qsort(edges, numEdges, sizeof(edges[0]), compareEdges);

    printf("Edges in the Minimum Spanning Tree:\n");
    for (int i = 0; i < numEdges; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int weight = edges[i].weight;

        if (find(&ds, u) != find(&ds, v)) {
            printf("%d -- %d == %d\n", u, v, weight);
            unionSets(&ds, u, v);
        }
    }
}

int main() {
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &numVertices, &numEdges);

    printf("Enter each edge (u, v, weight):\n");
    for (int i = 0; i < numEdges; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }

    kruskal();
    return 0;
}