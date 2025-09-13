/**https://leetcode.com/problems/string-without-aaa-or-bbb/ */
//Given two integers a and b, return any string s such that:
//	s has length a + b and contains exactly a 'a' letters, and exactly b 'b' letters,
//	The substring 'aaa' does not occur in s, and
//	The substring 'bbb' does not occur in s.
// 
//Example 1:
//Input: a = 1, b = 2
//Output: "abb"
//Explanation: "abb", "bab" and "bba" are all correct answers.
//Example 2:
//Input: a = 4, b = 1
//Output: "aabaa"
// 
//Constraints:
//	0 <= a, b <= 100
//	It is guaranteed such an s exists for the given a and b.    
char* strWithout3a3b(int a, int b) {
    // Allocate memory for the result string
    char* result = (char*)malloc(sizeof(char) * (a + b + 1));
    int index = 0;
    
    // Keep track of consecutive characters
    int consecutiveA = 0;
    int consecutiveB = 0;
    
    // Build the string character by character
    while (a > 0 || b > 0) {
        // If we can add 'a' and doing so won't create "aaa"
        if ((a >= b && consecutiveA < 2) || (consecutiveB == 2)) {
            result[index++] = 'a';
            a--;
            consecutiveA++;
            consecutiveB = 0;
        }
        // Otherwise add 'b'
        else {
            result[index++] = 'b';
            b--;
            consecutiveB++;
            consecutiveA = 0;
        }
    }
    
    // Add null terminator
    result[index] = '\0';
    
    return result;
}
