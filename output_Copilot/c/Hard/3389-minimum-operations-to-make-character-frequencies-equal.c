/*
 You are given a string s.
 A string t is called good if all characters of t occur the same number of times.
 You can perform the following operations any number of times:
 Delete a character from s.
 Insert a character in s.
 Change a character in s to its next letter in the alphabet.
 Note that you cannot change 'z' to 'a' using the third operation.
 Return the minimum number of operations required to make s good.
 Example 1:
 Input: s = "acab"
 Output: 1
 Explanation:
 We can make s good by deleting one occurrence of character 'a'.
 Example 2:
 Input: s = "wddw"
 Output: 0
 Explanation:
 We do not need to perform any operations since s is initially good.
 Example 3:
 Input: s = "aaabc"
 Output: 2
 Explanation:
 We can make s good by applying these operations:
 Change one occurrence of 'a' to 'b'
 Insert one occurrence of 'c' into s
 Constraints:
 3 <= s.length <= 2 * 104
 s contains only lowercase English letters.
*/

int makeStringGood(char* s) {
    int freq[26] = {0};
    int n = 0, i, j, max_freq = 0;

    // Count frequency of each character
    for (i = 0; s[i] != '\0'; i++) {
        freq[s[i] - 'a']++;
        n++;
    }

    // Find the maximum frequency
    for (i = 0; i < 26; i++) {
        if (freq[i] > max_freq) {
            max_freq = freq[i];
        }
    }

    // Calculate the number of operations needed
    int operations = 0;
    for (i = 0; i < 26; i++) {
        if (freq[i] > max_freq) {
            operations += freq[i] - max_freq;
        } else if (freq[i] < max_freq) {
            operations += max_freq - freq[i];
        }
    }

    return operations / 2; // Each operation can affect two characters    
}