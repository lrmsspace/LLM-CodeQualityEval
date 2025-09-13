/**https://leetcode.com/problems/find-three-consecutive-integers-that-sum-to-a-given-number/ */
//Given an integer num, return three consecutive integers (as a sorted array) that sum to num. If num cannot be expressed as the sum of three consecutive integers, return an empty array.
// 
//Example 1:
//Input: num = 33
//Output: [10,11,12]
//Explanation: 33 can be expressed as 10 + 11 + 12 = 33.
//10, 11, 12 are 3 consecutive integers, so we return [10, 11, 12].
//Example 2:
//Input: num = 4
//Output: []
//Explanation: There is no way to express 4 as the sum of 3 consecutive integers.
// 
//Constraints:
//	0 <= num <= 1015
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
long long* sumOfThree(long long num, int* returnSize) {
    long long* result = (long long*)malloc(sizeof(long long) * 3);
    *returnSize = 0;
    for (long long i = 1; i <= num / 3; i++) {
        long long sum = i + i + 1 + i + 2;
        if (sum == num) {
            result[0] = i;
            result[1] = i + 1;
            result[2] = i + 2;
            *returnSize = 3;
            return result;
        }
    }
    return result;    
}