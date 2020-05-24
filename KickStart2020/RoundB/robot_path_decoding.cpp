#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long int
#define ll long long int

ll MAX = 1000000000;
ll w;
ll h;

string prog;
vector<ll> rstk; // Repetition stack

void solve() {
    
    w = 0;
    h = 0;

    cin >> prog;

    for (char c : prog) {
        if (c >= '2' && c <= '9') {
            ll r = c - '0';
            rstk.push_back(rstk.back() * R % MAX);
        }
        else if (c == ')') {
            rstk.pop_back();
        }
        else if (c != '(') {
            if (c == 'N')
                h = ((h - rstk.back()) % MAX + MAX) % MAX;
            else if (c == 'S')
                h = (h + rstk.back()) % MAX;
            else if (c == 'W')
                w = ((w - rstk.back()) % MAX + MAX) % MAX;
            else if (c == 'E')
                w = (w + rstk.back()) % MAX;
        }
    }

    cout << ++w << " " << ++h << endl;

}

int main(void) {

    int c;
    cin >> c;

    rstk.push_back(1);

    for (int i = 1; i <= c; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}
