/**https://leetcode.com/problems/uncommon-words-from-two-sentences/ */
//A sentence is a string of single-space separated words where each word consists only of lowercase letters.
//A word is uncommon if it appears exactly once in one of the sentences, and does not appear in the other sentence.
//Given two sentences s1 and s2, return a list of all the uncommon words. You may return the answer in any order.
// 
//Example 1:
//Input: s1 = "this apple is sweet", s2 = "this apple is sour"
//Output: ["sweet","sour"]
//Explanation:
//The word "sweet" appears only in s1, while the word "sour" appears only in s2.
//Example 2:
//Input: s1 = "apple apple", s2 = "banana"
//Output: ["banana"]
// 
//Constraints:
//	1 <= s1.length, s2.length <= 200
//	s1 and s2 consist of lowercase English letters and spaces.
//	s1 and s2 do not have leading or trailing spaces.
//	All the words in s1 and s2 are separated by a single space.
/**
 * @param {string} s1
 * @param {string} s2
 * @return {string[]}
 */
var uncommonFromSentences = function(s1, s2) {
    let s1Arr = s1.split(' ');
    let s2Arr = s2.split(' ');
    let s1Map = new Map();
    let s2Map = new Map();
    let res = [];
    for(let i = 0; i < s1Arr.length; i++){
        if(s1Map.has(s1Arr[i])){
            s1Map.set(s1Arr[i], s1Map.get(s1Arr[i]) + 1);
        }else{
            s1Map.set(s1Arr[i], 1);
        }
    }
    for(let i = 0; i < s2Arr.length; i++){
        if(s2Map.has(s2Arr[i])){
            s2Map.set(s2Arr[i], s2Map.get(s2Arr[i]) + 1);
        }else{
            s2Map.set(s2Arr[i], 1);
        }
    }
    for(let [key, value] of s1Map){
        if(s2Map.has(key)){
            let min = Math.min(value, s2Map.get(key));
            for(let i = 0; i < min; i++){
                result.push(key);
            }
        }
    }
    return result;
};