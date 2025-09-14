/**https://leetcode.com/problems/additive-number/ */
//An additive number is a string whose digits can form an additive sequence.
//A valid additive sequence should contain at least three numbers. Except for the first two numbers, each subsequent number in the sequence must be the sum of the preceding two.
//Given a string containing only digits, return true if it is an additive number or false otherwise.
//Note: Numbers in the additive sequence cannot have leading zeros, so sequence 1, 2, 03 or 1, 02, 3 is invalid.
// 
//Example 1:
//Input: "112358"
//Output: true
//Explanation: 
//The digits can form an additive sequence: 1, 1, 2, 3, 5, 8. 
//1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
//Example 2:
//Input: "199100199"
//Output: true
//Explanation: 
//The additive sequence is: 1, 99, 100, 199. 
//1 + 99 = 100, 99 + 100 = 199
// 
//Constraints:
//	1 <= num.length <= 35
//	num consists only of digits.
// 
//Follow up: How would you handle overflow for very large input integers?
/**
 * @param {string} num
 * @return {boolean}
 */
var isAdditiveNumber = function(num) {
    const isValid = (num1, num2, num3) => {
        if (num1 != '0' && num1.startsWith('0')) return false;
        if (num2 != '0' && num2.startsWith('0')) return false;
        let sum = (BigInt(num1) + BigInt(num2)).toString();
        if (sum == num3) return true;
        return false;
    }
    const dfs = (i, j) => {
        for (let k = j + 1; k < num.length; k++) {
            let num1 = num.substring(i, j + 1);
            let num2 = num.substring(j + 1, k + 1);
            if (k == num.length - 1 || isValid(num1, num2, num.substring(k + 1))) {
                return true;
            }
            if (isValid(num1, num2, num.substring(j + 1, k + 2))) {
                if (dfs(j + 1, k)) return true;
            }
        }
        return false;
    }
    for (let i = 0; i < num.length - 2; i++) {
        if (i == 0 || (i == 1 && num[0] != '0')) {
            for (let j = i + 1; j < num.length - 1; j++) {
                if (dfs(i, j)) return true;
            }
        }
    }
    return false;
};