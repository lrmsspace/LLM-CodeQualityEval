/**https://leetcode.com/problems/contiguous-array/ */
//Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.
// 
//Example 1:
//Input: nums = [0,1]
//Output: 2
//Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.
//Example 2:
//Input: nums = [0,1,0]
//Output: 2
//Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
// 
//Constraints:
//	1 <= nums.length <= 105
//	nums[i] is either 0 or 1.
class Solution {
    public int findMaxLength(int[] nums) {
        int maxLength = 0;
        int count = 0;
        Map<Integer, Integer> map = new HashMap<>();
        map.put(0, -1); // Initialize with count 0 at index -1

        for (int i = 0; i < nums.length; i++) {
            count += (nums[i] == 1) ? 1 : -1; // Increment count for 1 and decrement for 0

            if (map.containsKey(count)) {
                maxLength = Math.max(maxLength, i - map.get(count)); // Update maxLength if found
            } else {
                map.put(count, i); // Store the first occurrence of this count
            }
        }

        return maxLength;        
    }
}