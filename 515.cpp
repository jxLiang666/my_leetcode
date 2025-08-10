/*
 * @lc app=leetcode.cn id=515 lang=cpp
 *
 * [515] 在每个树行中找最大值
 *
 * https://leetcode.cn/problems/find-largest-value-in-each-tree-row/description/
 *
 * algorithms
 * Medium (66.66%)
 * Likes:    393
 * Dislikes: 0
 * Total Accepted:    178.3K
 * Total Submissions: 267.4K
 * Testcase Example:  '[1,3,2,5,3,null,9]'
 *
 * 给定一棵二叉树的根节点 root ，请找出该二叉树中每一层的最大值。
 * 
 * 
 * 
 * 示例1：
 * 
 * 
 * 
 * 
 * 输入: root = [1,3,2,5,3,null,9]
 * 输出: [1,3,9]
 * 
 * 
 * 示例2：
 * 
 * 
 * 输入: root = [1,2,3]
 * 输出: [1,3]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 二叉树的节点个数的范围是 [0,10^4]
 * -2^31 <= Node.val <= 2^31 - 1
 * 
 * 
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
#include <deque>
#include <climits>
class Solution {
public:
    std::vector<int> largestValues(TreeNode* root) {
        std::vector<int> result;
        std::deque<TreeNode*> deq1;
        if(root) deq1.push_back(root);
        while(!deq1.empty()){
            int size = deq1.size();
            int maxVal = INT_MIN;
            for(int i =0;i<size;i++){
                TreeNode* node = deq1.front();
                deq1.pop_front();
                if(maxVal<node->val) maxVal = node->val;
                if(node->left) deq1.push_back(node->left);
                if(node->right) deq1.push_back(node->right);
            }
            result.push_back(maxVal);
        }
        return result;
    }
};
// @lc code=end

