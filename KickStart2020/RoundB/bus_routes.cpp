#include <bits/stdc++.h>
using namespace std;

#define MAX 1000
#define ull unsigned long long int

int N;
ull D;

ull a[MAX];

void solve() {

    cin >> N >> D;

    for (int i = 0; i < N; i++)
        cin >> a[i];

    ull num = D;
    for (int i = N - 1; i >= 0; i--) {
        ull mul = num / a[i];
        num = mul * a[i];
    }

    cout << num << endl;

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
