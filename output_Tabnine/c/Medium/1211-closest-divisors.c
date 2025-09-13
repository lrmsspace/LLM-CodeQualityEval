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
    int* result = (int*)malloc(2 * sizeof(int));
    int closest1 = num + 1;
    int closest2 = num + 2;
    int closest1Divisor = closest1;
    int closest2Divisor = closest2;
    
    // Find closest divisors for num + 1
    for (int i = 2; i * i <= closest1; i++) {
        if (closest1 % i == 0) {
            if (closest1 / i == i) {
                closest1Divisor = i;
            } else {
                closest1Divisor = closest1 / i;
            }
        }
    }
    
    // Find closest divisors for num + 2
    for (int i = 2; i * i <= closest2; i++) {
        if (closest2 % i == 0) {
            if (closest2 / i == i) {
                closest2Divisor = i;
            } else {
                closest2Divisor = closest2 / i;
            }
        }
    }
    
    result[0] = closest1Divisor;
    result[1] = closest2Divisor;
    *returnSize = 2;
    return result;
    
}