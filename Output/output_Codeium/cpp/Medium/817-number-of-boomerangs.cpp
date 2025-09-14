/**https://leetcode.com/problems/number-of-boomerangs/ */
//You are given n points in the plane that are all distinct, where points[i] = [xi, yi]. A boomerang is a tuple of points (i, j, k) such that the distance between i and j equals the distance between i and k (the order of the tuple matters).
//Return the number of boomerangs.
// 
//Example 1:
//Input: points = [[0,0],[1,0],[2,0]]
//Output: 2
//Explanation: The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]].
//Example 2:
//Input: points = [[1,1],[2,2],[3,3]]
//Output: 2
//Example 3:
//Input: points = [[1,1]]
//Output: 0
// 
//Constraints:
//	n == points.length
//	1 <= n <= 500
//	points[i].length == 2
//	-104 <= xi, yi <= 104
//	All the points are unique.
class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int boomerangs = 0;
        for (const auto& p : points) {
            unordered_map<int, int> distanceCount;
            for (const auto& q : points) {
                int dx = p[0] - q[0];
                int dy = p[1] - q[1];
                int distanceSquared = dx * dx + dy * dy;
                ++distanceCount[distanceSquared];
            }
            for (const auto& pair : distanceCount) {
                int count = pair.second;
                boomerangs += count * (count - 1);
            }
        }
        return boomerangs;

    }
};