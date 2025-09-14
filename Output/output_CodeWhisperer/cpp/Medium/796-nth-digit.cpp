/**https://leetcode.com/problems/nth-digit/ */
//Given an integer n, return the nth digit of the infinite integer sequence [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...].
// 
//Example 1:
//Input: n = 3
//Output: 3
//Example 2:
//Input: n = 11
//Output: 0
//Explanation: The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a 0, which is part of the number 10.
// 
//Constraints:
//	1 <= n <= 231 - 1
class Solution {
public:
    int findNthDigit(int n) {
        int digit = 1;
        long long count = 9;
        int start = 1;
        while (n > digit * count) {
            n -= digit * count;
            digit++;
            count *= 10;
            start *= 10;
        }
        start += (n - 1) / digit;
        string s = to_string(start);
        return s[(n - 1) % digit] - '0';     
    }
};