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
        // Split equation into two parts: left and right sides
        int i = equation.find('=');
        string left = equation.substr(0, i);
        string right = equation.substr(i + 1);
        
        // Initialize counters for the coefficients of 'x' on both sides
        int leftX = 0, leftNum = 0;
        int rightX = 0, rightNum = 0;
        
        // Parse left side and update counters
        for (char c : left) {
            if (isdigit(c)) {
                if (leftNum == 0) leftNum = c - '0';
                else leftNum = leftNum * 10 + c - '0';
            } else if (c == 'x') {
                leftX++;
            }
        }
        
        // Parse right side and update counters

        for (char c : right) {
            if (isdigit(c)) {
                if (rightNum == 0) rightNum = c - '0';
                else rightNum = rightNum * 10 + c - '0';
            } else if (c == 'x') {
                rightX++;
            }
        }
        
        // If the left side has no 'x' term, it means there is no solution
        if (leftX == 0) return "No solution";
        
        // If the right side has no 'x' term, it means there are infinite solutions
        if (rightX == 0) return "Infinite solutions";
        
        // Calculate the value of 'x'
        int x = (rightNum - leftNum) / leftX;
        
        // Return the result as a string
        return "x=" + to_string(x);
        
    }
};