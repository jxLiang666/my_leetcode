/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
 *
 * https://leetcode.cn/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (72.74%)
 * Likes:    1318
 * Dislikes: 0
 * Total Accepted:    458.2K
 * Total Submissions: 629.1K
 * Testcase Example:  '[9,3,15,20,7]\n[9,15,7,20,3]'
 *
 * 给定两个整数数组 inorder 和 postorder ，其中 inorder 是二叉树的中序遍历， postorder
 * 是同一棵树的后序遍历，请你构造并返回这颗 二叉树 。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入：inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
 * 输出：[3,9,20,null,null,15,7]
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入：inorder = [-1], postorder = [-1]
 * 输出：[-1]
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 <= inorder.length <= 3000
 * postorder.length == inorder.length
 * -3000 <= inorder[i], postorder[i] <= 3000
 * inorder 和 postorder 都由 不同 的值组成
 * postorder 中每一个值都在 inorder 中
 * inorder 保证是树的中序遍历
 * postorder 保证是树的后序遍历
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

#include <deque>
#include <unordered_map>
class Solution {
public:
    TreeNode* buildTree(const std::unordered_map<int,std::vector<int>::iterator> &map1,
        const std::vector<int>::iterator &inL,const std::vector<int>::iterator &inR,
        const std::vector<int>::iterator &postL,const std::vector<int>::iterator &postR){
        if(inR - inL<1) return nullptr;
        else if(inR - inL == 1) return new TreeNode(*inL);
        TreeNode *node = new TreeNode(*(postR-1));
        int inorderRelatedIdx = std::distance(inL,map1.find(node->val)->second);

        node->left = buildTree(map1,inL,map1.find(node->val)->second,
                                postL,postL+inorderRelatedIdx);

        node->right = buildTree(map1,map1.find(node->val)->second+1,inR,
                                postL+inorderRelatedIdx,postR-1);
        

        return node;
        

    }



    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // if(postorder.size() ==0) return nullptr;
        // // TreeNode *root = new TreeNode(*(postorder.end()-1));
        // if(postorder.size() ==1) return new TreeNode(*(postorder.end()-1));
        std::unordered_map<int,std::vector<int>::iterator > map1;
        for(int i =0;i<inorder.size();i++){
            map1[inorder[i]] =  inorder.begin() + i; // 索引值为值，保留值为index
        }
        // inorder 左闭右开
        // postorder 左闭右开
        // root->left = buildTree(map1,inorder.begin(),inorder.begin()+map1.find(root->val)->second,
        //                     postorder.begin(),postorder.begin()+map1.find(root->val)->second);
        // root->right = buildTree(map1,inorder.begin()+map1.find(root->val)->second+1,inorder.end(),
        //                     postorder.begin()+map1.find(root->val)->second+1,postorder.end()-1);
        // return root;
        return buildTree(map1,inorder.begin(),inorder.end(),postorder.begin(),postorder.end());
    }
};
// @lc code=end

