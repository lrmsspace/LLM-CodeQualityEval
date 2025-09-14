/**https://leetcode.com/problems/reverse-words-in-a-string-iii/ */
//Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.
// 
//Example 1:
//Input: s = "Let's take LeetCode contest"
//Output: "s'teL ekat edoCteeL tsetnoc"
//Example 2:
//Input: s = "Mr Ding"
//Output: "rM gniD"
// 
//Constraints:
//	1 <= s.length <= 5 * 104
//	s contains printable ASCII characters.
//	s does not contain any leading or trailing spaces.
//	There is at least one word in s.
//	All the words in s are separated by a single space.
char* reverseWords(char* s) {
    
    int start = 0;
    int end = 0;
    while (*s) {
        // find the end of the word
        while (*s && *s!= ' ') {
            s++;
            end++;
        }
        
        // reverse the word
        int left = start;
        int right = end - 1;
        while (left < right) {
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left++;
            right--;
        }
        
        // move to the next word
        start = end + 1;
        end = start;
    }
    
    return s;
}