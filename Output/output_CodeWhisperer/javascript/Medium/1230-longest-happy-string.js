/**https://leetcode.com/problems/longest-happy-string/ */
//A string s is called happy if it satisfies the following conditions:
//	s only contains the letters 'a', 'b', and 'c'.
//	s does not contain any of "aaa", "bbb", or "ccc" as a substring.
//	s contains at most a occurrences of the letter 'a'.
//	s contains at most b occurrences of the letter 'b'.
//	s contains at most c occurrences of the letter 'c'.
//Given three integers a, b, and c, return the longest possible happy string. If there are multiple longest happy strings, return any of them. If there is no such string, return the empty string "".
//A substring is a contiguous sequence of characters within a string.
// 
//Example 1:
//Input: a = 1, b = 1, c = 7
//Output: "ccaccbcc"
//Explanation: "ccbccacc" would also be a correct answer.
//Example 2:
//Input: a = 7, b = 1, c = 0
//Output: "aabaa"
//Explanation: It is the only correct answer in this case.
// 
//Constraints:
//	0 <= a, b, c <= 100
//	a + b + c > 0
/**
 * @param {number} a
 * @param {number} b
 * @param {number} c
 * @return {string}
 */
var longestDiverseString = function(a, b, c) {
    let res = "";
    let map = new Map();
    map.set('a', a);
    map.set('b', b);
    map.set('c', c);
    while (true) {
        map.sort((a, b) => b[1] - a[1]);
        let i = 0;
        for (let [key, value] of map) {
            if (value <= 0) break;
            if (res.length >= 2 && res[res.length - 1] == key && res[res.length - 2] == key) break;
            res += key;
            map.set(key, value - 1);
            i++;
        }
        if (i == 0) break;
    }
    return res;
};