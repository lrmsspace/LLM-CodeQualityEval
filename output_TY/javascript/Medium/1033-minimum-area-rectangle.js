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
/**
 * @param {number[][]} points
 * @return {number}
 */
var minAreaRect = function(points) {
    let minArea = Number.MAX_SAFE_INTEGER;  

    for(let i = 0; i < points.length; i++){
        for(let j = i + 1; j < points.length; j++){
            let [x1, y1] = points[i];
            let [x2, y2] = points[j];

            if(x1 !== x2 && y1 !== y2){
                let [x3, y3] = [x2, y1];
                let [x4, y4] = [x1, y2];

                if(points.some(point => point[0] === x3 && point[1] === y3) && points.some(point => point[0] === x4 && point[1] === y4)){
                    let area = Math.abs(x1 - x2) * Math.abs(y1 - y2);
                }
            }
        }
    }
    return minArea === Number.MAX_SAFE_INTEGER ? 0 : minArea;
};