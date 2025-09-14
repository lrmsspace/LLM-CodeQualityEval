/**https://leetcode.com/problems/number-of-digit-one/ */
//Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.
// 
//Example 1:
//Input: n = 13
//Output: 6
//Example 2:
//Input: n = 0
//Output: 0
// 
//Constraints:
//	0 <= n <= 109
class Solution {
    public int countDigitOne(int n) {
        // Counting number of 1s in each place value (hundreds, tens, ones)
        int ones = 0, tens = 0, hundreds = 0;
        
        // Counting number of 1s in hundreds place
        hundreds = n / 100;
        ones = (n % 10);
        tens = (n / 10) % 10;
        
        // If hundreds place is not 0, then 1s are coming from hundreds place only
        ones += hundreds;
        
        // Counting number of 1s in tens place
        ones += (tens == 1)? (n % 10) + 1 : tens * 10;
        
        // Counting number of 1s in ones place
        ones += (ones == 1)? (n % 10) + 1 : 0;
        
        return ones;
        
    }
}