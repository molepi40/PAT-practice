#include <bits/stdc++.h>
using namespace std;

typedef struct Node{
    int val = -1;
    struct Node* left = nullptr;
    struct Node* right = nullptr;
}TreeNode;

vector<int> pre, in, post;
void postTraval(TreeNode* cur) {
    if (cur == nullptr) {
        return;
    }
    postTraval(cur->left);
    postTraval(cur->right);
    post.push_back(cur->val);
}


TreeNode* buildTree(int s1, int e1, int s2, int e2){
    if (s1 > e1) {
        return nullptr;
    }
    TreeNode* node = new TreeNode();
    if (s1 == e1) {
        node->val = pre[s1];
        return node;
    }
    int i;
    for (i = s2; i <= e2; ++i) {
        if (in[i] == pre[s1]) {
            break;
        }
    }
    node->val = pre[s1];
    node->left = buildTree(s1 + 1, s1 + i - s2, s2, i - 1);
    node->right = buildTree(s1 + i - s2 + 1, e1, i + 1, e2);
    return node;
}

int main() {
    string op;
    int n, val;
    cin >> n;
    stack<int> st;
    for (int i = 0; i < 2 * n; ++i) {
        cin >> op;
        if (op[1] == 'u') {
            cin >> val;
            st.push(val);
            pre.push_back(val);
        } else {
            in.push_back(st.top());
            st.pop();
        }        
    }
    TreeNode* root = buildTree(0, n-1, 0, n-1);
    postTraval(root);
    cout << post[0];
    for (int i = 1; i < post.size(); ++i) {
        cout << " " << post[i];
    }
}