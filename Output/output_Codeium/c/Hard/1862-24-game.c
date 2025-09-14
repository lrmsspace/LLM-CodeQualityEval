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
bool judgePoint24(int* cards, int cardsSize) {
    double eps = 1e-6;
    double nums[4] = {0};
    for (int i = 0; i < cardsSize; i++) {
        nums[i] = cards[i];
    }
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            double a = nums[i], b = nums[j];
            double c = a + b;
            double d = a - b;
            double e = a * b;
            if (b != 0) {
                double f = a / b;
                nums[j] = c;
                if (judgePoint24(nums, cardsSize - 1)) return true;
                nums[j] = d;
                if (judgePoint24(nums, cardsSize - 1)) return true;
                nums[j] = e;
                if (judgePoint24(nums, cardsSize - 1)) return true;
                nums[j] = f;
                if (judgePoint24(nums, cardsSize - 1)) return true;
            }
            nums[j] = c;
            if (judgePoint24(nums, cardsSize - 1)) return true;
            nums[j] = d;
            if (judgePoint24(nums, cardsSize - 1)) return true;
            nums[j] = e;
            if (judgePoint24(nums, cardsSize - 1)) return true;
            if (b != 0) {
                nums[j] = f;
                if (judgePoint24(nums, cardsSize - 1)) return true;
            }
        }
    }
    return false;
}