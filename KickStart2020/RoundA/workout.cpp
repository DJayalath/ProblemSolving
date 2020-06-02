#include <bits/stdc++.h>
using namespace std;

int ksum(int N, int d[], int d_opt) {

    int s = 0;
    for (int i = 0; i < N - 1; i++) {
        s += ceil((double) d[i] / (double) d_opt) - 1;
    }
    return s;

}

void solve() {

    int N, K;
    cin >> N >> K;

    int a[N];
    for (int i = 0; i < N; i++)
        cin >> a[i];

    int d[N - 1];
    int d_max = 0;
    for (int i = 0; i < N - 1; i++) {
        d[i] = a[i + 1] - a[i];
        if (d[i] > d_max)
            d_max = d[i];
    }

    // Perform binary search
    int mx = d_max;
    int mn = 1;
    int d_opt = (mx + mn) / 2;
    while (true) {

        if (ksum(N, d, d_opt) <= K) {
            mx = d_opt;
        } else {
            mn = d_opt + 1;
        }

        if (mx == mn)
            break;

        d_opt = (mx + mn) / 2;
    }

    cout << mx << endl;

}

int main(void) {

    int c;
    cin >> c;

    for (int i = 1; i <= c; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}
