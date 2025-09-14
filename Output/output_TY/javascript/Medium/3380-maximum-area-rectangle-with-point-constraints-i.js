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

/**
 * @param {number[][]} points
 * @return {number}
 */
var maxRectangleArea = function(points) {
    let n = points.length;
    let x = new Array(n).fill(0).map(() => new Array(2).fill(0));
    let y = new Array(n).fill(0).map(() => new Array(2).fill(0));
    
    for(let i = 0; i < n; i++){
        x[i][0] = points[i][0];
        x[i][1] = i;
        y[i][0] = points[i][1];
        y[i][1] = i;
    }
    
    x.sort((a, b) => a[0] - b[0]);
    y.sort((a, b) => a[0] - b[0]);
    let gameScore = new Array(n).fill(0);
    for(let i = 0; i < n; i++){
        let index = x[i][1];
        gameScore[index] = Math.max(gameScore[index], points[index]);
        let left = 0, right = i;
        while(left < right){
            let mid = Math.floor((left + right + 1) / 2);
            if(x[mid][0] <= points[index][0]) left = mid;
            else right = mid - 1;
        }
        gameScore[index] = Math.max(gameScore[index], gameScore[left] + points[index]);
        left = i, right = n - 1;
        while(left < right){ 
            let mid = Math.floor((left + right) / 2);
            if(x[mid][0] >= points[index][0]) right = mid;
            else left = mid + 1;

        }
    }
    return gameScore[n - 1];    

    
};