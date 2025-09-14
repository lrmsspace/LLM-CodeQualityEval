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
        int n = nums.length;
        if (n < 2) return 0;
        int max = Integer.MIN_VALUE;
        int min = Integer.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            max = Math.max(max, nums[i]);
            min = Math.min(min, nums[i]);
        }
        int d = (int) Math.ceil((max - min) / (n - 1));
        int bucketNum = (int) Math.ceil((max - min) / d) + 1;
        int[] bucketMax = new int[bucketNum];
        int[] bucketMin = new int[bucketNum];
        for (int i = 0; i < bucketNum; i++) {
            bucketMax[i] = Integer.MIN_VALUE;
            bucketMin[i] = Integer.MAX_VALUE;
        }
        for (int i = 0; i < n; i++) {
            int index = (int) Math.ceil((nums[i] - min) / d);
            bucketMax[index] = Math.max(bucketMax[index], nums[i]);
            bucketMin[index] = Math.min(bucketMin[index], nums[i]);
        }
        int maxGap = Integer.MIN_VALUE;
        int prev = bucketMax[0];
        for (int i = 1; i < bucketNum; i++) {
            if (bucketMin[i] == Integer.MAX_VALUE && bucketMax[i] == Integer.MIN_VALUE) continue;
            maxGap = Math.max(maxGap, bucketMin[i] - prev);
            prev = bucketMax[i];
        }
        return maxGap;      
    }
}