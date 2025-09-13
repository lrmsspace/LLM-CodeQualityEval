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
/**
 * @param {number[][]} points
 * @return {number}
 */
var maxPoints = function(points) {
    if (points.length <= 2) return points.length;
    
    let maxPoints = 0;
    
    for (let i = 0; i < points.length; i++) {
        let samePoints = 1;
        let slopes = new Map();
        
        for (let j = i + 1; j < points.length; j++) {
            if (points[i][0] === points[j][0] && points[i][1] === points[j][1]) {
                samePoints++;
                continue;
            }
            
            let slope = (points[i][1] - points[j][1]) / (points[i][0] - points[j][0]);
            
            if (slopes.has(slope)) {
                slopes.set(slope, slopes.get(slope) + 1);
            } else {
                slopes.set(slope, 2);
            }
        }
        
        let maxSlopeCount = 0;
        slopes.forEach(count => maxSlopeCount = Math.max(maxSlopeCount, count));
        
        maxPoints = Math.max(maxPoints, samePoints + maxSlopeCount);

        slopes.clear();
    }
    
    return maxPoints;
    
};