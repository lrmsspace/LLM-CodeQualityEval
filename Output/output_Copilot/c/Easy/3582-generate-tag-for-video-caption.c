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
    int length = strlen(caption);
    char* tag = (char*)malloc(102 * sizeof(char)); // Allocate memory for the tag (+1 for null terminator)
    int index = 0;

    // Add the '#' at the beginning
    tag[index++] = '#';

    // Process each word in the caption
    int i = 0;
    while (i < length) {
        // Skip leading spaces
        while (i < length && caption[i] == ' ') {
            i++;
        }

        // If we reach the end of the string, break
        if (i >= length) {
            break;
        }

        // Add the first character of the word
        tag[index++] = caption[i++];

        // Capitalize the first letter of subsequent words
        while (i < length && caption[i] != ' ') {
            if (caption[i] >= 'A' && caption[i] <= 'Z') {
                tag[index++] = caption[i++];
            } else if (caption[i] >= 'a' && caption[i] <= 'z') {
                tag[index++] = caption[i++];
            } else {
                i++; // Skip non-letter characters
            }
        }
        
        // Convert to lowercase for the rest of the word
        while (i < length && caption[i] != ' ') {
            if (caption[i] >= 'A' && caption[i] <= 'Z') {
                tag[index++] = caption[i++] + ('a' - 'A'); // Convert to lowercase
            } else if (caption[i] >= 'a' && caption[i] <= 'z') {
                tag[index++] = caption[i++];
            } else {
                i++; // Skip non-letter characters
            }
        }
    }

    // Null-terminate the string and truncate to 100 characters if necessary
    tag[index] = '\0';
    if (index > 100) {
        tag[100] = '\0'; // Truncate to 100 characters
    }

    return tag;
    
}