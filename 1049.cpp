/*
 * @lc app=leetcode.cn id=1049 lang=cpp
 *
 * [1049] 最后一块石头的重量 II
 *
 * https://leetcode.cn/problems/last-stone-weight-ii/description/
 *
 * algorithms
 * Medium (71.69%)
 * Likes:    979
 * Dislikes: 0
 * Total Accepted:    227.8K
 * Total Submissions: 317.5K
 * Testcase Example:  '[2,7,4,1,8,1]'
 *
 * 有一堆石头，用整数数组 stones 表示。其中 stones[i] 表示第 i 块石头的重量。
 * 
 * 每一回合，从中选出任意两块石头，然后将它们一起粉碎。假设石头的重量分别为 x 和 y，且 x <= y。那么粉碎的可能结果如下：
 * 
 * 
 * 如果 x == y，那么两块石头都会被完全粉碎；
 * 如果 x != y，那么重量为 x 的石头将会完全粉碎，而重量为 y 的石头新重量为 y-x。
 * 
 * 
 * 最后，最多只会剩下一块 石头。返回此石头 最小的可能重量 。如果没有石头剩下，就返回 0。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：stones = [2,7,4,1,8,1]
 * 输出：1
 * 解释：
 * 组合 2 和 4，得到 2，所以数组转化为 [2,7,1,8,1]，
 * 组合 7 和 8，得到 1，所以数组转化为 [2,1,1,1]，
 * 组合 2 和 1，得到 1，所以数组转化为 [1,1,1]，
 * 组合 1 和 1，得到 0，所以数组转化为 [1]，这就是最优值。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：stones = [31,26,33,21,40]
 * 输出：5
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= stones.length <= 30
 * 1 <= stones[i] <= 100
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <algorithm>
#include <functional>
#include <math.h>
#include <numeric>
class Solution {
public:
    int lastStoneWeightII(std::vector<int>& stones) {
        int sum = std::accumulate(stones.begin(),stones.end(),0);
        int target = sum/2;
        std::vector<int> d(target+1,0);
        for(int i = 0;i<stones.size();++i){
            for(int j = target;j>=stones[i];--j){
                    d[j] = std::max(d[j],d[j-stones[i]]+stones[i]);
            }
        }
        return sum - d[target] - d[target];
        

        //  贪心+递归
        // std::function<void(void)> backtracking = [&]() ->void {
        //     if(stones.size() == 1 || stones.size() == 0){
        //         return;
        //     }
        //     std::sort(stones.begin(),stones.end());
        //     int y = *(stones.end()-1);
        //     int x = *(stones.end()-2);
        //     int rest = abs(y-x);
        //     stones.resize(stones.size()-2);
        //     if(rest){
        //         stones.push_back(rest);
        //     }
        //     backtracking();
        // };
        // backtracking();
        // return stones.empty()? 0 : stones[0];
    }
};
// @lc code=end

