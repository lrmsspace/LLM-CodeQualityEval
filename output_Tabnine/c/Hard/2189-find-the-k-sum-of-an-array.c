/**https://leetcode.com/problems/find-the-k-sum-of-an-array/ */
//You are given an integer array nums and a positive integer k. You can choose any subsequence of the array and sum all of its elements together.
//We define the K-Sum of the array as the kth largest subsequence sum that can be obtained (not necessarily distinct).
//Return the K-Sum of the array.
//A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.
//Note that the empty subsequence is considered to have a sum of 0.
// 
//Example 1:
//Input: nums = [2,4,-2], k = 5
//Output: 2
//Explanation: All the possible subsequence sums that we can obtain are the following sorted in decreasing order:
//- 6, 4, 4, 2, 2, 0, 0, -2.
//The 5-Sum of the array is 2.
//Example 2:
//Input: nums = [1,-2,3,4,-10,12], k = 16
//Output: 10
//Explanation: The 16-Sum of the array is 10.
// 
//Constraints:
//	n == nums.length
//	1 <= n <= 105
//	-109 <= nums[i] <= 109
//	1 <= k <= min(2000, 2n)
long long kSum(int* nums, int numsSize, int k) {
    // Sort the array in descending order
    qsort(nums, numsSize, sizeof(int), compare);
    
    // Initialize variables
    long long result = 0;
    int left = 0, right = numsSize - 1;
    
    // Iterate through the array while maintaining a window of size k
    while (left <= right) {
        // Calculate the sum of the current subsequence
        long long sum = 0;
        for (int i = left; i <= right && i < k; i++) {
            sum += nums[i];
        }
        
        // Update the result and move the window
        if (sum > result) {
            result = sum;
        }
        
        // Move the window to the right
        if (sum >= nums[right]) {
            right--;
        } else {
            left++;
        }
    }
    
    return result;
    
}