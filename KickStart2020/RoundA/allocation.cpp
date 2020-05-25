#include <bits/stdc++.h>
using namespace std;

void solve() {

    int N, B;
    cin >> N >> B;

    int l = 0;
    int ans = 0;

    int a[N];
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    qsort(a, N, sizeof(int), [](const void* a, const void* b) {

            int arg1 = *static_cast<const int*>(a);
            int arg2 = *static_cast<const int*>(b);

            if(arg1 < arg2) return -1;
            if(arg1 > arg2) return 1;
            return 0;
    
            });

    for (int i : a) {
        if (B - i < 0)
            break;
        B -= i;
        ans++;
    }

    cout << ans << endl;

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
