/*
Given a binary tree print all nodes that don’t have a sibling

Input Format
Enter the values of all the nodes in the binary tree in pre-order format where true suggest the node exists and false suggests it is NULL

Constraints
None

Output Format
Display all the nodes which do not have a sibling in a space separated manner

Sample Input
50 true 12 true 18 false false false false

Sample Output
12 18
*/

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

    TreeNode* root = new TreeNode(data);

    string childL;
    cin>>childL;

    if(childL == "true") {
        root->left = buildTree();
    } else {
        root->left = NULL;
    }

    string childR;
    cin>>childR;

    if(childR == "true") {
        root->right = buildTree();
    } else {
        root->right = NULL;
    }

    return root;
}

void SiblingBT(TreeNode* root) {
    //base case
    if(root == NULL) {
        return;
    }

    //recursive case
    if(root->left == NULL && root->right != NULL){
        cout<<root->right->val<<" ";
        //return;
    }

    if(root->left != NULL && root->right == NULL){
        cout<<root->left->val<<" ";
        //return;
    }

    SiblingBT(root->left);
    // if(flagL == true) {
    //     cout<<root->val;
    //     flagL = false;
    // }
    SiblingBT(root->right);
    // if(flagR == true) {
    //     cout<<root->val;
    //     flagR = false;
    // }
}

int main() {
    TreeNode* root = NULL;

    root = buildTree();
    SiblingBT(root);
    
    return 0;
}