/**https://leetcode.com/problems/add-digits/ */
//Given an integer num, repeatedly add all its digits until the result has only one digit, and return it.
// 
//Example 1:
//Input: num = 38
//Output: 2
//Explanation: The process is
//38 --> 3 + 8 --> 11
//11 --> 1 + 1 --> 2 
//Since 2 has only one digit, return it.
//Example 2:
//Input: num = 0
//Output: 0
// 
//Constraints:
//	0 <= num <= 231 - 1
// 
//Follow up: Could you do it without any loop/recursion in O(1) runtime?
class Solution {
public:
    int addDigits(int num) {
        return num - (num / 9) * 9; // Equivalent to (num - 1) % 9 + 1, but avoids division by 9
        // The number of times the last digit (9) repeats in a cycle is 9.
        // Subtracting 1 from the number and performing modulus 9 gives us the last digit.
        // Adding 1 ensures that the result is always a single digit.
        
    }
};