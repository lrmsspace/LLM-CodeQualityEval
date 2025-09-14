/*
 You are given an array heights of n integers representing the number of bricks in n consecutive towers. Your task is to remove some bricks to form a mountain-shaped tower arrangement. In this arrangement, the tower heights are non-decreasing, reaching a maximum peak value with one or multiple consecutive towers and then non-increasing.
 Return the maximum possible sum of heights of a mountain-shaped tower arrangement.
 Example 1:
 Input: heights = [5,3,4,1,1]
 Output: 13
 Explanation:
 We remove some bricks to make heights = [5,3,3,1,1], the peak is at index 0.
 Example 2:
 Input: heights = [6,5,3,9,2,7]
 Output: 22
 Explanation:
 We remove some bricks to make heights = [3,3,3,9,2,2], the peak is at index 3.
 Example 3:
 Input: heights = [3,2,5,5,2,3]
 Output: 18
 Explanation:
 We remove some bricks to make heights = [2,2,5,5,2,2], the peak is at index 2 or 3.
 Constraints:
 1 <= n == heights.length <= 103
 1 <= heights[i] <= 109
*/

class Solution {
    public long maximumSumOfHeights(int[] heights) {
        int n = heights.length;
        long[] left = new long[n];
        long[] right = new long[n];
        
        left[0] = heights[0];
        for (int i = 1; i < n; i++) {
            left[i] = left[i - 1];
            int h = heights[i];
            if (h >= heights[i - 1]) {
                left[i] += h;
            } else {
                int j = i - 1;
                while (j >= 0 && h < left[j]) {
                    left[i] += left[j] - h;
                    j--;
                }
                left[i] += h;
            }
        }
        
        right[n - 1] = heights[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            right[i] = right[i + 1];
            int h = heights[i];
            if (h >= heights[i + 1]) {
                right[i] += h;
            } else {
                int j = i + 1;
                while (j < n && h < right[j]) {
                    right[i] += right[j] - h;
                    j++;
                }
                right[i] += h;
            }
        }
        
        long maxSum = 0;
        for (int i = 0; i < n; i++) {
            maxSum = Math.max(maxSum, left[i] + right[i] - heights[i]);
        }
        
        return maxSum;           
    }
}