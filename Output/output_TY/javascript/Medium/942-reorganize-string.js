/**https://leetcode.com/problems/reorganize-string/ */
//Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.
//Return any possible rearrangement of s or return "" if not possible.
// 
//Example 1:
//Input: s = "aab"
//Output: "aba"
//Example 2:
//Input: s = "aaab"
//Output: ""
// 
//Constraints:
//	1 <= s.length <= 500
//	s consists of lowercase English letters.
/**
 * @param {string} s
 * @return {string}
 */
var reorganizeString = function(s) {
    let map = new Map();
    for(let i=0;i<s.length;i++){
        if(map.has(s[i])){
            map.set(s[i],map.get(s[i])+1);
        }else{
            map.set(s[i],1);
        }
    }
    let maxHeap = new MaxHeap();
    for(let [key,value] of map){
        maxHeap.insert([key,value]);
    }
    let result = "";
    while(maxHeap.size()>1){
        let [first,firstCount] = maxHeap.extractMax();
        let [second,secondCount] = maxHeap.extractMax();
    }
    return result;

};