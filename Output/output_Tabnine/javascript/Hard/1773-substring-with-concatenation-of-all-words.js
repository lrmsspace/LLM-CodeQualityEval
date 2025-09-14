/**https://leetcode.com/problems/substring-with-concatenation-of-all-words/ */
//You are given a string s and an array of strings words. All the strings of words are of the same length.
//A concatenated string is a string that exactly contains all the strings of any permutation of words concatenated.
//	For example, if words = ["ab","cd","ef"], then "abcdef", "abefcd", "cdabef", "cdefab", "efabcd", and "efcdab" are all concatenated strings. "acdbef" is not a concatenated string because it is not the concatenation of any permutation of words.
//Return an array of the starting indices of all the concatenated substrings in s. You can return the answer in any order.
// 
//Example 1:
//Input: s = "barfoothefoobarman", words = ["foo","bar"]
//Output: [0,9]
//Explanation:
//The substring starting at 0 is "barfoo". It is the concatenation of ["bar","foo"] which is a permutation of words.
//The substring starting at 9 is "foobar". It is the concatenation of ["foo","bar"] which is a permutation of words.
//Example 2:
//Input: s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
//Output: []
//Explanation:
//There is no concatenated substring.
//Example 3:
//Input: s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
//Output: [6,9,12]
//Explanation:
//The substring starting at 6 is "foobarthe". It is the concatenation of ["foo","bar","the"].
//The substring starting at 9 is "barthefoo". It is the concatenation of ["bar","the","foo"].
//The substring starting at 12 is "thefoobar". It is the concatenation of ["the","foo","bar"].
// 
//Constraints:
//	1 <= s.length <= 104
//	1 <= words.length <= 5000
//	1 <= words[i].length <= 30
//	s and words[i] consist of lowercase English letters.
/**
 * @param {string} s
 * @param {string[]} words
 * @return {number[]}
 */
var findSubstring = function(s, words) {
    const wordLen = words[0].length;
    const totalLen = wordLen * words.length;
    const map = new Map();
    const result = [];
    
    // Build the map for words
    for (const word of words) {
        map.set(word, (map.get(word) || 0) + 1);
    }
    
    // Slide the window over the string
    for (let i = 0; i <= s.length - totalLen; i++) {
        const windowMap = new Map();
        let count = 0;
        
        // Slide the window and count the occurrences of each word
        for (let j = i; j < i + totalLen; j += wordLen) {
            const word = s.slice(j, j + wordLen);
            
            if (!map.has(word)) {
                break;
            }
            
            windowMap.set(word, (windowMap.get(word) || 0) + 1);
            if (windowMap.get(word) <= map.get(word)) {
                count++;
            } else {
                break;
            }
        }
        
        // If the count of all words matches, add the starting index to the result
        if (count === words.length) {
            result.push(i);
        }
    }
    
    return result;
    
};