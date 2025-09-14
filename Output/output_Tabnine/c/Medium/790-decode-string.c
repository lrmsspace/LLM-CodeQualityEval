/**https://leetcode.com/problems/decode-string/ */
//Given an encoded string, return its decoded string.
//The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.
//You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc. Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there will not be input like 3a or 2[4].
//The test cases are generated so that the length of the output will never exceed 105.
// 
//Example 1:
//Input: s = "3[a]2[bc]"
//Output: "aaabcbc"
//Example 2:
//Input: s = "3[a2[c]]"
//Output: "accaccacc"
//Example 3:
//Input: s = "2[abc]3[cd]ef"
//Output: "abcabccdcdcdef"
// 
//Constraints:
//	1 <= s.length <= 30
//	s consists of lowercase English letters, digits, and square brackets '[]'.
//	s is guaranteed to be a valid input.
//	All the integers in s are in the range [1, 300].
char* decodeString(char* s) {
    int n = strlen(s);
    char* stack = (char*)malloc((n + 1) * sizeof(char));
    int top = -1;
    char* result = (char*)malloc((n + 1) * sizeof(char));
    int resultTop = 0;
    
    for (int i = 0; i < n; i++) {
        if (s[i] == '[') {
            stack[++top] = s[i];
        } else if (s[i] == ']') {
            char* temp = (char*)malloc((resultTop + 1) * sizeof(char));
            int count = 0;
            int j = top;
            while (stack[j]!= '[') {
                temp[count++] = result[--resultTop];
                j--;
            }
            top--;
            j--;
            int repeatCount = 0;
            while (isdigit(stack[j])) {
                repeatCount = repeatCount * 10 + (stack[j] - '0');
                j--;
            }
            for (int k = 0; k < repeatCount; k++) {
                for (int l = count - 1; l >= 0; l--) {
                    result[resultTop++] = temp[l];
                }
            }
            free(temp);
        } else if (isdigit(s[i])) {
            int count = 0;
            while (isdigit(s[i])) {
                count = count * 10 + (s[i] - '0');
                i++;
            }
            i--;
            for (int j = resultTop - count; j < resultTop; j++) {
                result[resultTop++] = result[j];
            }
        } else {
            result[resultTop++] = s[i];
        }
}
    result[resultTop] = '\0';
    free(stack);
    return result;
}