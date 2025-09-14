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
class Solution {
public:
    string solveEquation(string equation) {
        int n = equation.size();
        int x = 0, num = 0;
        int sign = 1;
        int i = 0;
        while (i < n) {
            if (equation[i] == '=') {
                sign = -1;
                i++;
                continue;
            }
            int s = sign;
            if (equation[i] == '+') {
                i++;
            } else if (equation[i] == '-') {
                s = -s;
                i++;
            }
            int n = 0;
            while (i < n && isdigit(equation[i])) {
                n = n * 10 + equation[i] - '0';
                i++;
            }
            if (i < n && equation[i] == 'x') {
                x += s * n;
                i++;
            } else {
                num += s * n;
            }
        }
        if (x == 0) {
            if (num == 0) {
                return "Infinite solutions";
            } else {
                return "No solution";
            }
        } else {
            return "x=" + to_string(-num / x);
        }
        
    }
};