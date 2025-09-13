/**https://leetcode.com/problems/verbal-arithmetic-puzzle/ */
//Given an equation, represented by words on the left side and the result on the right side.
//You need to check if the equation is solvable under the following rules:
//	Each character is decoded as one digit (0 - 9).
//	No two characters can map to the same digit.
//	Each words[i] and result are decoded as one number without leading zeros.
//	Sum of numbers on the left side (words) will equal to the number on the right side (result).
//Return true if the equation is solvable, otherwise return false.
// 
//Example 1:
//Input: words = ["SEND","MORE"], result = "MONEY"
//Output: true
//Explanation: Map 'S'-> 9, 'E'->5, 'N'->6, 'D'->7, 'M'->1, 'O'->0, 'R'->8, 'Y'->'2'
//Such that: "SEND" + "MORE" = "MONEY" ,  9567 + 1085 = 10652
//Example 2:
//Input: words = ["SIX","SEVEN","SEVEN"], result = "TWENTY"
//Output: true
//Explanation: Map 'S'-> 6, 'I'->5, 'X'->0, 'E'->8, 'V'->7, 'N'->2, 'T'->1, 'W'->'3', 'Y'->4
//Such that: "SIX" + "SEVEN" + "SEVEN" = "TWENTY" ,  650 + 68782 + 68782 = 138214
//Example 3:
//Input: words = ["LEET","CODE"], result = "POINT"
//Output: false
//Explanation: There is no possible mapping to satisfy the equation, so we return false.
//Note that two different characters cannot map to the same digit.
// 
//Constraints:
//	2 <= words.length <= 5
//	1 <= words[i].length, result.length <= 7
//	words[i], result contain only uppercase English letters.
//	The number of different characters used in the expression is at most 10.
/**
 * @param {string[]} words
 * @param {string} result
 * @return {boolean}
 */
var isSolvable = function(words, result) {
    const maxLen = Math.max(...words.map(w => w.length), result.length);
    const charSet = new Set([...words.join(''), result]);
    if (charSet.size < 10) return false;
    const charArr = [...charSet];
    const firstChars = new Set(words.map(w => w[0]).concat(result[0]));
    const map = {};
    const backtrack = (i, j, carry, used) => {
        if (i === maxLen) return carry === 0;
        if (j === words.length) {
            const sum = words.reduce((acc, w) => acc + (map[w[i]] || 0), carry);
            return sum % 10 === map[result[i]] && backtrack(i + 1, 0, sum / 10 | 0, used);
        }
        for (let k = (j === words.length - 1 && firstChars.has(result[i])) ? 1 : 0; k < 10; k++) {
            if (used & (1 << k)) continue;
            map[charArr[k]] = k;
            if (backtrack(i, j + 1, carry, used | (1 << k))) return true;
        }
        map[charArr[map[result[i]]]] = undefined;
        return false;
    };
    return backtrack(0, 0, 0, 0);
};