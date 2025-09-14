/**https://leetcode.com/problems/concatenated-words/ */
//Given an array of strings words (without duplicates), return all the concatenated words in the given list of words.
//A concatenated word is defined as a string that is comprised entirely of at least two shorter words (not necessarily distinct) in the given array.
// 
//Example 1:
//Input: words = ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]
//Output: ["catsdogcats","dogcatsdog","ratcatdogcat"]
//Explanation: "catsdogcats" can be concatenated by "cats", "dog" and "cats"; 
//"dogcatsdog" can be concatenated by "dog", "cats" and "dog"; 
//"ratcatdogcat" can be concatenated by "rat", "cat", "dog" and "cat".
//Example 2:
//Input: words = ["cat","dog","catdog"]
//Output: ["catdog"]
// 
//Constraints:
//	1 <= words.length <= 104
//	1 <= words[i].length <= 30
//	words[i] consists of only lowercase English letters.
//	All the strings of words are unique.
//	1 <= sum(words[i].length) <= 105
/**
 * @param {string[]} words
 * @return {string[]}
 */
var findAllConcatenatedWordsInADict = function(words) {
    const wordSet = new Set(words);
    const result = [];
    
    function backtrack(start, current) {
        if (wordSet.has(current)) {
            result.push(current);
            return;
        }
        
        for (let i = start; i < words.length; i++) {
            if (current.length + words[i].length + 1 > wordSet.size) break;
            
            if (wordSet.has(words[i])) {
                backtrack(i + 1, current +'' + words[i]);
            }
        }
    }
    
    for (let i = 0; i < words.length; i++) {
        backtrack(0, words[i]);
    }
    
    return result;
    
};