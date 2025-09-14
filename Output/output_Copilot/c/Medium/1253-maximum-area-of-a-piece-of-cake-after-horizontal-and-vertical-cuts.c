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
    int mod = 1000000007;
    int max_h = 0, max_w = 0;
    int pre_h = 0, pre_w = 0;
    int i;
    qsort(horizontalCuts, horizontalCutsSize, sizeof(int), cmp);
    qsort(verticalCuts, verticalCutsSize, sizeof(int), cmp);
    for (i = 0; i < horizontalCutsSize; i++) {
        max_h = fmax(max_h, horizontalCuts[i] - pre_h);
        pre_h = horizontalCuts[i];
    }
    max_h = fmax(max_h, h - pre_h);
    for (i = 0; i < verticalCutsSize; i++) {
        max_w = fmax(max_w, verticalCuts[i] - pre_w);
        pre_w = verticalCuts[i];
    }
    max_w = fmax(max_w, w - pre_w);
    return (long)max_h * max_w % mod;    
}