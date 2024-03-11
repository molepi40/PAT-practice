#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, i, j;
    scanf("%d", &n);
    double num[n + 1];
    for (i = 1; i <= n; ++i) {
        scanf("%lf", &num[i]);
    }
    double f = 0;
    int g = 0;
    double sum = 0;
    for (i = 1; i <= n; ++i) {
        f += num[i] * (g + 1);
        g++;
        sum += f;
    }
    printf("%.2lf", sum);
}