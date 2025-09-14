/**https://leetcode.com/problems/closest-divisors/ */
//Given an integer num, find the closest two integers in absolute difference whose product equals num + 1 or num + 2.
//Return the two integers in any order.
// 
//Example 1:
//Input: num = 8
//Output: [3,3]
//Explanation: For num + 1 = 9, the closest divisors are 3 & 3, for num + 2 = 10, the closest divisors are 2 & 5, hence 3 & 3 is chosen.
//Example 2:
//Input: num = 123
//Output: [5,25]
//Example 3:
//Input: num = 999
//Output: [40,25]
// 
//Constraints:
//	1 <= num <= 10^9
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* closestDivisors(int num, int* returnSize) {
    int a = (int)sqrt(num + 1);
    int b = (int)sqrt(num + 2);
    if (a * a == num + 1 && a <= b) {
        *returnSize = 2;
        int* ret = (int*)malloc(2 * sizeof(int));
        ret[0] = a;
        ret[1] = a;
        return ret;
    }
    if (b * b == num + 2 && b <= a) {
        *returnSize = 2;
        int* ret = (int*)malloc(2 * sizeof(int));
        ret[0] = b;
        ret[1] = b;
        return ret;
    }
    if (a * a == num + 1) {
        *returnSize = 2;
        int* ret = (int*)malloc(2 * sizeof(int));
        ret[0] = a;
        ret[1] = b;
        return ret;
    }
    if (b * b == num + 2) {
        *returnSize = 2;
        int* ret = (int*)malloc(2 * sizeof(int));
        ret[0] = a;
        ret[1] = b;
        return ret;
    }
    *returnSize = 2;
    int* ret = (int*)malloc(2 * sizeof(int));
    ret[0] = a;
    ret[1] = a; 
    return ret; 
    
}