/*
 You are given a string caption representing the caption for a video.
 The following actions must be performed in order to generate a valid tag for the video:
 Combine all words in the string into a single camelCase string prefixed with '#'. A camelCase string is one where the first letter of all words except the first one is capitalized. All characters after the first character in each word must be lowercase.
 Remove all characters that are not an English letter, except the first '#'.
 Truncate the result to a maximum of 100 characters.
 Return the tag after performing the actions on caption.
 Example 1:
 Input: caption = "Leetcode daily streak achieved"
 Output: "#leetcodeDailyStreakAchieved"
 Explanation:
 The first letter for all words except "leetcode" should be capitalized.
 Example 2:
 Input: caption = "can I Go There"
 Output: "#canIGoThere"
 Explanation:
 The first letter for all words except "can" should be capitalized.
 Example 3:
 Input: caption = "hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh"
 Output: "#hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh"
 Explanation:
 Since the first word has length 101, we need to truncate the last two letters from the word.
 Constraints:
 1 <= caption.length <= 150
 caption consists only of English letters and ' '.
*/

char* generateTag(char* caption) {
    int i = 0, j = 0, k = 0;
    char* tag = (char*)malloc(102 * sizeof(char));
    tag[0] = '#';
    while (caption[i] != '\0') {
        if (caption[i] == ' ') {
            i++;
            continue;
        }
        if (j == 0) {
            if (caption[i] >= 'a' && caption[i] <= 'z') {
                tag[k + 1] = caption[i] - 32;
            } else {
                tag[k + 1] = caption[i];
            }
            j++;
        } else {
            if (caption[i] >= 'A' && caption[i] <= 'Z') {
                tag[k + 1] = caption[i] + 32;
            } else {
                tag[k + 1] = caption[i];
            }
        }
        i++;
        k++;
        if (k == 100) {
            break;
        }
    }
    tag[k + 1] = '\0';
    return tag;    
}