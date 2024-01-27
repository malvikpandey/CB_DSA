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

void printPreOrder(TreeNode* root) {
    if(root == NULL) {
        cout<<-1<<" ";
        return;
    }

    cout<<root->val<<" ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}

bool strIdenCheck(TreeNode* root1, TreeNode* root2) {
    //base case
    if(root1 == NULL && root2 == NULL) {
        return true;
    }
    
    if(root1 == NULL || root2 == NULL) {
        return false;
    }


    //recursive case
    bool rootL = strIdenCheck(root1->left, root2->left);
    bool rootR = strIdenCheck(root1->right, root2->right);

    return rootL && rootR;
}

int main() {
    TreeNode* root1 = NULL;
    TreeNode* root2 = NULL;
    
    root1 = buildTree();
    root2 = buildTree();
    
    if(strIdenCheck(root1, root2)) cout<<"true";
    else cout<<"false";
    return 0;
}