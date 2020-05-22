#include <bits/stdc++.h>
using namespace std;

#define MAX 100
#define MAX_HEIGHT 100

int a[MAX + 2];
int N;

void solve() {

    cin >> N;
    memset(a, 0, sizeof(int) * (N + 2));

    a[0] = MAX_HEIGHT;
    a[N + 1] = MAX_HEIGHT;

    for (int i = 1; i < N + 1; i++)
        cin >> a[i];

    int ans = 0;
    for (int i = 1; i < N + 1; i++) {
        if (a[i] > a[i - 1] && a[i] > a[i + 1])
            ans++;
    }

    cout << ans << endl;
}

int main(void) {

    int c;
    cin >> c;

    for (int i = 1; i <= c; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }

}
