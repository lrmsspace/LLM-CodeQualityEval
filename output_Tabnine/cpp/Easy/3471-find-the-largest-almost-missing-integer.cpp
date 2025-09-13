/*
 You are given an integer array nums and an integer k.
 An integer x is almost missing from nums if x appears in exactly one subarray of size k within nums.
 Return the largest almost missing integer from nums. If no such integer exists, return -1.
 A subarray is a contiguous sequence of elements within an array.
 Example 1:
 Input: nums = [3,9,2,1,7], k = 3
 Output: 7
 Explanation:
 1 appears in 2 subarrays of size 3: [9, 2, 1] and [2, 1, 7].
 2 appears in 3 subarrays of size 3: [3, 9, 2], [9, 2, 1], [2, 1, 7].
 3 appears in 1 subarray of size 3: [3, 9, 2].
 7 appears in 1 subarray of size 3: [2, 1, 7].
 9 appears in 2 subarrays of size 3: [3, 9, 2], and [9, 2, 1].
 We return 7 since it is the largest integer that appears in exactly one subarray of size k.
 Example 2:
 Input: nums = [3,9,7,2,1,7], k = 4
 Output: 3
 Explanation:
 1 appears in 2 subarrays of size 4: [9, 7, 2, 1], [7, 2, 1, 7].
 2 appears in 3 subarrays of size 4: [3, 9, 7, 2], [9, 7, 2, 1], [7, 2, 1, 7].
 3 appears in 1 subarray of size 4: [3, 9, 7, 2].
 7 appears in 3 subarrays of size 4: [3, 9, 7, 2], [9, 7, 2, 1], [7, 2, 1, 7].
 9 appears in 2 subarrays of size 4: [3, 9, 7, 2], [9, 7, 2, 1].
 We return 3 since it is the largest and only integer that appears in exactly one subarray of size k.
 Example 3:
 Input: nums = [0,0], k = 1
 Output: -1
 Explanation:
 There is no integer that appears in only one subarray of size 1.
 Constraints:
 1 <= nums.length <= 50
 0 <= nums[i] <= 50
 1 <= k <= nums.length
*/

class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        // Sort the array in ascending order
        sort(nums.begin(), nums.end());
        
        // Initialize variables
        int max_diff = 0;
        int max_num = -1;
        
        // Iterate through the array
        for (int i = 0; i < nums.size() - k + 1; i++) {
            // Calculate the difference between the current number and the next k-1 numbers
            int diff = nums[i + k - 1] - nums[i];
            
            // Update the maximum difference and the maximum number if necessary
            if (diff > max_diff) {
                max_diff = diff;
                max_num = nums[i + k - 1];
            }
        }
        
        // Return the largest almost missing integer
        return max_num;
        
    }
};