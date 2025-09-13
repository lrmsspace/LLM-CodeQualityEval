/*
 You are given an array nums of length n. You are also given an integer k.
 You perform the following operation on nums once:
 Select a subarray nums[i..j] where 0 <= i <= j <= n - 1.
 Select an integer x and add x to all the elements in nums[i..j].
 Find the maximum frequency of the value k after the operation.
 Example 1:
 Input: nums = [1,2,3,4,5,6], k = 1
 Output: 2
 Explanation:
 After adding -5 to nums[2..5], 1 has a frequency of 2 in [1, 2, -2, -1, 0, 1].
 Example 2:
 Input: nums = [10,2,3,4,5,5,4,3,2,2], k = 10
 Output: 4
 Explanation:
 After adding 8 to nums[1..9], 10 has a frequency of 4 in [10, 10, 11, 12, 13, 13, 12, 11, 10, 10].
 Constraints:
 1 <= n == nums.length <= 105
 1 <= nums[i] <= 50
 1 <= k <= 50
*/

class Solution {
    public int maxFrequency(int[] nums, int k) {
        int n = nums.length;
        int[] count = new int[51];
        int[] prefixSum = new int[n + 1];
        int maxFrequency = 0;
        
        for (int num : nums) {
            count[num]++;
            prefixSum[count[num]]++;
            if (prefixSum[count[num]] > maxFrequency && count[num] > 0) {
                maxFrequency = prefixSum[count[num]];
            }
            int left = 0;   
            while (prefixSum[count[left]] < maxFrequency) {
                prefixSum[count[left]]--;
                count[nums[left]]--;
                left++;
            }   
            if (count[left] > 0 && count[left] == maxFrequency) {
                int right = left;
                while (right < n && nums[right] == nums[left]) {
                    right++;
                }
                maxFrequency = Math.max(maxFrequency, right - left);
            }   
            if (count[left] == maxFrequency) {
                maxFrequency = Math.max(maxFrequency, right - left);
            }
            maxFrequency = Math.max(maxFrequency, n - left);
            maxFrequency = Math.max(maxFrequency, left);

            if (count[left] == maxFrequency) {
                maxFrequency = Math.max(maxFrequency, right - left);
            }
        }
        return maxFrequency;    
        
    }
}