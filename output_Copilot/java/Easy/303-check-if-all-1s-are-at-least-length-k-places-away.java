/**https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away/ */
//Given an binary array nums and an integer k, return true if all 1's are at least k places away from each other, otherwise return false.
// 
//Example 1:
//Input: nums = [1,0,0,0,1,0,0,1], k = 2
//Output: true
//Explanation: Each of the 1s are at least 2 places away from each other.
//Example 2:
//Input: nums = [1,0,0,1,0,1], k = 2
//Output: false
//Explanation: The second 1 and third 1 are only one apart from each other.
// 
//Constraints:
//	1 <= nums.length <= 105
//	0 <= k <= nums.length
//	nums[i] is 0 or 1
class Solution {
    public boolean kLengthApart(int[] nums, int k) {
        int lastOneIndex = -1; // Initialize the index of the last 1 found to -1 (not found yet)
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == 1) { // If we find a 1 in the array
                if (lastOneIndex != -1 && i - lastOneIndex <= k) { // Check if the distance from the last 1 is less than or equal to k
                    return false; // If so, return false
                }
                lastOneIndex = i; // Update the index of the last 1 found
            }
        }
        return true; // If we finish the loop without finding any violations, return true        
    }
}