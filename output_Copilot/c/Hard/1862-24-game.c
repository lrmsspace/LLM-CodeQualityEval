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
    double a = cards[0], b = cards[1], c = cards[2], d = cards[3];
    return judge(a, b, c, d) || judge(a, b, d, c) || judge(a, c, b, d) || judge(a, c, d, b) || judge(a, d, b, c) || judge(a, d, c, b) ||
           judge(b, a, c, d) || judge(b, a, d, c) || judge(b, c, a, d) || judge(b, c, d, a) || judge(b, d, a, c) || judge(b, d, c, a) ||
           judge(c, a, b, d) || judge(c, a, d, b) || judge(c, b, a, d) || judge(c, b, d, a) || judge(c, d, a, b) || judge(c, d, b, a) ||
           judge(d, a, b, c) || judge(d, a, c, b) || judge(d, b, a, c) || judge(d, b, c, a) || judge(d, c, a, b) || judge(d, c, b, a);    
}