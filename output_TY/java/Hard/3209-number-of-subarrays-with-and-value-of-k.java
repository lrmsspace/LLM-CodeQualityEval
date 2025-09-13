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
        int[] prefix = new int[n];
        for(int i = 0; i < n; i++)
        {
            if(nums[i] == k)
            {
                prefix[i] = 1;
            }
            else
            {
                prefix[i] = 0;
            }
        }
        for(int i = 1; i < n; i++)
        {
            prefix[i] += prefix[i-1];
        }
        long ans = 0;
        for(int i = 0; i < n; i++)
        {
            int left = 0;
            int right = 0;
            int j = i;
            while(j >= 0 && nums[j] != k)
            {
                left++;
                j--;
            }
            j = i;
            while(j < n && nums[j] != k)
            {
                right++;
                j++;
            }
            if(i - left + 1 >= 0)
            {
                ans += prefix[i - left] * prefix[i - left + right - 1];
            }
            if(i + right < n)
            {
                ans += prefix[i + right] * prefix[i + right - 1];
            }
        }
        return ans;
        
    }
}