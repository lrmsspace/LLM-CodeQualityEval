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
        long long start = 1, end = 9;
        
        while (n > 0) {
            long long count = end - start + 1;
            if (n <= count) {
                int place = n % (int)pow(10, digit - 1);
                int pos = (start - 1) + place;
                int num = (int)(pos / digit);
                int remain = pos % digit;
                return num % 10;
            }
            n -= count;
            start = end + 1;
            end = end * 10 + 9;
            digit++;
        }
        return 0;  // This line should never be reached, but added for completeness.
        
    }
};