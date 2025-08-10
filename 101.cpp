/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 *
 * https://leetcode.cn/problems/symmetric-tree/description/
 *
 * algorithms
 * Easy (61.68%)
 * Likes:    2914
 * Dislikes: 0
 * Total Accepted:    1.3M
 * Total Submissions: 2.1M
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * 给你一个二叉树的根节点 root ， 检查它是否轴对称。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root = [1,2,2,3,4,4,3]
 * 输出：true
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = [1,2,2,null,3,null,3]
 * 输出：false
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中节点数目在范围 [1, 1000] 内
 * -100 <= Node.val <= 100
 * 
 * 
 * 
 * 
 * 进阶：你可以运用递归和迭代两种方法解决这个问题吗？
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
#include <deque>
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        std::deque<TreeNode*> deq1;
        if(!root) return true;
        if(root->left) deq1.push_back(root->left);
        if(root->right) deq1.push_front(root->right);
        while(!deq1.empty()){
            int size = deq1.size();
            if(size % 2 != 0) return false;
            std::deque<TreeNode*> deq2;
            for(int i =0; i<size;i+=2){
                TreeNode* leftNode = deq1.back();
                deq1.pop_back();
                TreeNode* rightNode = deq1.front();
                deq1.pop_front();
                if(leftNode->val != rightNode->val) return false;
                if(leftNode->left && rightNode->right){
                    deq2.push_back(leftNode->left);
                    deq2.push_front(rightNode->right);
                }
                else if(!(!leftNode->left && !rightNode->right)) return false;
                if(leftNode->right && rightNode->left){
                    deq2.push_back(rightNode->left);
                    deq2.push_front(leftNode->right);
                }
                else if(!(!leftNode->right && !rightNode->left)) return false;
            }
            deq1 = deq2;

        }
        return true;
    }
};
// @lc code=end

