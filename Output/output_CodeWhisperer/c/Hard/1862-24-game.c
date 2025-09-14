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
    int i, j, k, l;
    double a, b, c, d;
    for (i = 0; i < cardsSize; i++) {
        for (j = 0; j < cardsSize; j++) {
            if (i != j) {
                a = cards[i];
                b = cards[j];
                for (k = 0; k < cardsSize; k++) {
                    if (k != i && k != j) {
                        c = cards[k];
                        for (l = 0; l < cardsSize; l++) {
                            if (l != i && l != j && l != k) {
                                d = cards[l];
                                if (judgePoint24Helper(a, b, c, d)) return true;
                                if (judgePoint24Helper(a, b, d, c)) return true;
                                if (judgePoint24Helper(a, c, b, d)) return true;
                                if (judgePoint24Helper(a, c, d, b)) return true;
                                if (judgePoint24Helper(a, d, b, c)) return true;
                                if (judgePoint24Helper(a, d, c, b)) return true;
                            }
                        }
                    }
                }
            }
        }
    }
    return false;

}