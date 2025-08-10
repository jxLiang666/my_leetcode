/*
 * @lc app=leetcode.cn id=400 lang=cpp
 *
 * [400] 第 N 位数字
 *
 * https://leetcode.cn/problems/nth-digit/description/
 *
 * algorithms
 * Medium (45.63%)
 * Likes:    424
 * Dislikes: 0
 * Total Accepted:    68.2K
 * Total Submissions: 149.5K
 * Testcase Example:  '3'
 *
 * 给你一个整数 n ，请你在无限的整数序列 [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...] 中找出并返回第 n
 * 位上的数字。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 3
 * 输出：3
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 11
 * 输出：0
 * 解释：第 11 位数字在序列 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... 里是 0 ，它是 10 的一部分。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n <= 2^31 - 1
 * 
 * 
 */

// @lc code=start
/*
n = 29  -> (20) 10 11 12 13 14 15 16 17 18 19 
i=2
total = 189
func(1) = 9
func(2) = 180
第几个数(n - (total - func(i)))/i = 10
(total - func(i)) + 10
(n - (total - func(i)))%i = 0


1-9 共9个数字 一共 9*10^(1-1)*1 位 9 
10-99 共90个数字 一共9*10^(2-1)*2 位 180
100-999 共900个数字 一共900*3位 1800
*/
#include <math.h>
#include <iostream>
#include <string>
class Solution {
public:
    int findNthDigit(int n) {
        if (n < 10) return n;
        
        long long d = 1;
        long long dtotal = 9;
        long long start = 1;
        
        while (n > d * dtotal) {
            n -= d * dtotal;
            d++;
            start *= 10;
            dtotal = 9 * start * d;
        }

        int digit = n %d;
        int index = n / d;
        
        if(digit == 0){
            std::cout<<"1 n:"<<n<<" digit:"<<digit<<" index:"<<index<<" start:"<<start<<std::endl;
            return (start+index-1)%10;
        }
        else{
            std::cout<<"2 n:"<<n<<" digit:"<<digit<<" index:"<<index<<" start:"<<start<<std::endl;
            return std::to_string(start+index)[digit-1] - '0';
        }
        
        
    }
};
// @lc code=end

