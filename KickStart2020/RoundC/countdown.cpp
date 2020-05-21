#include <bits/stdc++.h>
using namespace std;

void solve() {

    int N, K;
    cin >> N >> K;

    int arr[N];
    int o[N]; // Indexes of ones in array
    int c = 0; // Count of ones in array

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        if (arr[i] == 1) {
            o[c] = i;
            c++; // increment counter
        }
    }

    int ans = 0;
    for (int i = 0; i < c; i++) {
        int j = 1;
        bool ok = true;
        while (o[i] - j >= 0 && ok) {
            if (arr[o[i] - j] != j + 1)
                ok = false;
            else if (arr[o[i] - j] == K) {
                ans++;
                ok = false;
            }
            j++;
        }
    }

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
