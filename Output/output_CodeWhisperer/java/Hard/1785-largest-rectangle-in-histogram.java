/**https://leetcode.com/problems/largest-rectangle-in-histogram/ */
//Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.
// 
//Example 1:
//Input: heights = [2,1,5,6,2,3]
//Output: 10
//Explanation: The above is a histogram where width of each bar is 1.
//The largest rectangle is shown in the red area, which has an area = 10 units.
//Example 2:
//Input: heights = [2,4]
//Output: 4
// 
//Constraints:
//	1 <= heights.length <= 105
//	0 <= heights[i] <= 104
class Solution {
    public int largestRectangleArea(int[] heights) {
        int n = heights.length;
        int[] left = new int[n];
        int[] right = new int[n];
        int max = 0;
        for (int i = 0; i < n; i++) {
            left[i] = max;
            max = Math.max(max, heights[i]);
        }
        max = 0;
        for (int i = n - 1; i >= 0; i--) {
            right[i] = max;
            max = Math.max(max, heights[i]);
        }
        int sum = 0;
        for (int i = 0; i < n; i++) {
            int min = Math.min(left[i], right[i]);
            if (min > heights[i]) {
                sum += min - heights[i];
            }
        }
        return sum;        
    }
}