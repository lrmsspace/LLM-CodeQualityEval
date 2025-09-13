/**https://leetcode.com/problems/3sum-closest/ */
//Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.
//Return the sum of the three integers.
//You may assume that each input would have exactly one solution.
// 
//Example 1:
//Input: nums = [-1,2,1,-4], target = 1
//Output: 2
//Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
//Example 2:
//Input: nums = [0,0,0], target = 1
//Output: 0
//Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).
// 
//Constraints:
//	3 <= nums.length <= 500
//	-1000 <= nums[i] <= 1000
//	-104 <= target <= 104
int threeSumClosest(int* nums, int numsSize, int target) {
    // Sort the array
    qsort(nums, numsSize, sizeof(int), compare);
    
    int closestSum = INT_MAX;
    int result = 0;
    
    for (int i = 0; i < numsSize - 2; i++) {
        int left = i + 1;
        int right = numsSize - 1;
        
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            
            if (abs(sum - target) < abs(closestSum - target)) {
                closestSum = sum;
                result = closestSum;
            }
            
            if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
    }
    
    return result;
    
}