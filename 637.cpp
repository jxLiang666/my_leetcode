/*
 * @lc app=leetcode.cn id=637 lang=cpp
 *
 * [637] 二叉树的层平均值
 *
 * https://leetcode.cn/problems/average-of-levels-in-binary-tree/description/
 *
 * algorithms
 * Easy (71.60%)
 * Likes:    523
 * Dislikes: 0
 * Total Accepted:    247.8K
 * Total Submissions: 345.6K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个非空二叉树的根节点 root , 以数组的形式返回每一层节点的平均值。与实际答案相差 10^-5 以内的答案可以被接受。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入：root = [3,9,20,null,null,15,7]
 * 输出：[3.00000,14.50000,11.00000]
 * 解释：第 0 层的平均值为 3,第 1 层的平均值为 14.5,第 2 层的平均值为 11 。
 * 因此返回 [3, 14.5, 11] 。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 
 * 
 * 输入：root = [3,9,20,15,7]
 * 输出：[3.00000,14.50000,11.00000]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 
 * 
 * 树中节点数量在 [1, 10^4] 范围内
 * -2^31 <= Node.val <= 2^31 - 1
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
class Solution {
public:
    std::vector<double> averageOfLevels(TreeNode* root) {
        std::vector<double> result;
        std::deque<TreeNode*> deq1;
        if(root) deq1.push_back(root);
        while(!deq1.empty()){
            int size = deq1.size();
            double sum = 0;
            for(int i=0;i<size;i++){
                sum+=deq1.front()->val;
                if(deq1.front()->left) deq1.push_back(deq1.front()->left);
                if(deq1.front()->right) deq1.push_back(deq1.front()->right);
                deq1.pop_front();
            }
            sum/=size;
            result.push_back(sum);
        }
        return result;
    }
};
// @lc code=end

