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
        long long maxSum = 0;

        for (int peak = 0; peak < n; peak++) {
            long long currentSum = 0;
            int currentHeight = heights[peak];

            // Go left
            for (int i = peak; i >= 0; i--) {
                currentSum += min(currentHeight, heights[i]);
                currentHeight = max(0, currentHeight - 1);
            }

            currentHeight = heights[peak];

            // Go right
            for (int i = peak + 1; i < n; i++) {
                currentSum += min(currentHeight, heights[i]);
                currentHeight = max(0, currentHeight - 1);
            }

            maxSum = max(maxSum, currentSum);
        }

        return maxSum;
    }
};