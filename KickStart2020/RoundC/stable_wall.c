#include <stdio.h>
#include <stdlib.h>

int R, C;

void visit(int node, int marks[], int N, int adj[N][N], int* L) {
    if (marks[node] == 2)
        return;
    else if (marks[node] == 1) {
        return;
    }

    marks[node] = 1;

    for (int i = 0; i < N; i++) {
        if (adj[node][i] > 0) {
            visit(i, marks, N, adj, L);
        }
    }

    marks[node] = 2;
    *L = node;
    L++;
}

void dfs(int* L, int N, int adj[N][N]) {

    // Temp mark = 1, Perm mark = 2
    int marks[N];
    for (int i = 0; i < N; i++)
        marks[i] = 0;

    int unmarked = 1;
    while (unmarked) {

        // Select unmarked node
        int pos = 0;
        while (pos < N) {
            if (marks[pos] == 0)
                pos += N;
            pos++;
        }
        
        //printf("Visting");
        visit(pos - N - 1, marks, N, adj, L);

        // Check for permanent marks
        unmarked = 0;
        for (int i = 0; i < N; i++) {
            if (marks[i] < 2)
                unmarked = 1;
                
        }
    }

}

void solve() {

    scanf("%i %i", &R, &C);

    int wall[R][C];
    int map[26];
    for (int i = 0; i < 26; i++)
        map[i] = -1;

    // Fill wall
    int idx = 0;
    for (int i = 0; i < R; i ++) {
        for (int j = 0; j < C; j++) {

            char c;
            scanf("%c", &c);
            wall[i][j] = (int) c - 65; // Convert from ASCII

            // Assign mapping
            if (map[wall[i][j]] == -1) {
                map[wall[i][j]] = idx;
                idx++;
            }

        }
    }

    // Adjacency matrix initialised to zero
    int adj[idx][idx];
    for (int i = 0; i < idx; i++)
        for (int j = 0; j < idx; j++)
            adj[i][j] = 0;

    
    // Fill dependencies
    for (int i = 0; i < R - 1; i++) {
        for (int j = 0; j < C; j++) {
            if (wall[i][j] != wall[i + 1][j]) {
                adj[map[wall[i][j]]][map[wall[i + 1][j]]] = 1;
            }
        }
    }

    // Check if grounded
    int grounded = 0;
    for (int i = 0; i < idx; i++) {
        int dependent = 0;
        for (int j = 0; j < idx; j++) {
            dependent += adj[i][j];
        }
        if (dependent == 0)
            grounded = 1;
    }

    if (grounded == 0) {
        printf("-1\n");
        return;
    }

    int L[idx];
    dfs(L, idx, adj);

    for (int i = idx - 1; i >= 0; i--) {
        printf("%i + ", L[i]);
    }
    printf("\n");

}

int main(void) {

    int cases;
    scanf("%i", &cases);

    for (int i = 1; i <= cases; i++) {
        printf("Case #%i: ", i);
        solve();
    }

    return 0;
}
