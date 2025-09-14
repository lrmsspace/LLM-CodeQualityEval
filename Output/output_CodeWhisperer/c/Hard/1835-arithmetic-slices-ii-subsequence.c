/**https://leetcode.com/problems/arithmetic-slices-ii-subsequence/ */
//Given an integer array nums, return the number of all the arithmetic subsequences of nums.
//A sequence of numbers is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.
//	For example, [1, 3, 5, 7, 9], [7, 7, 7, 7], and [3, -1, -5, -9] are arithmetic sequences.
//	For example, [1, 1, 2, 5, 7] is not an arithmetic sequence.
//A subsequence of an array is a sequence that can be formed by removing some elements (possibly none) of the array.
//	For example, [2,5,10] is a subsequence of [1,2,1,2,4,1,5,10].
//The test cases are generated so that the answer fits in 32-bit integer.
// 
//Example 1:
//Input: nums = [2,4,6,8,10]
//Output: 7
//Explanation: All arithmetic subsequence slices are:
//[2,4,6]
//[4,6,8]
//[6,8,10]
//[2,4,6,8]
//[4,6,8,10]
//[2,4,6,8,10]
//[2,6,10]
//Example 2:
//Input: nums = [7,7,7,7,7]
//Output: 16
//Explanation: Any subsequence of this array is arithmetic.
// 
//Constraints:
//	1  <= nums.length <= 1000
//	-231 <= nums[i] <= 231 - 1
int numberOfArithmeticSlices(int* nums, int numsSize) {
    int result = 0;
    int* dp = (int*)malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; i++) {
        dp[i] = (int*)malloc(sizeof(int) * numsSize);
        for (int j = 0; j < numsSize; j++) {
            dp[i][j] = 0;
        }
    }
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            long long diff = (long long)nums[j] - (long long)nums[i];
            if (diff < INT_MIN || diff > INT_MAX) {
                continue;
            }
            int diffInt = (int)diff;
            int count = 0;
            for (int k = 0; k < i; k++) {
                if (nums[i] - nums[k] == diffInt) {
                    count += dp[k][i] + 1;
                }
            }
            dp[i][j] = count;
            result += count;
        }
    }
    for (int i = 0; i < numsSize; i++) {
        free(dp[i]);
    }
    free(dp);
    return result;
    
}