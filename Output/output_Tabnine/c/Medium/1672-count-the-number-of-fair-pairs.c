/**https://leetcode.com/problems/count-the-number-of-fair-pairs/ */
//Given a 0-indexed integer array nums of size n and two integers lower and upper, return the number of fair pairs.
//A pair (i, j) is fair if:
//	0 <= i < j < n, and
//	lower <= nums[i] + nums[j] <= upper
// 
//Example 1:
//Input: nums = [0,1,7,4,4,5], lower = 3, upper = 6
//Output: 6
//Explanation: There are 6 fair pairs: (0,3), (0,4), (0,5), (1,3), (1,4), and (1,5).
//Example 2:
//Input: nums = [1,7,9,2,5], lower = 11, upper = 11
//Output: 1
//Explanation: There is a single fair pair: (2,3).
// 
//Constraints:
//	1 <= nums.length <= 105
//	nums.length == n
//	-109 <= nums[i] <= 109
//	-109 <= lower <= upper <= 109
long long countFairPairs(int* nums, int numsSize, int lower, int upper) {
    // Step 1: Sort the array
    qsort(nums, numsSize, sizeof(int), compare);
    
    // Step 2: Initialize variables
    long long count = 0;
    int left = 0;
    int right = numsSize - 1;
    
    // Step 3: Iterate through the sorted array
    while (left < right) {
        // Step 4: Calculate the sum of the current elements
        int sum = nums[left] + nums[right];
        
        // Step 5: Update the count based on the sum's range
        if (sum < lower) {
            left++;
        } else if (sum > upper) {
            right--;
        } else {
            // Step 6: Count the number of valid pairs
            count += right - left;
            
            // Step 7: Move the pointers towards the center
            left++;
            right--;
        }
    }
    
    // Step 8: Return the final count
    return count;
    
}