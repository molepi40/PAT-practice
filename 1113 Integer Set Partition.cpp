#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, i;
    scanf("%d", &n);
    int num[n];
    for (i = 0; i < n; ++i) {
        scanf("%d", &num[i]);
    }
    sort(num, num + n);
    int n1 = n / 2, n2 = n - n1, sum1 = 0, sum2 = 0, ans;
    i = 0;
    for (; i < n1; ++i) {
        sum1 += num[i];
    }
    for (; i < n; ++i) {
        sum2 += num[i];
    }
    ans = abs(sum1 - sum2);
    if (n2 > n1) {
        ans = max(ans, abs(sum1 - sum2 + 2 * num[n1]));
    }
    printf("%d %d", n2 - n1, ans);
}