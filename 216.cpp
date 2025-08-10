/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 *
 * https://leetcode.cn/problems/combination-sum-iii/description/
 *
 * algorithms
 * Medium (71.52%)
 * Likes:    927
 * Dislikes: 0
 * Total Accepted:    470.4K
 * Total Submissions: 657.7K
 * Testcase Example:  '3\n7'
 *
 * 找出所有相加之和为 n 的 k 个数的组合，且满足下列条件：
 * 
 * 
 * 只使用数字1到9
 * 每个数字 最多使用一次 
 * 
 * 
 * 返回 所有可能的有效组合的列表 。该列表不能包含相同的组合两次，组合可以以任何顺序返回。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: k = 3, n = 7
 * 输出: [[1,2,4]]
 * 解释:
 * 1 + 2 + 4 = 7
 * 没有其他符合的组合了。
 * 
 * 示例 2:
 * 
 * 
 * 输入: k = 3, n = 9
 * 输出: [[1,2,6], [1,3,5], [2,3,4]]
 * 解释:
 * 1 + 2 + 6 = 9
 * 1 + 3 + 5 = 9
 * 2 + 3 + 4 = 9
 * 没有其他符合的组合了。
 * 
 * 示例 3:
 * 
 * 
 * 输入: k = 4, n = 1
 * 输出: []
 * 解释: 不存在有效的组合。
 * 在[1,9]范围内使用4个不同的数字，我们可以得到的最小和是1+2+3+4 = 10，因为10 > 1，没有有效的组合。
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 2 <= k <= 9
 * 1 <= n <= 60
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <functional>
class Solution {
public:
    std::vector<std::vector<int>> combinationSum3(int k, int n) {
      std::vector<std::vector<int>> result;
      std::vector<int> cur;
      int sum = 0;

      std::function<void(int)> comb = [&](int start) -> void {
        if(cur.size() == k){
            if(sum == n){
                result.push_back(cur);
            }
            return ;
        }

        for(int i = start;i<10;i++){
            cur.push_back(i);
            sum+=i;
            comb(i+1);
            sum-= *(std::prev(cur.end()));
            cur.pop_back();
        }

      };

      comb(1);
      return result;
    }
};
// @lc code=end

