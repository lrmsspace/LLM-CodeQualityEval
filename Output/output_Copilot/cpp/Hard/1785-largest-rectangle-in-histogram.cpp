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
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n), right(n);
        stack<int> mono_stack;
        for (int i = 0; i < n; i++) {
            while (!mono_stack.empty() && heights[mono_stack.top()] >= heights[i]) {
                mono_stack.pop();
            }
            left[i] = mono_stack.empty() ? -1 : mono_stack.top();
            mono_stack.push(i);
        }
        mono_stack = stack<int>();
        for (int i = n - 1; i >= 0; i--) {
            while (!mono_stack.empty() && heights[mono_stack.top()] >= heights[i]) {
                mono_stack.pop();
            }
            right[i] = mono_stack.empty() ? n : mono_stack.top();
            mono_stack.push(i);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, (right[i] - left[i] - 1) * heights[i]);
        }
        return ans ;       
    }
};