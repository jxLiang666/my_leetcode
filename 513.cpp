/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
 *
 * https://leetcode.cn/problems/find-bottom-left-tree-value/description/
 *
 * algorithms
 * Medium (73.58%)
 * Likes:    626
 * Dislikes: 0
 * Total Accepted:    298.7K
 * Total Submissions: 405.5K
 * Testcase Example:  '[2,1,3]'
 *
 * 给定一个二叉树的 根节点 root，请找出该二叉树的 最底层 最左边 节点的值。
 * 
 * 假设二叉树中至少有一个节点。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 
 * 
 * 输入: root = [2,1,3]
 * 输出: 1
 * 
 * 
 * 示例 2:
 * 
 * ⁠
 * 
 * 
 * 输入: [1,2,3,4,null,5,6,null,null,7]
 * 输出: 7
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 二叉树的节点个数的范围是 [1,10^4]
 * -2^31  
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
#include <deque>
#endif
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        if(!root) return 0;
        std::deque<TreeNode*> deq1;
        deq1.push_back(root);
        TreeNode* leftNode = root;
        while(!deq1.empty()){
            int size = deq1.size();
            for (int i =0;i<size;i++){
                TreeNode* node = deq1.front();
                if(i==0) leftNode = node;
                deq1.pop_front();
                if(node->left) {
                    deq1.push_back(node->left);
                }
                if(node->right) {
                    deq1.push_back(node->right);
                }
            }
        }
        return leftNode->val;
    }
};
// @lc code=end

