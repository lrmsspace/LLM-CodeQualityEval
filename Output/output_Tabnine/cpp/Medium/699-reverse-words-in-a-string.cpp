/**https://leetcode.com/problems/reverse-words-in-a-string/ */
//Given an input string s, reverse the order of the words.
//A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.
//Return a string of the words in reverse order concatenated by a single space.
//Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.
// 
//Example 1:
//Input: s = "the sky is blue"
//Output: "blue is sky the"
//Example 2:
//Input: s = "  hello world  "
//Output: "world hello"
//Explanation: Your reversed string should not contain leading or trailing spaces.
//Example 3:
//Input: s = "a good   example"
//Output: "example good a"
//Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
// 
//Constraints:
//	1 <= s.length <= 104
//	s contains English letters (upper-case and lower-case), digits, and spaces ' '.
//	There is at least one word in s.
// 
//Follow-up: If the string data type is mutable in your language, can you solve it in-place with O(1) extra space?
class Solution {
public:
    string reverseWords(string s) {
        // Step 1: Remove leading and trailing spaces
        int start = 0, end = s.length() - 1;
        while (start <= end && s[start] =='') ++start;
        while (end >= start && s[end] =='') --end;
        
        // Step 2: Reverse the entire string
        reverse(s.begin(), s.end());
        
        // Step 3: Reverse each word
        int i = start;
        while (i <= end) {
            int j = i;
            while (j <= end && s[j]!='') ++j;
            reverse(s.begin() + i, s.begin() + j);
            i = j + 1;
        }
        
        return s;
        
    }
};