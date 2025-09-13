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
    let map = new Map();
    for(let i=0;i<text.length;i++){
        if(map.has(text[i])){
            map.set(text[i],map.get(text[i])+1);
        }else{
            map.set(text[i],1);
        }
    }
    let count = 0;
    while(map.has("b") && map.has("a") && map.has("l") && map.has("o") && map.has("n")){
        map.set("b",map.get("b")-1);
        map.set("a",map.get("a")-1);
        map.set("l",map.get("l")-2);
    }
    return count;
};