/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 *
 * https://leetcode.cn/problems/find-all-anagrams-in-a-string/description/
 *
 * algorithms
 * Medium (54.01%)
 * Likes:    1666
 * Dislikes: 0
 * Total Accepted:    675.2K
 * Total Submissions: 1.2M
 * Testcase Example:  '"cbaebabacd"\n"abc"'
 *
 * 给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: s = "cbaebabacd", p = "abc"
 * 输出: [0,6]
 * 解释:
 * 起始索引等于 0 的子串是 "cba", 它是 "abc" 的异位词。
 * 起始索引等于 6 的子串是 "bac", 它是 "abc" 的异位词。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: s = "abab", p = "ab"
 * 输出: [0,1,2]
 * 解释:
 * 起始索引等于 0 的子串是 "ab", 它是 "ab" 的异位词。
 * 起始索引等于 1 的子串是 "ba", 它是 "ab" 的异位词。
 * 起始索引等于 2 的子串是 "ab", 它是 "ab" 的异位词。
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 <= s.length, p.length <= 3 * 10^4
 * s 和 p 仅包含小写字母
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <unordered_map>
class Solution {
public:
    std::vector<int> findAnagrams(std::string s, std::string p) {
        std::vector<int> result;
        if (s.size() < p.size()) return result;

        std::vector<int> countP(26, 0), countS(26, 0);
        int size = p.size();

        for (char c : p) countP[c - 'a']++;
        for (int i = 0; i < s.size(); ++i) {
            countS[s[i] - 'a']++; // 添加当前字符

            if (i >= size) {
                countS[s[i - size] - 'a']--; // 移除窗口左边的字符
            }

            if (countS == countP) {
                result.push_back(i - size + 1);
            }
        }

        return result;
    }

};
// @lc code=end

