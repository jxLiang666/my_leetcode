/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
 *
 * https://leetcode.cn/problems/binary-tree-right-side-view/description/
 *
 * algorithms
 * Medium (69.12%)
 * Likes:    1179
 * Dislikes: 0
 * Total Accepted:    567K
 * Total Submissions: 812.5K
 * Testcase Example:  '[1,2,3,null,5,null,4]'
 *
 * 给定一个二叉树的 根节点 root，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root = [1,2,3,null,5,null,4]
 * 
 * 输出：[1,3,4]
 * 
 * 解释：
 * 
 * 
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = [1,2,3,4,null,null,null,5]
 * 
 * 输出：[1,3,4,5]
 * 
 * 解释：
 * 
 * 
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：root = [1,null,3]
 * 
 * 输出：[1,3]
 * 
 * 
 * 示例 4：
 * 
 * 
 * 输入：root = []
 * 
 * 输出：[]
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 二叉树的节点个数的范围是 [0,100]
 * -100 <= Node.val <= 100 
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
#include <algorithm>
class Solution {
public:
    std::vector<int> rightSideView(TreeNode* root) {
        std::deque<TreeNode*> deq1;
        std::vector<int> result;
        if(root) {
            deq1.push_back(root);
            result.push_back(root->val);    
        }

        while(!deq1.empty()){
            int size = deq1.size();
            std::deque<TreeNode*> deq2;
            for(int i =0;i<size;i++){
                if(deq1[i]->right) deq2.push_back(deq1[i]->right);
                if(deq1[i]->left) deq2.push_back(deq1[i]->left);
            }
            for(int i =0;i<size;i++){
                if(deq1[i]->right){
                    result.push_back(deq1[i]->right->val);
                    break;
                }
                if(deq1[i]->left){
                    result.push_back(deq1[i]->left->val);
                    break;
                }
            }
            deq1= deq2;
        }
        return result;
    }
};
// @lc code=end

