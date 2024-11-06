#include <iostream>
#include <vector>

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int v) { val = v; }
};


vector<int> inorderMorris(TreeNode *root) {
    vector<int> traversal;

    TreeNode *cur = root;

    // Till curr is not NULL
    while (cur != NULL) {
        // Left does not exist
        // Print Root as per the Left, Head, Right convention
        // and move to right of cur
        
        // An important point here to note is that
        // cur.right would always exist = Actual Node or Inorder Successor
        if (cur->left == NULL) {
            traversal.push_back(cur->val);
            cout<<cur->val<<endl;
            cur = cur->right;
        } else {
            // Left Exists
            // Find the RightMost Node in Left Subtree

            TreeNode *prev = cur->left;
            while (prev->right && prev->right != cur)
                prev = prev->right;
            
            // Now we are at the rightmost node in left subtree
            // Inorder successor of this node is the 'current' node

            // Create a thread to the inorder successor if right is NULL
            if (prev->right == NULL) {
                prev->right = cur;

                // Move to the next node in traversal
                cur = cur->left;
            } else {
                // We have visited this node before
                // when we created the link
                // break this thread
                // and print the current node since it is next in traversal

                prev->right = NULL;
                traversal.push_back(cur->val);
                cout<<cur->val<<endl;

                // Left Subtree is completely covered now
                // so move to Right
                cur = cur->right;
            }

            
        }
    }


    return traversal;
}


int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(6);
    root->left->right->right = new TreeNode(7);

    inorderMorris(root);
}

/*
            1
          /   \
        2       3
      /   \
     4     5
         /   \
        6     7
    
    4, 2, 6, 5, 7, 1, 3
*/