/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 找出字符串中第一个匹配项的下标
 *
 * https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/description/
 *
 * algorithms
 * Easy (44.55%)
 * Likes:    2360
 * Dislikes: 0
 * Total Accepted:    1.2M
 * Total Submissions: 2.7M
 * Testcase Example:  '"sadbutsad"\n"sad"'
 *
 * 给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串的第一个匹配项的下标（下标从 0
 * 开始）。如果 needle 不是 haystack 的一部分，则返回  -1 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：haystack = "sadbutsad", needle = "sad"
 * 输出：0
 * 解释："sad" 在下标 0 和 6 处匹配。
 * 第一个匹配项的下标是 0 ，所以返回 0 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：haystack = "leetcode", needle = "leeto"
 * 输出：-1
 * 解释："leeto" 没有在 "leetcode" 中出现，所以返回 -1 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= haystack.length, needle.length <= 10^4
 * haystack 和 needle 仅由小写英文字符组成
 * 
 * 
 */
#include <iostream>
#include <string>
#include <vector>
// @lc code=start
class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        std::vector<int> next = getNext(needle);
        int j =0;
        int m = needle.size();
        for(int i = 0; i < haystack.size();i++){
            while(j>0 && haystack[i] != needle[j]){
                j=next[j-1];
            }
            if(haystack[i] == needle[j]){
                j++;
            }
            if(j==m){
                return i-m+1;
            }
        }
        return -1;
    }

    std::vector<int> getNext(std::string needle){
        std::vector<int> next(needle.size(),0);
        int j =0;
        next[0] =0;
        for(int i =1;i<needle.size();i++){
            while(j>0 && needle[i] != needle[j]){
                j = next[j-1];
            }

            if(needle[i] == needle[j]){
                j++;
            }
            next[i] = j;
        }
        return next;
    }
};
// @lc code=end

