/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 *
 * https://leetcode.cn/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (43.05%)
 * Likes:    7442
 * Dislikes: 0
 * Total Accepted:    1.3M
 * Total Submissions: 2.9M
 * Testcase Example:  '[1,3]\n[2]'
 *
 * 给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。
 * 
 * 算法的时间复杂度应该为 O(log (m+n)) 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums1 = [1,3], nums2 = [2]
 * 输出：2.00000
 * 解释：合并数组 = [1,2,3] ，中位数 2
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums1 = [1,2], nums2 = [3,4]
 * 输出：2.50000
 * 解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5
 * 
 * 
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * nums1.length == m
 * nums2.length == n
 * 0 <= m <= 1000
 * 0 <= n <= 1000
 * 1 <= m + n <= 2000
 * -10^6 <= nums1[i], nums2[i] <= 10^6
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <set>
#include <algorithm>
class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::multiset<int> set1(nums1.begin(),nums1.end());
        set1.insert(nums2.begin(),nums2.end());
        float mid = (set1.size()+1)/2.0;
        if(mid == (float)(int)mid){
            auto it = set1.begin();  // 获取迭代器，指向容器的开始位置
            std::advance(it, mid - 1);
            return *it;
        }
        else{
            auto it1 = set1.begin();  // 获取迭代器，指向容器的开始位置
            auto it2 = set1.begin();  // 获取迭代器，指向容器的开始位置
            std::advance(it1, mid - 0.5-1);
            std::advance(it2, mid + 0.5-1);
            return (double)(*it1+*it2)/2.0;
        }

        
    }
};
// @lc code=end

