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
        int sign = 1, coeff = 0, val = 0;
        int i = 0;
        while (i < equation.size()) {
            if (equation[i] == '+' || equation[i] == '-') {
                sign = (equation[i] == '+') ? 1 : -1;
                i++;
            }
            else if (equation[i] == 'x') {
                coeff += sign * ((i == 0 || equation[i - 1] == '+') ? 1 : -1);
                i++;
            }
            else {
                int start = i;
                while (i < equation.size() && equation[i] >= '0' && equation[i] <= '9') i++;
            }
        }
        if (coeff == 0 && val == 0) return "Infinite solutions";
        else if (coeff == 0) return "No solution";
        else return "x=" + to_string(-val / coeff);
        return "";
    }
};