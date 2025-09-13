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
class Solution {
public:
    // Helper function to calculate bitwise AND of subarray
    int getAnd(vector<int>& nums, int start, int end) {
        int res = nums[start];
        for(int i = start + 1; i <= end; i++) {
            res &= nums[i];
        }
        return res;
    }
    
    int minimumValueSum(vector<int>& nums, vector<int>& andValues) {
        int n = nums.size();
        int m = andValues.size();
        
        // dp[i][j] represents min sum when first i elements divided into j subarrays
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MAX));
        dp[0][0] = 0;
        
        // For each position
        for(int i = 1; i <= n; i++) {
            // For each number of subarrays
            for(int j = 1; j <= min(i, m); j++) {
                // Try different lengths of last subarray
                for(int k = j - 1; k < i; k++) {
                    // Check if bitwise AND matches required value
                    if(getAnd(nums, k, i-1) == andValues[j-1]) {
                        // If previous state is reachable
                        if(dp[k][j-1] != INT_MAX) {
                            // Update min sum
                            dp[i][j] = min(dp[i][j], dp[k][j-1] + nums[i-1]);
                        }
                    }
                }
            }
        }
        
        return dp[n][m] == INT_MAX ? -1 : dp[n][m];
    }
};      