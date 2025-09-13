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
        
        int[] xCoord = new int[n];
        int[] yCoord = new int[n];
        for (int i = 0; i < n; i++) {
            xCoord[i] = points[i][0];
            yCoord[i] = points[i][1];
        }
        Arrays.sort(xCoord);
        Arrays.sort(yCoord);
        int[] x = new int[n];
        int[] y = new int[n];
        for (int i = 0; i < n; i++) {
            x[i] = xCoord[i];
            y[i] = yCoord[i];
        }
        for (int i = 1; i < n; i++) {
            x[i] += x[i - 1];
            y[i] += y[i - 1];
        }
        long ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                long x = x[j] - x[i - 1];
                long y = y[j] - y[i - 1];
                if (x * y <= threshold) {
                    ans = Math.max(ans, x * y);
                }
            }
        }
        return ans;
       
    }
}