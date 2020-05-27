#include <bits/stdc++.h>
using namespace std;

void solve() {

    int N, K;
    cin >> N >> K;

    int a[N];
    for (int i = 0; i < N; i++)
        cin >> a[i];

    int d[N - 1];
    for (int i = 0; i < N - 1; i++)
        d[i] = a[i + 1] - a[i];

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
