/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 *
 * https://leetcode.cn/problems/longest-consecutive-sequence/description/
 *
 * algorithms
 * Medium (50.33%)
 * Likes:    2481
 * Dislikes: 0
 * Total Accepted:    1M
 * Total Submissions: 2M
 * Testcase Example:  '[100,4,200,1,3,2]'
 *
 * 给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
 * 
 * 请你设计并实现时间复杂度为 O(n) 的算法解决此问题。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [100,4,200,1,3,2]
 * 输出：4
 * 解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [0,3,7,2,5,8,4,6,0,1]
 * 输出：9
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [1,0,1,2]
 * 输出：3
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <set>
#include <iostream>
class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        if(nums.size() == 0) return 0;
        std::set<int> s(nums.begin(),nums.end());
        int maxLength = 0;
        auto it = std::next(s.begin());
        // auto it = std::prev(s.begin());
        int count = 1;
        while(it != s.end()){
            int last_num = (*std::prev(it));
            int cur_num = (*it);
            std::cout<<'('<<last_num<<' '<<cur_num<<')'<<" ";
            if(cur_num == last_num+1){
                count++;
            }
            else{
                // count++;
                maxLength = std::max(count,maxLength);
                count = 1;
            }

            ++it;
        }
        // 更新最后一次计数
        maxLength = std::max(maxLength, count);
        return maxLength;
    }
};
// @lc code=end

