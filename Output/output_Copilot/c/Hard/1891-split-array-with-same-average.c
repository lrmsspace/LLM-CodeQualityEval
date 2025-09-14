/**https://leetcode.com/problems/split-array-with-same-average/ */
//You are given an integer array nums.
//You should move each element of nums into one of the two arrays A and B such that A and B are non-empty, and average(A) == average(B).
//Return true if it is possible to achieve that and false otherwise.
//Note that for an array arr, average(arr) is the sum of all the elements of arr over the length of arr.
// 
//Example 1:
//Input: nums = [1,2,3,4,5,6,7,8]
//Output: true
//Explanation: We can split the array into [1,4,5,8] and [2,3,6,7], and both of them have an average of 4.5.
//Example 2:
//Input: nums = [3,1]
//Output: false
// 
//Constraints:
//	1 <= nums.length <= 30
//	0 <= nums[i] <= 104


        bool helper(int* nums, int numsSize, int targetSum, int count, int start, int** dp) {
            if (count == 0) return targetSum == 0;
            if (start >= numsSize || count < 0 || targetSum < 0) return false;
            if (dp[targetSum][count] != -1) return dp[targetSum][count];

            bool include = helper(nums, numsSize, targetSum - nums[start], count - 1, start + 1, dp);
            bool exclude = helper(nums, numsSize, targetSum, count, start + 1, dp);

            dp[targetSum][count] = include || exclude;
            return dp[targetSum][count];
        }

        bool splitArraySameAverage(int* nums, int numsSize) {
            int totalSum = 0;
            for (int i = 0; i < numsSize; i++) {
                totalSum += nums[i];
            }

            for (int len = 1; len <= numsSize / 2; len++) {
                if ((totalSum * len) % numsSize != 0) continue;
                int targetSum = (totalSum * len) / numsSize;

                int** dp = (int**)malloc((targetSum + 1) * sizeof(int*));
                for (int i = 0; i <= targetSum; i++) {
                    dp[i] = (int*)malloc((len + 1) * sizeof(int));
                    memset(dp[i], -1, (len + 1) * sizeof(int));
                }

                if (helper(nums, numsSize, targetSum, len, 0, dp)) {
                    for (int i = 0; i <= targetSum; i++) free(dp[i]);
                    free(dp);
                    return true;
                }

                for (int i = 0; i <= targetSum; i++) free(dp[i]);
                free(dp);
            }

            return false;
        }

            