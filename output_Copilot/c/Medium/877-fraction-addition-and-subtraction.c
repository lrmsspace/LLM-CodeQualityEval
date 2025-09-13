/**https://leetcode.com/problems/fraction-addition-and-subtraction/ */
//Given a string expression representing an expression of fraction addition and subtraction, return the calculation result in string format.
//The final result should be an irreducible fraction. If your final result is an integer, change it to the format of a fraction that has a denominator 1. So in this case, 2 should be converted to 2/1.
// 
//Example 1:
//Input: expression = "-1/2+1/2"
//Output: "0/1"
//Example 2:
//Input: expression = "-1/2+1/2+1/3"
//Output: "1/3"
//Example 3:
//Input: expression = "1/3-1/2"
//Output: "-1/6"
// 
//Constraints:
//	The input string only contains '0' to '9', '/', '+' and '-'. So does the output.
//	Each fraction (input and output) has the format ±numerator/denominator. If the first input fraction or the output is positive, then '+' will be omitted.
//	The input only contains valid irreducible fractions, where the numerator and denominator of each fraction will always be in the range [1, 10]. If the denominator is 1, it means this fraction is actually an integer in a fraction format defined above.
//	The number of given fractions will be in the range [1, 10].
//	The numerator and denominator of the final result are guaranteed to be valid and in the range of 32-bit int.
char* fractionAddition(char* expression) {
        
        // Check if a character is an operator
        int isOperator(char c) {
            return c == '+' || c == '-';
        }
        
        // Calculate the greatest common divisor of two numbers
        int gcd(int a, int b) {
            return b == 0 ? a : gcd(b, a % b);
        }
        
        // Calculate the least common multiple of two numbers
        int lcm(int a, int b) {
            return a * b / gcd(a, b);
        }
        
        // Backtracking function to find the sum of fractions
        void backtrack(char* expression, int start, int end, int* result, int* returnSize, int* returnColumnSizes, int* path, int pathIndex) {
            if (start == end) {
                int numerator = 0, denominator = 1;
                for (int i = 0; i < pathIndex; i += 2) {
                    int num = path[i], den = path[i + 1];
                    denominator = lcm(denominator, den);
                    numerator = numerator * (denominator / den) + num * (denominator / den);
                    int divisor = gcd(numerator, denominator);
                    numerator /= divisor;
                    denominator /= divisor;
                }
                result[*returnSize] = numerator;
                result[*returnSize + 1] = denominator;
                (*returnSize) += 2;
                return;
            }
            for (int i = start; i <= end; i++) {
                if (isOperator(expression[i])) {
                    path[pathIndex] = atoi(expression + start);
                    path[pathIndex + 1] = atoi(expression + i + 1);
                    backtrack(expression, i + 1, end, result, returnSize, returnColumnSizes, path, pathIndex + 2);
                }
            }
        }
        
        // Initialize variables
        int n = strlen(expression);
        int* result = (int*)malloc(2 * sizeof(int));
        int* path = (int*)malloc(20 * sizeof(int));
        int returnSize = 0;
        
        // Find the sum of fractions
        backtrack(expression, 0, n, result, &returnSize, NULL, path, 0);
        
        // Convert the result to string format
        char* res = (char*)malloc(20 * sizeof(char));
        sprintf(res, "%d/%d", result[0], result[1]);
        return res; 
}