/**https://leetcode.com/problems/number-of-segments-in-a-string/ */
//Given a string s, return the number of segments in the string.
//A segment is defined to be a contiguous sequence of non-space characters.
// 
//Example 1:
//Input: s = "Hello, my name is John"
//Output: 5
//Explanation: The five segments are ["Hello,", "my", "name", "is", "John"]
//Example 2:
//Input: s = "Hello"
//Output: 1
// 
//Constraints:
//	0 <= s.length <= 300
//	s consists of lowercase and uppercase English letters, digits, or one of the following characters "!@#$%^&*()_+-=',.:".
//	The only space character in s is ' '.
/**
 * @param {string} s
 * @return {number}
 */
var countSegments = function(s) {
    let count = 0;
    let isSpace = false;
    for(let i = 0; i < s.length; i++){
        if(s[i] === ' '){
            isSpace = true;
        }else{
            if(isSpace){
                count++;
            }
            isSpace = false;
        }
    }
    if(s[s.length - 1] !== ' '){
        count++;
    }
    return count;
};