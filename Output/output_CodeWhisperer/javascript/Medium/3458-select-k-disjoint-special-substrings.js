/*
 Given a string s of length n and an integer k, determine whether it is possible to select k disjoint special substrings.
 A special substring is a substring where:
 Any character present inside the substring should not appear outside it in the string.
 The substring is not the entire string s.
 Note that all k substrings must be disjoint, meaning they cannot overlap.
 Return true if it is possible to select k such disjoint special substrings; otherwise, return false.
 Example 1:
 Input: s = "abcdbaefab", k = 2
 Output: true
 Explanation:
 We can select two disjoint special substrings: "cd" and "ef".
 "cd" contains the characters 'c' and 'd', which do not appear elsewhere in s.
 "ef" contains the characters 'e' and 'f', which do not appear elsewhere in s.
 Example 2:
 Input: s = "cdefdc", k = 3
 Output: false
 Explanation:
 There can be at most 2 disjoint special substrings: "e" and "f". Since k = 3, the output is false.
 Example 3:
 Input: s = "abeabe", k = 0
 Output: true
 Constraints:
 2 <= n == s.length <= 5 * 104
 0 <= k <= 26
 s consists only of lowercase English letters.
*/

/**
 * @param {string} s
 * @param {number} k
 * @return {boolean}
 */
var maxSubstringLength = function(s, k) {
    let map = new Map();
    let max = 0;
    for(let i = 0; i < s.length; i++){
        if(map.has(s[i])){
            map.get(s[i]).push(i);
        }else{
            map.set(s[i], [i]);
        }
    }
    for(let [key, value] of map){
        if(value.length < k) continue;
        for(let i = 0; i < value.length - k + 1; i++){
            let start = value[i];
            let end = value[i + k - 1];
            let valid = true;
            for(let j = start; j <= end; j++){
                if(value.indexOf(j) === -1){
                    valid = false;
                    break;
                }
            }
            if(valid){
                max = Math.max(max, end - start + 1);
            }
        }
    }
    return max >= k ? true : false;
        
};