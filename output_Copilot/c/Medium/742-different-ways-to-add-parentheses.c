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
        
        // Check if a character is an operator
        int isOperator(char c) {
            return c == '+' || c == '-' || c == '*';
        }
        
        // Calculate the result of an expression
        int calculate(int a, int b, char op) {
            if (op == '+') {
                return a + b;
            } else if (op == '-') {
                return a - b;
            } else if (op == '*') {
                return a * b;
            }
            return 0;
        }
        
        // Backtracking function to find all possible results
        void backtrack(char* expression, int start, int end, int** result, int* returnSize, int* returnColumnSizes, int* path, int pathIndex) {
            if (start == end) {
                result[*returnSize] = (int*)malloc(pathIndex * sizeof(int));
                returnColumnSizes[*returnSize] = pathIndex;
                for (int i = 0; i < pathIndex; i++) {
                    result[*returnSize][i] = path[i];
                }
                (*returnSize)++;
                return;
            }
            for (int i = start; i <= end; i++) {
                if (isOperator(expression[i])) {
                    int left = 0, right = 0;
                    backtrack(expression, start, i - 1, result, returnSize, returnColumnSizes, path, pathIndex);
                    left = *result[*returnSize - 1];
                    backtrack(expression, i + 1, end, result, returnSize, returnColumnSizes, path, pathIndex);
                    right = *result[*returnSize - 1];
                    for (int j = 0; j < returnColumnSizes[*returnSize - 1]; j++) {
                        path[pathIndex] = calculate(left, right, expression[i]);
                        pathIndex++;
                    }
                }
            }
        }
        
        // Initialize variables
        int n = strlen(expression);
        int** result = (int**)malloc(10000 * sizeof(int*));
        int* returnColumnSizes = (int*)malloc(10000 * sizeof(int));
        int* path = (int*)malloc(10000 * sizeof(int));
        *returnSize = 0;
        
        // Find all possible results
        backtrack(expression, 0, n - 1, result, returnSize, returnColumnSizes, path, 0);
        // Return result
        return result;
}