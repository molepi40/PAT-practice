#include <bits/stdc++.h>
using namespace std;

int getfa(int* f, int x) {
    return f[x] = (x == f[x] ? x: getfa(f, f[x]));
}

void bind(int* f, int x, int y) {
    int fx = getfa(f, x);
    int fy = getfa(f, y);
    if (fx != fy) {
        f[fx] = fy;
    }
}
int main() {
    int n, i, j, k, h;
    scanf("%d", &n);
    if (n == 0) {
        printf("0");
        return 0;
    }
    int f[n + 1];
    for (i = 1; i <= n; ++i) {
        f[i] = i;
    }
    vector<int> hobby;
    hobby.resize(1001, 0);
    for (i = 1; i <= n; ++i) {
        scanf("%d:", &k);
        while (k--) {
            scanf("%d", &h);
            if (hobby[h] == 0) {
                hobby[h] = i;
            } else {
               bind(f, i, hobby[h]); 
            }
        }
    }
    vector<int> num;
    num.resize(n + 1, 0);
    int fi;
    for (i = 1; i <= n; ++i) {
        fi = getfa(f, i);
        num[fi]++;
    }
    sort(num.begin(), num.end(), greater<int>());
    for (i = 0; i < num.size(); ++i) {
        if (num[i] <= 0) {
            break;
        }
    }
    printf("%d\n", i);
    for (j = 0; j < i; ++j) {
        if (j == 0) {
            printf("%d", num[j]);
        } else {
            printf(" %d", num[j]);
        }
    }
}