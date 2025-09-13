/*
 Given an array of integers nums and an integer k, return the number of subarrays of nums where the bitwise AND of the elements of the subarray equals k.
 Example 1:
 Input: nums = [1,1,1], k = 1
 Output: 6
 Explanation:
 All subarrays contain only 1's.
 Example 2:
 Input: nums = [1,1,2], k = 1
 Output: 3
 Explanation:
 Subarrays having an AND value of 1 are: [1,1,2], [1,1,2], [1,1,2].
 Example 3:
 Input: nums = [1,2,3], k = 2
 Output: 2
 Explanation:
 Subarrays having an AND value of 2 are: [1,2,3], [1,2,3].
 Constraints:
 1 <= nums.length <= 105
 0 <= nums[i], k <= 109
*/

class Solution {
    public long countSubarrays(int[] nums, int k) {
        int n = nums.length;
        long res = 0;
        int left = 0;
        int right = 0;
        int count = 0;
        while (right < n) {
            if ((nums[right] & k) != 0) {
                count++;
            }
            while (count > 0) {
                res += n - right;
                if ((nums[left] & k) != 0) {
                    count--;
                }
                left++;
            }
            right++;
        }
        return res;        
    }
}