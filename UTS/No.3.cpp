#include <iostream>
#include <string>
using namespace std;

int n = 5; 

void dfs(int v, int** adj, bool* visited, int* order, int &idx) {
    visited[v] = true;
    order[idx++] = v;
    for (int u = 0; u < n; u++) {
        if (adj[v][u] != 0 && !visited[u]) {
            dfs(u, adj, visited, order, idx);
        }
    }
}

int main() {
    int** adj = new int*[n];
    for (int i = 0; i < n; i++) {
        adj[i] = new int[n];
        for (int j = 0; j < n; j++) adj[i][j] = 0;
    }
    // edges
    adj[0][1] = adj[1][0] = 5; // A-B
    adj[0][2] = adj[2][0] = 2; // A-C
    adj[1][3] = adj[3][1] = 4; // B-D
    adj[2][3] = adj[3][2] = 1; // C-D
    adj[3][4] = adj[4][3] = 3; // D-E

    string label[5] = {
        "Ikan Bakar Pak Harry (A)",
        "Gudang Kaleng Bekas (B)", 
        "Sushi Kucing Alya (C)",
        "Kedai IKLC (D)",
        "Pasar Ikan Tengah Malam (E)"
    };

    // DFS 
    bool* visited = new bool[n];
    for (int i = 0; i < n; i++) visited[i] = false;
    int* order = new int[n];
    int idx = 0;
    dfs(0, adj, visited, order, idx);

    cout << "PENJELAJAHAN PARUL (DFS dari A):\n";
    for (int i = 0; i < idx; i++) {
        cout << char('A' + order[i]);
        if (i != idx - 1) cout << " -> ";
    }
    cout << "\n\n";

    // BFS 
    int* q = new int[n];
    int head = 0, tail = 0;
    for (int i = 0; i < n; i++) visited[i] = false;
    int* parent = new int[n];
    for (int i = 0; i < n; i++) parent[i] = -1;

    // enqueue 0
    q[tail++] = 0;
    visited[0] = true;
    bool found = false;
    while (head < tail) {
        int v = q[head++];
        if (v == 4) { found = true; break; }
        for (int u = 0; u < n; u++) {
            if (adj[v][u] != 0 && !visited[u]) {
                visited[u] = true;
                parent[u] = v;
                q[tail++] = u;
            }
        }
    }

    // reconstruct
    int target = 4;
    int* path = new int[n];
    int plen = 0;
    if (found || parent[target] != -1) {
        int cur = target;
        while (cur != -1) {
            path[plen++] = cur;
            cur = parent[cur];
        }
        // reverse
        for (int i = 0; i < plen / 2; i++) {
            int tmp = path[i];
            path[i] = path[plen - 1 - i];
            path[plen - 1 - i] = tmp;
        }
    }

    cout << "JALUR TERCEPAT PARUL (BFS):\n";
    if (plen == 0) {
        cout << "Tidak ada jalur dari A ke E\n";
    } else {
        // print node 
        for (int i = 0; i < plen; i++) {
            cout << label[path[i]] << "\n";
            if (i < plen - 1) {
                cout << adj[path[i]][path[i+1]] << "m\n";
            }
        }
        cout << "\nJalur terpendek: ";
        for (int i = 0; i < plen; i++) {
            cout << char('A' + path[i]);
            if (i != plen - 1) cout << " -> ";
        }
        int totalEdges = plen - 1;
        int totalDist = 0;
        for (int i = 0; i < plen - 1; i++) totalDist += adj[path[i]][path[i+1]];

        cout << "\nTotal langkah: " << totalEdges << " edge\n";
        cout << "Total jarak: " << totalDist << " meter\n";
    }

    // cleanup
    delete[] path;
    delete[] q;
    delete[] order;
    delete[] parent;
    delete[] visited;
    for (int i = 0; i < n; i++) delete[] adj[i];
    delete[] adj;

    return 0;
}