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
int addDigits(int num) {
    return (num - 1) % 9 + 1; // If num is 0, return 0, otherwise, return the remainder when subtracting 1 from num and then taking the modulo 9. This reduces the number of arithmetic operations and ensures the result is in the range [1, 9].
}