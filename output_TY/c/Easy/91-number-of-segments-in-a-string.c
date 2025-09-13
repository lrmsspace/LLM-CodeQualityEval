/**https://leetcode.com/problems/number-of-segments-in-a-string/ */
//Given a string s, return the number of segments in the string.
//A segment is defined to be a contiguous sequence of non-space characters.
// 
//Example 1:
//Input: s = "Hello, my name is John"
//Output: 5
//Explanation: The five segments are ["Hello,", "my", "name", "is", "John"]
//Example 2:
//Input: s = "Hello"
//Output: 1
// 
//Constraints:
//	0 <= s.length <= 300
//	s consists of lowercase and uppercase English letters, digits, or one of the following characters "!@#$%^&*()_+-=',.:".
//	The only space character in s is ' '.
int countSegments(char * s){
    int count = 0;
    int i = 0;
    while (s[i] != '\0') {
        if (s[i] != ' ' && (s[i + 1] == ' ' || s[i + 1] == '\0')) {
            count++;
        }
        i++;
    }
    return count;
}