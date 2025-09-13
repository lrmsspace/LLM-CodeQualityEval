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
    int i = 0;
    int b = 0;
    int a = 0;
    int l = 0;
    int o = 0;
    int n = 0;
    while (text[i] != '\0') {
        if (text[i] == 'b') {
            b++;
        } else if (text[i] == 'a') {
            a++;
        } else if (text[i] == 'l') {
            l++;
        } else if (text[i] == 'o') {
            o++;
        } else if (text[i] == 'n') {
            n++;
        }
        i++;
    }
    int min = b;
    if (a < min) {
        min = a;
    }
    if (l / 2 < min) {
        min = l / 2;
    }
    if (o / 2 < min) {
        min = o / 2;
    }
    if (n < min) {
        min = n;
    }
    return min;    
}