/**https://leetcode.com/problems/text-justification/ */
//Given an array of strings words and a width maxWidth, format the text such that each line has exactly maxWidth characters and is fully (left and right) justified.
//You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly maxWidth characters.
//Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line does not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.
//For the last line of text, it should be left-justified, and no extra space is inserted between words.
//Note:
//	A word is defined as a character sequence consisting of non-space characters only.
//	Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
//	The input array words contains at least one word.
// 
//Example 1:
//Input: words = ["This", "is", "an", "example", "of", "text", "justification."], maxWidth = 16
//Output:
//[
//   "This    is    an",
//   "example  of text",
//   "justification.  "
//]
//Example 2:
//Input: words = ["What","must","be","acknowledgment","shall","be"], maxWidth = 16
//Output:
//[
//  "What   must   be",
//  "acknowledgment  ",
//  "shall be        "
//]
//Explanation: Note that the last line is "shall be    " instead of "shall     be", because the last line must be left-justified instead of fully-justified.
//Note that the second line is also left-justified because it contains only one word.
//Example 3:
//Input: words = ["Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"], maxWidth = 20
//Output:
//[
//  "Science  is  what we",
//  "understand      well",
//  "enough to explain to",
//  "a  computer.  Art is",
//  "everything  else  we",
//  "do                  "
//]
// 
//Constraints:
//	1 <= words.length <= 300
//	1 <= words[i].length <= 20
//	words[i] consists of only English letters and symbols.
//	1 <= maxWidth <= 100
//	words[i].length <= maxWidth
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** fullJustify(char** words, int wordsSize, int maxWidth, int* returnSize) {
    *returnSize = 0;
    char** result = (char**)malloc(sizeof(char*) * wordsSize);
    int idx = 0;
    int width = 0;
    int wordCount = 0;
    for (int i = 0; i < wordsSize; i++) {
        if (width + strlen(words[i]) + wordCount > maxWidth) {
            int space = maxWidth - width;
            int perSpace = space / (wordCount - 1);
            int extraSpace = space % (wordCount - 1);
            char* line = (char*)malloc(sizeof(char) * (maxWidth + 1));
            int j = 0;
            for (int k = 0; k < idx; k++) {
                int len = strlen(words[k]);
                strncpy(line + j, words[k], len);
                j += len;
                if (k < idx - 1) {
                    line[j++] = ' ';
                    if (extraSpace-- > 0) {
                        line[j++] = ' ';
                    }
                }
            }
            line[j] = '\0';
            result[(*returnSize)++] = line;
            idx = 0;
            width = 0;
            wordCount = 0;
        }
        width += strlen(words[i]);
        wordCount++;
        result[(*returnSize)++] = words[i];
        idx++;
    }
    if (idx > 0) {
        char* line = (char*)malloc(sizeof(char) * (maxWidth + 1));
        int j = 0;
        for (int k = 0; k < idx; k++) {
            int len = strlen(words[k]);
            strncpy(line + j, words[k], len);
            j += len;
            if (k < idx - 1) {
                line[j++] = ' ';
            }
        }
        while (j < maxWidth) {
            line[j++] = ' ';
        }
        line[j] = '\0';
        result[(*returnSize)++] = line;
    }
    return result;
}