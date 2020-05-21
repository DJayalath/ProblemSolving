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
    int t = 0;
    int c[N];
    int s_pos = 0;
    int s_neg = 0;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        t += arr[i];
        c[i] = t;
        if (arr[i] > 0)
            s_pos += arr[i];
        else
            s_neg -= arr[i];
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        bool good = true;
        for (int j = 0; j < N - i && good; j++) {
            int sum = c[i + j];
            if (i > 0)
                sum -= c[i - 1];
            if (sum > s_pos)
                good = false;
            else if (p_square(sum)) {
                ans++;
            }
        }
    }


    // Loop over subarrays
   // for (int i = 0; i < N; i++) {
   //     for (int j = i; j < N; j++) {
   //         int sum = 0;
   //         for (int k = i; k <= j; k++) {
   //             sum += arr[k];
   //         }
   //         if (p_square(sum))
   //             ans++;
   //     }
   // }
    


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
