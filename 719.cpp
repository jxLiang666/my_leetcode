/*
 * @lc app=leetcode.cn id=719 lang=cpp
 *
 * [719] 找出第 K 小的数对距离
 *
 * https://leetcode.cn/problems/find-k-th-smallest-pair-distance/description/
 *
 * algorithms
 * Hard (48.29%)
 * Likes:    476
 * Dislikes: 0
 * Total Accepted:    42.8K
 * Total Submissions: 88.5K
 * Testcase Example:  '[1,3,1]\n1'
 *
 * 数对 (a,b) 由整数 a 和 b 组成，其数对距离定义为 a 和 b 的绝对差值。
 * 
 * 给你一个整数数组 nums 和一个整数 k ，数对由 nums[i] 和 nums[j] 组成且满足 0 <= i < j < nums.length
 * 。返回 所有数对距离中 第 k 小的数对距离。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,3,1], k = 1
 * 输出：0
 * 解释：数对和对应的距离如下：
 * (1,3) -> 2
 * (1,1) -> 0
 * (3,1) -> 2
 * 距离第 1 小的数对是 (1,1) ，距离为 0 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1,1,1], k = 2
 * 输出：0
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [1,6,1], k = 3
 * 输出：5
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == nums.length
 * 2 <= n <= 10^4
 * 0 <= nums[i] <= 10^6
 * 1 <= k <= n * (n - 1) / 2
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <queue>
#include <math.h>
#include <set>
class Solution {
private:
    struct comp
    {
        bool operator()(std::pair<int,int>&a,std::pair<int,int>&b){
            return abs(a.first-a.second) > abs(b.first-b.second);
        }
    };
    
public:
    int smallestDistancePair(std::vector<int>& nums, int k) {
        std::priority_queue<std::pair<int,int>,std::vector<std::pair<int,int>>,comp> pq;
        for(int i = 0 ; i < nums.size()-1;i++){
            for(int j = i+1 ; j < nums.size();j++){
                pq.push({nums[i],nums[j]});
            }
        }
        for(int i = 0 ; i < k-1;i++){
            pq.pop();
        }
        return abs(pq.top().first-pq.top().second);
    }
};
// @lc code=end

