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
    int* res = (int*)malloc(sizeof(int) * 2);
    *returnSize = 2;
    int* res1 = (int*)malloc(sizeof(int) * 2);
    int* res2 = (int*)malloc(sizeof(int) * 2);
    int num1 = num + 1;
    int num2 = num + 2;
    int diff1 = num1 - num2;
    int diff2 = num2 - num1;
    int i = 1;
    int j = sqrt(num1);
    int k = sqrt(num2);
    for (; i <= j; i++) {
        if (num1 % i == 0) {
            j = num1 / i;
            res1[0] = i;
            res1[1] = j;
        }
    }
    for (; i <= k; i++) {
        if (num2 % i == 0) {
            k = num2 / i;
            res2[0] = i;
            res2[1] = k;
        }
    }
    if (diff1 < diff2) {
        res[0] = res1[0];
        res[1] = res1[1];
    } else {
        res[0] = res2[0];
        res[1] = res2[1];
    }
    return res;    
}