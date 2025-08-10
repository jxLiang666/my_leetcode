/*
 * @lc app=leetcode.cn id=581 lang=cpp
 *
 * [581] 最短无序连续子数组
 *
 * https://leetcode.cn/problems/shortest-unsorted-continuous-subarray/description/
 *
 * algorithms
 * Medium (42.65%)
 * Likes:    1208
 * Dislikes: 0
 * Total Accepted:    216.5K
 * Total Submissions: 507.1K
 * Testcase Example:  '[2,6,4,8,10,9,15]'
 *
 * 给你一个整数数组 nums ，你需要找出一个 连续子数组 ，如果对这个子数组进行升序排序，那么整个数组都会变为升序排序。
 * 
 * 请你找出符合题意的 最短 子数组，并输出它的长度。
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [2,6,4,8,10,9,15]
 * 输出：5
 * 解释：你只需要对 [6, 4, 8, 10, 9] 进行升序排序，那么整个表都会变为升序排序。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1,2,3,4]
 * 输出：0
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [1]
 * 输出：0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * -10^5 
 * 
 * 
 * 
 * 
 * 进阶：你可以设计一个时间复杂度为 O(n) 的解决方案吗？
 * 
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <queue>
#include <algorithm>
class Solution {
public:
    // int findUnsortedSubarray(std::vector<int>& nums) {
    //     std::priority_queue<int,std::vector<int>> maxHeap(nums.begin(),nums.end());
    //     std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap(nums.begin(),nums.end());
    //     int left = 0;
    //     int right = nums.size()-1;
    //     while(!minHeap.empty() && nums[left] == minHeap.top()){
    //         left++;
    //         minHeap.pop();
    //     }
    //     while(!maxHeap.empty() && nums[right] == maxHeap.top()){
    //         right--;
    //         maxHeap.pop();
    //     }
    //     int num = right - left + 1;
    //     return num<0? 0 : num;
    // }
    int findUnsortedSubarray(std::vector<int>& nums) {
        int n = nums.size();
        int maxSeen = INT_MIN, minSeen = INT_MAX;
        int left = -1, right = -1;

        for (int i = 0; i < n; ++i) {
            maxSeen = std::max(maxSeen, nums[i]);
            if (nums[i] < maxSeen) right = i;
        }

        for (int i = n - 1; i >= 0; --i) {
            minSeen = std::min(minSeen, nums[i]);
            if (nums[i] > minSeen) left = i;
        }

        return (right == -1) ? 0 : (right - left + 1);
    }

};
// @lc code=end

