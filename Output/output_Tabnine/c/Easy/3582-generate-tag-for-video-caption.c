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
    int len = strlen(caption);
    char* tag = (char*)malloc(sizeof(char) * 101);
    int tagLen = 0;
    
    tag[tagLen++] = '#';
    
    int i = 0;
    while (i < len) {
        if (caption[i] =='') {
            i++;
            continue;
        }
        
        int wordLen = 0;
        while (i < len && isalpha(caption[i])) {
            wordLen++;
            i++;
        }
        
        if (wordLen == 0) {
            continue;
        }
        
        tag[tagLen++] = tolower(caption[i - wordLen]);
        for (int j = 1; j < wordLen; j++) {
            tag[tagLen++] = tolower(caption[i - wordLen + j]);
        }
    }
    
    tag[tagLen] = '\0';
    if (tagLen > 100) {
        tag[99] = '\0';
    }
    return tag;
    
}