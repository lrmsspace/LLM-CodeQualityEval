/**https://leetcode.com/problems/count-common-words-with-one-occurrence/ */
//Given two string arrays words1 and words2, return the number of strings that appear exactly once in each of the two arrays.
// 
//Example 1:
//Input: words1 = ["leetcode","is","amazing","as","is"], words2 = ["amazing","leetcode","is"]
//Output: 2
//Explanation:
//- "leetcode" appears exactly once in each of the two arrays. We count this string.
//- "amazing" appears exactly once in each of the two arrays. We count this string.
//- "is" appears in each of the two arrays, but there are 2 occurrences of it in words1. We do not count this string.
//- "as" appears once in words1, but does not appear in words2. We do not count this string.
//Thus, there are 2 strings that appear exactly once in each of the two arrays.
//Example 2:
//Input: words1 = ["b","bb","bbb"], words2 = ["a","aa","aaa"]
//Output: 0
//Explanation: There are no strings that appear in each of the two arrays.
//Example 3:
//Input: words1 = ["a","ab"], words2 = ["a","a","a","ab"]
//Output: 1
//Explanation: The only string that appears exactly once in each of the two arrays is "ab".
// 
//Constraints:
//	1 <= words1.length, words2.length <= 1000
//	1 <= words1[i].length, words2[j].length <= 30
//	words1[i] and words2[j] consists only of lowercase English letters.
/**
 * @param {string[]} words1
 * @param {string[]} words2
 * @return {number}
 */
var countWords = function(words1, words2) {
    let count = 0;
    const map1 = new Map();
    const map2 = new Map();
    
    for (const word of words1) {
        map1.set(word, (map1.get(word) || 0) + 1);
    }
    
    for (const word of words2) {
        map2.set(word, (map2.get(word) || 0) + 1);
    }
    
    for (const [word, count] of map1) {
        if (map2.get(word) === 1 && count === 1) {
            count++;
        }
    }
    
    return count;
};