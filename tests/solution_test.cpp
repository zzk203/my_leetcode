#include <gtest/gtest.h>
#include "solution.h"

TEST(SymmetricTreeTest, EmptyTree) {
    Solution solution;
    EXPECT_TRUE(solution.isSymmetric(nullptr));
}

TEST(SymmetricTreeTest, SingleNode) {
    Solution solution;
    TreeNode* root = new TreeNode(1);
    EXPECT_TRUE(solution.isSymmetric(root));
}

TEST(SymmetricTreeTest, SymmetricTree) {
    Solution solution;
    TreeNode* root = new TreeNode(1,
        new TreeNode(2, new TreeNode(3), new TreeNode(4)),
        new TreeNode(2, new TreeNode(4), new TreeNode(3)));
    EXPECT_TRUE(solution.isSymmetric(root));
}

TEST(SymmetricTreeTest, NotSymmetric) {
    Solution solution;
    TreeNode* root = new TreeNode(1,
        new TreeNode(2, new TreeNode(3), nullptr),
        new TreeNode(2, nullptr, new TreeNode(3)));
    EXPECT_FALSE(solution.isSymmetric(root));
}