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

void printTree(TreeNode* root) {
    //base case
    if(root == NULL) {
        return;
    }

    if(root->left != NULL)  {
        cout<<root->left->val<<" => ";
        cout<<root->val;
        //return;
    }else{
        cout<<"END"<<" => ";
        cout<<root->val;
        //return;
    }

    if(root->right != NULL)  {
        cout<<" <= "<<root->right->val;
        //return;
    }else{
        cout<<" <= "<<"END";
        //return;
    }
    cout<<endl;

    //recursive case
    printTree(root->left);
    //cout<<"$ ";
    printTree(root->right);
}

bool flag = false;
void removeLeaves(TreeNode* root) {
    //base case
    if(root == NULL) {
        return;
    }

    if(root->left == NULL && root->right == NULL){
        flag = true;
        return;
    }

    //recursive case
    removeLeaves(root->left);
    if(flag == true) {
        root->left = NULL;
        flag = false;
    }
    removeLeaves(root->right);
    if(flag == true) {
        root->right = NULL;
        flag = false;
    }
}

int main() {
    TreeNode* root = NULL;
    
    root = buildTree();
    
    removeLeaves(root);
    printTree(root);
    return 0;
}