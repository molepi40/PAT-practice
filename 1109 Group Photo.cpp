#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<string, int>& s1, pair<string, int>& s2) {
    if (s1.second == s2.second) {
        return s1.first < s2.first;
    }
    return s1.second > s2.second;
}

int main (){
    int n, k, m, last_row, i;
    string name;
    int height;

    cin >> n >> k;
    m = n / k;
    last_row = (n - m * k) + m;

    vector<pair<string, int>> students;
    students.resize(n);
    for (i = 0; i < n; ++i) {
        cin >> name >> height;
        students[i] = move(make_pair(name, height));
    }
    sort(students.begin(), students.end(), cmp);

    vector<vector<string>> formaiton;
    formaiton.resize(k);
    int mid, l, r, cnt;

    mid = last_row / 2;
    formaiton[0].resize(last_row);
    formaiton[0][mid] = students[0].first;
    cnt = 1;
    l = mid - 1, r = mid + 1;
    while (l >= 0 || r < last_row) {
        if (l >= 0) {
            formaiton[0][l--] = students[cnt++].first;
        }        
        if (r < last_row) {
            formaiton[0][r++] = students[cnt++].first;
        }
    }

    mid = m / 2;
    // int j;
    for (i = 1; i < k; ++i) {
        formaiton[i].resize(m);
        formaiton[i][mid] = students[cnt++].first;
        l = mid - 1, r = mid + 1;
        while (l >= 0 || r < m) {
            if (l >= 0) {
                formaiton[i][l--] = students[cnt++].first;
            }        
            if (r < m) {
                formaiton[i][r++] = students[cnt++].first;
            }
        }
    }
    int j;
    for (i = 0; i < k; ++i) {
        cout << formaiton[i][0];
        for (j = 1; j < formaiton[i].size(); ++j) {
            cout << " " << formaiton[i][j];
        }
        cout << "\n";
    }
}