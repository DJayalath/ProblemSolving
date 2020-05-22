#include <bits/stdc++.h>
using namespace std;

#define MAX 200001

// Cumulative sums
int f0[MAX]; // +A0 -A1 +A2 -A3 ...
int f0_m[MAX]; // +0 * A0 -1 * A1 +2 * A2 ...

int f1[MAX]; // -A0 +A1 -A2 +A3 ...
int f1_m[MAX]; // -0 * A0 +1 * A1 -2 * A2 ...

void reset(int N) {
    memset(f0, 0, sizeof(int) * (N + 1));
    memset(f0_m, 0, sizeof(int) * (N + 1));
    memset(f1, 0, sizeof(int) * (N + 1));
    memset(f1_m, 0, sizeof(int) * (N + 1));
}

void solve() {
    
    int N, Q;
    cin >> N >> Q;

    reset(N);

    int arr[N + 1];
    arr[0] = 0;

    for (int i = 1; i < N + 1; i++) {

        int a;
        cin >> a;
        arr[i] = a;

        if (i & 1) {
            f0[i] = f0[i - 1] + a;
            f0_m[i] = f0_m[i - 1] + i * a;

            f1[i] = f1[i - 1] - a;
            f1_m[i] = f1_m[i - 1] - i * a;
        } else {
            f0[i] = f0[i - 1] - a;
            f0_m[i] = f0_m[i - 1] - i * a;

            f1[i] = f1[i - 1] + a;
            f1_m[i] = f1_m[i - 1] + i * a;
        }

    }
   
    long long swt = 0;
    
    char op;
    int x, y;
    for (int k = 0; k < Q; k++) {
        
        cin >> op >> x >> y;
  
        if (op == 'Q') { // Query

            if (x & 1) {
                swt += (f0_m[y] - f0_m[x - 1]) - (x - 1) * (f0[y] - f0[x - 1]);
            } else {
                swt += (f1_m[y] - f1_m[x - 1]) - (x - 1) * (f1[y] - f1[x - 1]);            
            }
        
        } else { // Update
           
            arr[x] = y;

            for (int i = x; i < N + 1; i++) {

                if (i & 1) {
                    f0[i] = f0[i - 1] + arr[i];
                    f0_m[i] = f0_m[i - 1] + i * arr[i];

                    f1[i] = f1[i - 1] - arr[i];
                    f1_m[i] = f1_m[i - 1] - i * arr[i];
                } else {
                    f0[i] = f0[i - 1] - arr[i];
                    f0_m[i] = f0_m[i - 1] - i * arr[i];

                    f1[i] = f1[i - 1] + arr[i];
                    f1_m[i] = f1_m[i - 1] + i * arr[i];
                }
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
