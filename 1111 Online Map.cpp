#include <bits/stdc++.h>
using namespace std;

typedef struct{
    int v;
    int len, time;
}Edge;
vector<vector<Edge>> edges;
vector<int> path;
int n, total_dis, total_time;

void djkstral(int s, int d) {
    int dis[n];
    int time[n];
    int i, j;
    for (i = 0; i < n; ++i) {
        dis[i] = INT_MAX;
        time[i] = INT_MAX;
    }
    dis[s] = 0, time[s] = 0;

    queue<int> que;
    que.push(s);
    path[s] = -1;
    int cur;
    while (!que.empty()) {
        cur = que.front();
        que.pop();
        for (auto& e: edges[cur]) {
            if (dis[e.v] != INT_MAX && dis[e.v] == dis[cur] + e.len) {
                if (time[e.v] > time[cur] + e.time) {
                    time[e.v] = time[cur] + e.time;
                    path[e.v] = cur;
                    que.push(e.v);
                }
            } else if (dis[e.v] == INT_MAX || dis[e.v] > dis[cur] + e.len) {
                dis[e.v] = dis[cur] + e.len;
                time[e.v] = time[cur] + e.time;
                path[e.v] = cur;
                que.push(e.v);
            }
        }
    }
    total_dis = dis[d];
    total_time = time[d];
}

void djkstral2(int s, int d) {
    int time[n];
    int sect[n];
    int i, j;
    for (i = 0; i < n; ++i) {
        time[i] = INT_MAX;
        sect[i] = INT_MAX;
    }
    time[s] = 0, sect[s] = 1;

    queue<int> que;
    que.push(s);
    path[s] = -1;
    int cur;
    while (!que.empty()) {
        cur = que.front();
        que.pop();
        for (auto& e: edges[cur]) {
            if (time[e.v] != INT_MAX && time[e.v] == time[cur] + e.time) {
                if (sect[e.v] > sect[cur] + 1) {
                    sect[e.v] = sect[cur] + 1;
                    path[e.v] = cur;
                    que.push(e.v);
                }
            } else if (time[e.v] == INT_MAX || time[e.v] > time[cur] + e.time) {
                time[e.v] = time[cur] + e.time;
                sect[e.v] = sect[cur] + 1;
                path[e.v] = cur;
                que.push(e.v);
            }
        }
    }
    total_time = time[d];
    total_dis = sect[d];
}

bool vecEqual(vector<int>& v1, vector<int>& v2) {
    if (v1.size() != v2.size()) {
        return false;
    }
    for (int i = 0; i < v1.size(); ++i) {
        if (v1[i] != v2[i]) {
            return false;
        }
    }
    return true;
}

void outputPath(vector<int>& seq) {
    cout << seq[0];
    for (int i = 1; i < seq.size(); ++i) {
        cout << " -> " << seq[i];
    }
}

int main() {
    int m, i, j;
    cin >> n >> m;
    edges.resize(n);
    path.resize(n);

    int s, d, u, v, one_way, len, time;
    Edge e;
    for (i = 0; i < m; ++i) {
        cin >> u >> v >> one_way >> len >> time;
        e.v = v, e.len = len, e.time = time;
        edges[u].push_back(e);
        if (!one_way) {
            e.v = u;
            edges[v].push_back(e);
        }
    }
    cin >> s >> d;
    djkstral(s, d);
    vector<int> seq1;
    int path1_dis = total_dis, path1_time = total_time;
    int cur = d;
    while (path[cur] > -1) {
        seq1.push_back(cur);
        cur = path[cur];
    }
    seq1.push_back(s);
    reverse(seq1.begin(), seq1.end());
    path.clear();
    path.resize(n);

    djkstral2(s, d);
    vector<int> seq2;
    int path2_dis = total_dis, path2_time = total_time;
    cur = d;
    while (path[cur] > -1) {
        seq2.push_back(cur);
        cur = path[cur];
    }
    seq2.push_back(s);
    reverse(seq2.begin(), seq2.end());

    if (vecEqual(seq1, seq2)) {
        cout << "Distance = " << path1_dis << "; Time = " << path1_time << ": ";
        outputPath(seq1);
    } else {
        cout << "Distance = " << path1_dis << ": ";
        outputPath(seq1);
        cout << "\n";
        cout << "Time = " << path2_time << ": ";
        outputPath(seq2);
    }
}