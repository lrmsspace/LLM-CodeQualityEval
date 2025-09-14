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
        if (n == 0) return 0;
        int[] left = new int[n];
        int[] right = new int[n];
        int maxArea = 0;
        
        //Calculate the left boundary

        left[0] = -1;
        for (int i = 1; i < n; i++) {
            int j = i - 1;
            while (j >= 0 && heights[j] >= heights[i]) j = left[j];
            left[i] = j;
        }
        
        //Calculate the right boundary
        right[n - 1] = n;
        for (int i = n - 2; i >= 0; i--) {
            int j = i + 1;
            while (j < n && heights[j] >= heights[i]) j = right[j];
            right[i] = j;
        }
        
        //Calculate the area of each rectangle and update the maxArea
        for (int i = 0; i < n; i++) {
            maxArea = Math.max(maxArea, heights[i] * (right[i] - left[i] - 1));
        }
        
        return maxArea;
        
    }
}