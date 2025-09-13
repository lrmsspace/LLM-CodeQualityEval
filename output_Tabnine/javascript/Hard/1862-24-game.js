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
    // Your code here
    // Helper function to evaluate the expression
    function evaluate(a, b, op) {
        switch (op) {
            case '+':
                return a + b;
            case '-':
                return a - b;
            case '*':
                return a * b;
            case '/':
                return a / b;
        }
    }
    
    // Helper function to generate all possible combinations of cards
    function generateCombinations(cards) {
        const n = cards.length;
        const res = [];
        
        function backtrack(start, curr) {
            if (curr.length === n) {
                res.push(curr.slice());
                return;
            }
            
            for (let i = start; i < n; i++) {
                if (i > start && cards[i] === cards[i - 1]) continue; // Skip duplicates
                curr.push(cards[i]);
                backtrack(i + 1, curr);
                curr.pop();
            }
        }
        
        backtrack(0, []);
        return res;
    }
    
    // Generate all possible combinations
    const combinations = generateCombinations(cards);
    
    // Check if any combination can evaluate to 24
    for (const combination of combinations) {
        let result = combination[0];
        
        for (let i = 1; i < combination.length; i++) {
            result = evaluate(result, combination[i], '+-*/'.charAt(i - 1));
        }
        
        if (Math.abs(result - 24) < 1e-6) return true;
    }
    
    return false;
    
};