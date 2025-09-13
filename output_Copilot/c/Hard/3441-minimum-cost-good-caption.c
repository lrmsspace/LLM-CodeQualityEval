/*
 You are given a string caption of length n. A good caption is a string where every character appears in groups of at least 3 consecutive occurrences.
 For example:
 "aaabbb" and "aaaaccc" are good captions.
 "aabbb" and "ccccd" are not good captions.
 You can perform the following operation any number of times:
 Choose an index i (where 0 <= i < n) and change the character at that index to either:
 The character immediately before it in the alphabet (if caption[i] != 'a').
 The character immediately after it in the alphabet (if caption[i] != 'z').
 Your task is to convert the given caption into a good caption using the minimum number of operations, and return it. If there are multiple possible good captions, return the lexicographically smallest one among them. If it is impossible to create a good caption, return an empty string "".
 Example 1:
 Input: caption = "cdcd"
 Output: "cccc"
 Explanation:
 It can be shown that the given caption cannot be transformed into a good caption with fewer than 2 operations. The possible good captions that can be created using exactly 2 operations are:
 "dddd": Change caption[0] and caption[2] to their next character 'd'.
 "cccc": Change caption[1] and caption[3] to their previous character 'c'.
 Since "cccc" is lexicographically smaller than "dddd", return "cccc".
 Example 2:
 Input: caption = "aca"
 Output: "aaa"
 Explanation:
 It can be proven that the given caption requires at least 2 operations to be transformed into a good caption. The only good caption that can be obtained with exactly 2 operations is as follows:
 Operation 1: Change caption[1] to 'b'. caption = "aba".
 Operation 2: Change caption[1] to 'a'. caption = "aaa".
 Thus, return "aaa".
 Example 3:
 Input: caption = "bc"
 Output: ""
 Explanation:
 It can be shown that the given caption cannot be converted to a good caption by using any number of operations.
 Constraints:
 1 <= caption.length <= 5 * 104
 caption consists only of lowercase English letters.
*/

char* minCostGoodCaption(char* caption) {
    int n = strlen(caption);
    if (n < 3) return "";

    char* result = (char*)malloc(n + 1);
    int i = 0, j = 0;

    while (i < n) {
        int count = 1;
        while (i + 1 < n && caption[i] == caption[i + 1]) {
            count++;
            i++;
        }

        if (count < 3) {
            if (i + 1 < n && caption[i] == caption[i + 1]) {
                // If next character is the same, we can change this one
                result[j++] = caption[i];
                result[j++] = caption[i];
                result[j++] = caption[i];
            } else {
                // If next character is different, we need to change this one
                if (caption[i] > 'a') {
                    result[j++] = caption[i] - 1;
                    result[j++] = caption[i] - 1;
                    result[j++] = caption[i] - 1;
                } else {
                    return "";
                }
            }
        } else {
            for (int k = 0; k < count; k++) {
                result[j++] = caption[i];
            }
        }
        i++;
    }

    result[j] = '\0';
    return result;    
}