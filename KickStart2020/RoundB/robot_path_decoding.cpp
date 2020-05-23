#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long int
#define MAX 1000000000

ull w;
ull h;

string prog;


void exec(string p, int repeats) {
    
    int rep;
    bool bra = false;
    int bal = 0;
    string s = "";
    //cout << p << endl;
    
    ull offset_w = 0;
    ull offset_h = 0;

    for (char c : p) {
        if (!bra && c >= '2' && c <= '9')
            rep = c - '0';
        else if (c == '(' && !bra) {
            bra = true;
        } else if (c == '(' && bra) {
            s += c;
            bal += 1;
        } else if (c == ')' && bra) {
            if (bal == 0) {
                exec(s, rep);
                bra = false;
                bal = 0;
                s.clear();
            } else {
                s += c;
                bal -= 1;
            }
        } else if (!bra) {
            //cout << c;
            if (c == 'N') {
                offset_h -= 1;
            } else if (c == 'S') {
                offset_h += 1;
            } else if (c == 'W') {
                offset_w -= 1;
            } else if (c == 'E') {
                offset_w += 1;
            }
        } else {
            s += c;
        }
    }

    h += repeats * offset_h;
    w += repeats * offset_w;

    if (h > MAX)
        h = h - MAX;
    else if (h < 1)
        h = MAX - h;

    if (w > MAX)
        w = w - MAX;
    else if (w < 1)
        w = MAX - w;

}

void solve() {
    
    w = 1;
    h = 1;

    cin >> prog;

    exec(prog, 1);

    cout << w << " " << h << endl;

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
