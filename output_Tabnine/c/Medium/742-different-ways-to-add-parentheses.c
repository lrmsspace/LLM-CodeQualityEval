/**https://leetcode.com/problems/different-ways-to-add-parentheses/ */
//Given a string expression of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. You may return the answer in any order.
//The test cases are generated such that the output values fit in a 32-bit integer and the number of different results does not exceed 104.
// 
//Example 1:
//Input: expression = "2-1-1"
//Output: [0,2]
//Explanation:
//((2-1)-1) = 0 
//(2-(1-1)) = 2
//Example 2:
//Input: expression = "2*3-4*5"
//Output: [-34,-14,-10,-10,10]
//Explanation:
//(2*(3-(4*5))) = -34 
//((2*3)-(4*5)) = -14 
//((2*(3-4))*5) = -10 
//(2*((3-4)*5)) = -10 
//(((2*3)-4)*5) = 10
// 
//Constraints:
//	1 <= expression.length <= 20
//	expression consists of digits and the operator '+', '-', and '*'.
//	All the integer values in the input expression are in the range [0, 99].
//	The integer values in the input expression do not have a leading '-' or '+' denoting the sign.
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* diffWaysToCompute(char* expression, int* returnSize) {
    int len = strlen(expression);
    int** dp = (int**)malloc(sizeof(int*) * len);
    for (int i = 0; i < len; ++i) {
        dp[i] = (int*)malloc(sizeof(int) * len);
        memset(dp[i], -1, sizeof(int) * len);
    }
    int* result = diffWaysToComputeHelper(expression, 0, len - 1, dp);
    *returnSize = sizeof(result) / sizeof(result[0]);
    return result;
}