/**https://leetcode.com/problems/maximum-gap/ */
//Given an integer array nums, return the maximum difference between two successive elements in its sorted form. If the array contains less than two elements, return 0.
//You must write an algorithm that runs in linear time and uses linear extra space.
// 
//Example 1:
//Input: nums = [3,6,9,1]
//Output: 3
//Explanation: The sorted form of the array is [1,3,6,9], either (3,6) or (6,9) has the maximum difference 3.
//Example 2:
//Input: nums = [10]
//Output: 0
//Explanation: The array contains less than 2 elements, therefore return 0.
// 
//Constraints:
//	1 <= nums.length <= 105
//	0 <= nums[i] <= 109
class Solution {
    public int maximumGap(int[] nums) {
        if (nums.length < 2) {
            return 0;
        }
        int max = nums[0];
        int min = nums[0];
        for (int num : nums) {
            max = Math.max(max, num);
            min = Math.min(min, num);
        }
        int gap = max - min;
        if (gap == 0) {
            return 0;
        }
        int[] maxBuckets = new int[nums.length - 1];
        int[] minBuckets = new int[nums.length - 1];
        double section = (double) gap / (nums.length - 1);
        for (int i = 0; i < nums.length; i++) {
            if (i == 0 || i == nums.length - 1) {
                continue;
            }
            int idx = (int) Math.floor((nums[i] - min) / section);
            maxBuckets[idx] = Math.max(maxBuckets[idx], nums[i]);
            minBuckets[idx] = Math.min(minBuckets[idx], nums[i]);
        }
        int maxGap = 0;
        int preMax = min;
        for (int i = 0; i < nums.length - 1; i++) {
            if (maxBuckets[i] == 0) {
                continue;
            }
            maxGap = Math.max(maxGap, minBuckets[i] - preMax);
            preMax = maxBuckets[i];
        }
        return maxGap;
    }
}