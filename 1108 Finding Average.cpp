#include <bits/stdc++.h>
using namespace std;

void notif(string& num) {
    cout << "ERROR: " << num << " is not a legal number\n";
}

int main (){
    int n;
    cin >> n;
    string num;
    vector<float> seq;
    int cnt = -1;
    int i, j;
    float f;
    for (i = 0; i < n; ++i) {
        cin >> num;
        j = 0;
        if (num[0] == '-') {
            j = 1;
        }
        cnt = -1;
        for (; j < num.size(); ++j) {
            if (!isdigit(num[j])){
                if (num[j] == '.') {
                    // cout << num << " " << cnt << "\n";
                    if (cnt >= 0) {
                        notif(num);
                        break;
                    }
                    cnt = 0;
                } else {
                    notif(num);
                    break;                    
                }
            } else {
                if (cnt >= 0) {
                    cnt++;
                    if (cnt > 2) {
                        notif(num);
                        break;
                    }
                }
            }
        }
        if (j == num.size()) {
            f = stof(num);
            if (f < -1000 || f > 1000) {
                notif(num);
            } else {
                seq.push_back(stof(num));
            }
        }
    }
    if (seq.size() == 0) {
        cout << "The average of 0 numbers is Undefined";
    } else {
        float avg = 0;
        for (auto f: seq) {
            avg += f;
        }
        // cout << avg;
        avg /= (seq.size() * 1.0);
        // cout.setf(ios::showpoint);
        cout << "The average of " << seq.size();
        if (seq.size() > 1) {
            cout <<" numbers is " << fixed << setprecision(2) << avg;            
        } else {
            cout << " number is " << fixed << setprecision(2) << avg;
        }

    }
}