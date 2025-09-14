/*
 You are given an integer array nums. Each element in nums is 1, 2 or 3. In each operation, you can remove an element from nums. Return the minimum number of operations to make nums non-decreasing.
 Example 1:
 Input: nums = [2,1,3,2,1]
 Output: 3
 Explanation:
 One of the optimal solutions is to remove nums[0], nums[2] and nums[3].
 Example 2:
 Input: nums = [1,3,2,1,3,3]
 Output: 2
 Explanation:
 One of the optimal solutions is to remove nums[1] and nums[2].
 Example 3:
 Input: nums = [2,2,2,2,3,3]
 Output: 0
 Explanation:
 nums is already non-decreasing.
 Constraints:
 1 <= nums.length <= 100
 1 <= nums[i] <= 3
 Follow-up: Can you come up with an algorithm that runs in O(n) time complexity?
*/

int minimumOperations(int* nums, int numsSize) {  
    int dp[numsSize];
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > nums[i - 1])
            dp[i] = dp[i - 1];
        for (int j = i - 2; j >= 0; j--) {
            if (nums[i] > nums[j])
                dp[i] = fmin(dp[i], dp[j] + 1);
        }
    }
    return dp[numsSize - 1];
}