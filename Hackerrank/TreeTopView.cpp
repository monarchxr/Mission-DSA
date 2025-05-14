#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
using namespace std;

class Node{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};


Node* insert(Node* root, int data){
    if(!root) return new Node(data);
    if(data <= root->data)
        root->left  = insert(root->left,  data);
    else
        root->right = insert(root->right, data);
    return root;
}

/* Prints the top view of the binary tree */
void topView(Node* root) {
    if (!root) return;
    queue<pair<Node*, int>> q;
    map<int, int> mp;
    q.push({ root, 0 });
    while (q.size()) {
        auto temp = q.front();
        q.pop();
        int horizontal_distance = temp.second;
        Node* node = temp.first;
        if (!mp[horizontal_distance]) {
            mp[horizontal_distance] = node->data;
        }
        if (node->left) {
            q.push({ node->left, horizontal_distance - 1 });
        }
        if (node->right) {
            q.push({ node->right, horizontal_distance + 1 });
        }
    }
    for (auto node : mp) {
        cout << node.second << ' ';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    Node* root = nullptr;
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        root = insert(root, v);
    }
    topView(root);
    return 0;
}