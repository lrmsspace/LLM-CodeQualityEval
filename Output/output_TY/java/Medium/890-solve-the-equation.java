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
        String[] s = equation.split("=");
        int[] left = solve(s[0]);
        int[] right = solve(s[1]);
        int x = left[0] - right[0];
        int num = right[1] - left[1];
        if (x == 0 && num == 0) {
            return "Infinite solutions";
        } else if (x == 0) {
            return "No solution";
        } else {
            return "x=" + num / x;
        }
        private int[] solve(String s) {
            int[] res = new int[2];
            int n = s.length();
            int sign = 1, num = 0;
            for (int i = 0; i < n; i++) {
                if (s.charAt(i) == '+') {
                    sign = 1;
                } else if (s.charAt(i) == '-') {
                    sign = -1;
                } else if (s.charAt(i) == 'x') {
                    if (i == n - 1) {
                        res[0] += sign;
                    } else {
                        res[0] +=sign * Integer.parseInt(s.substring(i - num, i));
                    }
                }
            }
        }
        private int[] solve(String s) {
            int[] res = new int[2];
            int n = s.length();
            int sign = 1, num = 0;
            for (int i = 0; i < n; i++) {
                if (s.charAt(i) == '+') {
                    sign = 1;
                } else if (s.charAt(i) == '-') {
                    sign = -1;
                } else if (s.charAt(i) == 'x') {
                    if (i == n - 1) {
                        res[0] += sign;
                    } else {
                        res[0] +=sign * Integer.parseInt(s.substring(i - num, i));

                    }
                }
            }
        }
        return "x=" + num / x;
    }
}