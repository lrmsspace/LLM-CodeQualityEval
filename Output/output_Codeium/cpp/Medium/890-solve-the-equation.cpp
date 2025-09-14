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
        int leftCoef = 0, rightCoef = 0, leftVal = 0, rightVal = 0;
        bool isLeft = true;
        for (int i = 0; i < equation.length(); ++i) {
            if (equation[i] == '=') {
                isLeft = false;
                continue;
            }
            if (equation[i] == 'x') {
                if (i == 0 || equation[i-1] != '+') {
                    leftCoef += isLeft ? 1 : -1;
                } else {
                    leftCoef += isLeft ? 1 : -1;
                }
            } else if (equation[i] >= '0' && equation[i] <= '9') {
                int val = 0;
                while (i < equation.length() && equation[i] >= '0' && equation[i] <= '9') {
                    val = val * 10 + equation[i] - '0';
                    ++i;
                }
                --i;
                if (i > 0 && equation[i-1] == '-') {
                    val = -val;
                }
                if (isLeft) {
                    leftVal += val;
                } else {
                    rightVal += val;
                }
            }
        }
        if (leftCoef == rightCoef) {
            if (leftVal != rightVal) {
                return "No solution";
            }
            return "Infinite solutions";
        }
        int x = (rightVal - leftVal) / (leftCoef - rightCoef);
        return "x=" + to_string(x);
    }
};