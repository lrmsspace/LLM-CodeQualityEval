/**https://leetcode.com/problems/find-k-th-smallest-pair-distance/ */
//The distance of a pair of integers a and b is defined as the absolute difference between a and b.
//Given an integer array nums and an integer k, return the kth smallest distance among all the pairs nums[i] and nums[j] where 0 <= i < j < nums.length.
// 
//Example 1:
//Input: nums = [1,3,1], k = 1
//Output: 0
//Explanation: Here are all the pairs:
//(1,3) -> 2
//(1,1) -> 0
//(3,1) -> 2
//Then the 1st smallest distance pair is (1,1), and its distance is 0.
//Example 2:
//Input: nums = [1,1,1], k = 2
//Output: 0
//Example 3:
//Input: nums = [1,6,1], k = 3
//Output: 5
// 
//Constraints:
//	n == nums.length
//	2 <= n <= 104
//	0 <= nums[i] <= 106
//	1 <= k <= n * (n - 1) / 2
int smallestDistancePair(int* nums, int numsSize, int k) {
    int n = numsSize;
    // Sort the array
    qsort(nums, n, sizeof(int), compare);
    // Initialize the minimum distance to be the maximum possible value
    int minDist = INT_MAX;
    // Initialize two pointers, one at the beginning of the array and the other at the end
    int left = 0, right = n - 1;
    // While there are still pairs to compare
    while (left < right) {
        // Calculate the current distance
        int dist = nums[right] - nums[left];
        // Update the minimum distance if necessary
        minDist = min(minDist, dist);
        // If the sum of the current pair is less than or equal to k, move the left pointer to the right
        if (nums[right] - nums[left] <= k) {
            left++;
        } else {
            // Otherwise, move the right pointer to the left
            right--;
        }
    }
    // Return the kth smallest distance
    return minDist;
}