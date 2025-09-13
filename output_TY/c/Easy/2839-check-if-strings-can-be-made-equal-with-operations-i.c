/*
 You are given two strings s1 and s2, both of length 4, consisting of lowercase English letters.
 You can apply the following operation on any of the two strings any number of times:
 Choose any two indices i and j such that j - i = 2, then swap the two characters at those indices in the string.
 Return true if you can make the strings s1 and s2 equal, and false otherwise.
 Example 1:
 Input: s1 = "abcd", s2 = "cdab"
 Output: true
 Explanation: We can do the following operations on s1:
 - Choose the indices i = 0, j = 2. The resulting string is s1 = "cbad".
 - Choose the indices i = 1, j = 3. The resulting string is s1 = "cdab" = s2.
 Example 2:
 Input: s1 = "abcd", s2 = "dacb"
 Output: false
 Explanation: It is not possible to make the two strings equal.
 Constraints:
 s1.length == s2.length == 4
 s1 and s2 consist only of lowercase English letters.
*/

bool canBeEqual(char* s1, char* s2) {
 char even1[3], odd1[3], even2[3], odd2[3];
    
    even1[0] = s1[0]; even1[1] = s1[2]; even1[2] = '\0';
    odd1[0] = s1[1]; odd1[1] = s1[3]; odd1[2] = '\0';
    even2[0] = s2[0]; even2[1] = s2[2]; even2[2] = '\0';
    odd2[0] = s2[1]; odd2[1] = s2[3]; odd2[2] = '\0';

    for (int i = 0; i < 2; i++) {
        for (int j = i + 1; j < 2; j++) {
            if (even1[i] > even1[j]) {
                char temp = even1[i];
                even1[i] = even1[j];
                even1[j] = temp;
            }
            if (odd1[i] > odd1[j]) {
                char temp = odd1[i];
                odd1[i] = odd1[j];
                odd1[j] = temp;
            }
            if (even2[i] > even2[j]) {
                char temp = even2[i];
                even2[i] = even2[j];
                even2[j] = temp;
            }
            if (odd2[i] > odd2[j]) {
                char temp = odd2[i];
                odd2[i] = odd2[j];
                odd2[j] = temp;
            }
        }
    }

    return (strcmp(even1, even2) == 0) && (strcmp(odd1, odd2) == 0);
}