/**https://leetcode.com/problems/minimize-result-by-adding-parentheses-to-expression/ */
//You are given a 0-indexed string expression of the form "<num1>+<num2>" where <num1> and <num2> represent positive integers.
//Add a pair of parentheses to expression such that after the addition of parentheses, expression is a valid mathematical expression and evaluates to the smallest possible value. The left parenthesis must be added to the left of '+' and the right parenthesis must be added to the right of '+'.
//Return expression after adding a pair of parentheses such that expression evaluates to the smallest possible value. If there are multiple answers that yield the same result, return any of them.
//The input has been generated such that the original value of expression, and the value of expression after adding any pair of parentheses that meets the requirements fits within a signed 32-bit integer.
// 
//Example 1:
//Input: expression = "247+38"
//Output: "2(47+38)"
//Explanation: The expression evaluates to 2 * (47 + 38) = 2 * 85 = 170.
//Note that "2(4)7+38" is invalid because the right parenthesis must be to the right of the '+'.
//It can be shown that 170 is the smallest possible value.
//Example 2:
//Input: expression = "12+34"
//Output: "1(2+3)4"
//Explanation: The expression evaluates to 1 * (2 + 3) * 4 = 1 * 5 * 4 = 20.
//Example 3:
//Input: expression = "999+999"
//Output: "(999+999)"
//Explanation: The expression evaluates to 999 + 999 = 1998.
// 
//Constraints:
//	3 <= expression.length <= 10
//	expression consists of digits from '1' to '9' and '+'.
//	expression starts and ends with digits.
//	expression contains exactly one '+'.
//	The original value of expression, and the value of expression after adding any pair of parentheses that meets the requirements fits within a signed 32-bit integer.
char* minimizeResult(char* expression) {
    // Your implementation here
    // Example implementation using dynamic programming
    int n = strlen(expression);
    int dp[n][n];
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 0; i < n; i++) {
        dp[i][i] = 0;
    }
    for (int length = 2; length <= n; length++) {
        for (int i = 0; i < n - length + 1; i++) {
            int j = i + length - 1;
            for (int k = i; k < j; k++) {
                int left = dp[i][k] + dp[k + 1][j];
                int right = expression[i] - '0' + expression[k + 1] - '0' + dp[i][k] + dp[k + 1][j];
                dp[i][j] = min(dp[i][j], min(left, right));
            }
        }
    }
    int minValue = dp[0][n - 1];
    int left = 0, right = n - 1;
    char* result = (char*)malloc((n + 1) * sizeof(char));
    result[n] = '\0';
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (dp[left][mid] + dp[mid + 1][right] < minValue) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    result[left] = '(';
    result[right] = ')';
    int i = 0, j = 0;
    while (i <= left - 1 || j < n - 1) {
        if (i <= left - 1 && expression[i]!= '+' && expression[i]!= '(' && expression[i]!= ')') {
            result[left - 1] = expression[i];
            i++;
        } else if (expression[j]!= '+' && expression[j]!= '(' && expression[j]!= ')') {
            result[right + 1] = expression[j];
            j++;
        } else {
            result[left] = expression[j];
            result[right] = expression[j];
            left++;
            right--;
            i++;
            j++;
        }
    }
    return result;
}