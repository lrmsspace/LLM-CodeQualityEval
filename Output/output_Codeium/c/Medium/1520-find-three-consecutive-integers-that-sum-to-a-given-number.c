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
    
    long long* res = (long long*)malloc(3 * sizeof(long long));
    if (num % 3 == 0) {
        res[0] = num / 3 - 1;
        res[1] = num / 3;
        res[2] = num / 3 + 1;
        *returnSize = 3;
        return res;
    }
    *returnSize = 0;
    return res;
}
