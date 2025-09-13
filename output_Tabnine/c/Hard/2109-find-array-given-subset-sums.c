/**https://leetcode.com/problems/find-array-given-subset-sums/ */
//You are given an integer n representing the length of an unknown array that you are trying to recover. You are also given an array sums containing the values of all 2n subset sums of the unknown array (in no particular order).
//Return the array ans of length n representing the unknown array. If multiple answers exist, return any of them.
//An array sub is a subset of an array arr if sub can be obtained from arr by deleting some (possibly zero or all) elements of arr. The sum of the elements in sub is one possible subset sum of arr. The sum of an empty array is considered to be 0.
//Note: Test cases are generated such that there will always be at least one correct answer.
// 
//Example 1:
//Input: n = 3, sums = [-3,-2,-1,0,0,1,2,3]
//Output: [1,2,-3]
//Explanation: [1,2,-3] is able to achieve the given subset sums:
//- []: sum is 0
//- [1]: sum is 1
//- [2]: sum is 2
//- [1,2]: sum is 3
//- [-3]: sum is -3
//- [1,-3]: sum is -2
//- [2,-3]: sum is -1
//- [1,2,-3]: sum is 0
//Note that any permutation of [1,2,-3] and also any permutation of [-1,-2,3] will also be accepted.
//Example 2:
//Input: n = 2, sums = [0,0,0,0]
//Output: [0,0]
//Explanation: The only correct answer is [0,0].
//Example 3:
//Input: n = 4, sums = [0,0,5,5,4,-1,4,9,9,-1,4,3,4,8,3,8]
//Output: [0,-1,4,5]
//Explanation: [0,-1,4,5] is able to achieve the given subset sums.
// 
//Constraints:
//	1 <= n <= 15
//	sums.length == 2n
//	-104 <= sums[i] <= 104
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* recoverArray(int n, int* sums, int sumsSize, int* returnSize) {
    // Validate input parameters
    if (n <= 0 || sumsSize < 2 * n || sumsSize % 2!= 0) {
        *returnSize = 0;
        return NULL;
    }
    
    // Sort the sums array in ascending order
    qsort(sums, sumsSize, sizeof(int), compare);
    
    // Create a dynamic programming table to store the subset sums
    int** dp = (int**)malloc(sizeof(int*) * sumsSize);
    for (int i = 0; i < sumsSize; i++) {
        dp[i] = (int*)calloc(n + 1, sizeof(int));
    }
    
    // Initialize the first subset sum
    dp[0][0] = sums[0];
    
    // Build the dynamic programming table
    for (int i = 1; i < sumsSize; i++) {
        for (int j = 0; j <= n; j++) {
            if (dp[i - 1][j]!= 0) {
                if (j + sums[i] <= n) {
                    dp[i][j + sums[i]] = 1;
                }
                if (j - sums[i] >= 0) {
                    dp[i][j - sums[i]] = 1;
                }
            }
        }
    }
    
    // Find the subset sums that are equal to each other
    int equalSumCount = 0;
    for (int i = 1; i < sumsSize; i++) {
        if (dp[i][sums[i]] == 1) {
            equalSumCount++;
        }
    }
    
    // Allocate memory for the result array
    int* result = (int*)malloc(sizeof(int) * equalSumCount);
    int resultIndex = 0;
    
    // Find the subset sums that are equal to each other and store them in the result array
    for (int i = 1; i < sumsSize; i++) {
        if (dp[i][sums[i]] == 1) {
            result[resultIndex++] = sums[i];
        }
    }
    
    // Sort the result array in ascending order
    qsort(result, equalSumCount, sizeof(int), compare);
    
    // Store the size of the result array
    *returnSize = equalSumCount;
    
    // Return the result array
    return result;
}