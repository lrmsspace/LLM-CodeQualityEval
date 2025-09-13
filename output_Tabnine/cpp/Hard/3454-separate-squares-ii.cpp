/*
 You are given a 2D integer array squares. Each squares[i] = [xi, yi, li] represents the coordinates of the bottom-left point and the side length of a square parallel to the x-axis.
 Find the minimum y-coordinate value of a horizontal line such that the total area covered by squares above the line equals the total area covered by squares below the line.
 Answers within 10-5 of the actual answer will be accepted.
 Note: Squares may overlap. Overlapping areas should be counted only once in this version.
 Example 1:
 Input: squares = [[0,0,1],[2,2,1]]
 Output: 1.00000
 Explanation:
 Any horizontal line between y = 1 and y = 2 results in an equal split, with 1 square unit above and 1 square unit below. The minimum y-value is 1.
 Example 2:
 Input: squares = [[0,0,2],[1,1,1]]
 Output: 1.00000
 Explanation:
 Since the blue square overlaps with the red square, it will not be counted again. Thus, the line y = 1 splits the squares into two equal parts.
 Constraints:
 1 <= squares.length <= 5 * 104
 squares[i] = [xi, yi, li]
 squares[i].length == 3
 0 <= xi, yi <= 109
 1 <= li <= 109
 The total area of all the squares will not exceed 1015.
*/

class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {

        // Sort the squares based on their x-coordinate
        sort(squares.begin(), squares.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        // Initialize the prefix sums for the squares above and below the line
        vector<int> prefixSumAbove(squares.size(), 0);
        vector<int> prefixSumBelow(squares.size(), 0);
        // Calculate the prefix sums
        for (int i = 1; i < squares.size(); i++) {
            prefixSumAbove[i] = prefixSumAbove[i - 1] + squares[i][2] * squares[i][2];
            prefixSumBelow[i] = prefixSumBelow[i - 1] + squares[squares.size() - 1 - i][2] * squares[squares.size() - 1 - i][2];
        }
        // Initialize the minimum y-coordinate value
        double minY = INT_MAX;
        // Iterate through the squares to find the minimum y-coordinate value
        for (int i = 0; i < squares.size(); i++) {
            // Calculate the area covered by squares above and below the line
            double areaAbove = prefixSumAbove[i];
            double areaBelow = prefixSumBelow[squares.size() - 1 - i];
            // Calculate the minimum y-coordinate value
            double y = (areaAbove + areaBelow) / (i + 1);
            minY = min(minY, y);
        }
        // Return the minimum y-coordinate value
        return minY;

        
    }
};