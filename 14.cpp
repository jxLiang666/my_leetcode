/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 *
 * https://leetcode.cn/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (44.59%)
 * Likes:    3311
 * Dislikes: 0
 * Total Accepted:    1.5M
 * Total Submissions: 3.3M
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * 编写一个函数来查找字符串数组中的最长公共前缀。
 * 
 * 如果不存在公共前缀，返回空字符串 ""。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：strs = ["flower","flow","flight"]
 * 输出："fl"
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：strs = ["dog","racecar","car"]
 * 输出：""
 * 解释：输入不存在公共前缀。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= strs.length <= 200
 * 0 <= strs[i].length <= 200
 * strs[i] 如果非空，则仅由小写英文字母组成
 * 
 * 
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        std::string prefix(strs[0]);

        for(int i =1;i<strs.size();i++){
            int len = std::min(prefix.size(),strs[i].size());
            int j = 0;
            for(;j < len;j++){
                if(prefix[j] != strs[i][j]){
                    break;
                }
            }
            prefix = prefix.substr(0,j);
        }
        return prefix;
    }
};
// @lc code=end

