/**https://leetcode.com/problems/vowels-of-all-substrings/ */
//Given a string word, return the sum of the number of vowels ('a', 'e', 'i', 'o', and 'u') in every substring of word.
//A substring is a contiguous (non-empty) sequence of characters within a string.
//Note: Due to the large constraints, the answer may not fit in a signed 32-bit integer. Please be careful during the calculations.
// 
//Example 1:
//Input: word = "aba"
//Output: 6
//Explanation: 
//All possible substrings are: "a", "ab", "aba", "b", "ba", and "a".
//- "b" has 0 vowels in it
//- "a", "ab", "ba", and "a" have 1 vowel each
//- "aba" has 2 vowels in it
//Hence, the total sum of vowels = 0 + 1 + 1 + 1 + 1 + 2 = 6. 
//Example 2:
//Input: word = "abc"
//Output: 3
//Explanation: 
//All possible substrings are: "a", "ab", "abc", "b", "bc", and "c".
//- "a", "ab", and "abc" have 1 vowel each
//- "b", "bc", and "c" have 0 vowels each
//Hence, the total sum of vowels = 1 + 1 + 1 + 0 + 0 + 0 = 3.
//Example 3:
//Input: word = "ltcd"
//Output: 0
//Explanation: There are no vowels in any substring of "ltcd".
// 
//Constraints:
//	1 <= word.length <= 105
//	word consists of lowercase English letters.
/**
 * @param {string} word
 * @return {number}
 */
var countVowels = function(word) {
    // Define the set of vowels
    const vowels = new Set(['a', 'e', 'i', 'o', 'u']);
    
    let sum = 0;
    
    // Iterate over all possible substrings
    for (let i = 0; i < word.length; i++) {
        for (let j = i; j < word.length; j++) {
            const substring = word.slice(i, j + 1);
            
            // Count the number of vowels in the substring
            let vowelCount = 0;
            for (let k = 0; k < substring.length; k++) {
                if (vowels.has(substring[k])) {
                    vowelCount++;
                }
            }
            
            // Add the vowel count to the total sum
            sum += vowelCount;
        }
    }
    
    return sum;
    
};