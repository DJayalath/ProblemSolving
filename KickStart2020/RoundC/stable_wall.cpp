#include <bits/stdc++.h>

using namespace std;

set<int> adj[26];
set<char> p;
string ans;

bool vis[26];
bool stk[26]; // On DFS stack?
bool cyc = false;
void dfs(int s) {
   
    vis[s] = true;
    stk[s] = true;

    for (int u : adj[s]) {
        if (!vis[u])
            dfs(u);
        else if (stk[u]) // If visited neighbour is already on stack there is a cycle!
            cyc = true;
    }

    // No longer on stack
    stk[s] = false;

    ans += (char) (s + 'A');
}

void solve() {

    // Init
    for (char c : p)
        adj[c - 'A'].clear();
    p.clear();

    int R, C;
    cin >> R >> C;

    string wall[R];

    for (int i = 0; i < R; i++) {
        cin >> wall[i];
        for (char c : wall[i]) {
            p.insert(c);
        }
    }

    // Fill adjacency list
    for (int i = 0; i < R - 1; i++) {
        for (int j = 0; j < C; j++) {
            if (wall[i][j] != wall[i + 1][j]) {
                adj[wall[i][j] - 'A'].insert(wall[i + 1][j] - 'A');
            }
        }
    }

    // Reset variables
    memset(vis, false, sizeof(vis));
    memset(act, false, sizeof(act));
    cyc = false;
    ans.clear();

    // DAG --> Topological sort via DFS
    for (char c : p) {
        if (!vis[c - 'A'])
            dfs(c - 'A');
    }

    if (cyc)
        ans = "-1";

    cout << ans << endl;

}

int main(void) {

    int cases;
    cin >> cases;
    
    for (int i = 1; i <= cases; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}
