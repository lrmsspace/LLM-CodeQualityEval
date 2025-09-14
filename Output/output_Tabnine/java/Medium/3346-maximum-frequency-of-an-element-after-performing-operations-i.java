/*
 You are given an integer array nums and two integers k and numOperations.
 You must perform an operation numOperations times on nums, where in each operation you:
 Select an index i that was not selected in any previous operations.
 Add an integer in the range [-k, k] to nums[i].
 Return the maximum possible frequency of any element in nums after performing the operations.
 Example 1:
 Input: nums = [1,4,5], k = 1, numOperations = 2
 Output: 2
 Explanation:
 We can achieve a maximum frequency of two by:
 Adding 0 to nums[1]. nums becomes [1, 4, 5].
 Adding -1 to nums[2]. nums becomes [1, 4, 4].
 Example 2:
 Input: nums = [5,11,20,20], k = 5, numOperations = 1
 Output: 2
 Explanation:
 We can achieve a maximum frequency of two by:
 Adding 0 to nums[1].
 Constraints:
 1 <= nums.length <= 105
 1 <= nums[i] <= 105
 0 <= k <= 105
 0 <= numOperations <= nums.length
*/

class Solution {
    public int maxFrequency(int[] nums, int k, int numOperations) {
        // Sort the array
        Arrays.sort(nums);
        
        // Initialize variables
        int maxFrequency = 1;
        int start = 0;
        int count = 1;
        
        // Iterate through the array
        for (int end = 1; end < nums.length; end++) {
            // If the current element is equal to the previous one, increment the count
            if (nums[end] == nums[end - 1]) {
                count++;
            } else {
                // If the count is greater than the maximum frequency, update the maximum frequency
                maxFrequency = Math.max(maxFrequency, count);
                
                // If the count exceeds the number of operations, return the maximum frequency
                if (count > numOperations) {
                    return maxFrequency;
                }
                
                // Reset the count
                count = 1;
            }
        }
        
        // Return the maximum frequency after the last operation
        return Math.max(maxFrequency, count);
        
    }
}