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
    public int maxPoints(int[][] points) {
        int n = points.length;
        int max = 0;
        for (int i = 0; i < n; i++) {
            Map<String, Integer> map = new HashMap<>();
            int same = 1;
            int localMax = 0;
            for (int j = i + 1; j < n; j++) {
                int x = points[j][0] - points[i][0];
                int y = points[j][1] - points[i][1];
                if (x == 0 && y == 0) {
                    same++;
                    continue;
                }
                int gcd = gcd(x, y);
                String key = (x / gcd) + "_" + (y / gcd);
                map.put(key, map.getOrDefault(key, 0) + 1);
                localMax = Math.max(localMax, map.get(key));
            }
            max = Math.max(max, localMax + same);
        }
        return max;
    }
    
    private int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);   
    }
}