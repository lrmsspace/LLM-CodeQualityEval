/**https://leetcode.com/problems/24-game/ */
//You are given an integer array cards of length 4. You have four cards, each containing a number in the range [1, 9]. You should arrange the numbers on these cards in a mathematical expression using the operators ['+', '-', '*', '/'] and the parentheses '(' and ')' to get the value 24.
//You are restricted with the following rules:
//	The division operator '/' represents real division, not integer division.
//	
//		For example, 4 / (1 - 2 / 3) = 4 / (1 / 3) = 12.
//	
//	
//	Every operation done is between two numbers. In particular, we cannot use '-' as a unary operator.
//	
//		For example, if cards = [1, 1, 1, 1], the expression "-1 - 1 - 1 - 1" is not allowed.
//	
//	
//	You cannot concatenate numbers together
//	
//		For example, if cards = [1, 2, 1, 2], the expression "12 + 12" is not valid.
//	
//	
//Return true if you can get such expression that evaluates to 24, and false otherwise.
// 
//Example 1:
//Input: cards = [4,1,8,7]
//Output: true
//Explanation: (8-4) * (7-1) = 24
//Example 2:
//Input: cards = [1,2,1,2]
//Output: false
// 
//Constraints:
//	cards.length == 4
//	1 <= cards[i] <= 9
class Solution {
    public boolean judgePoint24(int[] cards) {
        double eps = 1e-6;
        for (int i = 0; i < 4; i++) {
            for (int j = i + 1; j < 4; j++) {
                for (int k = j + 1; k < 4; k++) {
                    for (int l = k + 1; l < 4; l++) {
                        double[] nums = new double[]{cards[i], cards[j], cards[k], cards[l]};
                        if (canMake24(nums)) return true;
                    }
                }
            }
        }
        return false;
    }

    private boolean canMake24(double[] nums) {
        if (nums.length == 1) {
            return Math.abs(nums[0] - 24) < eps;
        }
        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                double[] next = new double[nums.length - 1];
                int index = 0;
                for (int k = 0; k < nums.length; k++) {
                    if (k != i && k != j) {
                        next[index++] = nums[k];
                    }
                }
                for (int k = 0; k < 4; k++) {
                    double result = 0;
                    switch (k) {
                        case 0:
                            result = nums[i] + nums[j];
                            break;
                        case 1:
                            result = nums[i] - nums[j];
                            break;
                        case 2:
                            result = nums[i] * nums[j];
                            break;
                        case 3:
                            result = nums[i] / nums[j];
                            break;
                    }
                    next[next.length - 1] = result;
                    if (canMake24(next)) return true;
                }
            }
        }
        return false;
        }
}