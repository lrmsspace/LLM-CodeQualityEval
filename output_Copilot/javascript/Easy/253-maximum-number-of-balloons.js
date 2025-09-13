/**https://leetcode.com/problems/maximum-number-of-balloons/ */
//Given a string text, you want to use the characters of text to form as many instances of the word "balloon" as possible.
//You can use each character in text at most once. Return the maximum number of instances that can be formed.
// 
//Example 1:
//Input: text = "nlaebolko"
//Output: 1
//Example 2:
//Input: text = "loonbalxballpoon"
//Output: 2
//Example 3:
//Input: text = "leetcode"
//Output: 0
// 
//Constraints:
//	1 <= text.length <= 104
//	text consists of lower case English letters only.
// 
//Note: This question is the same as  2287: Rearrange Characters to Make Target String.
/**
 * @param {string} text
 * @return {number}
 */
var maxNumberOfBalloons = function(text) {
    let count = {b: 0, a: 0, l: 0, o: 0, n: 0};
    for (let char of text) {
        if (count[char] !== undefined) {
            count[char]++;
        }
    }
    count.l = Math.floor(count.l / 2);
    count.o = Math.floor(count.o / 2);
    return Math.min(count.b, count.a, count.l, count.o, count.n);    
};