#include <bits/stdc++.h>
using namespace std;

int W, H, L, U, R, D;

int fact(int n) {
    int t = 1;
    for (int i = 1; i <= n; i++)
        t *= i;
    return t;
}

double log2c(int n, int k) {
    return log2(fact(n)) - log2(fact(k)) - log2(fact(n - k));
}

double log2path(int S, int E) {
    return log2c(S + E, S) - S - E;
}

void solve() {

    cin >> W >> H >> L >> U >> R >> D;

    int n = D;
    int m = L;

    // Examine bottom left
    vector<double> p;
    while (m - 1 >= 1 && n + 1 <= H) {
        
        p.push_back(log2path(n, m - 2));

        n++;
        m--;
    }

    // Examine top right
    n = U;
    m = R;

    while (n - 1 >= 1 && m <= R) {

        p.push_back(log2path(n - 2, m));

        n--;
        m++;
    }

    double t = 0;
    for (double x : p) {
        t += pow(2, x);
    }


    cout << t << endl;

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
