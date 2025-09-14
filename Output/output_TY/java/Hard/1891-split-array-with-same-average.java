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
        int n = nums.length;
        int sum = 0;
        for (int num : nums) sum += num;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= n / 2; j++) {
                if (sum * j % n == 0) return true;
            }
        }
        return false;  
    }
}