#include <iostream>
#include <queue>
#include <stack>

using namespace std;

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

class BinaryTree {
public:
    TreeNode* root;

    BinaryTree() : root(nullptr) {}

    // DFS Iterator
    class DFSIterator {
    private:
        stack<TreeNode*> st;
    public:
        DFSIterator(TreeNode* root) {
            if (root) st.push(root);
        }

        bool hasNext() {
            return !st.empty();
        }

        int next() {
            TreeNode* current = st.top();
            st.pop();
            if (current->right) st.push(current->right);
            if (current->left) st.push(current->left);
            return current->value;
        }
    };

    // BFS Iterator
    class BFSIterator {
    private:
        queue<TreeNode*> q;
    public:
        BFSIterator(TreeNode* root) {
            if (root) q.push(root);
        }

        bool hasNext() {
            return !q.empty();
        }

        int next() {
            TreeNode* current = q.front();
            q.pop();
            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
            return current->value;
        }
    };
};

int main() {
    BinaryTree tree;
    tree.root = new TreeNode(1);
    tree.root->left = new TreeNode(2);
    tree.root->right = new TreeNode(3);
    tree.root->left->left = new TreeNode(4);
    tree.root->left->right = new TreeNode(5);

    cout << "DFS: ";
    BinaryTree::DFSIterator dfs(tree.root);
    while (dfs.hasNext()) {
        cout << dfs.next() << " ";
    }
    cout << "\n";

    cout << "BFS: ";
    BinaryTree::BFSIterator bfs(tree.root);
    while (bfs.hasNext()) {
        cout << bfs.next() << " ";
    }
    cout << "\n";

    return 0;
}
//I honestly tried myself, but it didn't work, I threw the raw code into the gpt chat and I have this