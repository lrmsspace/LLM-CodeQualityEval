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
    const wordMap = new Map();
    for (let i = 0; i < words.length; i++) {
        wordMap.set(words[i], i);
    }
    const result = [];
    for (let i = 0; i < words.length; i++) {
        const word = words[i];
        for (let j = 0; j <= word.length; j++) {
            const left = word.slice(0, j);
            const right = word.slice(j);
            if (isPalindrome(left)) {
                const reversedRight = right.split('').reverse().join('');
                if (wordMap.has(reversedRight) && wordMap.get(reversedRight) !== i) {
                    result.push([wordMap.get(reversedRight), i]);
                }
            }
            if (j !== word.length && isPalindrome(right)) {
                const reversedLeft = left.split('').reverse().join('');
                if (wordMap.has(reversedLeft) && wordMap.get(reversedLeft) !== i) {
                    result.push([i, wordMap.get(reversedLeft)]);
                }
            }
        }
    }
    return result;

};