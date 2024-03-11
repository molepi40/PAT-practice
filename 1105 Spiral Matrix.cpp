#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, i, j;
    scanf("%d", &n);
    int num[n];
    for (i = 0; i < n; ++i) {
        scanf("%d", &num[i]);
    }
    sort(num, num + n, greater<int>());
    int r = sqrt(n);
    for (; r <= n; ++r) {
        if (n % r == 0) {
            break;
        }
    }
    int c = n / r;
    if (c > r) {
        swap(r, c);
    }
    int r1 = r, c1 = c;
    int matrix[r][c];
    int idx, posx, posy;
    idx = posx = posy = 0;
    while (idx < n) {
        for (j = posy; j < posy + c; ++j) {
            matrix[posx][j] = num[idx++];
        }
        if (idx >= n){
            break;
        }
        --j;
        for (i = posx + 1; i < posx + r; ++i) {
            matrix[i][j] = num[idx++];
        }
        if (idx >= n){
            break;
        }
        --i;
        --j;
        for (; j >= posy; --j) {
            matrix[i][j] = num[idx++];
        }
        if (idx >= n){
            break;
        }
        --i;
        for (; i > posx; --i) {
            matrix[i][posy] = num[idx++];
        }
        if (idx >= n){
            break;
        }
        posx++;
        posy++;
        r -= 2;
        c -= 2;
        if (r < 0 || c < 0) {
            break;
        }
    }
    for (i = 0; i < r1; ++i) {
        printf("%d", matrix[i][0]);
        for (j = 1; j < c1; ++j) {
            printf(" %d", matrix[i][j]);
        }
        printf("\n");
    }
}