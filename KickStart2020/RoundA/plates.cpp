#include <bits/stdc++.h>
using namespace std;

void solve() {

    int N, K, P;
    cin >> N >> K >> P;

    // Set sum array to zero
    int s[N + 1][K + 1];
    for (int i = 0; i < N + 1; i++)
        for (int j = 0; j < K + 1; j++)
            s[i][j] = 0;


    for (int i = 1; i < N + 1; i++) {
        for (int j = 1; j < K + 1; j++) {
            int x;
            cin >> x;
            s[i][j] += s[i][j - 1] + x;
        }
    }

   
    // dp[i][j] is max of picking j plates from first i stacks
    // Inductive method
    int dp[N + 1][P + 1];
    for (int i = 0; i < N + 1; i++)
        for(int j = 0; j < P + 1; j++)
            dp[i][j] = 0;

    for (int i = 1; i < N + 1; i++) {
        for (int j = 0; j <= P; j++) {
            dp[i][j] = 0;
            for (int x = 0; x <= min(j, K); x++) {
                dp[i][j] = max(dp[i][j], s[i][x] + dp[i - 1][j - x]);
            }
        }
    }

    cout << dp[N][P] << endl;
    


}

int main(void) {

    int c;
    cin >> c;

    for (int i = 1; i <= c; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }

}
