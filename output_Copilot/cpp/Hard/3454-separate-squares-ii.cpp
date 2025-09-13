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
        long long totalArea = 0;
        vector<long long> yCoordinates;

        // Calculate total area and collect y-coordinates
        for (const auto& square : squares) {
            int x = square[0], y = square[1], l = square[2];
            totalArea += static_cast<long long>(l) * l;
            yCoordinates.push_back(y);
            yCoordinates.push_back(y + l);
        }

        // Sort the y-coordinates
        sort(yCoordinates.begin(), yCoordinates.end());
        yCoordinates.erase(unique(yCoordinates.begin(), yCoordinates.end()), yCoordinates.end());

        double leftArea = 0, rightArea = totalArea;
        double result = -1;

        // Binary search over unique y-coordinates
        for (double y : yCoordinates) {
            // Calculate area above the line
            leftArea = 0;
            for (const auto& square : squares) {
                int x = square[0], ly = square[1], l = square[2];
                if (ly + l > y) {
                    leftArea += static_cast<long long>(l) * (min(ly + l, static_cast<int>(y)) - ly);
                }
            }
            rightArea = totalArea - leftArea;

            if (leftArea == rightArea) {
                result = max(result, y);
            }
        }

        return result < 0 ? -1.0 : result;
        
    }
};