/**https://leetcode.com/problems/solve-the-equation/ */
//Solve a given equation and return the value of 'x' in the form of a string "x=#value". The equation contains only '+', '-' operation, the variable 'x' and its coefficient. You should return "No solution" if there is no solution for the equation, or "Infinite solutions" if there are infinite solutions for the equation.
//If there is exactly one solution for the equation, we ensure that the value of 'x' is an integer.
// 
//Example 1:
//Input: equation = "x+5-3+x=6+x-2"
//Output: "x=2"
//Example 2:
//Input: equation = "x=x"
//Output: "Infinite solutions"
//Example 3:
//Input: equation = "2x=x"
//Output: "x=0"
// 
//Constraints:
//	3 <= equation.length <= 1000
//	equation has exactly one '='.
//	equation consists of integers with an absolute value in the range [0, 100] without any leading zeros, and the variable 'x'.
//	The input is generated that if there is a single solution, it will be an integer.
char* solveEquation(char* equation) {
    int x = 0, num = 0, sign = 1, equal = 1;
    for (int i = 0; equation[i] != '\0'; i++) {
        if (equation[i] == '=') {
            equal = -1;
            sign = 1;
        } else if (equation[i] == '+') {
            sign = 1;
        } else if (equation[i] == '-') {
            sign = -1;
        } else if (equation[i] == 'x') {
            if (num == 0 && (i == 0 || equation[i - 1] == '=' || equation[i - 1] == '+' || equation[i - 1] == '-')) {
                num = 1;
            }
            x += equal * sign * num;
            num = 0;
        } else {
            num = num * 10 + (equation[i] - '0');
        }
    }
    if (num != 0) {
        x += equal * sign * num;
    }
    if (x == 0) {
        return "Infinite solutions";
    } else {
        char* result = (char*)malloc(10 * sizeof(char));
        sprintf(result, "x=%d", -x);
        return result;
    }
}