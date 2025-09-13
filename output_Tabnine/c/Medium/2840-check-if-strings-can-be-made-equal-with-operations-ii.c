/*
 You are given two strings s1 and s2, both of length n, consisting of lowercase English letters.
 You can apply the following operation on any of the two strings any number of times:
 Choose any two indices i and j such that i < j and the difference j - i is even, then swap the two characters at those indices in the string.
 Return true if you can make the strings s1 and s2 equal, and false otherwise.
 Example 1:
 Input: s1 = "abcdba", s2 = "cabdab"
 Output: true
 Explanation: We can apply the following operations on s1:
 - Choose the indices i = 0, j = 2. The resulting string is s1 = "cbadba".
 - Choose the indices i = 2, j = 4. The resulting string is s1 = "cbbdaa".
 - Choose the indices i = 1, j = 5. The resulting string is s1 = "cabdab" = s2.
 Example 2:
 Input: s1 = "abe", s2 = "bea"
 Output: false
 Explanation: It is not possible to make the two strings equal.
 Constraints:
 n == s1.length == s2.length
 1 <= n <= 105
 s1 and s2 consist only of lowercase English letters.
*/

bool checkStrings(char* s1, char* s2) {
    int n = strlen(s1);
    int count[26] = {0};
    
    // Count the frequency of each character in s1
    for (int i = 0; i < n; i++) {
        count[s1[i] - 'a']++;
    }
    
    // Check if s2 can be made equal to s1 by applying the operation
    for (int i = 0; i < n; i++) {
        if (s2[i]!= s1[i]) {
            count[s2[i] - 'a']--;
            if (count[s2[i] - 'a'] < 0) {
                return false;
            }
        }
    }
    
    return true;    
    
}