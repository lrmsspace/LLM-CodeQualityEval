/**https://leetcode.com/problems/maximum-number-of-occurrences-of-a-substring/ */
//Given a string s, return the maximum number of occurrences of any substring under the following rules:
//	The number of unique characters in the substring must be less than or equal to maxLetters.
//	The substring size must be between minSize and maxSize inclusive.
// 
//Example 1:
//Input: s = "aababcaab", maxLetters = 2, minSize = 3, maxSize = 4
//Output: 2
//Explanation: Substring "aab" has 2 occurrences in the original string.
//It satisfies the conditions, 2 unique letters and size 3 (between minSize and maxSize).
//Example 2:
//Input: s = "aaaa", maxLetters = 1, minSize = 3, maxSize = 3
//Output: 2
//Explanation: Substring "aaa" occur 2 times in the string. It can overlap.
// 
//Constraints:
//	1 <= s.length <= 105
//	1 <= maxLetters <= 26
//	1 <= minSize <= maxSize <= min(26, s.length)
//	s consists of only lowercase English letters.

    int maxFreq(char* s, int maxLetters, int minSize, int maxSize) {
        int n = strlen(s);
        int freq[26] = {0};
        int uniqueCount = 0;
        int maxOccurrences = 0;

        // Hash map to store substring frequencies
        typedef struct {
            char* key;
            int value;
        } HashMapEntry;

        HashMapEntry* hashMap = malloc(n * sizeof(HashMapEntry));
        int hashMapSize = 0;

        // Helper function to find a substring in the hash map
        int findInHashMap(char* key) {
            for (int i = 0; i < hashMapSize; i++) {
                if (strcmp(hashMap[i].key, key) == 0) {
                    return i;
                }
            }
            return -1;
        }

        // Sliding window
        for (int i = 0; i < n; i++) {
            if (i >= minSize) {
                // Remove the character going out of the window
                freq[s[i - minSize] - 'a']--;
                if (freq[s[i - minSize] - 'a'] == 0) {
                    uniqueCount--;
                }
            }

            // Add the current character to the window
            freq[s[i] - 'a']++;
            if (freq[s[i] - 'a'] == 1) {
                uniqueCount++;
            }

            // Check if the current window satisfies the conditions
            if (i >= minSize - 1 && uniqueCount <= maxLetters) {
                char* substring = strndup(s + i - minSize + 1, minSize);
                int index = findInHashMap(substring);
                if (index == -1) {
                    hashMap[hashMapSize].key = substring;
                    hashMap[hashMapSize].value = 1;
                    hashMapSize++;
                } else {
                    hashMap[index].value++;
                    free(substring);
                }
            }
        }

        // Find the maximum frequency
        for (int i = 0; i < hashMapSize; i++) {
            if (hashMap[i].value > maxOccurrences) {
                maxOccurrences = hashMap[i].value;
            }
            free(hashMap[i].key);
        }

        free(hashMap);
        return maxOccurrences;
    }
    