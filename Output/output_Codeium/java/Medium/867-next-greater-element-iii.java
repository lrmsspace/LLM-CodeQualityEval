/**https://leetcode.com/problems/next-greater-element-iii/ */
//Given a positive integer n, find the smallest integer which has exactly the same digits existing in the integer n and is greater in value than n. If no such positive integer exists, return -1.
//Note that the returned integer should fit in 32-bit integer, if there is a valid answer but it does not fit in 32-bit integer, return -1.
// 
//Example 1:
//Input: n = 12
//Output: 21
//Example 2:
//Input: n = 21
//Output: -1
// 
//Constraints:
//	1 <= n <= 231 - 1
class Solution {
    public int nextGreaterElement(int n) {
        char[] nums = Integer.toString(n).toCharArray();
        int i = nums.length - 2;
        
        // Find the first decreasing element from the end
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }
        
        if (i < 0) {
            return -1;
        }
        
        int j = nums.length - 1;
        
        // Find the element just larger than nums[i] to swap with
        while (nums[j] <= nums[i]) {
            j--;
        }
        
        // Swap elements at i and j
        char temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
        
        // Reverse the part of the array after index i
        int left = i + 1, right = nums.length - 1;
        while (left < right) {
            temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;
            left++;
            right--;
        }
        
        long result = Long.parseLong(new String(nums));
        return (result > Integer.MAX_VALUE) ? -1 : (int) result;

    }
}