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
        if (nums.length < 2) return 0;
        
        int n = nums.length;
        int min = nums[0], max = nums[0];
        for (int num : nums) {
            min = Math.min(min, num);
            max = Math.max(max, num);
        }
        
        double gap = (double) (max - min) / (n - 1);
        if (gap == 0) return 0;
        
        boolean[] visited = new boolean[n];
        Arrays.fill(visited, false);
        
        int maxGap = 0;
        for (int i = 0; i < n - 1; i++) {
            double left = min + i * gap;
            double right = left + gap;
            
            int j = Arrays.binarySearch(nums, (int) right);
            if (j < 0) j = -j - 1;
            
            while (j < n && visited[j]) j++;
            
            if (j < n) {
                maxGap = Math.max(maxGap, nums[j] - left);
                visited[j] = true;
            }

        }
        
        return maxGap;
        
    }
}