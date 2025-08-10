/*
 * @lc app=leetcode.cn id=44 lang=cpp
 *
 * [44] 通配符匹配
 *
 * https://leetcode.cn/problems/wildcard-matching/description/
 *
 * algorithms
 * Hard (34.25%)
 * Likes:    1195
 * Dislikes: 0
 * Total Accepted:    168.8K
 * Total Submissions: 492.7K
 * Testcase Example:  '"aa"\n"a"'
 *
 * 给你一个输入字符串 (s) 和一个字符模式 (p) ，请你实现一个支持 '?' 和 '*' 匹配规则的通配符匹配：
 * 
 * 
 * '?' 可以匹配任何单个字符。
 * '*' 可以匹配任意字符序列（包括空字符序列）。
 * 
 * 
 * 
 * 
 * 判定匹配成功的充要条件是：字符模式必须能够 完全匹配 输入字符串（而不是部分匹配）。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "aa", p = "a"
 * 输出：false
 * 解释："a" 无法匹配 "aa" 整个字符串。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "aa", p = "*"
 * 输出：true
 * 解释：'*' 可以匹配任意字符串。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：s = "cb", p = "?a"
 * 输出：false
 * 解释：'?' 可以匹配 'c', 但第二个 'a' 无法匹配 'b'。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= s.length, p.length <= 2000
 * s 仅由小写英文字母组成
 * p 仅由小写英文字母、'?' 或 '*' 组成
 * 
 * 
 */
#include <string>
#include <iostream>
// @lc code=start
class Solution {
public:
    bool isMatch(std::string s, std::string p) {
        int sidx = 0;
        int pidx =0;
        int staridx =-1;
        int smatch =0;
        int slen = s.size();
        int plen = p.size();

        while(sidx < slen){
            if(s[sidx] == p[pidx] || p[pidx] =='?'){
                sidx++;
                pidx++;
            }

            else if(pidx < plen && p[pidx] == '*'){
                staridx = pidx;//记录star的位置,开始从s中找对应pidx下一个的匹配位置
                smatch = sidx;
                pidx++;
            }

            else if(staridx != -1){
                pidx = staridx +1;
                sidx = ++smatch;
            }

            else return false;
        }

        while (pidx < plen && p[pidx] == '*') {
            pidx++;
        }

        return pidx == plen;
    }   
};
// @lc code=end

