/**https://leetcode.com/problems/pascals-triangle-ii/ */
//Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.
//In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
// 
//Example 1:
//Input: rowIndex = 3
//Output: [1,3,3,1]
//Example 2:
//Input: rowIndex = 0
//Output: [1]
//Example 3:
//Input: rowIndex = 1
//Output: [1,1]
// 
//Constraints:
//	0 <= rowIndex <= 33
// 
//Follow up: Could you optimize your algorithm to use only O(rowIndex) extra space?
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize){
    int* row = (int*)malloc(sizeof(int) * (rowIndex + 1));
    int i, j;
    for (i = 0; i <= rowIndex; i++) {
        row[i] = 1;
        for (j = i - 1; j > 0; j--) {
            row[j] += row[j - 1];
        }
    }
    *returnSize = rowIndex+ 1;
    return row;
}