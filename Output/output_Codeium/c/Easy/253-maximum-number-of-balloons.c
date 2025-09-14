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
    int b = 0, a = 0, l = 0, o = 0, n = 0;
    for (int i = 0; text[i]; i++) {
        switch (text[i]) {
            case 'b': b++; break;
            case 'a': a++; break;
            case 'l': l++; break;
            case 'o': o++; break;
            case 'n': n++; break;
        }
    }
    int res = INT_MAX;
    res = fmin(res, b);
    res = fmin(res, a);
    res = fmin(res, l / 2);
    res = fmin(res, o / 2);
    res = fmin(res, n);
    return res;
}