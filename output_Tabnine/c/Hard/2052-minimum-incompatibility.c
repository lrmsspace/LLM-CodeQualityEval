/**https://leetcode.com/problems/minimum-incompatibility/ */
//You are given an integer array nums​​​ and an integer k. You are asked to distribute this array into k subsets of equal size such that there are no two equal elements in the same subset.
//A subset's incompatibility is the difference between the maximum and minimum elements in that array.
//Return the minimum possible sum of incompatibilities of the k subsets after distributing the array optimally, or return -1 if it is not possible.
//A subset is a group integers that appear in the array with no particular order.
// 
//Example 1:
//Input: nums = [1,2,1,4], k = 2
//Output: 4
//Explanation: The optimal distribution of subsets is [1,2] and [1,4].
//The incompatibility is (2-1) + (4-1) = 4.
//Note that [1,1] and [2,4] would result in a smaller sum, but the first subset contains 2 equal elements.
//Example 2:
//Input: nums = [6,3,8,1,3,1,2,2], k = 4
//Output: 6
//Explanation: The optimal distribution of subsets is [1,2], [2,3], [6,8], and [1,3].
//The incompatibility is (2-1) + (3-2) + (8-6) + (3-1) = 6.
//Example 3:
//Input: nums = [5,3,3,6,3,3], k = 3
//Output: -1
//Explanation: It is impossible to distribute nums into 3 subsets where no two elements are equal in the same subset.
// 
//Constraints:
//	1 <= k <= nums.length <= 16
//	nums.length is divisible by k
//	1 <= nums[i] <= nums.length
int minimumIncompatibility(int* nums, int numsSize, int k) {
    int n = numsSize;
    int* freq = (int*)calloc(n + 1, sizeof(int));
    int* dp = (int*)calloc(1 << n, sizeof(int));
    int* subset = (int*)calloc(n, sizeof(int));
    int* subset_size = (int*)calloc(k, sizeof(int));
    int* subset_max = (int*)calloc(k, sizeof(int));
    int* subset_min = (int*)calloc(k, sizeof(int));
    
    // Count frequency of each number
    for (int i = 0; i < n; ++i) {
        freq[nums[i]]++;
    }
    
    // Generate all possible subsets
    int mask = 0;
    for (int i = 0; i < n; ++i) {
        mask |= (1 << i);
        subset_size[0]++;
        subset_max[0] = max(subset_max[0], nums[i]);
        subset_min[0] = min(subset_min[0], nums[i]);
        
        for (int j = 1; j < k; ++j) {
            if (subset_size[j - 1] + subset_size[j] <= n) {
                subset_size[j]++;
                subset_max[j] = max(subset_max[j], nums[i]);
                subset_min[j] = min(subset_min[j], nums[i]);
            }
        }
        
        // Backtrack
        mask ^= (1 << i);
        subset_size[0]--;
        subset_max[0] = nums[i];
        subset_min[0] = nums[i];
    }
    
    // Calculate dp[mask]
    for (int i = 1; i < (1 << n); ++i) {
        int max_incompatibility = 0;
        int min_incompatibility = INT_MAX;
        
        for (int j = 0; j < n; ++j) {
            if ((i & (1 << j))!= 0) {
                max_incompatibility = max(max_incompatibility, nums[j]);
                min_incompatibility = min(min_incompatibility, nums[j]);
            }
        }
        
        dp[i] = max_incompatibility - min_incompatibility;
    }
    
    // Find the minimum possible sum of incompatibilities
    int min_sum = INT_MAX;
    for (int i = 0; i < (1 << n); ++i) {
        if (subset_size[i] == k) {
            min_sum = min(min_sum, dp[i]);
        }
    }
    
    free(freq);
    free(dp);
    free(subset);
    free(subset_size);
    free(subset_max);
    free(subset_min);
    
    return min_sum == INT_MAX? -1 : min_sum;
}