/**https://leetcode.com/problems/restore-the-array-from-adjacent-pairs/ */
//There is an integer array nums that consists of n unique elements, but you have forgotten it. However, you do remember every pair of adjacent elements in nums.
//You are given a 2D integer array adjacentPairs of size n - 1 where each adjacentPairs[i] = [ui, vi] indicates that the elements ui and vi are adjacent in nums.
//It is guaranteed that every adjacent pair of elements nums[i] and nums[i+1] will exist in adjacentPairs, either as [nums[i], nums[i+1]] or [nums[i+1], nums[i]]. The pairs can appear in any order.
//Return the original array nums. If there are multiple solutions, return any of them.
// 
//Example 1:
//Input: adjacentPairs = [[2,1],[3,4],[3,2]]
//Output: [1,2,3,4]
//Explanation: This array has all its adjacent pairs in adjacentPairs.
//Notice that adjacentPairs[i] may not be in left-to-right order.
//Example 2:
//Input: adjacentPairs = [[4,-2],[1,4],[-3,1]]
//Output: [-2,4,1,-3]
//Explanation: There can be negative numbers.
//Another solution is [-3,1,4,-2], which would also be accepted.
//Example 3:
//Input: adjacentPairs = [[100000,-100000]]
//Output: [100000,-100000]
// 
//Constraints:
//	nums.length == n
//	adjacentPairs.length == n - 1
//	adjacentPairs[i].length == 2
//	2 <= n <= 105
//	-105 <= nums[i], ui, vi <= 105
//	There exists some nums that has adjacentPairs as its pairs.
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* restoreArray(int** adjacentPairs, int adjacentPairsSize, int* adjacentPairsColSize, int* returnSize) {
    int n = adjacentPairsSize + 1;
    int* res = (int*)malloc(n * sizeof(int));
    int count[200005] = {0};
    for (int i = 0; i < adjacentPairsSize; i++) {
        count[adjacentPairs[i][0]]++;
        count[adjacentPairs[i][1]]++;
    }
    int start = -1;
    for (int i = 0; i < 200005; i++) {
        if (count[i] == 1) {
            res[0] = i;
            start = i;
            break;
        }
    }
    res[1] = adjacentPairs[0][0] == start ? adjacentPairs[0][1] : adjacentPairs[0][0];
    for (int i = 2; i < n; i++) {
        for (int j = 0; j < adjacentPairsSize; j++) {
            if (adjacentPairs[j][0] == res[i - 1]) {
                res[i] = adjacentPairs[j][1];
                break;
            }
            if (adjacentPairs[j][1] == res[i - 1]) {
                res[i] = adjacentPairs[j][0];
                break;
            }
        }
    }
    *returnSize = n;
    return res;
    
}