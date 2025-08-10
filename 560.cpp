/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 *
 * https://leetcode.cn/problems/subarray-sum-equals-k/description/
 *
 * algorithms
 * Medium (44.79%)
 * Likes:    2743
 * Dislikes: 0
 * Total Accepted:    712K
 * Total Submissions: 1.6M
 * Testcase Example:  '[1,1,1]\n2'
 *
 * 给你一个整数数组 nums 和一个整数 k ，请你统计并返回 该数组中和为 k 的子数组的个数 。
 * 
 * 子数组是数组中元素的连续非空序列。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,1,1], k = 2
 * 输出：2
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1,2,3], k = 3
 * 输出：2
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 2 * 10^4
 * -1000 <= nums[i] <= 1000
 * -10^7 <= k <= 10^7
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <unordered_map>
class Solution {
public:
    int subarraySum(const std::vector<int>& nums, int k) {
        int count = 0;
        int sum = 0;
        std::unordered_map<int, int> prefixSumCount;
        prefixSumCount[0]=1;
        for (int num : nums) {
            sum += num;

            // if (sum == k) {
            //     count++;
            // }

            if (prefixSumCount.find(sum - k) != prefixSumCount.end()) {
                count += prefixSumCount[sum - k];
            }

            prefixSumCount[sum]++;
        }

        return count;
    }
};
// @lc code=end

