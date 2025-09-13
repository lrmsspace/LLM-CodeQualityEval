/**https://leetcode.com/problems/max-points-on-a-line/ */
//Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane, return the maximum number of points that lie on the same straight line.
// 
//Example 1:
//Input: points = [[1,1],[2,2],[3,3]]
//Output: 3
//Example 2:
//Input: points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
//Output: 4
// 
//Constraints:
//	1 <= points.length <= 300
//	points[i].length == 2
//	-104 <= xi, yi <= 104
//	All the points are unique.  
class Solution {
    public:
        int maxPoints(vector<vector<int>>& points) {
            int n = points.size();
            if (n <= 2) return n; // If there are 0, 1, or 2 points, they all lie on the same line
            
            int maxCount = 2; // At least 2 points can form a line
            
            for (int i = 0; i < n; i++) {
                // Use a map to store the count of points for each slope
                // We use a string representation of the slope to avoid floating-point precision issues
                unordered_map<string, int> slopeCount;
                
                for (int j = 0; j < n; j++) {
                    if (i == j) continue; // Skip the same point
                    
                    int dx = points[j][0] - points[i][0];
                    int dy = points[j][1] - points[i][1];
                    
                    // Calculate the GCD to simplify the slope representation
                    int gcd = findGCD(dx, dy);
                    
                    // Normalize the slope by dividing both dx and dy by their GCD
                    dx /= gcd;
                    dy /= gcd;
                    
                    // Create a string representation of the slope
                    // Handle special cases for horizontal and vertical lines
                    string slope;
                    if (dx == 0) {
                        slope = "inf"; // Vertical line
                    } else if (dy == 0) {
                        slope = "0"; // Horizontal line
                    } else {
                        // Handle negative slopes correctly
                        if (dx < 0) {
                            dx = -dx;
                            dy = -dy;
                        }
                        slope = to_string(dy) + "/" + to_string(dx);
                    }
                    
                    // Increment the count for this slope
                    slopeCount[slope]++;
                    
                    // Update the maximum count
                    maxCount = max(maxCount, slopeCount[slope] + 1); // +1 for the point i itself
                }
            }
            
            return maxCount;
        }
        
    private:
        // Function to find the greatest common divisor (GCD) using Euclidean algorithm
        int findGCD(int a, int b) {
            a = abs(a);
            b = abs(b);
            while (b) {
                int temp = b;
                b = a % b;
                a = temp;
            }
            return a;
        }
    };
    