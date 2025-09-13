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
    const result = [];
    
    // Build a map of words and their reversed versions
    for (let i = 0; i < words.length; i++) {
        const word = words[i];
        const reversed = word.split('').reverse().join('');
        
        wordMap.set(word, i);
        wordMap.set(reversed, i);
    }
    
    // Iterate through each word
    for (let i = 0; i < words.length; i++) {
        const word = words[i];
        const wordLength = word.length;
        
        // Check for palindromes of length 1
        for (let j = 0; j < wordLength; j++) {
            const prefix = word.slice(0, j);
            const suffix = word.slice(j);
            
            if (wordMap.has(suffix) && wordMap.get(suffix)!== i) {
                result.push([i, wordMap.get(suffix)]);
            }
            
            if (wordMap.has(prefix) && wordMap.get(prefix)!== i && prefix.length > 0) {
                result.push([wordMap.get(prefix), i]);
            }
        }
        
        // Check for palindromes of length greater than 1
        for (let j = 1; j < wordLength; j++) {
            const left = word.slice(0, j);
            const right = word.slice(j);
            
            if (wordMap.has(left) && wordMap.get(left)!== i && right === right.split('').reverse().join('')) {
                result.push([i, wordMap.get(left)]);
            }
            
            if (wordMap.has(right) && wordMap.get(right)!== i && left === left.split('').reverse().join('')) {
                result.push([wordMap.get(right), i]);
            }
        }
    }
    
    return result;
    
};