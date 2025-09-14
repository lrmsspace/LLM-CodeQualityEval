/**https://leetcode.com/problems/sum-game/ */
//Alice and Bob take turns playing a game, with Alice starting first.
//You are given a string num of even length consisting of digits and '?' characters. On each turn, a player will do the following if there is still at least one '?' in num:
//	Choose an index i where num[i] == '?'.
//	Replace num[i] with any digit between '0' and '9'.
//The game ends when there are no more '?' characters in num.
//For Bob to win, the sum of the digits in the first half of num must be equal to the sum of the digits in the second half. For Alice to win, the sums must not be equal.
//	For example, if the game ended with num = "243801", then Bob wins because 2+4+3 = 8+0+1. If the game ended with num = "243803", then Alice wins because 2+4+3 != 8+0+3.
//Assuming Alice and Bob play optimally, return true if Alice will win and false if Bob will win.
// 
//Example 1:
//Input: num = "5023"
//Output: false
//Explanation: There are no moves to be made.
//The sum of the first half is equal to the sum of the second half: 5 + 0 = 2 + 3.
//Example 2:
//Input: num = "25??"
//Output: true
//Explanation: Alice can replace one of the '?'s with '9' and it will be impossible for Bob to make the sums equal.
//Example 3:
//Input: num = "?3295???"
//Output: false
//Explanation: It can be proven that Bob will always win. One possible outcome is:
//- Alice replaces the first '?' with '9'. num = "93295???".
//- Bob replaces one of the '?' in the right half with '9'. num = "932959??".
//- Alice replaces one of the '?' in the right half with '2'. num = "9329592?".
//- Bob replaces the last '?' in the right half with '7'. num = "93295927".
//Bob wins because 9 + 3 + 2 + 9 = 5 + 9 + 2 + 7.
// 
//Constraints:
//	2 <= num.length <= 105
//	num.length is even.
//	num consists of only digits and '?'.
/**
 * @param {string} num
 * @return {boolean}
 */
var sumGame = function(num) {
    let n = num.length;
    let left = 0, right = 0;
    let leftCount = 0, rightCount = 0;
    for (let i = 0; i < n / 2; i++) {
        if (num[i] !== '?') left += parseInt(num[i]);
        else leftCount++;
        if (num[n - 1 - i] !== '?') right += parseInt(num[n - 1 - i]);
        else rightCount++;
    }
    if (left === right) return false;
    let diff = Math.abs(left - right);
    if (leftCount === 0 || rightCount === 0)return true;
    for (let i = 0; i < n / 2; i++) {
        if (num[i] === '?') {
            if (leftCount === 1 && rightCount === 1) return true;
            if (leftCount > rightCount) {
                if (diff > 9) return true;
                leftCount--;
                rightCount += diff;
            } else {
                if (diff > 9) return false;
                leftCount += diff;
                rightCount--;
            }
        }
        if (num[n - 1 - i] === '?') {
            if (leftCount === 1 && rightCount === 1) return true;
           if (leftCount < rightCount) {
              if (diff > 9) return true;
           }
        }
    }
    return false;
};