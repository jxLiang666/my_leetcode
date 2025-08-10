/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 *
 * https://leetcode.cn/problems/3sum/description/
 *
 * algorithms
 * Medium (38.90%)
 * Likes:    7355
 * Dislikes: 0
 * Total Accepted:    2.2M
 * Total Submissions: 5.6M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * 给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j !=
 * k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。请你返回所有和为 0 且不重复的三元组。
 * 
 * 注意：答案中不可以包含重复的三元组。
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [-1,0,1,2,-1,-4]
 * 输出：[[-1,-1,2],[-1,0,1]]
 * 解释：
 * nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0 。
 * nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0 。
 * nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0 。
 * 不同的三元组是 [-1,0,1] 和 [-1,-1,2] 。
 * 注意，输出的顺序和三元组的顺序并不重要。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [0,1,1]
 * 输出：[]
 * 解释：唯一可能的三元组和不为 0 。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [0,0,0]
 * 输出：[[0,0,0]]
 * 解释：唯一可能的三元组和为 0 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 3 <= nums.length <= 3000
 * -10^5 <= nums[i] <= 10^5
 * 
 * 
 */
#include <iostream>
#include<vector>
#include <unordered_map>
#include<algorithm>
// @lc code=start
class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::sort(nums.begin(),nums.end());
        for(int i =0 ;i<nums.size();i++){
            if(nums[i] >0){
                return result;
            }

            if(i >0 && nums[i] == nums[i-1]){
                continue;
            }

            int left = i+1;
            int right = nums.size()-1;
            while(right>left){
                if(nums[i] + nums[left] + nums[right] == 0){
                    result.push_back({nums[i],nums[left],nums[right]});
                    while(right > left && nums[left] == nums[left+1]) left++;
                    while(right > left && nums[right] == nums[right-1]) right--;

                    left ++;
                    right --;
                }
                else if (nums[i] + nums[left] + nums[right] > 0){
                    right--;
                }
                else if (nums[i] + nums[left] + nums[right] < 0){
                    left ++;
                }
            }
        }
        return result;
    }
};
// @lc code=end

