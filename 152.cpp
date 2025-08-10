/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 *
 * https://leetcode.cn/problems/maximum-product-subarray/description/
 *
 * algorithms
 * Medium (42.67%)
 * Likes:    2432
 * Dislikes: 0
 * Total Accepted:    557.2K
 * Total Submissions: 1.3M
 * Testcase Example:  '[2,3,-2,4]'
 *
 * 给你一个整数数组 nums ，请你找出数组中乘积最大的非空连续 子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。
 * 
 * 测试用例的答案是一个 32-位 整数。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: nums = [2,3,-2,4]
 * 输出: 6
 * 解释: 子数组 [2,3] 有最大乘积 6。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: nums = [-2,0,-1]
 * 输出: 0
 * 解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 <= nums.length <= 2 * 10^4
 * -10 <= nums[i] <= 10
 * nums 的任何子数组的乘积都 保证 是一个 32-位 整数
 * 
 * 
 */

// @lc code=start
#include <vector>
class Solution {
public:
    // int maxProduct(std::vector<int>& nums) {
    //     int maxVal =nums[0];
    //     for(int i =0 ; i < nums.size();i++){
    //         int product =1;
    //         for(int j = i;j<nums.size();j++){
    //             product *= nums[j];
    //             maxVal = std::max(product,maxVal);
    //             if(!product){
    //                 break;
    //             }
    //         }
    //     }
    //     return maxVal;
    // }
    int maxProduct(std::vector<int>& nums) {
        int maxProd = nums[0], minProd = nums[0], result = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < 0) std::swap(maxProd, minProd);
            maxProd = std::max(nums[i], maxProd * nums[i]);
            minProd = std::min(nums[i], minProd * nums[i]);
            result = std::max(result, maxProd);
        }
        return result;
    }

};
// @lc code=end

