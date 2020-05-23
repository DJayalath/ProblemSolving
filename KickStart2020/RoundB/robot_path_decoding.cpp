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
    
    w = 1;
    h = 1;

    cin >> prog;

    for (char c : prog) {
        if (c >= '2' && c <= '9') {
            ll r = c - '0';
            rstk.push_back(r * rstk.back());
        }
        else if (c == ')') {
            rstk.pop_back();
        }
        else if (c != '(') {
            if (c == 'N')
                h -= rstk.back();
            else if (c == 'S')
                h += rstk.back();
            else if (c == 'W')
                w -= rstk.back();
            else if (c == 'E')
                w += rstk.back();
        }
    }

    if (h > MAX)
        h = h - MAX;
    else if (h < 1)
        h = MAX + h;

    if (w > MAX)
        w = w - MAX;
    else if (w < 1)
        w = MAX + w;

    cout << w << " " << h << endl;

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
