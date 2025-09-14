/**https://leetcode.com/problems/contains-duplicate-ii/ */
//Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.
// 
//Example 1:
//Input: nums = [1,2,3,1], k = 3
//Output: true
//Example 2:
//Input: nums = [1,0,1,1], k = 1
//Output: true
//Example 3:
//Input: nums = [1,2,3,1,2,3], k = 2
//Output: false
// 
//Constraints:
//	1 <= nums.length <= 105
//	-109 <= nums[i] <= 109
//	0 <= k <= 105
class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        // Create a HashMap to store the last index of each number
        Map<Integer, Integer> map = new HashMap<>();
        
        // Iterate through the array
        for (int i = 0; i < nums.length; i++) {
            // If the number is already in the map and the difference between indices is less than or equal to k
            if (map.containsKey(nums[i]) && i - map.get(nums[i]) <= k) {
                return true; // Found a duplicate within the range
            }
            // Update the last index of the current number
            map.put(nums[i], i);
        }
        
        return false; // No duplicates found within the range        
    }
}