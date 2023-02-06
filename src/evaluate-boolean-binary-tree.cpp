#include "leetcode.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

class Solution {
public:
    bool evaluateTree(TreeNode* root) {
        if(root->val == 2){ // OR
            return evaluateTree(root->left) || evaluateTree(root->right);
        }else if(root->val == 3){ // AND
            return evaluateTree(root->left) && evaluateTree(root->right);
        }else{
            return !!root->val;
        }
    }
};

TEST_CASE("evaluate-boolean-binary-tree-1"){
    TreeNode* node1 = new TreeNode(2);
    TreeNode* node2= new TreeNode(1);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node4 = new TreeNode(0);
    TreeNode* node5 = new TreeNode(1);

    node1->left = node2;
    node1->right = node3;
    
    node3->left = node4;
    node3->right =  node5;

    auto solution = new Solution();
    CHECK(solution->evaluateTree(node1) == true);

    delete node1;
    delete node2;
    delete node3;
    delete node4;
    delete node5;
    delete solution;
};

TEST_CASE("evaluate-boolean-binary-tree-2"){
    TreeNode* node = new TreeNode(0);
    auto solution = new Solution();
    CHECK(solution->evaluateTree(node) == false);

    delete node;
    delete solution;
};