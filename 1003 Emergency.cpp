#include <bits/stdc++.h>
using namespace std;

typedef struct{
    int v, w;
}Edge;

int main(){
    int n, m, s, e;
    int i, j, k;
    scanf("%d %d %d %d", &n, &m, &s, &e);
    int teams[n];
    for (i = 0; i < n; ++i) {
        scanf("%d", &teams[i]);
    }
    vector<vector<Edge>> edges;
    Edge edge;
    edges.resize(n);
    int u, v, w;
    for (i = 0; i < m; ++i) {
        scanf("%d %d %d", &u, &v, &w);
        edge.w = w;
        edge.v = v;
        edges[u].push_back(edge);
        edge.v = u;
        edges[v].push_back(edge);
    }
    int dis[n];
    for (i = 0; i < n; ++i) {
        dis[i] = INT_MAX;
    }
    dis[s] = 0;

    int num[n];
    memset(num, 0, sizeof(num));
    num[s] = 1;

    int road[n];
    memset(road, 0, sizeof(road));

    queue<int> q;
    for (i = 0; i < edges[s].size(); ++i) {
        v = edges[s][i].v;
        w = edges[s][i].w;
        dis[v] = w;
        num[v] = teams[s] + teams[v];
        road[v] = 1;
        q.push(v);
    }

    int min_val;
    int idx;
    bool vis[n];
    memset(vis, 0, sizeof(vis));
    vis[s] = true;

    for (i = 1; i < n; ++i) {
        idx = -1;
        min_val = INT_MAX;
        for (j = 0; j < n; ++j) {
            if (!vis[j] && min_val > dis[j]) {
                idx = j;
                min_val = dis[j];
            }
        }
        if (idx == -1) {
            break;
        }
        vis[idx] = true;
        for (j = 0; j < edges[idx].size(); ++j) {
            v = edges[idx][j].v;
            w = edges[idx][j].w;
            if (vis[v]) {
                continue;
            }
            if (dis[v] > dis[idx] + w) {
                dis[v] = dis[idx] + w;
                num[v] = num[idx] + teams[v];
                road[v] = road[idx];
            } else if (dis[v] == dis[idx] + w) {
                if (num[v] < num[idx] + teams[v]) {
                    num[v] = num[idx] + teams[v];
                }
                road[v] += road[idx];
            }
        }
    }
    printf("%d %d", road[e], num[e]);
}