#include <iostream>
#include <queue>

using namespace std;


class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int v): val(v), left(NULL), right(NULL) {}
};



TreeNode* upsideDown (TreeNode *root) {
    if (root == NULL)
        return root;

    // leaf, just return
    if (!root->left && !root->right)
        return root;

    TreeNode *newRoot = upsideDown(root->left);

    TreeNode *left = root->left;
    left->left = root->right;
    left->right = root;

    root->left = root->left = NULL;

    return newRoot;
}




// void print (TreeNode *r) {
//     queue<TreeNode*> q;
//     q.push(r);

//     while (q.size() > 0) {
//         int s = q.size();

//         while (s--) {
//             TreeNode *front = q.front(); q.pop();

//             cout<<front->val<<" ";

//             if 
//         }

//         cout<<endl;
//     }
// }


int main() {

    // build tree
    // [1,2,3,4,5]
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    TreeNode *newRoot = upsideDown(root);

    
    // print(newRoot);
}