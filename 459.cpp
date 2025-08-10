/*
 * @lc app=leetcode.cn id=459 lang=cpp
 *
 * [459] 重复的子字符串
 *
 * https://leetcode.cn/problems/repeated-substring-pattern/description/
 *
 * algorithms
 * Easy (52.08%)
 * Likes:    1268
 * Dislikes: 0
 * Total Accepted:    316.8K
 * Total Submissions: 607.7K
 * Testcase Example:  '"abab"'
 *
 * 给定一个非空的字符串 s ，检查是否可以通过由它的一个子串重复多次构成。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: s = "abab"
 * 输出: true
 * 解释: 可由子串 "ab" 重复两次构成。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: s = "aba"
 * 输出: false
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: s = "abcabcabcabc"
 * 输出: true
 * 解释: 可由子串 "abc" 重复四次构成。 (或子串 "abcabc" 重复两次构成。)
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 
 * 
 * 1 <= s.length <= 10^4
 * s 由小写英文字母组成
 * 
 * 
 */

// @lc code=start
#include <string>
#include <iostream>
#include <vector>
class Solution {
public:
    std::vector<int> getNext(const std::string &s){
        std::vector<int> next(s.size(),0);
        for(int i =1,j =0;i<s.size();i++){
            while(j>0 && s[i] != s[j]){
                j = next[j-1];
            }
            if(s[i] == s[j]){
                j++;
            }
            next[i] = j;
        }
        return next;
    }

    bool repeatedSubstringPattern(std::string s) {
        std::vector<int> next(s.size(),0);
        next = getNext(s);
        int len = next[s.size()-1];
        return (len>0 && s.size()%(s.size()-len)==0);
    }
};
// @lc code=end

