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
    const vowels = 'aeiouAEIOU';
    let left = 0;
    let right = s.length - 1;
    const strArray = s.split('');

    while (left < right) {
        if (vowels.includes(strArray[left]) && vowels.includes(strArray[right])) {
            [strArray[left], strArray[right]] = [strArray[right], strArray[left]];
            left++;
            right--;
        } else {
            if (!vowels.includes(strArray[left])) left++;
            if (!vowels.includes(strArray[right])) right--;
        }
    }

    return strArray.join('');    
};