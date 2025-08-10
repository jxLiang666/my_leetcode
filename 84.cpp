/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 *
 * https://leetcode.cn/problems/largest-rectangle-in-histogram/description/
 *
 * algorithms
 * Hard (46.78%)
 * Likes:    2904
 * Dislikes: 0
 * Total Accepted:    509.6K
 * Total Submissions: 1.1M
 * Testcase Example:  '[2,1,5,6,2,3]'
 *
 * 给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。
 * 
 * 求在该柱状图中，能够勾勒出来的矩形的最大面积。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 
 * 
 * 输入：heights = [2,1,5,6,2,3]
 * 输出：10
 * 解释：最大的矩形为图中红色区域，面积为 10
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 
 * 输入： heights = [2,4]
 * 输出： 4
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 0 
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <stack>
#include <limits.h>
class Solution {
public:
    int largestRectangleArea(std::vector<int>& heights) {
        std::stack<int> sta1;
        int lArea = 0;
        sta1.push(0);
        for(int idx =0;idx<heights.size();idx++){
            lArea = std::max(lArea, heights[idx]);
            while(!sta1.empty() && heights[idx] < heights[sta1.top()]){
                int height = heights[sta1.top()];
                sta1.pop();
                int width = sta1.empty() ? idx : idx - sta1.top() - 1; // 计算宽度
                lArea = std::max(lArea, height * width);
            }
            sta1.push(idx);
        }
        // 处理栈中剩余的元素
        int n = heights.size();
        while (!sta1.empty()) {
            int height = heights[sta1.top()];
            sta1.pop();
            
            // 栈为空时，宽度为数组长度；否则为数组长度减去栈顶索引再减1
            int width = sta1.empty() ? n : n - sta1.top() - 1;
            lArea = std::max(lArea, height * width);
        }
        return lArea;
    }
};
// @lc code=end

