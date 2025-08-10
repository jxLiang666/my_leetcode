/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 *
 * https://leetcode.cn/problems/intersection-of-two-arrays/description/
 *
 * algorithms
 * Easy (75.19%)
 * Likes:    964
 * Dislikes: 0
 * Total Accepted:    663.2K
 * Total Submissions: 881.5K
 * Testcase Example:  '[1,2,2,1]\n[2,2]'
 *
 * 给定两个数组 nums1 和 nums2 ，返回 它们的 交集 。输出结果中的每个元素一定是 唯一 的。我们可以 不考虑输出结果的顺序 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums1 = [1,2,2,1], nums2 = [2,2]
 * 输出：[2]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * 输出：[9,4]
 * 解释：[4,9] 也是可通过的
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums1.length, nums2.length <= 1000
 * 0 <= nums1[i], nums2[i] <= 1000
 * 
 * 
 */
#include<iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
// @lc code=start
class Solution {
public:
    std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
        
        std::unordered_set<int> set1(nums1.begin(),nums1.end());
        std::unordered_set<int> set2;
        for(int i : nums2){
            auto it = set1.find(i);
            if(it != set1.end()){
                set2.insert(i);
            }
        }
        return std::vector<int>(set2.begin(),set2.end());;
    }
};
// @lc code=end

