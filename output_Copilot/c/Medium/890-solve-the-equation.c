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
    int n = strlen(equation);
    int a = 0, b = 0, sign = 1, num = 0, i = 0;
    for (int j = 0; j < n; j++) {
        if (equation[j] == '+' || equation[j] == '-') {
            if (j > i) {
                num = atoi(equation + i);
                b += sign * num;
            }
            i = j;
        } else if (equation[j] == 'x') {
            if (j == i || equation[j - 1] == '+') {
                num = 1;
            } else if (equation[j - 1] == '-') {
                num = -1;
            } else {
                num = atoi(equation + i);
            }
            a += sign * num;
            i = j + 1;
        } else if (equation[j] == '=') {
            if (j > i) {
                num = atoi(equation + i);
                b += sign * num;
            }
            sign = -1;
            i = j + 1;
        }
    }
    if (i < n) {
        num = atoi(equation + i);
        b += sign * num;
    }
    if (a == 0) {
        if (b == 0) {
            return "Infinite solutions";
        } else {
            return "No solution";
        }
    } else {
        return (char*)malloc(20 * sizeof(char));
    }    
}