/**https://leetcode.com/problems/rectangle-area-ii/ */
//You are given a 2D array of axis-aligned rectangles. Each rectangle[i] = [xi1, yi1, xi2, yi2] denotes the ith rectangle where (xi1, yi1) are the coordinates of the bottom-left corner, and (xi2, yi2) are the coordinates of the top-right corner.
//Calculate the total area covered by all rectangles in the plane. Any area covered by two or more rectangles should only be counted once.
//Return the total area. Since the answer may be too large, return it modulo 109 + 7.
// 
//Example 1:
//Input: rectangles = [[0,0,2,2],[1,0,2,3],[1,0,3,1]]
//Output: 6
//Explanation: A total area of 6 is covered by all three rectangles, as illustrated in the picture.
//From (1,1) to (2,2), the green and red rectangles overlap.
//From (1,0) to (2,3), all three rectangles overlap.
//Example 2:
//Input: rectangles = [[0,0,1000000000,1000000000]]
//Output: 49
//Explanation: The answer is 1018 modulo (109 + 7), which is 49.
// 
//Constraints:
//	1 <= rectangles.length <= 200
//	rectanges[i].length == 4
//	0 <= xi1, yi1, xi2, yi2 <= 109
//	xi1 <= xi2
//	yi1 <= yi2
/**
 * @param {number[][]} rectangles
 * @return {number}
 */
var rectangleArea = function(rectangles) {
    let count = new Array(rectangles.length).fill(0);
    let ans = 0;
    
    for (let i = 0; i < rectangles.length; i++) {
        let [x1, y1, x2, y2] = rectangles[i];
        for (let j = i + 1; j < rectangles.length; j++) {
            let [x3, y3, x4, y4] = rectangles[j];
            
            if (Math.max(x1, x3) <= Math.min(x2, x4) && Math.max(y1, y3) <= Math.min(y2, y4)) {
                count[i]++;
                count[j]++;
            }
        }
    }
    
    for (let i = 0; i < rectangles.length; i++) {
        let [x1, y1, x2, y2] = rectangles[i];
        ans = (ans + (x2 - x1 + 1) * (y2 - y1 + 1) - count[i]) % (10 ** 9 + 7);
    }
    
    return ans;
    
};