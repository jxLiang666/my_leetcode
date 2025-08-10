/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 *
 * https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/description/
 *
 * algorithms
 * Medium (72.81%)
 * Likes:    2933
 * Dislikes: 0
 * Total Accepted:    906.1K
 * Total Submissions: 1.2M
 * Testcase Example:  '[3,5,1,6,2,0,8,null,null,7,4]\n5\n1'
 *
 * 给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
 * 
 * 百度百科中最近公共祖先的定义为：“对于有根树 T 的两个节点 p、q，最近公共祖先表示为一个节点 x，满足 x 是 p、q 的祖先且 x
 * 的深度尽可能大（一个节点也可以是它自己的祖先）。”
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
 * 输出：3
 * 解释：节点 5 和节点 1 的最近公共祖先是节点 3 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
 * 输出：5
 * 解释：节点 5 和节点 4 的最近公共祖先是节点 5 。因为根据定义最近公共祖先节点可以为节点本身。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：root = [1,2], p = 1, q = 2
 * 输出：1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中节点数目在范围 [2, 10^5] 内。
 * -10^9 
 * 所有 Node.val 互不相同 。
 * p != q
 * p 和 q 均存在于给定的二叉树中。
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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
#include<vector>
#include<queue>
#include<iostream>
using namespace std;
#endif

class Solution {
    bool findNode(TreeNode* node, TreeNode* p,std::queue<TreeNode*> &que1){
        if(!node) return false;
        if(node == p){
            que1.push(node);
            return true;
        }
        bool resulta = findNode(node->left,p,que1);
        if(resulta){
            //std::cout<<node->val<<" ";
            que1.push(node);
            return true;
        }
        resulta = findNode(node->right,p,que1);
        if(resulta){
            //std::cout<<node->val<<" ";
            que1.push(node);
            return true;
        }
        return false;
    }
    TreeNode* lowestCommonAncestor(std::queue<TreeNode*> &quelong,std::queue<TreeNode*> &queshort){
        if(quelong.front() == queshort.front()) return quelong.front();
        if(quelong.size() == queshort.size()){
            quelong.pop();
            queshort.pop();
        }
        else{
            quelong.pop();
        }
        
        return lowestCommonAncestor(quelong,queshort);
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        std::queue<TreeNode*> quep;
        std::queue<TreeNode*> queq;
        findNode(root,p,quep);
        //std::cout<<endl;
        findNode(root,q,queq);
        //std::cout<<endl;
        if(quep.size() >= queq.size()){
            std::queue<TreeNode*> &quelong = quep;
            std::queue<TreeNode*> &queshort = queq;
            return lowestCommonAncestor(quelong,queshort); 
        }
        else{
            std::queue<TreeNode*> &quelong = queq;
            std::queue<TreeNode*> &queshort = quep;
            return lowestCommonAncestor(quelong,queshort);
        }

    }
};
// @lc code=end

