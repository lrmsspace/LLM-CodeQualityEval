/**https://leetcode.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers/ */
//No-Zero integer is a positive integer that does not contain any 0 in its decimal representation.
//Given an integer n, return a list of two integers [a, b] where:
//	a and b are No-Zero integers.
//	a + b = n
//The test cases are generated so that there is at least one valid solution. If there are many valid solutions, you can return any of them.
// 
//Example 1:
//Input: n = 2
//Output: [1,1]
//Explanation: Let a = 1 and b = 1.
//Both a and b are no-zero integers, and a + b = 2 = n.
//Example 2:
//Input: n = 11
//Output: [2,9]
//Explanation: Let a = 2 and b = 9.
//Both a and b are no-zero integers, and a + b = 11 = n.
//Note that there are other valid answers as [8, 3] that can be accepted.
// 
//Constraints:
//	2 <= n <= 104
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getNoZeroIntegers(int n, int* returnSize) {
    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;
    
    int a = 1;
    while (a <= n) {
        int b = n - a;
        if (hasNoZero(a) && hasNoZero(b)) {
            result[0] = a;
            result[1] = b;
            break;
        }
        a++;
    }
    
    return result;
    
}