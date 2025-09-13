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
int largestRectangleArea(int* heights, int heightsSize) {
    int *stack = (int *)malloc(sizeof(int) * (heightsSize + 1));
    int top = -1;
    int max = 0;
    int i = 0;
    while (i < heightsSize) {
        if (top == -1 || heights[i] >= heights[stack[top]]) {
            stack[++top] = i++;
        } else {
            int h = heights[stack[top--]];
            int w = top == -1 ? i : i - stack[top] - 1;
            int area = h * w;
            if (area > max) {
                max = area;
            }
        }
    }
    while (top != -1) {
        int h = heights[stack[top--]];
        int w = top == -1 ? i : i - stack[top] - 1;
        int area = h * w;
        if (area > max) {
            max = area;
        }
    }
    free(stack);
    return max;    
}