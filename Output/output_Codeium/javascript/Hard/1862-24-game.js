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
/**
 * @param {number[]} cards
 * @return {boolean}
 */
var judgePoint24 = function(cards) {
    const operations = ['+', '-', '*', '/'];
    for (let i = 0; i < operations.length; i++) {
        for (let j = 0; j < operations.length; j++) {
            for (let k = 0; k < operations.length; k++) {
                const a = cards[0];
                const b = cards[1];
                const c = cards[2];
                const d = cards[3];
                const expression = `(${a} ${operations[i]} ${b}) ${operations[j]} (${c} ${operations[k]} ${d})`;
                const result = eval(expression);
                if (Math.abs(result - 24) < 1e-9) {
                    return true;
                }
            }
        }
    }
    return false;
};