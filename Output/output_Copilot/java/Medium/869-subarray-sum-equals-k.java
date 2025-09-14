/**https://leetcode.com/problems/subarray-sum-equals-k/ */
//Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
//A subarray is a contiguous non-empty sequence of elements within an array.
// 
//Example 1:
//Input: nums = [1,1,1], k = 2
//Output: 2
//Example 2:
//Input: nums = [1,2,3], k = 3
//Output: 2
// 
//Constraints:
//	1 <= nums.length <= 2 * 104
//	-1000 <= nums[i] <= 1000
//	-107 <= k <= 107
class Solution {
    public int subarraySum(int[] nums, int k) {
        int count = 0, sum = 0;
        Map<Integer, Integer> map = new HashMap<>();
        map.put(0, 1); // Handle the case where a subarray starts from index 0

        for (int num : nums) {
            sum += num;
            count += map.getOrDefault(sum - k, 0);
            map.put(sum, map.getOrDefault(sum, 0) + 1);
        }

        return count;        
    }
}