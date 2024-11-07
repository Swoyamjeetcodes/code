#include <stdio.h>
#include <stdlib.h>

#define MAX_EDGES 100

// Edge structure
typedef struct {
    int u, v, weight;
} Edge;

// Disjoint Set Union-Find functions
int find(int parent[], int i) {
    if (parent[i] == i)
        return i;
    return find(parent, parent[i]);
}

void unionSets(int parent[], int rank[], int x, int y) {
    int xRoot = find(parent, x);
    int yRoot = find(parent, y);

    if (rank[xRoot] < rank[yRoot]) {
        parent[xRoot] = yRoot;
    } else if (rank[xRoot] > rank[yRoot]) {
        parent[yRoot] = xRoot;
    } else {
        parent[yRoot] = xRoot;
        rank[xRoot]++;
    }
}

// Comparison function for sorting edges based on their weight
int compareEdges(const void *a, const void *b) {
    Edge *edge1 = (Edge *)a;
    Edge *edge2 = (Edge *)b;
    return edge1->weight - edge2->weight;
}

// Kruskal's algorithm to find the Minimum Spanning Tree
void kruskalMST(Edge edges[], int n, int m) {
    Edge result[MAX_EDGES]; // Array to store the resultant MST
    int parent[n + 1]; // Disjoint set (Union-Find) for node grouping
    int rank[n + 1];   // Rank array for Union by Rank
    int e = 0, i = 0, totalWeight = 0;

    // Initialize disjoint sets
    for (int v = 1; v <= n; v++) {
        parent[v] = v;
        rank[v] = 0;
    }

    // Sort edges by their weight
    qsort(edges, m, sizeof(Edge), compareEdges);

    // Iterate through sorted edges and pick the smallest, non-cyclic edge
    while (e < n - 1 && i < m) {
        Edge nextEdge = edges[i++];

        int uSet = find(parent, nextEdge.u);
        int vSet = find(parent, nextEdge.v);

        if (uSet != vSet) {
            result[e++] = nextEdge;
            totalWeight += nextEdge.weight;
            unionSets(parent, rank, uSet, vSet);
        }
    }

    // Print the selected edges and total cost
    printf("Selected edges and their weights in MST:\n");
    for (i = 0; i < e; i++) {
        printf("%d -- %d == %d\n", result[i].u, result[i].v, result[i].weight);
    }
    printf("Total cost of the Minimum Spanning Tree: %d\n", totalWeight);
}

int main() {
    int n, m;

    printf("Enter the number of nodes and edges: ");
    scanf("%d %d", &n, &m);

    Edge edges[MAX_EDGES];
    
    printf("Enter each edge (node1 node2 weight):\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }

    kruskalMST(edges, n, m);

    return 0;
}
