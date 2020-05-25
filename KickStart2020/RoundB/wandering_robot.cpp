#include <bits/stdc++.h>
using namespace std;

#define ld long double

int W, H, L, U, R, D;

ld log2fact(int n) {
    if (n == 0)
        return log2((ld) 1.0);
    ld t = 0.0;
    for (int i = 1; i <= n; i++)
        t += log2((ld) i);
    return t;
}

ld log2c(int n, int k) {
    return log2fact(n) - log2fact(k) - log2fact(n - k);
}

ld log2path(int S, int E) {
    return log2c(S + E, S) - S - E;
}

void solve() {

    cin >> W >> H >> L >> U >> R >> D;

    int n = D;
    int m = L;

    // Examine bottom left
    ld p = 0.0;
    while (m - 1 >= 1 && n + 1 <= H) {
        
        p += pow(2, log2path(m - 2, n));

        n++;
        m--;
    }

    // Examine top right
    n = U;
    m = R;

    while (n - 1 >= 1 && m + 1 <= W) {

        p += pow(2, log2path(n - 2, m));

        n--;
        m++;
    }

    cout << setprecision(9) << p << endl;

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
