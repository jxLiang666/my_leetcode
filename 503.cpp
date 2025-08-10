/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
 *
 * https://leetcode.cn/problems/next-greater-element-ii/description/
 *
 * algorithms
 * Medium (68.46%)
 * Likes:    1043
 * Dislikes: 0
 * Total Accepted:    298.8K
 * Total Submissions: 435.6K
 * Testcase Example:  '[1,2,1]'
 *
 * 给定一个循环数组 nums （ nums[nums.length - 1] 的下一个元素是 nums[0] ），返回 nums 中每个元素的
 * 下一个更大元素 。
 * 
 * 数字 x 的 下一个更大的元素 是按数组遍历顺序，这个数字之后的第一个比它更大的数，这意味着你应该循环地搜索它的下一个更大的数。如果不存在，则输出 -1
 * 。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: nums = [1,2,1]
 * 输出: [2,-1,2]
 * 解释: 第一个 1 的下一个更大的数是 2；
 * 数字 2 找不到下一个更大的数； 
 * 第二个 1 的下一个最大的数需要循环搜索，结果也是 2。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: nums = [1,2,3,4,3]
 * 输出: [2,3,4,-1,4]
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 <= nums.length <= 10^4
 * -10^9 <= nums[i] <= 10^9
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <stack>
#include <limits.h>
#include <stack>
#include <iostream>
class Solution {
public:
    std::vector<int> nextGreaterElements(std::vector<int>& nums) {
        std::vector<int> result(nums.size(),-1);
        int maxVal = INT_MIN;
        int maxValIdx = -1;
        std::stack<int> sta1;
        for(int idx = 0 ; idx < nums.size() ; idx++){
            while(!sta1.empty() && nums[idx] > nums[sta1.top()]){
                result[sta1.top()] = nums[idx];
                sta1.pop();
            }
            
            sta1.push(idx);
            if(maxVal <= nums[idx]){
                maxVal = nums[idx];
                maxValIdx = idx;
            }

        }
        // std::cout<<sta1.top() <<" " << maxValIdx << std::endl;
        if(sta1.top() != maxValIdx){
            int size = sta1.top();
            for(int idx = 0 ; idx < size; idx++){
                while(!sta1.empty() && nums[idx] > nums[sta1.top()]){
                    // std::cout << nums[idx]<<" " << result[sta1.top()] << " " ;
                    result[sta1.top()] = nums[idx];
                    sta1.pop();
                }
            }
        }
        return result;

    }
};
// @lc code=end

