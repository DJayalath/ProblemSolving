#include <bits/stdc++.h>
using namespace std;

bool p_square(int n) {
    if (n < 0)
        return false;
    int isqrt = round(sqrt(n));
    return n == root * root;
}

void solve() {

    int N;
    cin >> N;

    int arr[N];

    for (int i = 0; i < N; i++)
        cin >> arr[N];

    int p_N = pow(2, N); // Size of powerset

    int ans = 0;
    
    // Loop over powerset
    int c; // Binary counter
    for (c = 0; c < p_N; c++) {

        int sum = 0;
        for (int i = 0; i < N; i++) {

            // If ith bit is set, ith element is part of subset
            if (c & (1 << i)) {
                sum += arr[i];
            }

        }

        if (p_square(sum))
            ans++;

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
