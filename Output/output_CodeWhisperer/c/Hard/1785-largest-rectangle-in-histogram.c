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
    int max = 0;
    int* stack = (int*)malloc(sizeof(int) * heightsSize);
    int stackSize = 0;
    for (int i = 0; i <= heightsSize; i++) {
        int h = (i == heightsSize) ? 0 : heights[i];
        while (stackSize > 0 && heights[stack[stackSize - 1]] > h) {
            int height = heights[stack[--stackSize]];
            int width = (stackSize == 0) ? i : (i - stack[stackSize - 1] - 1);
            max = fmax(max, height * width);
        }
        stack[stackSize++] = i;
    }
    free(stack);
    return max;
    
}