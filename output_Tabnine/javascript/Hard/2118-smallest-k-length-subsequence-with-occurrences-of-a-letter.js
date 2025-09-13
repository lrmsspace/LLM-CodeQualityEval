/**https://leetcode.com/problems/smallest-k-length-subsequence-with-occurrences-of-a-letter/ */
//You are given a string s, an integer k, a letter letter, and an integer repetition.
//Return the lexicographically smallest subsequence of s of length k that has the letter letter appear at least repetition times. The test cases are generated so that the letter appears in s at least repetition times.
//A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.
//A string a is lexicographically smaller than a string b if in the first position where a and b differ, string a has a letter that appears earlier in the alphabet than the corresponding letter in b.
// 
//Example 1:
//Input: s = "leet", k = 3, letter = "e", repetition = 1
//Output: "eet"
//Explanation: There are four subsequences of length 3 that have the letter 'e' appear at least 1 time:
//- "lee" (from "leet")
//- "let" (from "leet")
//- "let" (from "leet")
//- "eet" (from "leet")
//The lexicographically smallest subsequence among them is "eet".
//Example 2:
//Input: s = "leetcode", k = 4, letter = "e", repetition = 2
//Output: "ecde"
//Explanation: "ecde" is the lexicographically smallest subsequence of length 4 that has the letter "e" appear at least 2 times.
//Example 3:
//Input: s = "bb", k = 2, letter = "b", repetition = 2
//Output: "bb"
//Explanation: "bb" is the only subsequence of length 2 that has the letter "b" appear at least 2 times.
// 
//Constraints:
//	1 <= repetition <= k <= s.length <= 5 * 104
//	s consists of lowercase English letters.
//	letter is a lowercase English letter, and appears in s at least repetition times.
/**
 * @param {string} s
 * @param {number} k
 * @param {character} letter
 * @param {number} repetition
 * @return {string}
 */
var smallestSubsequence = function(s, k, letter, repetition) {
    // Create a frequency map of the characters in s
    const freqMap = new Map();
    for (let char of s) {
        freqMap.set(char, (freqMap.get(char) || 0) + 1);
    }
    
    // Create a priority queue to keep track of the characters in decreasing order of their frequency
    const pq = [];
    for (let [char, count] of freqMap) {
        if (char === letter) {
            for (let _ = 0; _ < count - repetition; _++) {
                pq.push(char);
            }
        } else {
            pq.push([char, count]);
        }
    }
    pq.sort((a, b) => b[1] - a[1]);
    
    // Create a result string to store the subsequence
    let result = '';
    
    // Iterate through the priority queue and add characters to the result string until k is reached
    while (pq.length > 0 && k > 0) {
        const [char, count] = pq.shift();
        result += char;
        k--;
        
        // Update the frequency of the current character in the priority queue
        if (freqMap.get(char) > 0) {
            freqMap.set(char, freqMap.get(char) - 1);
            if (freqMap.get(char) > 0) {
                pq.push([char, freqMap.get(char)]);
            }
        }
    }
    
    return result;
    
};