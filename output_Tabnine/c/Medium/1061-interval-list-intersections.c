/**https://leetcode.com/problems/interval-list-intersections/ */
//You are given two lists of closed intervals, firstList and secondList, where firstList[i] = [starti, endi] and secondList[j] = [startj, endj]. Each list of intervals is pairwise disjoint and in sorted order.
//Return the intersection of these two interval lists.
//A closed interval [a, b] (with a <= b) denotes the set of real numbers x with a <= x <= b.
//The intersection of two closed intervals is a set of real numbers that are either empty or represented as a closed interval. For example, the intersection of [1, 3] and [2, 4] is [2, 3].
// 
//Example 1:
//Input: firstList = [[0,2],[5,10],[13,23],[24,25]], secondList = [[1,5],[8,12],[15,24],[25,26]]
//Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
//Example 2:
//Input: firstList = [[1,3],[5,9]], secondList = []
//Output: []
// 
//Constraints:
//	0 <= firstList.length, secondList.length <= 1000
//	firstList.length + secondList.length >= 1
//	0 <= starti < endi <= 109
//	endi < starti+1
//	0 <= startj < endj <= 109 
//	endj < startj+1
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** intervalIntersection(int** firstList, int firstListSize, int* firstListColSize, int** secondList, int secondListSize, int* secondListColSize, int* returnSize, int** returnColumnSizes) {
    // Your code here
    *returnSize = 0;
    *returnColumnSizes = malloc(sizeof(int) * 2);
    (*returnColumnSizes)[0] = (*returnColumnSizes)[1] = 0;
    
    int** result = malloc(sizeof(int*) * 1000);
    for (int i = 0; i < 1000; i++) {
        result[i] = malloc(sizeof(int) * 2);
        result[i][0] = result[i][1] = 0;
    }
    
    int i = 0, j = 0, k = 0;
    
    while (i < firstListSize && j < secondListSize) {
        int start = fmax(firstList[i][0], secondList[j][0]);
        int end = fmin(firstList[i][1], secondList[j][1]);
        
        if (start <= end) {
            result[k][0] = start;
            result[k][1] = end;
            (*returnColumnSizes)[0]++;
            (*returnSize)++;
            k++;
        }
        
        if (firstList[i][1] < secondList[j][1]) {
            i++;
        } else {
            j++;
        }
    }
    
    return result;
}