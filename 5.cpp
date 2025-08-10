/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 *
 * https://leetcode.cn/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (39.09%)
 * Likes:    7622
 * Dislikes: 0
 * Total Accepted:    2M
 * Total Submissions: 5M
 * Testcase Example:  '"babad"'
 *
 * 给你一个字符串 s，找到 s 中最长的 回文 子串。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "babad"
 * 输出："bab"
 * 解释："aba" 同样是符合题意的答案。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "cbbd"
 * 输出："bb"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 1000
 * s 仅由数字和英文字母组成
 * 
 * 
 */

// @lc code=start
#include <string>
#include <vector>
class Solution {
public:
    std::string longestPalindrome(std::string s) {
        std::vector<int> nxt = getNxt(s);
        // for(auto i : nxt){
        //     std::cout<<i<<" ";
        // }
        // std::cout<< std::endl;
        int maxVal  = -1;
        int maxValIdx = -1;
        for(int i =0; i < nxt.size();i++){
            if(nxt[i] > maxVal){
                maxVal = nxt[i];
                maxValIdx = i;
            }
        }
        // std::cout<< maxValIdx <<" "<<maxVal;
        std::string result;
        result.insert(0,s,maxValIdx - nxt[maxValIdx]-1,maxValIdx);
        return result;
    }
};
// @lc code=end

