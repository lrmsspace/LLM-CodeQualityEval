/**https://leetcode.com/problems/largest-values-from-labels/ */
//You are given n item's value and label as two integer arrays values and labels. You are also given two integers numWanted and useLimit.
//Your task is to find a subset of items with the maximum sum of their values such that:
//	The number of items is at most numWanted.
//	The number of items with the same label is at most useLimit.
//Return the maximum sum.
// 
//Example 1:
//Input: values = [5,4,3,2,1], labels = [1,1,2,2,3], numWanted = 3, useLimit = 1
//Output: 9
//Explanation:
//The subset chosen is the first, third, and fifth items with the sum of values 5 + 3 + 1.
//Example 2:
//Input: values = [5,4,3,2,1], labels = [1,3,3,3,2], numWanted = 3, useLimit = 2
//Output: 12
//Explanation:
//The subset chosen is the first, second, and third items with the sum of values 5 + 4 + 3.
//Example 3:
//Input: values = [9,8,8,7,6], labels = [0,0,0,1,1], numWanted = 3, useLimit = 1
//Output: 16
//Explanation:
//The subset chosen is the first and fourth items with the sum of values 9 + 7.
// 
//Constraints:
//	n == values.length == labels.length
//	1 <= n <= 2 * 104
//	0 <= values[i], labels[i] <= 2 * 104
//	1 <= numWanted, useLimit <= n
int largestValsFromLabels(int* values, int valuesSize, int* labels, int labelsSize, int numWanted, int useLimit) {
    int dp[20001][numWanted + 1] = {0};

    for (int i = 0; i < valuesSize; ++i) {
        for (int j = numWanted; j >= 1; --j) {
            int k = labels[i] * 20001 + j - 1;
            if (dp[k][j - 1] + values[i] > dp[k + 1][j]) {
                dp[k + 1][j] = dp[k][j - 1] + values[i];
            }
        }
    }
    return dp[labelsSize * 20001][numWanted];
}