
#include <stdio.h>

using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

vector<int> postOrder(Node* root) {
    vector<int> res;
    stack<Node*> st;
    while (true) {
        while (root) {
            st.push(root);
            st.push(root);
            root = root->left;
        }
        if (st.empty())
            return res;
        root = st.top();
        st.pop();
        if (!st.empty() && st.top() == root)
            root = root->right;
        else {
            res.push_back(root->data);
            root = nullptr;
        }
    }
    return res;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<int> postOrderList = postOrder(root);
    for (auto it : postOrderList)
        cout << it << " ";
    
    return 0;
}