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
    public String solveEquation(String equation) {
        String[] parts = equation.split("=");
        String left = parts[0].trim();
        String right = parts[1].trim();
        
        int leftCoefficient = 0;
        int leftVariable = 0;
        int rightCoefficient = 0;
        int rightVariable = 0;
        
        for (String part : left.split("x")) {
            if (part.isEmpty()) {
                continue;
            }
            
            if (part.charAt(0) == '-') {
                leftCoefficient--;
            } else {
                leftCoefficient++;
            }
            
            if (part.length() > 1) {
                leftVariable += Integer.parseInt(part.substring(1));
            }
        }
        
        for (String part : right.split("x")) {
            if (part.isEmpty()) {
                continue;
            }
            
            if (part.charAt(0) == '-') {
                rightCoefficient--;
            } else {
                rightCoefficient++;
            }
            
            if (part.length() > 1) {
                rightVariable -= Integer.parseInt(part.substring(1));
            }
        }
        
        if (leftCoefficient == 0 && rightCoefficient == 0) {
            if (leftVariable == rightVariable) {
                return "Infinite solutions";
            } else {
                return "No solution";
            }
        }
        
        int x = rightVariable - leftVariable;
        
        if (x == 0) {
            return "x=0";
        }
        
        return "x=" + (x > 0? "+" : "") + x;
        
    }
}