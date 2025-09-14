/**https://leetcode.com/problems/determine-if-two-strings-are-close/ */
//Two strings are considered close if you can attain one from the other using the following operations:
//	Operation 1: Swap any two existing characters.
//	
//		For example, abcde -> aecdb
//	
//	
//	Operation 2: Transform every occurrence of one existing character into another existing character, and do the same with the other character.
//	
//		For example, aacabb -> bbcbaa (all a's turn into b's, and all b's turn into a's)
//	
//	
//You can use the operations on either string as many times as necessary.
//Given two strings, word1 and word2, return true if word1 and word2 are close, and false otherwise.
// 
//Example 1:
//Input: word1 = "abc", word2 = "bca"
//Output: true
//Explanation: You can attain word2 from word1 in 2 operations.
//Apply Operation 1: "abc" -> "acb"
//Apply Operation 1: "acb" -> "bca"
//Example 2:
//Input: word1 = "a", word2 = "aa"
//Output: false
//Explanation: It is impossible to attain word2 from word1, or vice versa, in any number of operations.
//Example 3:
//Input: word1 = "cabbba", word2 = "abbccc"
//Output: true
//Explanation: You can attain word2 from word1 in 3 operations.
//Apply Operation 1: "cabbba" -> "caabbb"
//Apply Operation 2: "caabbb" -> "baaccc"
//Apply Operation 2: "baaccc" -> "abbccc"
// 
//Constraints:
//	1 <= word1.length, word2.length <= 105
//	word1 and word2 contain only lowercase English letters.
/**
 * @param {string} word1
 * @param {string} word2
 * @return {boolean}
 */
var closeStrings = function(word1, word2) {
    let w1 = word1.split('');
    let w2 = word2.split('');
    let w1_set = new Set(w1);
    let w2_set = new Set(w2);
    if(w1_set.size !== w2_set.size) return false;
    let w1_map = new Map();
    let w2_map = new Map();
    for(let i = 0; i < w1.length; i++){
        if(w1_map.has(w1[i])){
            w1_map.set(w1[i], w1_map.get(w1[i]) + 1);
        }else{
            w1_map.set(w1[i], 1);
        }
        if(w2_map.has(w2[i])){
            w2_map.set(w2[i], w2_map.get(w2[i]) + 1);
        }else{
            w2_map.set(w2[i], 1);
        }
    }
    let w1_arr = [];
    for(let [key, value] of w1_map){
        w1_arr.push(value);
    }
    w1_arr.sort((a, b) => a - b);
    let w2_arr = [];
    for(let [key, value] of w2_map){
        w2_arr.push(value);
    }
    w2_arr.sort((a, b) => a - b);
    for(let i = 0; i < w1_arr.length; i++){
        if(w1_arr[i] !== w2_arr[i]) return false;
    }
    return true;
};