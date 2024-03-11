#include <bits/stdc++.h>
using namespace std;

double lp = 10e10;
int cnt;
double r;

void traval(vector<vector<int>>& edges, int u, double p) {
    if (edges[u].size() == 0) {
        if (p < lp) {
            lp = p;
            cnt = 1;
        } else if (p == lp) {
            cnt++;
        }
        return;
    }
    int v;
    for (int i = 0; i < edges[u].size(); ++i) {
        v = edges[u][i];
        traval(edges, v, p * (1 + r / 100.0));
    }
}

int main() {
    int n, i, j, k, u, v, w;
    double p;
    scanf("%d %lf %lf", &n, &p, &r);
    vector<vector<int>> edges;
    edges.resize(n);
    for (i = 0; i < n; ++i) {
        scanf("%d", &k);
        while(k--) {
            scanf("%d", &v);
            edges[i].push_back(v);
        }
    }
    traval(edges, 0, p);
    printf("%.4lf %d", lp, cnt);

}