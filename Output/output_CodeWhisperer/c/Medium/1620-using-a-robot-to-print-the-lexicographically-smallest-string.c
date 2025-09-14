/**https://leetcode.com/problems/using-a-robot-to-print-the-lexicographically-smallest-string/ */
//You are given a string s and a robot that currently holds an empty string t. Apply one of the following operations until s and t are both empty:
//	Remove the first character of a string s and give it to the robot. The robot will append this character to the string t.
//	Remove the last character of a string t and give it to the robot. The robot will write this character on paper.
//Return the lexicographically smallest string that can be written on the paper.
// 
//Example 1:
//Input: s = "zza"
//Output: "azz"
//Explanation: Let p denote the written string.
//Initially p="", s="zza", t="".
//Perform first operation three times p="", s="", t="zza".
//Perform second operation three times p="azz", s="", t="".
//Example 2:
//Input: s = "bac"
//Output: "abc"
//Explanation: Let p denote the written string.
//Perform first operation twice p="", s="c", t="ba". 
//Perform second operation twice p="ab", s="c", t="". 
//Perform first operation p="ab", s="", t="c". 
//Perform second operation p="abc", s="", t="".
//Example 3:
//Input: s = "bdda"
//Output: "addb"
//Explanation: Let p denote the written string.
//Initially p="", s="bdda", t="".
//Perform first operation four times p="", s="", t="bdda".
//Perform second operation four times p="addb", s="", t="".
// 
//Constraints:
//	1 <= s.length <= 105
//	s consists of only English lowercase letters.   
char* robotWithString(char* s) {
    int len = strlen(s);
    
    // Create an array to store the result
    char* result = (char*)malloc((len + 1) * sizeof(char));
    
    // Create a stack to simulate the robot's string t
    char* stack = (char*)malloc((len + 1) * sizeof(char));
    int top = -1;  // Stack pointer
    
    // Create an array to store the minimum character from each position onwards
    char* min_suffix = (char*)malloc((len + 1) * sizeof(char));
    min_suffix[len] = '{';  // Character after 'z' in ASCII
    
    // Fill the min_suffix array from right to left
    for (int i = len - 1; i >= 0; i--) {
        min_suffix[i] = (s[i] < min_suffix[i + 1]) ? s[i] : min_suffix[i + 1];
    }
    
    int result_idx = 0;
    int s_idx = 0;
    
    // Process the string
    while (s_idx < len || top >= 0) {
        // If the stack is empty or the top of the stack is greater than the minimum remaining in s
        if (top == -1 || (s_idx < len && stack[top] > min_suffix[s_idx])) {
            // Take a character from s and add it to the stack
            stack[++top] = s[s_idx++];
        } else {
            // Pop from the stack and add to the result
            result[result_idx++] = stack[top--];
        }
    }
    
    // Null-terminate the result string
    result[result_idx] = '\0';
    
    // Free allocated memory
    free(stack);
    free(min_suffix);
    
    return result;
}
