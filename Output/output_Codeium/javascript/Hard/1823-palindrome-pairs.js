/**https://leetcode.com/problems/palindrome-pairs/ */
//You are given a 0-indexed array of unique strings words.
//A palindrome pair is a pair of integers (i, j) such that:
//	0 <= i, j < words.length,
//	i != j, and
//	words[i] + words[j] (the concatenation of the two strings) is a palindrome.
//Return an array of all the palindrome pairs of words.
//You must write an algorithm with O(sum of words[i].length) runtime complexity.
// 
//Example 1:
//Input: words = ["abcd","dcba","lls","s","sssll"]
//Output: [[0,1],[1,0],[3,2],[2,4]]
//Explanation: The palindromes are ["abcddcba","dcbaabcd","slls","llssssll"]
//Example 2:
//Input: words = ["bat","tab","cat"]
//Output: [[0,1],[1,0]]
//Explanation: The palindromes are ["battab","tabbat"]
//Example 3:
//Input: words = ["a",""]
//Output: [[0,1],[1,0]]
//Explanation: The palindromes are ["a","a"]
// 
//Constraints:
//	1 <= words.length <= 5000
//	0 <= words[i].length <= 300
//	words[i] consists of lowercase English letters.
/**
 * @param {string[]} words
 * @return {number[][]}
 */
var palindromePairs = function(words) {
    const result = [];
    const map = new Map();
    for (let i = 0; i < words.length; i++) {
        map.set(words[i], i);
    }
    for (let i = 0; i < words.length; i++) {
        for (let j = 0; j <= words[i].length; j++) {
            const prefix = words[i].slice(0, j);
            const suffix = words[i].slice(j);
            if (isPalindrome(prefix)) {
                const reverseSuffix = suffix.split("").reverse().join("");
                if (map.has(reverseSuffix) && map.get(reverseSuffix) !== i) {
                    result.push([i, map.get(reverseSuffix)]);
                }
            }
            if (isPalindrome(suffix)) {
                const reversePrefix = prefix.split("").reverse().join("");
                if (map.has(reversePrefix) && map.get(reversePrefix) !== i) {
                    result.push([map.get(reversePrefix), i]);
                }
            }
        }
    }
    return result;
    function isPalindrome(word) {
        let left = 0, right = word.length - 1;
        while (left < right) {
            if (word[left] !== word[right]) return false;
            left++;
            right--;
        }
        return true;
    }
};