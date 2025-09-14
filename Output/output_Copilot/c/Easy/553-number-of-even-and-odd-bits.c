/**https://leetcode.com/problems/number-of-even-and-odd-bits/ */
//You are given a positive integer n.
//Let even denote the number of even indices in the binary representation of n with value 1.
//Let odd denote the number of odd indices in the binary representation of n with value 1.
//Note that bits are indexed from right to left in the binary representation of a number.
//Return the array [even, odd].
// 
//Example 1:
//Input: n = 50
//Output: [1,2]
//Explanation:
//The binary representation of 50 is 110010.
//It contains 1 on indices 1, 4, and 5.
//Example 2:
//Input: n = 2
//Output: [0,1]
//Explanation:
//The binary representation of 2 is 10.
//It contains 1 only on index 1.
// 
//Constraints:
//	1 <= n <= 1000
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* evenOddBit(int n, int* returnSize) {
    int *ret = (int*)malloc(sizeof(int) * 2);
    ret[0] = ret[1] = 0;
    for (int i = 0; n; i++, n >>= 1) {
        if (n & 1) {
            if (i & 1) {
                ret[1]++;
            } else {
                ret[0]++;
            }
        }
    }
    *returnSize = 2;
    return ret;    
}