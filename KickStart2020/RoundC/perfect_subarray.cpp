#include <bits/stdc++.h>
using namespace std;

int f[20000001];

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

    f[s_neg]++;
    int t = 0;
    for (int i = 0; i < N; i++) {
            
        t += arr[i];

        for (int j = 0; j*j <= s_pos; j++) {
            
            // t - j*j is cumulative total up to start of perfect
            // square subarray of sum j*j if it exists
            if (s_neg + t - j*j >= 0) // Check indexable
                ans += f[s_neg + t - j*j]; // Add frequency of this sum

        }

        // Added here so that longer partial array totals aren't
        // counted accidentally at this point in the search
        f[s_neg + t]++; // Increment count of this total

    }

    cout << ans << endl;

    memset(f, 0, sizeof(int) * (s_neg + s_pos + 1));

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
