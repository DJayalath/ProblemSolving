#include <bits/stdc++.h>
using namespace std;

bool p_square(int n) {
    if (n < 0)
        return false;
    int isqrt = round(sqrt(n));
    return n == isqrt * isqrt;
}

void solve() {

    int N;
    cin >> N;

    int arr[N];

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    int ans = 0;

    // Loop over subarrays
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            int sum = 0;
            for (int k = i; k <= j; k++) {
                sum += arr[k];
            }
            if (p_square(sum))
                ans++;
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
