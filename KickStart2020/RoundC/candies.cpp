#include <bits/stdc++.h>
using namespace std;

#define MAX 200000

// Cumulative sums
int f0[MAX]; // +A0 -A1 +A2 -A3 ...
int f0_m[MAX]; // +0 * A0 -1 * A1 +2 * A2 ...

int f1[MAX]; // -A0 +A1 -A2 +A3 ...
int f1_m[MAX]; // -0 * A0 +1 * A1 -2 * A2 ...

void reset(int N) {
    memset(f0, 0, 4 * N);
    memset(f0_m, 0, 4 * N);
    memset(f1, 0, 4 * N);
    memset(f1_m, 0, 4 * N);
}

void solve() {
    
    int N, Q;
    cin >> N >> Q;

    reset(N);

    int arr[N];
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    for (int i = 0; i < N; i++) {

        cin >> arr[i];

        if (i & 1) {
            a += -arr[i];
            b += -i * arr[i];
            c += arr[i];
            d += i * arr[i];
        } else {
            a += arr[i];
            b += i * arr[i];
            c += -arr[i];
            d += -i * arr[i];
        }

        f0[i] = a;
        f0_m[i] = b;
        f1[i] = c;
        f1_m[i] = d;

    }
   
    long long swt = 0;
    
    char op;
    int x, y;
    for (int i = 0; i < Q; i++) {
        
        cin >> op >> x >> y;

        // Index correction
        x--;
        y--;
        
        if (op == 'Q') { // Query

            if (x & 1) {
                int u = 0;
                int v = 0;
                if (x - 1 >= 0) {
                    u = f1_m[x - 1];
                    v = f1[x - 1];
                }
                swt += (f1_m[y] - u) - (x - 1) * (f1[y] - v); // CHECK BELOW ZERO
            } else {
                int u = 0;
                int v = 0;
                if (x - 1 >= 0) {
                    u = f0_m[x - 1];
                    v = f0[x - 1];
                }
                swt += (f0_m[y] - u) - (x - 1) * (f0[y] - v);
            }
        
        } else { // Update
           
            y++;
            arr[x] = y;

            if (x - 1 >= 0) {
                a = f0[x - 1];
                b = f0_m[x - 1];
                c = f1[x - 1];
                d = f1_m[x - 1];
            } else {
                a = 0;
                b = 0;
                c = 0;
                d = 0;
            }
            for (int i = x; i < N; i++) {
               
                if (i & 1) {
                    a += -arr[i];
                    b += -i * arr[i];
                    c += arr[i];
                    d += i * arr[i];
                } else {
                    a += arr[i];
                    b += i * arr[i];
                    c += -arr[i];
                    d += -i * arr[i];
                }

                f0[i] = a;
                f0_m[i] = b;
                f1[i] = c;
                f1_m[i] = d;

            }
            
        }
        
    }

    cout << swt << endl;
    
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
