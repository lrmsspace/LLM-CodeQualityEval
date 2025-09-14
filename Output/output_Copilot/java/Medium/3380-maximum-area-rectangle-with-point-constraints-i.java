/*
 You are given an array points where points[i] = [xi, yi] represents the coordinates of a point on an infinite plane.
 Your task is to find the maximum area of a rectangle that:
 Can be formed using four of these points as its corners.
 Does not contain any other point inside or on its border.
 Has its edges parallel to the axes.
 Return the maximum area that you can obtain or -1 if no such rectangle is possible.
 Example 1:
 Input: points = [[1,1],[1,3],[3,1],[3,3]]
 Output: 4
 Explanation:
 We can make a rectangle with these 4 points as corners and there is no other point that lies inside or on the border. Hence, the maximum possible area would be 4.
 Example 2:
 Input: points = [[1,1],[1,3],[3,1],[3,3],[2,2]]
 Output: -1
 Explanation:
 There is only one rectangle possible is with points [1,1], [1,3], [3,1] and [3,3] but [2,2] will always lie inside it. Hence, returning -1.
 Example 3:
 Input: points = [[1,1],[1,3],[3,1],[3,3],[1,2],[3,2]]
 Output: 2
 Explanation:
 The maximum area rectangle is formed by the points [1,3], [1,2], [3,2], [3,3], which has an area of 2. Additionally, the points [1,1], [1,2], [3,1], [3,2] also form a valid rectangle with the same area.
 Constraints:
 1 <= points.length <= 10
 points[i].length == 2
 0 <= xi, yi <= 100
 All the given points are unique.
*/

class Solution {
    public int maxRectangleArea(int[][] points) {
        int n = points.length;
        if (n < 4) return -1; // Not enough points to form a rectangle

        Set<String> pointSet = new HashSet<>();
        for (int[] point : points) {
            pointSet.add(point[0] + "," + point[1]);
        }

        int maxArea = -1;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    for (int l = k + 1; l < n; l++) {
                        int x1 = points[i][0], y1 = points[i][1];
                        int x2 = points[j][0], y2 = points[j][1];
                        int x3 = points[k][0], y3 = points[k][1];
                        int x4 = points[l][0], y4 = points[l][1];

                        // Check if they can form a rectangle
                        if ((x1 == x2 && y3 == y4 && y1 == y2 && x3 == x4) ||
                            (x1 == x3 && y2 == y4 && y1 == y3 && x2 == x4) ||
                            (x1 == x4 && y2 == y3 && y1 == y4 && x2 == x3)) {

                            // Calculate area
                            int width = Math.abs(x2 - x1);
                            int height = Math.abs(y3 - y1);
                            int area = width * height;

                            // Check if the rectangle is valid
                            if (area > 0 && !pointSet.contains(x1 + "," + y3) &&
                                !pointSet.contains(x2 + "," + y4) &&
                                !pointSet.contains(x3 + "," + y1) &&
                                !pointSet.contains(x4 + "," + y2)) {
                                maxArea = Math.max(maxArea, area);
                            }
                        }
                    }
                }
            }
        }

        return maxArea; 
            
    }
}