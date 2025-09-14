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
int largestRectangleArea(int* heights, int heightsSize){
    int i, j, k, max = 0, temp;
    for (i = 0; i < heightsSize; i++) {
        temp = heights[i];
        for (j = i; j < heightsSize; j++) {
            temp = temp < heights[j] ? temp : heights[j];
            for (k = i; k <= j; k++) {
                max = max > temp * (j - i + 1)? max : temp * (j - i + 1);
            }
        }
    }
    return max;
}