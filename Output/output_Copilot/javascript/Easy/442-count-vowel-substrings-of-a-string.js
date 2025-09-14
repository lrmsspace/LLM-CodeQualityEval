/**https://leetcode.com/problems/count-vowel-substrings-of-a-string/ */
//A substring is a contiguous (non-empty) sequence of characters within a string.
//A vowel substring is a substring that only consists of vowels ('a', 'e', 'i', 'o', and 'u') and has all five vowels present in it.
//Given a string word, return the number of vowel substrings in word.
// 
//Example 1:
//Input: word = "aeiouu"
//Output: 2
//Explanation: The vowel substrings of word are as follows (underlined):
//- "aeiouu"
//- "aeiouu"
//Example 2:
//Input: word = "unicornarihan"
//Output: 0
//Explanation: Not all 5 vowels are present, so there are no vowel substrings.
//Example 3:
//Input: word = "cuaieuouac"
//Output: 7
//Explanation: The vowel substrings of word are as follows (underlined):
//- "cuaieuouac"
//- "cuaieuouac"
//- "cuaieuouac"
//- "cuaieuouac"
//- "cuaieuouac"
//- "cuaieuouac"
//- "cuaieuouac"
// 
//Constraints:
//	1 <= word.length <= 100
//	word consists of lowercase English letters only.
/**
 * @param {string} word
 * @return {number}
 */
var countVowelSubstrings = function(word) {
    const vowels = new Set(['a', 'e', 'i', 'o', 'u']);
    let count = 0;
    let left = 0;
    const seen = new Set();

    for (let right = 0; right < word.length; right++) {
        if (vowels.has(word[right])) {
            seen.add(word[right]);
            while (seen.size === 5) {
                count++;
                seen.delete(word[left]);
                left++;
            }
        } else {
            left = right + 1;
            seen.clear();
        }
    }

    return count;    
};