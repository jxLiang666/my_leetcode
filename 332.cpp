/*
 * @lc app=leetcode.cn id=332 lang=cpp
 *
 * [332] 重新安排行程
 *
 * https://leetcode.cn/problems/reconstruct-itinerary/description/
 *
 * algorithms
 * Hard (44.36%)
 * Likes:    962
 * Dislikes: 0
 * Total Accepted:    123.5K
 * Total Submissions: 279.6K
 * Testcase Example:  '[["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]'
 *
 * 给你一份航线列表 tickets ，其中 tickets[i] = [fromi, toi]
 * 表示飞机出发和降落的机场地点。请你对该行程进行重新规划排序。
 * 
 * 所有这些机票都属于一个从 JFK（肯尼迪国际机场）出发的先生，所以该行程必须从 JFK
 * 开始。如果存在多种有效的行程，请你按字典排序返回最小的行程组合。
 * 
 * 
 * 例如，行程 ["JFK", "LGA"] 与 ["JFK", "LGB"] 相比就更小，排序更靠前。
 * 
 * 
 * 假定所有机票至少存在一种合理的行程。且所有的机票 必须都用一次 且 只能用一次。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：tickets = [["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]
 * 输出：["JFK","MUC","LHR","SFO","SJC"]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：tickets =
 * [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
 * 输出：["JFK","ATL","JFK","SFO","ATL","SFO"]
 * 解释：另一种有效的行程是 ["JFK","SFO","ATL","JFK","ATL","SFO"] ，但是它字典排序更大更靠后。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * tickets[i].length == 2
 * fromi.length == 3
 * toi.length == 3
 * fromi 和 toi 由大写英文字母组成
 * fromi != toi
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <functional>
class Solution {
public:
    std::vector<std::string> findItinerary(std::vector<std::vector<std::string>>& tickets) {
        std::vector<std::string> result({"JFK"});
        std::unordered_map<std::string,std::map<std::string,int>> umap1;

        for(auto i : tickets){
            std::string from = i[0];
            std::string to2 = i[1];
            umap1[from][to2]++;
        }

        std::function<bool(void)> backtracking = [&](){
            if(result.size() == tickets.size() +1 ){
                return true;
            }
            std::string from = result.back();
            for (auto &i : umap1[from]){
                if(i.second > 0){
                    result.push_back(i.first);
                    i.second -- ;
                    if(backtracking()) return true;
                    i.second++;
                    result.pop_back();
                }
            }
            return false;
        };

        backtracking();
        return result;
    }
};
// @lc code=end

