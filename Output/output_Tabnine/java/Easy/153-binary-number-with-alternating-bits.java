/**https://leetcode.com/problems/binary-number-with-alternating-bits/ */
//Given a positive integer, check whether it has alternating bits: namely, if two adjacent bits will always have different values.
// 
//Example 1:
//Input: n = 5
//Output: true
//Explanation: The binary representation of 5 is: 101
//Example 2:
//Input: n = 7
//Output: false
//Explanation: The binary representation of 7 is: 111.
//Example 3:
//Input: n = 11
//Output: false
//Explanation: The binary representation of 11 is: 1011.
// 
//Constraints:
//	1 <= n <= 231 - 1
class Solution {
    public boolean hasAlternatingBits(int n) {
        int prevBit = n & 1; // Get the least significant bit
        n >>= 1; // Shift the bits to the right to ignore the least significant bit
        while (n!= 0) {
            int currentBit = n & 1; // Get the least significant bit
            if (currentBit == prevBit) {
                return false; // If the current bit is the same as the previous bit, return false
            }
            prevBit = currentBit; // Update the previous bit
            n >>= 1; // Shift the bits to the right to ignore the least significant bit
        }
        return true; // If all bits have alternated, return true
        
    }
}