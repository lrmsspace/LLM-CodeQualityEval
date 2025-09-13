/**https://leetcode.com/problems/find-original-array-from-doubled-array/ */
//An integer array original is transformed into a doubled array changed by appending twice the value of every element in original, and then randomly shuffling the resulting array.
//Given an array changed, return original if changed is a doubled array. If changed is not a doubled array, return an empty array. The elements in original may be returned in any order.
// 
//Example 1:
//Input: changed = [1,3,4,2,6,8]
//Output: [1,3,4]
//Explanation: One possible original array could be [1,3,4]:
//- Twice the value of 1 is 1 * 2 = 2.
//- Twice the value of 3 is 3 * 2 = 6.
//- Twice the value of 4 is 4 * 2 = 8.
//Other original arrays could be [4,3,1] or [3,1,4].
//Example 2:
//Input: changed = [6,3,0,1]
//Output: []
//Explanation: changed is not a doubled array.
//Example 3:
//Input: changed = [1]
//Output: []
//Explanation: changed is not a doubled array.
// 
//Constraints:
//	1 <= changed.length <= 105
//	0 <= changed[i] <= 105
/**
 * @param {number[]} changed
 * @return {number[]}
 */
var findOriginalArray = function(changed) {
    let freq = new Map();
    let doubled = [];
    
    for (let num of changed) {
        if (freq.has(num)) {
            freq.set(num, freq.get(num) + 1);
        } else {
            freq.set(num, 1);
        }
    }
    
    for (let [num, count] of freq.entries()) {
        if (count % 2!== 0) {
            return [];
        }
        
        doubled.push(num);
        freq.set(num, count / 2);
    }
    
    doubled.sort((a, b) => a - b);
    
    let original = [];
    for (let num of doubled) {
        if (freq.has(num)) {
            original.push(num);
            freq.set(num, freq.get(num) - 1);
        }
        
        if (freq.has(2 * num)) {
            original.push(2 * num);
            freq.set(2 * num, freq.get(2 * num) - 1);
        }
        
        if (freq.get(num) === 0) {
            freq.delete(num);
        }
        
        if (freq.get(2 * num) === 0) {
            freq.delete(2 * num);
        }
    }
    
    return original.length === freq.size? original : [];
    
};