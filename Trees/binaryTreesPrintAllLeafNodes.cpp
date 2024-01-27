/*
Given a Binary Tree Print all the leaf nodes.

Input Format
Level order input of the binary tree

Constraints
Total no of nodes <1000

Output Format
All leaf nodes from left to right in single line

Sample Input
1
2 3
4 5
6 7
-1 -1
-1 -1
-1 -1
-1 -1

Sample Output
4 5 6 7
*/

#include <iostream>
#include <queue>

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

TreeNode* buildTree(){
    int rootData;
    cin>>rootData;

    TreeNode* root = new TreeNode(rootData);

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()) {
        TreeNode* front = q.front();
        q.pop();

        int leftData;
        cin>>leftData;

        if(leftData != -1) {
            TreeNode* leftChild = new TreeNode(leftData);
            front->left = leftChild;
            q.push(leftChild);
        }

        int rightData;
        cin>>rightData;

        if(rightData != -1) {
            TreeNode* rightChild = new TreeNode(rightData);
            front->right = rightChild;
            q.push(rightChild);
        }
    }

    return root;
}

void printLeafNode(TreeNode* root) {
    //base case
    if(root == NULL) {
        return;
    }

    //recursive case
    if(root->left == NULL && root->right == NULL){
        cout<<root->val<<" ";
        return;
    }

    printLeafNode(root->left);
    printLeafNode(root->right);
}

int main() {
    TreeNode* root = NULL;
    root = buildTree();
    cout<<endl;
    // printPreOrder(root);
    // cout<<endl;
    printLeafNode(root);
    return 0;
}