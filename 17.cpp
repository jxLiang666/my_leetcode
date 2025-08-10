/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 *
 * https://leetcode.cn/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (61.35%)
 * Likes:    3032
 * Dislikes: 0
 * Total Accepted:    1.1M
 * Total Submissions: 1.7M
 * Testcase Example:  '"23"'
 *
 * 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。
 * 
 * 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：digits = "23"
 * 输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：digits = ""
 * 输出：[]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：digits = "2"
 * 输出：["a","b","c"]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= digits.length <= 4
 * digits[i] 是范围 ['2', '9'] 的一个数字。
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <string>
#include <functional>
class Solution {
public:
    std::string num2letter (int i){
        switch (i)
        {
            case 2:{
                return "abc";
                break;
            }
            case 3:{
                return "def";
                break;
            }   
            case 4:{
                return "ghi";
                break;
            }
            case 5:{
                return "jkl";
                break;
            }
            case 6:{
                return "mno";
                break;
            }
            case 7:{
                return "pqrs";
                break;
            }
            case 8:{
                return "tuv";
                break;
            }   
            case 9:{
                return "wxyz";
                break;
            }
            default:
                return "";     
        }
    }
    
    std::vector<std::string> letterCombinations(std::string digits) {
        std::vector<std::string> result;
        std::string cur = "";
        std::function<void(int)> comb=[&](int idx){
            int num = digits[idx] - '0';
            std::string s = num2letter(num);
            if(idx == digits.size()-1){                                
                for( char i: s){
                    result.push_back(cur + i);
                }
                return;
            }
            for( char i: s){
                cur = cur + i;
                comb(idx+1);
                cur.erase(cur.end()-1);
            }
            return;
            
        };
        comb(0);
        return result;
        
    }
};
// @lc code=end

