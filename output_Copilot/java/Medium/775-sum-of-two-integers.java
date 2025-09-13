/**https://leetcode.com/problems/sum-of-two-integers/ */
//Given two integers a and b, return the sum of the two integers without using the operators + and -.
// 
//Example 1:
//Input: a = 1, b = 2
//Output: 3
//Example 2:
//Input: a = 2, b = 3
//Output: 5
// 
//Constraints:
//	-1000 <= a, b <= 1000
class Solution {
    public int getSum(int a, int b) {
        // Iterate till there is no carry
        while (b != 0) {
            // Carry now contains common set bits of a and b
            int carry = a & b;

            // Sum of bits of a and b where at least one of the bits is not set
            a = a ^ b;

            // Carry is shifted by one so that adding it to a gives the required sum
            b = carry << 1;
        }
        return a;        
    }
}