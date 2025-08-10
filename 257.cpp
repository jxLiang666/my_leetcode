/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
 *
 * https://leetcode.cn/problems/binary-tree-paths/description/
 *
 * algorithms
 * Easy (71.38%)
 * Likes:    1217
 * Dislikes: 0
 * Total Accepted:    459.9K
 * Total Submissions: 643.5K
 * Testcase Example:  '[1,2,3,null,5]'
 *
 * 给你一个二叉树的根节点 root ，按 任意顺序 ，返回所有从根节点到叶子节点的路径。
 * 
 * 叶子节点 是指没有子节点的节点。
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root = [1,2,3,null,5]
 * 输出：["1->2->5","1->3"]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = [1]
 * 输出：["1"]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中节点的数目在范围 [1, 100] 内
 * -100 <= Node.val <= 100
 * 
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#if 0
struct TreeNode {
         int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode() : val(0), left(nullptr), right(nullptr) {}
         TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
         TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
     };
#endif
#include <vector>
#include <string>
#include <iostream>
class Solution {
public:
    void getPathOfNode(TreeNode* node,std::string prefix,std::vector<std::string>& result){
        if (!prefix.empty()) prefix += "->";
        prefix += std::to_string(node->val);
        if(node->left == nullptr && node->right == nullptr){
            result.push_back(prefix);
            return;
        }
        if(node->left){
            getPathOfNode(node->left,prefix,result);
        }
        if(node->right){
            getPathOfNode(node->right,prefix,result);
        }
        
    }
    std::vector<std::string> binaryTreePaths(TreeNode* root) {
        std::vector<std::string> result;
        if(root) getPathOfNode(root,"",result);
        return result;
    }
};
// @lc code=end

