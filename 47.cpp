/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 *
 * https://leetcode.cn/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (66.54%)
 * Likes:    1695
 * Dislikes: 0
 * Total Accepted:    649K
 * Total Submissions: 974K
 * Testcase Example:  '[1,1,2]'
 *
 * 给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,1,2]
 * 输出：
 * [[1,1,2],
 * ⁠[1,2,1],
 * ⁠[2,1,1]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1,2,3]
 * 输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 8
 * -10 <= nums[i] <= 10
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <functional>
#include <algorithm>
class Solution {
public:
    std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::vector<int> cur;
        std::vector<bool> used(nums.size(),false);
        std::sort(nums.begin(),nums.end());
        std::function <void(void)> backtracking = [&]() ->void {
            if(cur.size() == nums.size()){
                result.push_back(cur);
                return;
            }
            
            for ( int i =0 ; i < nums.size();i++){
                if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) {
                    continue;
                }
                if(used[i] == true) continue;

                used[i] = true;
                cur.push_back(nums[i]);
                backtracking();
                cur.pop_back();
                used[i] = false;

            }


        };
        backtracking();
        return result;
    }
};
// @lc code=end

