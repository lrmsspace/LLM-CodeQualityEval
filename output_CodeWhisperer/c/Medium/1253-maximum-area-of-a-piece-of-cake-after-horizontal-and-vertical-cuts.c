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
int maxArea(int h, int w, int* horizontalCuts, int horizontalCutsSize, int* verticalCuts, int verticalCutsSize) {
    int maxH = 0, maxV = 0;
    int prev = 0;
    qsort(horizontalCuts, horizontalCutsSize, sizeof(int), cmpfunc);
    for (int i = 0; i < horizontalCutsSize; i++) {
        maxH = fmax(maxH, horizontalCuts[i] - prev);
        prev = horizontalCuts[i];
    }
    maxH = fmax(maxH, h - prev);
    prev = 0;
    qsort(verticalCuts, verticalCutsSize, sizeof(int), cmpfunc);
    for (int i = 0; i < verticalCutsSize; i++) {
        maxV = fmax(maxV, verticalCuts[i] - prev);
        prev = verticalCuts[i];
    }
    maxV = fmax(maxV, w - prev);
    return (int)((long)maxH * maxV % 1000000007);
}