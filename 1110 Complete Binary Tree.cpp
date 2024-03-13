#include <bits/stdc++.h>
using namespace std;

typedef struct Node{
    int val;
    struct Node* left = nullptr;
    struct Node* right = nullptr;
}TreeNode;

int main () {
    int n, i;
    cin >> n;

    map<int, TreeNode*> mp;
    string lval, rval;
    int lint, rint;
    TreeNode* cur;

    bool vis[n];
    memset(vis, 0, sizeof(vis));
    for (i = 0; i < n; ++i) {
        cin >> lval >> rval;
        cur = mp.find(i) == mp.end() ? mp[i] = new TreeNode(): mp[i];
        cur->val = i;
        if (lval != "-") {
            lint = stoi(lval);
            vis[lint] = true;
            cur->left = mp.find(lint) == mp.end() ? mp[lint] = new TreeNode(): mp[lint];
        }
        if (rval != "-") {
            rint = stoi(rval);
            vis[rint] = true;
            cur->right = mp.find(rint) == mp.end() ? mp[rint] = new TreeNode(): mp[rint];
        }
    }
    for (i = 0; i < n; ++i) {
        if(!vis[i]) {
            break;
        }
    }
    int root = i;
    queue<TreeNode*> que;
    que.push(mp[i]);
    bool flag = false;
    int last_node;
    while(!que.empty()) {
        cur = que.front();
        que.pop();
        // cout << cur->val << "\n";
        if (cur == nullptr) {
            flag = true;
        } else if (flag) {
            cout << "NO " << root;
            return 0;
        } else {
            // cout << cur->val << "\n";
            last_node = cur->val;
            que.push(cur->left);
            que.push(cur->right);
        }
    }
    cout << "YES " << last_node;
}