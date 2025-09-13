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
    int* ret = malloc(sizeof(int) * 2);
    *returnSize = 2;
    int even = 0, odd = 0;
    int i = 0;
    while (n > 0) {
        if (n % 2 == 1) {
            if (i % 2 == 0) {
                even++;
            } else {
                odd++;
            }
        }
        n /= 2;
        i++;
    }
    ret[0] = even;
    ret[1] = odd;
    return ret;
    
}