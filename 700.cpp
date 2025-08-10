/*
 * @lc app=leetcode.cn id=700 lang=cpp
 *
 * [700] 二叉搜索树中的搜索
 *
 * https://leetcode.cn/problems/search-in-a-binary-search-tree/description/
 *
 * algorithms
 * Easy (78.87%)
 * Likes:    498
 * Dislikes: 0
 * Total Accepted:    376.2K
 * Total Submissions: 476.3K
 * Testcase Example:  '[4,2,7,1,3]\n2'
 *
 * 给定二叉搜索树（BST）的根节点 root 和一个整数值 val。
 * 
 * 你需要在 BST 中找到节点值等于 val 的节点。 返回以该节点为根的子树。 如果节点不存在，则返回 null 。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 
 * 
 * 输入：root = [4,2,7,1,3], val = 2
 * 输出：[2,1,3]
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入：root = [4,2,7,1,3], val = 5
 * 输出：[]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中节点数在 [1, 5000] 范围内
 * 1 <= Node.val <= 10^7
 * root 是二叉搜索树
 * 1 <= val <= 10^7
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
#include<vector>
#include<queue>
using namespace std;
#endif
class Solution {
public:
    TreeNode* findVal(TreeNode* root, int val){
        if(!root) return nullptr;
        TreeNode * node = root;
        
        while(node){
            int nodeVal = node->val;
            if(nodeVal == val) return node;
            if(nodeVal > val) node = node->left;
            else if (nodeVal<val) node = node->right;
        }
        return nullptr;
    }

    // std::vector<int> getSubTree(TreeNode * node){
    //     std::vector<int> result;
    //     if(!node) return result;
    //     std::queue<TreeNode *> que1;
    //     que1.push(node);
    //     while(!que1.empty()){
    //         int size = que1.size();
    //         for(int i=0;i<size;i++){
    //             TreeNode* tmpNode = que1.front();
    //             que1.pop();
    //             result.push_back(tmpNode->val);
    //             if(tmpNode->left) que1.push(tmpNode->left);
    //             if(tmpNode->right) que1.push(tmpNode->right);
    //         }
    //     }
    //     return result;
    // }

    TreeNode* searchBST(TreeNode* root, int val) {
        return findVal(root,val);
        
    }
};
// @lc code=end

