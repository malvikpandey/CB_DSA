#include <iostream>

using namespace std;

class TreeNode {
    public:
        int val;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int val) {
            this->val = val;
            this->left = NULL;
            this->right = NULL;
        }
};

TreeNode* buildTree() {
    int data;
    cin>>data;

    if(data == -1) {
        return NULL;
    }

    TreeNode* root = new TreeNode(data);

    root->left = buildTree();
    root->right = buildTree();

    return root;
}

void printPreOrder(TreeNode* root) {
    if(root == NULL) {
        cout<<-1<<" ";
        return;
    }

    cout<<root->val<<" ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}

int main() {
    TreeNode* root = NULL;
    
    root = buildTree();
    printPreOrder(root);

    return 0;
}