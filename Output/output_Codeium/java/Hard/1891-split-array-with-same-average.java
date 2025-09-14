/**https://leetcode.com/problems/split-array-with-same-average/ */
//You are given an integer array nums.
//You should move each element of nums into one of the two arrays A and B such that A and B are non-empty, and average(A) == average(B).
//Return true if it is possible to achieve that and false otherwise.
//Note that for an array arr, average(arr) is the sum of all the elements of arr over the length of arr.
// 
//Example 1:
//Input: nums = [1,2,3,4,5,6,7,8]
//Output: true
//Explanation: We can split the array into [1,4,5,8] and [2,3,6,7], and both of them have an average of 4.5.
//Example 2:
//Input: nums = [3,1]
//Output: false
// 
//Constraints:
//	1 <= nums.length <= 30
//	0 <= nums[i] <= 104
class Solution {
    public boolean splitArraySameAverage(int[] nums) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        int target = sum / nums.length;
        int mask = 1;
        for (int i = 0; i < nums.length; i++) {
            mask |= mask << nums[i];
        }
        for (int i = 0; i < (1 << (nums.length - 1)); i++) {
            int curSum = 0;
            for (int j = 0; j < nums.length; j++) {
                if (((i >> j) & 1) == 1) {
                    curSum += nums[j];
                }
            }
            if (curSum == target && (mask & (mask << curSum)) != 0) {
                return true;
            }
        }
        return false;
     }  
}