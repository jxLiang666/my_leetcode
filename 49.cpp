/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 *
 * https://leetcode.cn/problems/group-anagrams/description/
 *
 * algorithms
 * Medium (69.72%)
 * Likes:    2251
 * Dislikes: 0
 * Total Accepted:    1.1M
 * Total Submissions: 1.5M
 * Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
 *
 * 给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。
 * 
 * 字母异位词 是由重新排列源单词的所有字母得到的一个新单词。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
 * 输出: [["bat"],["nat","tan"],["ate","eat","tea"]]
 * 
 * 示例 2:
 * 
 * 
 * 输入: strs = [""]
 * 输出: [[""]]
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: strs = ["a"]
 * 输出: [["a"]]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= strs.length <= 10^4
 * 0 <= strs[i].length <= 100
 * strs[i] 仅包含小写字母
 * 
 * 
 */

// @lc code=start
#include<vector>
#include <vector>
#include <string>
#include <unordered_map>
#include <map>
#include <iostream>
class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::vector<std::vector<std::string>> result;
        std::multimap<int,std::pair<int,std::unordered_map<char,int>>> mmap;
        //umap 字符串长度->(<result中的位置，字符映射表>)
        for(int i = 0 ; i < strs.size();i++){
            //先构建字符映射表
            std::unordered_map<char,int> charmapping;
            for(auto &c:strs[i]){
                charmapping[c]++;
            }
            int size = strs[i].size();
            auto range = mmap.equal_range(size);
            bool flag = true;
            for(auto &it = range.first;it != range.second;++it){
                int idx = it->second.first;
                auto &um = it->second.second;
                if(charmapping == um){
                    result[idx].push_back(strs[i]);
                    flag = false;
                    break;
                }
            }
            if(flag){
                int idx = result.size();
                std::vector<std::string> cur;
                cur.push_back(strs[i]);
                result.insert(result.begin()+idx,cur);
                mmap.insert({size,{idx,charmapping}});
            } 
           
        }
        return result;


    }
};
// @lc code=end

