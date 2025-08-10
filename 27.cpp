/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
#include <iostream>
#include <vector>

class Solution{
public:
    int removeElement(std::vector<int>& nums, int val) {
        int left = 0;
        int right = nums.size()-1;

        while (left <= right){
            while(left <= right && nums[left] != val){
                left++;
            }

            while(left <= right && nums[right] == val){
                right--;
            }

            if(left < right){
                std::swap(nums[left],nums[right]);
                left++;
                right--;
            }

        }
        return left;   
    }
};

// int main(){
//     auto nums = std::vector<int>({3,2,2,3});
//     int val = 3;
//     std::cout<< Solution().removeElement(nums,val);
// }
// @lc code=end

