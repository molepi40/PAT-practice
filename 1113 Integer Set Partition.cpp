#include <bits/stdc++.h>
using namespace std;

void findKthNum(int* num, int s, int e, int k) {
    if (s == e) {
        return;
    } else if (s > e) {
        return;
    }
    int t = num[s], l = s, r = e;
    while (l < r) {
        while (l < r && num[r] > t) r--;
        if (l < r) num[l++] = num[r];
        while (l < r && num[l] < t) l++;
        if (l < r) num[r--] = num[l];
    }
    num[l] = t;
    if ((l - s + 1) == k) {
        return;
    } else if ((l - s + 1) < k) {
        findKthNum(num, l + 1, e, k - (l - s + 1));
    } else {
        findKthNum(num, s, l - 1, k);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int num[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &num[i]);
    }
    int n1 = n / 2;
    int n2 = n - n2;
    findKthNum(num, 0, n-1, n1);
    int sum1 = 0, sum2 = 0, i = 0;
    for (; i < n1; ++i) {
        sum1 += num[i];
    }
    for (; i < n; ++i) {
        sum2 += num[i];
    }
    int ans = abs(sum1 - sum2);
    if (n2 > n1) {
        ans = max(ans, abs(sum1 - sum2 + 2 * num[n1]));
    }
    printf("%d %d", n - 2 * n1, ans);
}