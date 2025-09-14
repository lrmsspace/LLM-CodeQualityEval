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
    char** result = (char**)malloc(wordsSize * sizeof(char*));
    *returnSize = 0;
    int i = 0;
    while (i < wordsSize) {
        int j = i + 1;
        int lineLength = strlen(words[i]);
        while (j < wordsSize && lineLength + strlen(words[j]) + j - i <= maxWidth) {
            lineLength += strlen(words[j]);
            j++;
        }
        int diff = j - i - 1;
        char* line = (char*)malloc((maxWidth + 1) * sizeof(char));
        line[0] = '\0';
        if (j == wordsSize || diff == 0) {
            for (int k = i; k < j; k++) {
                strcat(line, words[k]);
                if (k < j - 1) {
                    strcat(line, " ");
                }
            }
            while (strlen(line) < maxWidth) {
                strcat(line, " ");
            }
        } else {
            int spaces = (maxWidth - lineLength) / diff;
            int extraSpaces = (maxWidth - lineLength) % diff;
            for (int k = i; k < j; k++) {
                strcat(line, words[k]);
                if (k < j - 1) {
                    for (int l = 0; l <= spaces + (k - i < extraSpaces ? 1 : 0); l++) {
                        strcat(line, " ");
                    }
                }
            }
        }
        result[*returnSize] = line;
        (*returnSize)++;
        i = j;
    }
    return result;   
}