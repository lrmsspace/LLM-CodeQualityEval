/*
 You are given two arrays nums and andValues of length n and m respectively.
 The value of an array is equal to the last element of that array.
 You have to divide nums into m disjoint contiguous subarrays such that for the ith subarray [li, ri], the bitwise AND of the subarray elements is equal to andValues[i], in other words, nums[li] & nums[li + 1] & ... & nums[ri] == andValues[i] for all 1 <= i <= m, where & represents the bitwise AND operator.
 Return the minimum possible sum of the values of the m subarrays nums is divided into. If it is not possible to divide nums into m subarrays satisfying these conditions, return -1.
 Example 1:
 Input: nums = [1,4,3,3,2], andValues = [0,3,3,2]
 Output: 12
 Explanation:
 The only possible way to divide nums is:
 [1,4] as 1 & 4 == 0.
 [3] as the bitwise AND of a single element subarray is that element itself.
 [3] as the bitwise AND of a single element subarray is that element itself.
 [2] as the bitwise AND of a single element subarray is that element itself.
 The sum of the values for these subarrays is 4 + 3 + 3 + 2 = 12.
 Example 2:
 Input: nums = [2,3,5,7,7,7,5], andValues = [0,7,5]
 Output: 17
 Explanation:
 There are three ways to divide nums:
 [[2,3,5],[7,7,7],[5]] with the sum of the values 5 + 7 + 5 == 17.
 [[2,3,5,7],[7,7],[5]] with the sum of the values 7 + 7 + 5 == 19.
 [[2,3,5,7,7],[7],[5]] with the sum of the values 7 + 7 + 5 == 19.
 The minimum possible sum of the values is 17.
 Example 3:
 Input: nums = [1,2,3,4], andValues = [2]
 Output: -1
 Explanation:
 The bitwise AND of the entire array nums is 0. As there is no possible way to divide nums into a single subarray to have the bitwise AND of elements 2, return -1.
 Constraints:
 1 <= n == nums.length <= 104
 1 <= m == andValues.length <= min(n, 10)
 1 <= nums[i] < 105
 0 <= andValues[j] < 105
*/

int minimumValueSum(int* nums, int numsSize, int* andValues, int andValuesSize) {
    // dp[i][j] represents min sum when dividing nums[0...i] into j+1 subarrays
    int dp[10001][11];
    // Initialize dp array with large value
    for(int i = 0; i < numsSize; i++) {
        for(int j = 0; j < andValuesSize; j++) {
            dp[i][j] = 1e9;
        }
    }
    
    // Calculate AND value for each possible subarray
    int and[10001][10001];
    for(int i = 0; i < numsSize; i++) {
        and[i][i] = nums[i];
        for(int j = i+1; j < numsSize; j++) {
            and[i][j] = and[i][j-1] & nums[j];
        }
    }
    
    // Base case - first subarray
    for(int i = 0; i < numsSize; i++) {
        if(and[0][i] == andValues[0]) {
            dp[i][0] = nums[i];
        }
    }
    
    // Fill dp array
    for(int j = 1; j < andValuesSize; j++) {
        for(int i = j; i < numsSize; i++) {
            for(int k = j-1; k < i; k++) {
                if(dp[k][j-1] != 1e9 && and[k+1][i] == andValues[j]) {
                    dp[i][j] = fmin(dp[i][j], dp[k][j-1] + nums[i]);
                }
            }
        }
    }
    
    // Return result
    if(dp[numsSize-1][andValuesSize-1] == 1e9) {
        return -1;
    }
    return dp[numsSize-1][andValuesSize-1];
}            
