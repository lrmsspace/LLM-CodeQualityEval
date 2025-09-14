/**https://leetcode.com/problems/substring-with-largest-variance/ */
//The variance of a string is defined as the largest difference between the number of occurrences of any 2 characters present in the string. Note the two characters may or may not be the same.
//Given a string s consisting of lowercase English letters only, return the largest variance possible among all substrings of s.
//A substring is a contiguous sequence of characters within a string.
// 
//Example 1:
//Input: s = "aababbb"
//Output: 3
//Explanation:
//All possible variances along with their respective substrings are listed below:
//- Variance 0 for substrings "a", "aa", "ab", "abab", "aababb", "ba", "b", "bb", and "bbb".
//- Variance 1 for substrings "aab", "aba", "abb", "aabab", "ababb", "aababbb", and "bab".
//- Variance 2 for substrings "aaba", "ababbb", "abbb", and "babb".
//- Variance 3 for substring "babbb".
//Since the largest possible variance is 3, we return it.
//Example 2:
//Input: s = "abcde"
//Output: 0
//Explanation:
//No letter occurs more than once in s, so the variance of every substring is 0.
// 
//Constraints:
//	1 <= s.length <= 104
//	s consists of lowercase English letters.
/**
 * @param {string} s
 * @return {number}
 */
var largestVariance = function(s) {
    let maxVariance = 0;
    for(let i=0; i<26; i++){
        for(let j=0; j<26; j++){
            if(i===j) continue;
            let char1 = String.fromCharCode(i+97);
            let char2 = String.fromCharCode(j+97);
            let char1Count = 0;
            let char2Count = 0;
            let char1Present = false;
            let char2Present = false;
            for(let k=0; k<s.length; k++){
                if(s[k]===char1){
                    char1Present = true;
                    char1Count++;
                }
                if(s[k]===char2){
                    char2Present = true;
                    char2Count++;
                }
            }
        }
    }
    return maxAppeal;
};