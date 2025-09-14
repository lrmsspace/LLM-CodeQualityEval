/**https://leetcode.com/problems/count-special-quadruplets/ */
//Given a 0-indexed integer array nums, return the number of distinct quadruplets (a, b, c, d) such that:
//	nums[a] + nums[b] + nums[c] == nums[d], and
//	a < b < c < d
// 
//Example 1:
//Input: nums = [1,2,3,6]
//Output: 1
//Explanation: The only quadruplet that satisfies the requirement is (0, 1, 2, 3) because 1 + 2 + 3 == 6.
//Example 2:
//Input: nums = [3,3,6,4,5]
//Output: 0
//Explanation: There are no such quadruplets in [3,3,6,4,5].
//Example 3:
//Input: nums = [1,1,1,3,5]
//Output: 4
//Explanation: The 4 quadruplets that satisfy the requirement are:
//- (0, 1, 2, 3): 1 + 1 + 1 == 3
//- (0, 1, 3, 4): 1 + 1 + 3 == 5
//- (0, 2, 3, 4): 1 + 1 + 3 == 5
//- (1, 2, 3, 4): 1 + 1 + 3 == 5
// 
//Constraints:
//	4 <= nums.length <= 50
//	1 <= nums[i] <= 100
int countQuadruplets(int* nums, int numsSize) {
    int count = 0;
    int n = numsSize;
    
    // Sort the array
    qsort(nums, n, sizeof(int), compare);
    
    // Iterate through the array and find quadruplets
    for (int i = 0; i < n - 3; i++) {
        // Skip duplicates
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        
        // Find the two numbers that sum up to -2 * nums[i]
        int left = i + 1;
        int right = n - 1;
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == -2 * nums[i]) {
                // Count the number of distinct quadruplets
                count += right - left;
                // Skip duplicates
                while (left < right && nums[left] == nums[left + 1])
                    left++;
                while (left < right && nums[right] == nums[right - 1])
                    right--;
                left++;
                right--;
            } else if (sum < -2 * nums[i])
                left++;
            else
                right--;
        }
    }
    
    return count;
    
}