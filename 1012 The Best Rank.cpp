#include <bits/stdc++.h>
using namespace std;

const int N = 2001;
typedef struct{
    string id;
    int score[4]; // e m c a
    int rank[4];
    int best_rank = 0;
}Student;

int sub_idx;
bool cmp(Student& s1, Student& s2) {
    return s1.score[sub_idx] > s2.score[sub_idx];
}

const string subjects = "EMCA";

int main() {
    int n, m;
    cin >> n >> m;
    Student s[n];
    map<string, int> mp;
    for (int i = 0; i < n; ++i) {
        cin >> s[i].id >> s[i].score[2] >> s[i].score[1] >> s[i].score[0];
        s[i].score[3] = (s[i].score[0] + s[i].score[1] + s[i].score[2]) / 3.0 + 0.5;
    }
    int r;
    for (sub_idx = 0; sub_idx < 4; ++sub_idx) {
        sort(s, s + n, cmp);
        s[0].rank[sub_idx] = 1;
        s[0].best_rank = sub_idx;
        for (int i = 1; i < n; ++i) {
            if (s[i].score[sub_idx] == s[i-1].score[sub_idx]) {
                s[i].rank[sub_idx] = s[i-1].rank[sub_idx];
            } else {
                s[i].rank[sub_idx] = i + 1;
            }
            if (s[i].rank[sub_idx] <= s[i].rank[s[i].best_rank]) {
                s[i].best_rank = sub_idx;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        mp[s[i].id] = i;
    }
    string id;
    for (int i = 0; i < m; ++i) {
        cin >> id;
        if (mp.find(id) == mp.end()) {
            cout << "N/A" << "\n";
        } else {
            cout << s[mp[id]].rank[s[mp[id]].best_rank] << " " << subjects[s[mp[id]].best_rank] << "\n";
        }
    }

}