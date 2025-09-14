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
    int n = strlen(expression);
    int* res = (int*)malloc(n * sizeof(int));
    *returnSize = 0;
    
    for (int i = 0; i < n; ++i) {
        if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*') {
            int j = i, k = i + 1;
            while (j >= 0 && isdigit(expression[j])) --j;
            while (k < n && isdigit(expression[k])) ++k;
            int len1 = i - j - 1, len2 = k - i - 1;
            int* left = diffWaysToCompute(expression + j + 1, &len1);
            int* right = diffWaysToCompute(expression + i + 1, &len2);
            for (int l = 0; l < len1; ++l) {
                for (int r = 0; r < len2; ++r) {
                    int val;
                    switch (expression[i]) {
                        case '+':
                            val = left[l] + right[r];
                            break;
                        case '-':
                            val = left[l] - right[r];
                            break;
                        case '*':
                            val = left[l] * right[r];
                            break;
                    }
                    res[(*returnSize)++] = val;
                }
            }
            free(left);
            free(right);
        }
    }
    
    if (*returnSize == 0) {
        res[(*returnSize)++] = atoi(expression);
    }
    
    return res;
}