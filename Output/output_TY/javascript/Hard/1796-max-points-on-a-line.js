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
    var max = 0;
    for(var i=0;i<points.length;i++){
        var map = {};
        var same = 1;
        for(var j=i+1;j<points.length;j++){
            if(points[i][0]==points[j][0] && points[i][1]==points[j][1]){
                same++;
                continue;
            }
            var k = (points[i][1]-points[j][1])/(points[i][0]-points[j][0]);
            if(map[k]){
                map[k]++;
            }else{
                map[k]=1;
            }
        }
    }
    return max;

};