/**https://leetcode.com/problems/make-number-of-distinct-characters-equal/ */
//You are given two 0-indexed strings word1 and word2.
//A move consists of choosing two indices i and j such that 0 <= i < word1.length and 0 <= j < word2.length and swapping word1[i] with word2[j].
//Return true if it is possible to get the number of distinct characters in word1 and word2 to be equal with exactly one move. Return false otherwise.
// 
//Example 1:
//Input: word1 = "ac", word2 = "b"
//Output: false
//Explanation: Any pair of swaps would yield two distinct characters in the first string, and one in the second string.
//Example 2:
//Input: word1 = "abcc", word2 = "aab"
//Output: true
//Explanation: We swap index 2 of the first string with index 0 of the second string. The resulting strings are word1 = "abac" and word2 = "cab", which both have 3 distinct characters.
//Example 3:
//Input: word1 = "abcde", word2 = "fghij"
//Output: true
//Explanation: Both resulting strings will have 5 distinct characters, regardless of which indices we swap.
// 
//Constraints:
//	1 <= word1.length, word2.length <= 105
//	word1 and word2 consist of only lowercase English letters.
/**
 * @param {string} word1
 * @param {string} word2
 * @return {boolean}
 */
var isItPossible = function(word1, word2) {
    let map1 = new Map();
    let map2 = new Map();
    for(let i=0;i<word1.length;i++){
        map1.set(word1[i],map1.get(word1[i])?map1.get(word1[i])+1:1);
    }
    for(let i=0;i<word2.length;i++){
        map2.set(word2[i],map2.get(word2[i])?map2.get(word2[i])+1:1);
    }
    for(let i=97;i<=122;i++){
        for(let j=97;j<=122;j++){
            if(map1.has(String.fromCharCode(i)) && map2.has(String.fromCharCode(j))){
                let temp1 = map1.get(String.fromCharCode(i));
                let temp2 = map2.get(String.fromCharCode(j));
                map1.set(String.fromCharCode(i),temp1-1);
                map2.set(String.fromCharCode(j),temp2-1);
                map1.set(String.fromCharCode(j),map1.get(String.fromCharCode(j))?map1.get(String.fromCharCode(j))+1:1);
                map2.set(String.fromCharCode(i),map2.get(String.fromCharCode(i)))?map2.get(String.fromCharCode(i))+1:1;
            }
        }
    }
    return map1.size==map2.size;

};