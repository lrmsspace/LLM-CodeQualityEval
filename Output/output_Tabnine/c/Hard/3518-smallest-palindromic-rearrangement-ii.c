/*
 You are given a palindromic string s and an integer k.
 Return the k-th lexicographically smallest palindromic permutation of s. If there are fewer than k distinct palindromic permutations, return an empty string.
 Note: Different rearrangements that yield the same palindromic string are considered identical and are counted once.
 Example 1:
 Input: s = "abba", k = 2
 Output: "baab"
 Explanation:
 The two distinct palindromic rearrangements of "abba" are "abba" and "baab".
 Lexicographically, "abba" comes before "baab". Since k = 2, the output is "baab".
 Example 2:
 Input: s = "aa", k = 2
 Output: ""
 Explanation:
 There is only one palindromic rearrangement: "aa".
 The output is an empty string since k = 2 exceeds the number of possible rearrangements.
 Example 3:
 Input: s = "bacab", k = 1
 Output: "abcba"
 Explanation:
 The two distinct palindromic rearrangements of "bacab" are "abcba" and "bacab".
 Lexicographically, "abcba" comes before "bacab". Since k = 1, the output is "abcba".
 Constraints:
 1 <= s.length <= 104
 s consists of lowercase English letters.
 s is guaranteed to be palindromic.
 1 <= k <= 106
*/

char* smallestPalindrome(char* s, int k) {

    // Step 1: Convert the string to a list of characters
    int n = strlen(s);
    char* chars = (char*)malloc((n + 1) * sizeof(char));
    strcpy(chars, s);
    chars[n] = '\0';
    
    // Step 2: Sort the characters in descending order
    qsort(chars, n, sizeof(char), compare);
    
    // Step 3: Find the k-th lexicographically smallest palindromic permutation
    int count = 0;
    int start = 0;
    int end = n - 1;
    while (count < k) {
        // Swap the characters at the start and end indices
        char temp = chars[start];
        chars[start] = chars[end];
        chars[end] = temp;
        
        // Increment the start index and decrement the end index
        start++;
        end--;
        
        // Increment the count
        count++;
        
        // If the palindrome is not valid, revert the swap and try the next permutation
        if (!isPalindrome(chars, start, end)) {
            count--;
            temp = chars[start];
            chars[start] = chars[end];
            chars[end] = temp;
            start++;
            end--;
        }
    }
    return chars;
    
}