#include <bits/stdc++.h>
using namespace std;

int c[20000001]; // Frequency of totals

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
    int s_pos = 0;
    int s_neg = 0;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        if (arr[i] > 0)
            s_pos += arr[i];
        else
            s_neg -= arr[i];
    }

    long long ans = 0;
    int t = 0;
    c[s_neg]++;
    for (int i = 0; i < N; i++) {

        t += arr[i];

        // examine subarrays with perfect square sum
        // if subarray has sum j*j for array t then
        // total sum to this point is (s_neg +) t - j*j
        // (if indexable) add the count of this sum to number of answers
        for (int j = 0; j*j <= s_pos; j++) {
            if (s_neg + (t - j*j) >= 0)
                ans += c[s_neg + (t - j*j)];
        }

        c[s_neg + t]++; // Add one to frequency of this total
    }

    cout << ans << endl;

    memset(c, 0, sizeof(int) * (s_neg + s_pos + 1));

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
