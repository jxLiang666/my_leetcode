/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 *
 * https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (72.42%)
 * Likes:    2499
 * Dislikes: 0
 * Total Accepted:    800.3K
 * Total Submissions: 1.1M
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * 给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历， inorder
 * 是同一棵树的中序遍历，请构造二叉树并返回其根节点。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
 * 输出: [3,9,20,null,null,15,7]
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: preorder = [-1], inorder = [-1]
 * 输出: [-1]
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 <= preorder.length <= 3000
 * inorder.length == preorder.length
 * -3000 <= preorder[i], inorder[i] <= 3000
 * preorder 和 inorder 均 无重复 元素
 * inorder 均出现在 preorder
 * preorder 保证 为二叉树的前序遍历序列
 * inorder 保证 为二叉树的中序遍历序列
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

using namespace std;

#endif

#include <unordered_map>
class Solution {
public:
    TreeNode* buildTree(const std::unordered_map<int,std::vector<int>::iterator> &map1,
                        const std::vector<int>::iterator & preL,const std::vector<int>::iterator & preR,
                        const std::vector<int>::iterator & inL,const std::vector<int>::iterator & inR){
        if(inR-inL <1) return nullptr;
        else if(inR - inL == 1) return new TreeNode(*inL);
        TreeNode* node = new TreeNode(*preL);

        int leftNum = std::distance(inL, map1.find(node->val)->second);
        node->left = buildTree(map1,preL+1,preL+1+leftNum,inL,inL+leftNum);
        node->right = buildTree(map1,preL+1+leftNum,preR,inL+leftNum+1,inR);
        return node;
    }
    

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // if(preorder.size() == 0) return nullptr;
        // else if(preorder.size() == 1) return new TreeNode(preorder[0]);

        std::unordered_map<int,std::vector<int>::iterator> map1;
        for(auto it = inorder.begin();it < inorder.end();it++){
            map1[*it] = it;
        }

        return buildTree(map1,preorder.begin(),preorder.end(),inorder.begin(),inorder.end());

    }
};
// @lc code=end

