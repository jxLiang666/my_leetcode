/*
 * @lc app=leetcode.cn id=617 lang=cpp
 *
 * [617] 合并二叉树
 *
 * https://leetcode.cn/problems/merge-two-binary-trees/description/
 *
 * algorithms
 * Easy (79.64%)
 * Likes:    1449
 * Dislikes: 0
 * Total Accepted:    541.2K
 * Total Submissions: 679.2K
 * Testcase Example:  '[1,3,2,5]\n[2,1,3,null,4,null,7]'
 *
 * 给你两棵二叉树： root1 和 root2 。
 * 
 * 
 * 想象一下，当你将其中一棵覆盖到另一棵之上时，两棵树上的一些节点将会重叠（而另一些不会）。你需要将这两棵树合并成一棵新二叉树。合并的规则是：如果两个节点重叠，那么将这两个节点的值相加作为合并后节点的新值；否则，不为
 * null 的节点将直接作为新二叉树的节点。
 * 
 * 返回合并后的二叉树。
 * 
 * 注意: 合并过程必须从两个树的根节点开始。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root1 = [1,3,2,5], root2 = [2,1,3,null,4,null,7]
 * 输出：[3,4,5,5,4,null,7]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root1 = [1], root2 = [1,2]
 * 输出：[2,2]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 两棵树中的节点数目在范围 [0, 2000] 内
 * -10^4 <= Node.val <= 10^4
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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        std::deque<TreeNode*> deq1;
        if(root1){
            deq1.push_back(root1);
            if(root2){
                deq1.push_back(root2);
            }
            else return root1;
        }
        else return root2;
        while(!deq1.empty()){
            int size = deq1.size();
            for(int i=0;i<size;i+=2){
                TreeNode* node1 = deq1.front();
                deq1.pop_front();
                TreeNode* node2 = deq1.front();
                deq1.pop_front();
                node1->val+=node2->val;
                if(node1->left){
                    if(node2->left){
                        deq1.push_back(node1->left);
                        deq1.push_back(node2->left);
                    } 
                }
                else{
                    node1->left = node2->left;
                    node2->left = nullptr;
                }
                if(node1->right){
                    if(node2->right){
                        deq1.push_back(node1->right);
                        deq1.push_back(node2->right);
                    } 
                }
                else{
                    node1->right = node2->right;
                    node2->right = nullptr;
                }
            }
        }
        return root1;
      
    }
};
// @lc code=end

