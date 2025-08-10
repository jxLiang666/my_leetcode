/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
 *
 * https://leetcode.cn/problems/find-mode-in-binary-search-tree/description/
 *
 * algorithms
 * Easy (55.95%)
 * Likes:    793
 * Dislikes: 0
 * Total Accepted:    249K
 * Total Submissions: 443.9K
 * Testcase Example:  '[1,null,2,2]'
 *
 * 给你一个含重复值的二叉搜索树（BST）的根节点 root ，找出并返回 BST 中的所有 众数（即，出现频率最高的元素）。
 * 
 * 如果树中有不止一个众数，可以按 任意顺序 返回。
 * 
 * 假定 BST 满足如下定义：
 * 
 * 
 * 结点左子树中所含节点的值 小于等于 当前节点的值
 * 结点右子树中所含节点的值 大于等于 当前节点的值
 * 左子树和右子树都是二叉搜索树
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root = [1,null,2,2]
 * 输出：[2]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = [0]
 * 输出：[0]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中节点的数目在范围 [1, 10^4] 内
 * -10^5 <= Node.val <= 10^5
 * 
 * 
 * 
 * 
 * 进阶：你可以不使用额外的空间吗？（假设由递归产生的隐式调用栈的开销不被计算在内）
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
using namespace std;
#endif

#include <vector>
#include <unordered_map>
class Solution {
public:

    void inorder(TreeNode* node,int &maxCount,std::unordered_map<int,int> &map1){
        if(!node) return;
        inorder(node->left,maxCount,map1);
        map1[node->val] ++;
        maxCount = std::max(maxCount,map1[node->val]);
        inorder(node->right,maxCount,map1);
    }

    vector<int> findMode(TreeNode* root) {
        std::vector<int> result;
        int maxCount = 0;
        std::unordered_map<int,int> map1;
        inorder(root,maxCount,map1);
        for(auto i : map1){
            if(i.second == maxCount){
                result.push_back(i.first);
            }
        }
        return result;
    }
};
// @lc code=end

