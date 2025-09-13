/**https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/ */
//You are given a rectangular cake of size h x w and two arrays of integers horizontalCuts and verticalCuts where:
//	horizontalCuts[i] is the distance from the top of the rectangular cake to the ith horizontal cut and similarly, and
//	verticalCuts[j] is the distance from the left of the rectangular cake to the jth vertical cut.
//Return the maximum area of a piece of cake after you cut at each horizontal and vertical position provided in the arrays horizontalCuts and verticalCuts. Since the answer can be a large number, return this modulo 109 + 7.
// 
//Example 1:
//Input: h = 5, w = 4, horizontalCuts = [1,2,4], verticalCuts = [1,3]
//Output: 4 
//Explanation: The figure above represents the given rectangular cake. Red lines are the horizontal and vertical cuts. After you cut the cake, the green piece of cake has the maximum area.
//Example 2:
//Input: h = 5, w = 4, horizontalCuts = [3,1], verticalCuts = [1]
//Output: 6
//Explanation: The figure above represents the given rectangular cake. Red lines are the horizontal and vertical cuts. After you cut the cake, the green and yellow pieces of cake have the maximum area.
//Example 3:
//Input: h = 5, w = 4, horizontalCuts = [3], verticalCuts = [3]
//Output: 9
// 
//Constraints:
//	2 <= h, w <= 109
//	1 <= horizontalCuts.length <= min(h - 1, 105)
//	1 <= verticalCuts.length <= min(w - 1, 105)
//	1 <= horizontalCuts[i] < h
//	1 <= verticalCuts[i] < w
//	All the elements in horizontalCuts are distinct.
//	All the elements in verticalCuts are distinct.
/**
 * @param {number} h
 * @param {number} w
 * @param {number[]} horizontalCuts
 * @param {number[]} verticalCuts
 * @return {number}
 */
var maxArea = function(h, w, horizontalCuts, verticalCuts) {
       horizontalCuts.sort((a, b) => a - b); // Sort horizontal cuts in ascending order
        verticalCuts.sort((a, b) => a - b); // Sort vertical cuts in ascending order
    
        // Calculate the maximum height between horizontal cuts
        let maxHeight = Math.max(horizontalCuts[0], h - horizontalCuts[horizontalCuts.length - 1]);
        for (let i = 1; i < horizontalCuts.length; i++) {
            maxHeight = Math.max(maxHeight, horizontalCuts[i] - horizontalCuts[i - 1]);
        }
    
        // Calculate the maximum width between vertical cuts
        let maxWidth = Math.max(verticalCuts[0], w - verticalCuts[verticalCuts.length - 1]);
        for (let i = 1; i < verticalCuts.length; i++) {
            maxWidth = Math.max(maxWidth, verticalCuts[i] - verticalCuts[i - 1]);
        }
    
        // Return the area modulo 10^9 + 7
        return (maxHeight * maxWidth) % (10 ** 9 + 7);     
};