/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 *
 * https://leetcode.cn/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (40.66%)
 * Likes:    10738
 * Dislikes: 0
 * Total Accepted:    3.4M
 * Total Submissions: 8.3M
 * Testcase Example:  '"abcabcbb"'
 *
 * 给定一个字符串 s ，请你找出其中不含有重复字符的 最长 子串 的长度。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: s = "abcabcbb"
 * 输出: 3 
 * 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: s = "bbbbb"
 * 输出: 1
 * 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: s = "pwwkew"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
 * 请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= s.length <= 5 * 10^4
 * s 由英文字母、数字、符号和空格组成
 * 
 * 
 */

// @lc code=start
#include <string>
#include <unordered_map>
class Solution {
public:
    // int lengthOfLongestSubstring(std::string s) {
    //     std::unordered_map<char, int> umap1;
    //     int maxLen = 0;
    //     int left = 0;  // 滑动窗口左边界

    //     for (int right = 0; right < s.size(); right++) {
    //         if (umap1.find(s[right]) != umap1.end() && umap1[s[right]] >= left) {
    //             left = umap1[s[right]] + 1;  // 更新窗口左边界
    //         }

    //         umap1[s[right]] = right;  // 更新哈希表中的位置
    //         maxLen = std::max(maxLen, right - left + 1);  // 更新最大长度
    //     }

    //     return maxLen;
    // }
    int lengthOfLongestSubstring(std::string s) {
        std::unordered_map<char,int> um;
        int maxLength =0;
        int left = 0;
        for(int i = 0 ; i < s.size();i++){
            if(um.find(s[i]) != um.end() && um[s[i]] >= left){
                left = um[s[i]]+1;
            }
            um[s[i]] = i;
            maxLength = std::max(maxLength, i - left +  1);
        }
        return maxLength;
    }
};
// @lc code=end

