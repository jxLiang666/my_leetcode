/*
 * @lc app=leetcode.cn id=1496 lang=cpp
 *
 * [1496] 判断路径是否相交
 *
 * https://leetcode.cn/problems/path-crossing/description/
 *
 * algorithms
 * Easy (54.70%)
 * Likes:    62
 * Dislikes: 0
 * Total Accepted:    20.5K
 * Total Submissions: 37.5K
 * Testcase Example:  '"NES"'
 *
 * 给你一个字符串 path，其中 path[i] 的值可以是 'N'、'S'、'E' 或者 'W'，分别表示向北、向南、向东、向西移动一个单位。
 * 
 * 你从二维平面上的原点 (0, 0) 处开始出发，按 path 所指示的路径行走。
 * 
 * 如果路径在任何位置上与自身相交，也就是走到之前已经走过的位置，请返回 true ；否则，返回 false 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入：path = "NES"
 * 输出：false 
 * 解释：该路径没有在任何位置相交。
 * 
 * 示例 2：
 * 
 * 
 * 
 * 
 * 输入：path = "NESWW"
 * 输出：true
 * 解释：该路径经过原点两次。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= path.length <= 10^4
 * path[i] 为 'N'、'S'、'E' 或 'W'
 * 
 * 
 */

// @lc code=start
#include <string>
#include <unordered_map>
class Solution {
private:
    std::pair<int,int> go(int x, int y, char c){
        switch (c)
        {
        case 'N':
            y++;
            break;
        
        case 'S':
            y--;
            break;
        case 'E':
            x++;
            break;
        case 'W':
            x--;
            break;
        default:
            break;
        }
        return std::make_pair(x,y);
    }
public:
    bool isPathCrossing(std::string path) {
        std::unordered_map<std::string,int> um;
        int x = 0 , y = 0;
        std::string location;
        um["0-0"]=1;
        for(int i =0 ; i < path.size();i++){
            auto [xn,yn] = go(x,y,path[i]);
            x=xn;
            y=yn;
            location=std::to_string(x)+'-'+std::to_string(y);
            std::cout<<um.hash_function()(location)<<std::endl;
            std::cout<<location<<std::endl;
            um[location]++;
            if(um[location]>1){
                return true;
            }
        }   
        return false;
    }
};
// @lc code=end

