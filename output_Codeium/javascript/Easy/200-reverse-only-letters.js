/**https://leetcode.com/problems/reverse-only-letters/ */
//Given a string s, reverse the string according to the following rules:
//	All the characters that are not English letters remain in the same position.
//	All the English letters (lowercase or uppercase) should be reversed.
//Return s after reversing it.
// 
//Example 1:
//Input: s = "ab-cd"
//Output: "dc-ba"
//Example 2:
//Input: s = "a-bC-dEf-ghIj"
//Output: "j-Ih-gfE-dCba"
//Example 3:
//Input: s = "Test1ng-Leet=code-Q!"
//Output: "Qedo1ct-eeLg=ntse-T!"
// 
//Constraints:
//	1 <= s.length <= 100
//	s consists of characters with ASCII values in the range [33, 122].
//	s does not contain '\"' or '\\'.
/**
 * @param {string} s
 * @return {string}
 */
var reverseOnlyLetters = function(s) {
    let result = s.split('');
    let left = 0;
    let right = s.length - 1;
    
    while (left < right) {
        if (!isLetter(result[left])) {
            left++;
        } else if (!isLetter(result[right])) {
            right--;
        } else {
            let temp = result[left];
            result[left] = result[right];
            result[right] = temp;
            left++;
            right--;
        }
    }
    
    return result.join('');
    
    function isLetter(char) {
        return char.charCodeAt(0) >= 65 && char.charCodeAt(0) <= 90 || char.charCodeAt(0) >= 97 && char.charCodeAt(0) <= 122;
    }
};