/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 *
 * https://leetcode.cn/problems/remove-all-adjacent-duplicates-in-string/description/
 *
 * algorithms
 * Easy (73.25%)
 * Likes:    683
 * Dislikes: 0
 * Total Accepted:    369.6K
 * Total Submissions: 503.6K
 * Testcase Example:  '"abbaca"'
 *
 * 给出由小写字母组成的字符串 s，重复项删除操作会选择两个相邻且相同的字母，并删除它们。
 * 
 * 在 s 上反复执行重复项删除操作，直到无法继续删除。
 * 
 * 在完成所有重复项删除操作后返回最终的字符串。答案保证唯一。
 * 
 * 
 * 
 * 示例：
 * 
 * 
 * 输入："abbaca"
 * 输出："ca"
 * 解释：
 * 例如，在 "abbaca" 中，我们可以删除 "bb" 由于两字母相邻且相同，这是此时唯一可以执行删除操作的重复项。之后我们得到字符串
 * "aaca"，其中又只有 "aa" 可以执行重复项删除操作，所以最后的字符串为 "ca"。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 10^5
 * s 仅由小写英文字母组成。
 * 
 * 
 */

// @lc code=start
#include <string>
class Solution {
public:
    std::string removeDuplicates(std::string s) {
        for(auto it = s.begin();it < s.end();){
            if(it+1 < s.end() && *it == *(it+1)){
                it = s.erase(it);
                it = s.erase(it);
                if(it != s.begin()) it--;
            }
            else{
                it++;
            }
        }
        return s;
    }
};
// @lc code=end

