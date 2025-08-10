/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 *
 * https://leetcode.cn/problems/reverse-string-ii/description/
 *
 * algorithms
 * Easy (58.10%)
 * Likes:    662
 * Dislikes: 0
 * Total Accepted:    355K
 * Total Submissions: 610.6K
 * Testcase Example:  '"abcdefg"\n2'
 *
 * 给定一个字符串 s 和一个整数 k，从字符串开头算起，每计数至 2k 个字符，就反转这 2k 字符中的前 k 个字符。
 * 
 * 
 * 如果剩余字符少于 k 个，则将剩余字符全部反转。
 * 如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "abcdefg", k = 2
 * 输出："bacdfeg"
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "abcd", k = 2
 * 输出："bacd"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 10^4
 * s 仅由小写英文组成
 * 1 <= k <= 10^4
 * 
 * 
 */

 #include <string>
 #include <algorithm>
// @lc code=start
class Solution {
public:
    void reverseString(std::string &s, int left, int right){
        // while(right>left){
        //     std::swap(s[left++],s[right--]);
        // }
        reverse(s.begin()+left,s.begin()+right+1);
    }
    
    std::string reverseStr(std::string s, int k) {
        int length = s.size();
        int index =0;
        int restLength = length;
        while(restLength>=2*k){
            reverseString(s,index,index+k-1);
            index +=2*k;
            restLength = length - index; 
        }
        
        if(restLength<k){
            reverseString(s,index,length-1);
        }
        else if(restLength < 2*k){
            reverseString(s,index,index+k-1);
        }
        return s;
    }
};
// @lc code=end

