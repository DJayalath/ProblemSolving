#include <bits/stdc++.h>
using namespace std;

#define MAX 200001

// Cumulative sums encoded in Fenwick trees
long long f0[MAX]; // +A1 -A2 +A3 -A4 ...
long long f0_m[MAX]; // +1 * A1 -2 * A2 +3 * A1 ...

long long f1[MAX]; // -A1 +A2 -A3 +A4 ...
long long f1_m[MAX]; // -1 * A1 +2 * A2 -3 * A3 ...

long long arr[MAX];

int N;

// Reset
void reset() {
    memset(f0, 0, sizeof(long long) * (N + 1));
    memset(f0_m, 0, sizeof(long long) * (N + 1));
    memset(f1, 0, sizeof(long long) * (N + 1));
    memset(f1_m, 0, sizeof(long long) * (N + 1));
    memset(arr, 0, sizeof(long long) * (N + 1));
}

// Update
void upd(int i, long long x, long long f[]) {
    for (; i <= N; i += i & -i)
        f[i] += x;
}

// Query
long long qry(int i, long long f[]) {
    long long t = 0;
    for (; i; i -= i & -i)
        t += f[i];
    return t;
}

void apply(int i, long long x) {

    if (i & 1) {
        upd(i, x - arr[i], f0);
        upd(i, i * (x - arr[i]), f0_m);
        upd(i, -(x - arr[i]), f1);
        upd(i, -i * (x - arr[i]), f1_m);
    } else {
        upd(i, -(x - arr[i]), f0);
        upd(i, -i * (x - arr[i]), f0_m);
        upd(i, x - arr[i], f1);
        upd(i, i * (x - arr[i]), f1_m);
    }

    arr[i] = x;
}

void solve() {
    
    int Q;
    cin >> N >> Q;

    reset();

    for (int i = 1; i < N + 1; i++) {

        long long x;
        cin >> x;
        
        apply(i, x);

    }
   
    long long swt = 0;
    
    char op;
    int x, y;
    for (int k = 0; k < Q; k++) {
        
        cin >> op;
  
        if (op == 'Q') { // Query

            int x, y;
            cin >> x >> y;

            if (x & 1) {
                swt += (qry(y, f0_m) - qry(x - 1, f0_m)) - (x - 1) * (qry(y, f0) - qry(x - 1, f0));
            } else {
                swt += (qry(y, f1_m) - qry(x - 1, f1_m)) - (x - 1) * (qry(y, f1) - qry(x - 1, f1));            
            }
        
        } else { // Update
           
            int i;
            long long x;
            cin >> i >> x;

            apply(i, x);
            
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
