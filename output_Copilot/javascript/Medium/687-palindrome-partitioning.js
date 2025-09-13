/**https://leetcode.com/problems/palindrome-partitioning/ */
//Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.
// 
//Example 1:
//Input: s = "aab"
//Output: [["a","a","b"],["aa","b"]]
//Example 2:
//Input: s = "a"
//Output: [["a"]]
// 
//Constraints:
//	1 <= s.length <= 16
//	s contains only lowercase English letters.
/**
 * @param {string} s
 * @return {string[][]}
 */
var partition = function(s) {
    const result = [];
    const path = [];
    
    function backtrack(start) {
        if (start === s.length) {
            result.push([...path]);
            return;
        }
        
        for (let end = start; end < s.length; end++) {
            const substring = s.slice(start, end + 1);
            if (isPalindrome(substring)) {
                path.push(substring);
                backtrack(end + 1);
                path.pop();
            }
        }
    }
    
    function isPalindrome(str) {
        let left = 0;
        let right = str.length - 1;
        while (left < right) {
            if (str[left] !== str[right]) return false;
            left++;
            right--;
        }
        return true;
    }
    
    backtrack(0);
    return result;    
};