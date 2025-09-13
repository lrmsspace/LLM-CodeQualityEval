/*
 You are given a string s. It may contain any number of '*' characters. Your task is to remove all '*' characters.
 While there is a '*', do the following operation:
 Delete the leftmost '*' and the smallest non-'*' character to its left. If there are several smallest characters, you can delete any of them.
 Return the lexicographically smallest resulting string after removing all '*' characters.
 Example 1:
 Input: s = "aaba*"
 Output: "aab"
 Explanation:
 We should delete one of the 'a' characters with '*'. If we choose s[3], s becomes the lexicographically smallest.
 Example 2:
 Input: s = "abc"
 Output: "abc"
 Explanation:
 There is no '*' in the string.
 Constraints:
 1 <= s.length <= 105
 s consists only of lowercase English letters and '*'.
 The input is generated such that it is possible to delete all '*' characters.
*/

/**
 * @param {string} s
 * @return {string}
 */
var clearStars = function(s) {
    let arr = s.split('');
    let stars = [];
    let letters = [];
    for (let i = 0; i < arr.length; i++) {
        if (arr[i] === '*') {
            stars.push(i);
        } else {
            letters.push([arr[i], i]);
        }
    }
    letters.sort((a, b) => {
        if (a[0] < b[0]) {
            return -1;
        } else if (a[0] > b[0]) {
            return 1;
        } else {
            return 0;
        }
    });
    stars.sort((a, b) => a - b);
    for (let i = 0; i < stars.length; i++) {
        let j = 0;
        while (j < letters.length) {
            if (letters[j][1] < stars[i]) {
                j++;
            } else {
                letters.splice(j, 1);
                break;
            }
        }
    }
    let res = '';
    for (let i = 0; i < letters.length; i++) {
        res += letters[i][0];
    }
    return res;
            
};