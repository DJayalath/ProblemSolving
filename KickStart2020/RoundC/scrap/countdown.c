#include <stdio.h>

int array[200000];
int N, K;

int solve() {

    scanf("%i %i", &N, &K);

    for (int i = 0; i < N; i++) {
        scanf("%i", &array[i]);
    }

    int ans = 0;
    for (int i = K - 1; i < N; ++i) {
        int ok=1;
        for (int j = 1; j <= K && ok; ++j) {
            if (array[i + 1 - j] != j) {
                ok = 0;
            }
        }
        ans += ok;
    }

    printf("%i\n", ans);
}

int main(void) {

    int cases;
    scanf("%i", &cases);

    for (int i = 1; i <= cases; i++) {
        printf("Case #%i: ", i);
        solve();
    }
}
