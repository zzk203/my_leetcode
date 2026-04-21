#include "solution.h"

bool isSymmetricTwo(TreeNode* left, TreeNode* right) {
    if (left == right) {
        return true;
    }
    if (left == NULL || right == NULL) {
        return false;
    }
    if (left->val != right->val) {
        return false;
    }
    return isSymmetricTwo(left->left, right->right) &&
           isSymmetricTwo(left->right, right->left);
}
bool Solution::isSymmetric(TreeNode* root) {
    if (root == NULL) {
        return true;
    }
    return isSymmetricTwo(root->left, root->right);
}