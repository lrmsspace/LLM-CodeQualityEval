/**https://leetcode.com/problems/lexicographically-smallest-beautiful-string/ */
//A string is beautiful if:
//	It consists of the first k letters of the English lowercase alphabet.
//	It does not contain any substring of length 2 or more which is a palindrome.
//You are given a beautiful string s of length n and a positive integer k.
//Return the lexicographically smallest string of length n, which is larger than s and is beautiful. If there is no such string, return an empty string.
//A string a is lexicographically larger than a string b (of the same length) if in the first position where a and b differ, a has a character strictly larger than the corresponding character in b.
//	For example, "abcd" is lexicographically larger than "abcc" because the first position they differ is at the fourth character, and d is greater than c.
// 
//Example 1:
//Input: s = "abcz", k = 26
//Output: "abda"
//Explanation: The string "abda" is beautiful and lexicographically larger than the string "abcz".
//It can be proven that there is no string that is lexicographically larger than the string "abcz", beautiful, and lexicographically smaller than the string "abda".
//Example 2:
//Input: s = "dc", k = 4
//Output: ""
//Explanation: It can be proven that there is no string that is lexicographically larger than the string "dc" and is beautiful.
// 
//Constraints:
//	1 <= n == s.length <= 105
//	4 <= k <= 26
//	s is a beautiful string.
/**
 * @param {string} s
 * @param {number} k
 * @return {string}
 */
var smallestBeautifulString = function(s, k) {
    let arr = s.split('');
    let n = arr.length;
    let i = n - 1;
    arr[i] = String.fromCharCode(arr[i].charCodeAt(0) + 1);
    while (i >= 0 && arr[i] > String.fromCharCode(k + 'a'.charCodeAt(0) - 1)) {
        if (i == 0) return '';
        i--;
        arr[i] = String.fromCharCode(arr[i].charCodeAt(0) + 1);
    }
    for (i = i + 1; i < n; i++) {
        for (let c = 'a'.charCodeAt(0); c < 'a'.charCodeAt(0) + k; c++) {
            arr[i] = String.fromCharCode(c);
            if (i > 0 && arr[i] == arr[i - 1]) continue;
            if (i > 1 && arr[i] == arr[i - 2]) continue;
            break;
        }
    }
    return arr.join('');
};