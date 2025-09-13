/**https://leetcode.com/problems/remove-invalid-parentheses/ */
//Given a string s that contains parentheses and letters, remove the minimum number of invalid parentheses to make the input string valid.
//Return a list of unique strings that are valid with the minimum number of removals. You may return the answer in any order.
// 
//Example 1:
//Input: s = "()())()"
//Output: ["(())()","()()()"]
//Example 2:
//Input: s = "(a)())()"
//Output: ["(a())()","(a)()()"]
//Example 3:
//Input: s = ")("
//Output: [""]
// 
//Constraints:
//	1 <= s.length <= 25
//	s consists of lowercase English letters and parentheses '(' and ')'.
//	There will be at most 20 parentheses in s.
/**
 * @param {string} s
 * @return {string[]}
 */
var removeInvalidParentheses = function(s) {
    let result = new Set(); // Use a set to avoid duplicates
    let minRemoved = Infinity; // Track the minimum number of removals

    function isValid(str) {
        let balance = 0;
        for (let char of str) {
            if (char === '(') balance++;
            else if (char === ')') balance--;
            if (balance < 0) return false; // More ')' than '('
        }
        return balance === 0; // Must be balanced at the end
    }

    function backtrack(start, leftCount, rightCount, removedCount, currentStr) {
        if (start === s.length) {
            if (leftCount === rightCount) {
                if (removedCount < minRemoved) {
                    minRemoved = removedCount;
                    result.clear(); // Clear previous results
                }
                if (removedCount === minRemoved) {
                    result.add(currentStr); // Add valid string to result
                }
            }
            return;
        }

        const char = s[start];
        if (char === '(') {
            // Option 1: Exclude this '(' and increase removed count
            backtrack(start + 1, leftCount, rightCount, removedCount + 1, currentStr);
            // Option 2: Include this '('
            backtrack(start + 1, leftCount + 1, rightCount, removedCount, currentStr + char);
        } else if (char === ')') {
            // Option 1: Exclude this ')' and increase removed count
            backtrack(start + 1, leftCount, rightCount, removedCount + 1, currentStr);
            // Option 2: Include this ')' only if we have a matching '('
            if (leftCount > rightCount) {
                backtrack(start + 1, leftCount, rightCount + 1, removedCount, currentStr + char);
            }
        } else {
            // Just add the letter to the current string
            backtrack(start + 1, leftCount, rightCount, removedCount, currentStr + char);
        }
    }

    backtrack(0, 0, 0, 0, '');
    return Array.from(result); // Convert set to array before returning    
};