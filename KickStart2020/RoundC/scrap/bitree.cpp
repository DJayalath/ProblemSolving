#include <bits/stdc++.h>
using namespace std;

// Playing around with Fenwick Trees encoded as arrays

#define MAX 200000

int f[MAX + 1];
int N;

void reset(int N) {
    memset(f, 0, sizeof(int) * (N + 1));
}

// Start value is ++i because 0 is a dummy node in the tree
// We increment by the LSB (i & -i) because this gives us the
// parent by the definition of this tree type.
//
// upd adds x to the node and all its ancestors
void upd(int i, int x) {
    for (++i; i <= N; i += i & -i)
        f[i] += x;
}

// Returns sum of arr[0..i]
//
// In query view, subtracting LSB gives ancestors
int qry(int i) {
    int t = 0;
    for (++i; i; i -= i & -i)
        t += f[i];
    return t;
}

int main(void) {

    N = 5;

    reset(N);

    int arr[5] = {3, 4, 1, 2, 9};

    for (int i = 0; i < N; i++)
        upd(i, arr[i]);

    cout << qry(4) << endl;

    upd(4, 10 - arr[4]);

    cout << qry(4) << endl;

    upd(2, 10 - arr[2]);

    cout << qry(3) << endl;

    return 0;
}
