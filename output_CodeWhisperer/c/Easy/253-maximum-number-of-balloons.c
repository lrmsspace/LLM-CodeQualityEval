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
int maxNumberOfBalloons(char* text) {
    int count[26] = {0};
    for (int i = 0; text[i] != '\0'; i++) {
        count[text[i] - 'a']++;
    }
    int min = count['b' - 'a'];
    min = min < count['a' - 'a'] ? min : count['a' - 'a'];
    min = min < count['l' - 'a'] / 2 ? min : count['l' - 'a'] / 2;
    min = min < count['o' - 'a'] / 2 ? min : count['o' - 'a'] / 2;
    min = min < count['n' - 'a'] ? min : count['n' - 'a'];
    return min;
    
}