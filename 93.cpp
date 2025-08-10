/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 *
 * https://leetcode.cn/problems/restore-ip-addresses/description/
 *
 * algorithms
 * Medium (60.79%)
 * Likes:    1493
 * Dislikes: 0
 * Total Accepted:    492.8K
 * Total Submissions: 808.1K
 * Testcase Example:  '"25525511135"'
 *
 * 有效 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。
 * 
 * 
 * 例如："0.1.2.201" 和 "192.168.1.1" 是 有效 IP 地址，但是 "0.011.255.245"、"192.168.1.312"
 * 和 "192.168@1.1" 是 无效 IP 地址。
 * 
 * 
 * 给定一个只包含数字的字符串 s ，用以表示一个 IP 地址，返回所有可能的有效 IP 地址，这些地址可以通过在 s 中插入 '.' 来形成。你 不能
 * 重新排序或删除 s 中的任何数字。你可以按 任何 顺序返回答案。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "25525511135"
 * 输出：["255.255.11.135","255.255.111.35"]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "0000"
 * 输出：["0.0.0.0"]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：s = "101023"
 * 输出：["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 20
 * s 仅由数字组成
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <string>
#include <functional>
class Solution {
public:
    bool isIPok(const std::string &ip){
        if((ip[0] == '0' && ip.size() > 1) || ip.size() > 3){
            return false;
        }
        int ipaddress = std::stoi(ip);
        if(ipaddress>-1 && ipaddress <256){
            return true;
        }
        return false;
    }

    std::vector<std::string> restoreIpAddresses(std::string s) {
        std::vector<std::string>  result;
        std::string cur;
        int num =0;

        std::function<void(int)> backtracking = [&](int idx) -> void {
            // 如果已经形成了4段并且使用了所有字符
            if (num == 4 && idx == s.size()) {
                // 移除最后一个点
                cur.resize(cur.size() - 1);
                result.push_back(cur);
                return;
            }

            if (num >= 4 || idx >= s.size()) {
                return;
            }
            int originalLength = cur.size();
            for(int i =1;i < 4 && idx + i < s.size() + 1;i++){
                std::string segment = s.substr(idx, i);
                if(isIPok(segment)){
                    cur  = cur + segment + '.';
                    num++;
                    backtracking(idx+i);
                    num--;
                    cur.resize(originalLength);
                }

            }
        };

        backtracking(0);
        return result;
    }
};
// @lc code=end

