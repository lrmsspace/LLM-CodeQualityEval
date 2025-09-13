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
        int x = 0, num = 0, sign = 1;
        boolean afterEqual = false;
        char[] arr = equation.toCharArray();
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == '=') {
                afterEqual = true;
                sign = -1;
                continue;
            }
            int s = sign;
            if (arr[i] == '-') {
                s = -s;
            } else if (arr[i] == '+') {
                continue;
            }
            int n = 0;
            if (Character.isDigit(arr[i])) {
                while (i < arr.length && Character.isDigit(arr[i])) {
                    n = n * 10 + arr[i] - '0';
                    i++;
                }
            }
            if (i < arr.length && arr[i] == 'x') {
                x += (afterEqual ? -1 : 1) * s * (n == 0 ? 1 : n);
                i++;
            } else {
                num += s * n;
                i--;
            }
            sign = 1;
        }
        if (x == 0) {
            return num == 0 ? "Infinite solutions" : "No solution";
        } else {
            return "x=" + (-num / x);
       }         
    }
}