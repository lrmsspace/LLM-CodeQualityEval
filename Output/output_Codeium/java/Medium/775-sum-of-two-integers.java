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
int sum = 0, carry;
while (b != 0) {
    carry = a & b;  // calculate carry
    a = a ^ b;      // calculate sum without carry
    b = carry << 1; // shift carry to the left
}
return a;

    }
}