/*
Given a binary tree. Print the zig zag order i.e print level 1 from left to right, level 2 from right to left and so on. This means odd levels should get printed from left to right and even levels should be printed from right to left.

Input Format
Enter the values of all the nodes in the binary tree in pre-order format where true suggest the node exists and false suggests it is NULL

Constraints
None

Output Format
Display the values in zigzag level order in which each value is separated by a space

Sample Input
10 true 20 true 40 false false true 50 false false true 30 true 60 false false true 73 false false

Sample Output
10 30 20 40 50 60 73 
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
            this->left=NULL;
            this->right=NULL;
            this->val=val;
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

vector<int> zigzagTrav(TreeNode* root) {

    bool rightToLeft = true;
    vector<int> zigZagRes;
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()) {
        int size = q.size();
        vector<int> row(size);

        for(int i = 0; i < size; i++){
            TreeNode* front = q.front();
            q.pop();

            // find the position for the ith node
            int index = (rightToLeft) ? i : size-1-i;
            row[index] = front->val;

            if(front->left){
                q.push(front->left);
            }

            if(front->right){
                q.push(front->right);
            }
        }

        for(int j : row){
            zigZagRes.push_back(j);
        }
        rightToLeft = !rightToLeft;
        
    }
    return zigZagRes;
}


int main() {
    TreeNode* root = NULL;
    root = buildTree();
    vector<int> res = zigzagTrav(root);

    for(int i : res){
        cout<<i<<" ";
    }
    return 0;
}