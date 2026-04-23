#include "solution.h"

#include <queue>

std::vector<double> Solution::averageOfLevels(TreeNode* root) {
    if (root == NULL) {
        return {};
    }
    std::vector<double> ret;
    queue<TreeNode*> treeLayer;
    treeLayer.push(root);
    while (!treeLayer.empty()) {
        double sum = 0;
        double num = 0;
        // 标识不同层
        treeLayer.push(NULL);
        while (!treeLayer.empty() && treeLayer.front() != NULL) {
            sum += treeLayer.front()->val;
            ++num;
            if (treeLayer.front()->left != NULL) {
                treeLayer.push(treeLayer.front()->left);
            }
            if (treeLayer.front()->right != NULL) {
                treeLayer.push(treeLayer.front()->right);
            }
            treeLayer.pop();
        }
        ret.push_back(sum / num);
        // 把标识弹出队列
        if (!treeLayer.empty()) {
            treeLayer.pop();
        }
    }
    return ret;
}