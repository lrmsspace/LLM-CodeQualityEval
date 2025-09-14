/*
 Given a string s containing only digits, return the lexicographically smallest string that can be obtained after swapping adjacent digits in s with the same parity at most once.
 Digits have the same parity if both are odd or both are even. For example, 5 and 9, as well as 2 and 4, have the same parity, while 6 and 9 do not.
 Example 1:
 Input: s = "45320"
 Output: "43520"
 Explanation: 
 s[1] == '5' and s[2] == '3' both have the same parity, and swapping them results in the lexicographically smallest string.
 Example 2:
 Input: s = "001"
 Output: "001"
 Explanation:
 There is no need to perform a swap because s is already the lexicographically smallest.
 Constraints:
 2 <= s.length <= 100
 s consists only of digits.
*/

char* getSmallestString(char* s) {
    int n = strlen(s);
    char* result = (char*)malloc(n + 1);
    strcpy(result, s); // Copy original string to result

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            // Check if both characters have the same parity
            if ((result[i] % 2) == (result[j] % 2)) {
                // Swap characters
                char temp = result[i];
                result[i] = result[j];
                result[j] = temp;

                // Check if the new string is lexicographically smaller
                if (strcmp(result, s) < 0) {
                    strcpy(s, result); // Update original string if smaller
                }

                // Swap back to restore original order
                temp = result[i];
                result[i] = result[j];
                result[j] = temp;
            }
        }
    }

    return s; // Return the modified string
    
}