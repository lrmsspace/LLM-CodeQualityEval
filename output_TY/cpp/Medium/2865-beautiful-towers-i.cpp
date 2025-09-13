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
public:
    long long maximumSumOfHeights(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        stack<int> st;
        
        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(!st.empty()){
                left[i] = st.top() + 1;
            }
            st.push(i);
        }
        
        while(!st.empty()){
            st.pop();
        }
        
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(!st.empty()){
                right[i] = st.top() - 1;
            }
            st.push(i);
        }

        for(int i = 0; i < n; i++){
            int width = right[i] - left[i] + 1;
            int min_height = heights[i] - (width - 1);
            ans = max(ans, width * min_height);
        }
        return ans;
        
    }
};