/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 *
 * https://leetcode.cn/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (51.31%)
 * Likes:    2561
 * Dislikes: 0
 * Total Accepted:    1.2M
 * Total Submissions: 2.2M
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * 以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi]
 * 。请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
 * 输出：[[1,6],[8,10],[15,18]]
 * 解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：intervals = [[1,4],[4,5]]
 * 输出：[[1,5]]
 * 解释：区间 [1,4] 和 [4,5] 可被视为重叠区间。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= intervals.length <= 10^4
 * intervals[i].length == 2
 * 0 <= starti <= endi <= 10^4
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <algorithm>
#include <iostream>
class Solution {
private:
    void showvec(std::vector<std::vector<int>>& interval){
        for(auto &a:interval){
            std::cout<<"("<<a[0]<<','<<a[1]<<")"<<std::endl;
        }
    }
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        std::vector<std::vector<int>> result;
        std::sort(intervals.begin(),intervals.end(),[](std::vector<int> &a,std::vector<int> &b){return a[0]<b[0];});
        for(int i = 0 ; i < intervals.size()-1;i++){
            int left = intervals[i][0];
            int right = intervals[i][1];

            int nleft = intervals[i+1][0];
            int nright = intervals[i+1][1];

            if(right<nleft){
                result.push_back(intervals[i]);
            }
            else if(right>= nleft){
                right = std::max(right,nright);
                intervals[i+1][0] = left;
                intervals[i+1][1] = right;
            }
        }
        result.push_back(intervals.back());
        return result;
    }
};
// @lc code=end

