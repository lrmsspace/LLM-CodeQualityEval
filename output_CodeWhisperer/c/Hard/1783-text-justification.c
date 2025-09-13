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
    int* wordLengths = (int*)malloc(wordsSize * sizeof(int));
    int totalLength = 0;
    for (int i = 0; i < wordsSize; i++) {
        wordLengths[i] = strlen(words[i]);
        totalLength += wordLengths[i];
    }

    int* spaces = (int*)malloc((wordsSize - 1) * sizeof(int));
    int extraSpaces = maxWidth - (totalLength + wordsSize - 1);
    for (int i = 0; i < wordsSize - 1; i++) {
        spaces[i] = 1;
        if (extraSpaces > 0) {
            spaces[i] += extraSpaces / (wordsSize - 1 - i);
            if (i < extraSpaces % (wordsSize - 1 - i)) {
                spaces[i]++;
            }
        }
    }

    char** result = (char**)malloc(wordsSize * sizeof(char*));

    int lineStart = 0;

    for (int i = 0; i < wordsSize; i++) {
        int lineLength = wordLengths[i];
        int numSpaces = 0;
        while (i + 1 < wordsSize && lineLength + wordLengths[i + 1] + numSpaces + 1 <= maxWidth) {
            lineLength += wordLengths[i + 1] + 1;
            numSpaces++;
            i++;
        }

        result[lineStart] = (char*)malloc((lineLength + 1) * sizeof(char));
        int charIndex = 0;
        for (int j = lineStart; j <= i; j++) {
            for (int k = 0; k < words[j][k] != '\0'; k++) {
                result[lineStart][charIndex++] = words[j][k];
            }
            if (j < i) {
                for (int k = 0; k < spaces[j - lineStart]; k++) {
                    result[lineStart][charIndex++] = ' ';
                }
            }
        }
        while (charIndex < maxWidth) {
            result[lineStart][charIndex++] = ' ';
        }
        result[lineStart][charIndex] = '\0';

        lineStart = i + 1;
    }
    *returnSize = wordsSize;
    return result;
    
}