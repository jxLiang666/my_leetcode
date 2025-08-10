/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 *
 * https://leetcode.cn/problems/top-k-frequent-elements/description/
 *
 * algorithms
 * Medium (64.45%)
 * Likes:    1982
 * Dislikes: 0
 * Total Accepted:    684.7K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,1,1,2,2,3]\n2'
 *
 * 给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: nums = [1,1,1,2,2,3], k = 2
 * 输出: [1,2]
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: nums = [1], k = 1
 * 输出: [1]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * k 的取值范围是 [1, 数组中不相同的元素的个数]
 * 题目数据保证答案唯一，换句话说，数组中前 k 个高频元素的集合是唯一的
 * 
 * 
 * 
 * 
 * 进阶：你所设计算法的时间复杂度 必须 优于 O(n log n) ，其中 n 是数组大小。
 * 
 */

// @lc code=start
#include <vector>
#include <unordered_map>
#include <queue>
#include <functional>
class Solution {
public:
    // bool compare(const std::pair<int,int> &pair1,const std::pair<int,int> &pair2)const{
    //     if(pair1.second >pair2.second){
    //         return true;
    //     }
    //     return false;
    // }
    class comp{
        public:
            bool operator()(const std::pair<int,int> &pair1,const std::pair<int,int> &pair2)const{
                return(pair1.second >pair2.second);
            };
    };
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::unordered_map<int,int> map1;
        for(auto i:nums){
            map1[i]++;
        }

        std::priority_queue<std::pair<int,int>,std::vector<std::pair<int,int>>,comp> queue1;

        for(auto i : map1){
            queue1.push(i);
            if(queue1.size()>k){
                queue1.pop();
            }
        }

        std::vector<int> result(k);
        for(int i =0;i<k;i++){
            result[i] = (queue1.top().first);
            queue1.pop();
        }
        return result;
    }
};
// @lc code=end

