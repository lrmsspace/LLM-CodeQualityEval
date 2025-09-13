/**https://leetcode.com/problems/minimum-area-rectangle/ */
//You are given an array of points in the X-Y plane points where points[i] = [xi, yi].
//Return the minimum area of a rectangle formed from these points, with sides parallel to the X and Y axes. If there is not any such rectangle, return 0.
// 
//Example 1:
//Input: points = [[1,1],[1,3],[3,1],[3,3],[2,2]]
//Output: 4
//Example 2:
//Input: points = [[1,1],[1,3],[3,1],[3,3],[4,1],[4,3]]
//Output: 2
// 
//Constraints:
//	1 <= points.length <= 500
//	points[i].length == 2
//	0 <= xi, yi <= 4 * 104
//	All the given points are unique.
class Solution {
    public int minAreaRect(int[][] points) {
        int n = points.length;
        Map<Integer, Integer> map = new HashMap<>();
        int res = Integer.MAX_VALUE;
        for (int[] point : points) {
            int x = point[0], y = point[1];
            map.put(x + y * 10000, map.getOrDefault(x + y * 10000, 0) + 1);
        }
        for (int[] point : points) {
            int x = point[0], y = point[1];
            int target = x - y + 10000 * 4;
            if (map.containsKey(target)) {
                res = Math.min(res, (x - map.get(target)) * (y + map.get(target)));
            }
        }
        return res == Integer.MAX_VALUE? 0 : res;

    }
}