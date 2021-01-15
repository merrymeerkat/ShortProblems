#include <iostream>
#include <vector>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
};

//idea 1:  do inorder traversal then check if the resulting array is symm
// THIS DOES NOT WORK. That's because this solution does not take into account the STRUCTURE of the tree, only the values
// therefore a test case such as 
//     1
//   /  \
//  2    2
// /     / 
// 2    2
// would return TRUE even though it's clearly false!
vector <int> ordered_nodes;
void inorderTraversal(TreeNode *root){
    if (root == nullptr) return;
    inorderTraversal(root -> left);
    ordered_nodes.push_back(root -> val);
    inorderTraversal(root -> right);
    return;
}

bool is_symm(TreeNode* root){
    inorderTraversal(root);
    int n = ordered_nodes.size();
    bool symm = true;
    for (int i = 0; i < n/2; i++){
        if (ordered_nodes[i] != ordered_nodes[n-1-i])
            symm = false;
    }
    return symm;
}

int main(){

}
