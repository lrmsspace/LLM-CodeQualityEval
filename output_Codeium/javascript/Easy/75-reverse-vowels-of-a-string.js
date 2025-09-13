/**https://leetcode.com/problems/reverse-vowels-of-a-string/ */
//Given a string s, reverse only all the vowels in the string and return it.
//The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.
// 
//Example 1:
//Input: s = "IceCreAm"
//Output: "AceCreIm"
//Explanation:
//The vowels in s are ['I', 'e', 'e', 'A']. On reversing the vowels, s becomes "AceCreIm".
//Example 2:
//Input: s = "leetcode"
//Output: "leotcede"
// 
//Constraints:
//	1 <= s.length <= 3 * 105
//	s consist of printable ASCII characters.
/**
 * @param {string} s
 * @return {string}
 */
var reverseVowels = function(s) {
    let vowels = ['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'];
    let sArray = s.split('');
    let left = 0;
    let right = sArray.length - 1;
    while (left < right) {
        while (left < right && !vowels.includes(sArray[left])) {
            left++;
        }
        while (left < right && !vowels.includes(sArray[right])) {
            right--;
        }
        [sArray[left], sArray[right]] = [sArray[right], sArray[left]];
        left++;
        right--;
    }
    return sArray.join('');
};