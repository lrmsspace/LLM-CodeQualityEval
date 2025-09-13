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
public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> nums(cards.begin(), cards.end());
        
        function<bool(vector<double>)> solve = [&](vector<double> nums) {
            if (nums.size() == 1) {
                return fabs(nums[0] - 24) < 1e-6;
            }
            for (int i = 0; i < nums.size(); ++i) {
                for (int j = 0; j < nums.size(); ++j) {
                    if (i != j) {
                        vector<double> nextNums;
                        for (int k = 0; k < nums.size(); ++k) {
                            if (k != i && k != j) {
                                nextNums.push_back(nums[k]);
                            }
                        }
                        for (int op = 0; op < 4; ++op) {
                            if (op < 2 && j > i) continue;
                            if (op == 0) nextNums.push_back(nums[i] + nums[j]);
                            else if (op == 1) nextNums.push_back(nums[i] * nums[j]);
                            else if (op == 2) nextNums.push_back(nums[i] - nums[j]);
                            else if (op == 3 && nums[j] != 0) nextNums.push_back(nums[i] / nums[j]);
                            if (solve(nextNums)) return true;
                            nextNums.pop_back();
                        }
                    }
                }
            }
            return false;
        };
        
        return solve(nums);

    }
};