/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 *
 * https://leetcode.cn/problems/3sum-closest/description/
 *
 * algorithms
 * Medium (44.84%)
 * Likes:    1715
 * Dislikes: 0
 * Total Accepted:    621.3K
 * Total Submissions: 1.4M
 * Testcase Example:  '[-1,2,1,-4]\n1'
 *
 * 给你一个长度为 n 的整数数组 nums 和 一个目标值 target。请你从 nums 中选出三个整数，使它们的和与 target 最接近。
 * 
 * 返回这三个数的和。
 * 
 * 假定每组输入只存在恰好一个解。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [-1,2,1,-4], target = 1
 * 输出：2
 * 解释：与 target 最接近的和是 2 (-1 + 2 + 1 = 2)。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [0,0,0], target = 1
 * 输出：0
 * 解释：与 target 最接近的和是 0（0 + 0 + 0 = 0）。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 3 <= nums.length <= 1000
 * -1000 <= nums[i] <= 1000
 * -10^4 <= target <= 10^4
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <algorithm>
#include <math.h>
#include <limits.h>
#include <functional>
class Solution {
public:
    int threeSumClosest(std::vector<int>& nums, int target) {
        std::sort(nums.begin(),nums.end());
        int dis = INT_MAX;
        int result = 0;
        for (int i =0;i<nums.size()-2;i++){
            int left = i+1;
            int right = nums.size()-1;
            int sum = 0;
            while(right > left){
                sum = nums[i] + nums[left] + nums[right] ;
                if(dis >= abs(sum-target)){
                    dis = abs(sum - target);
                    result = sum;
                }
                if(sum > target){
                    right--;
                }
                else if (sum == target){
                    return sum;
                }
                else{
                    left ++;
                }
            }
        }



        return result;
    }
};
// @lc code=end

