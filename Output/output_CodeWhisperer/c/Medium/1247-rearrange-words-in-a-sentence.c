/**https://leetcode.com/problems/rearrange-words-in-a-sentence/ */
//Given a sentence text (A sentence is a string of space-separated words) in the following format:
//	First letter is in upper case.
//	Each word in text are separated by a single space.
//Your task is to rearrange the words in text such that all words are rearranged in an increasing order of their lengths. If two words have the same length, arrange them in their original order.
//Return the new text following the format shown above.
// 
//Example 1:
//Input: text = "Leetcode is cool"
//Output: "Is cool leetcode"
//Explanation: There are 3 words, "Leetcode" of length 8, "is" of length 2 and "cool" of length 4.
//Output is ordered by length and the new first word starts with capital letter.
//Example 2:
//Input: text = "Keep calm and code on"
//Output: "On and keep calm code"
//Explanation: Output is ordered as follows:
//"On" 2 letters.
//"and" 3 letters.
//"keep" 4 letters in case of tie order by position in original text.
//"calm" 4 letters.
//"code" 4 letters.
//Example 3:
//Input: text = "To be or not to be"
//Output: "To be or to be not"
// 
//Constraints:
//	text begins with a capital letter and then contains lowercase letters and single space between words.
//	1 <= text.length <= 10^5
char* arrangeWords(char* text) {
    int len = strlen(text);
    char* result = (char*)malloc(sizeof(char) * (len + 1));
    int wordCount = 0;
    int maxLen = 0;
    int i, j;
    for (i = 0; i < len; i++) {
        if (text[i] == ' ') {
            wordCount++;
        }
    }
    wordCount++;
    char** words = (char**)malloc(sizeof(char*) * wordCount);
    for (i = 0; i < wordCount; i++) {
        words[i] = (char*)malloc(sizeof(char) * (len + 1));
    }
    i = 0;
    j = 0;
    while (text[i] != '\0') {
        if (text[i] == ' ') {
            words[j][i] = '\0';
            j++;
            i++;
        }
        words[j][i] = text[i];
        i++;
    }
    words[j][i] = '\0';
    for (i = 0; i < wordCount; i++) {
        if (strlen(words[i]) > maxLen) {
            maxLen = strlen(words[i]);
        }
    }
    int* wordLen = (int*)malloc(sizeof(int) * wordCount);
    for (i = 0; i < wordCount; i++) {
        wordLen[i] = strlen(words[i]);
    }
    for (i = 0; i < maxLen; i++) {
        for (j = 0; j < wordCount; j++) {
            if (wordLen[j] == i) {
                if (i == 0) {
                    words[j][0] = words[j][0] - 'a' + 'A';
                }
                strcat(result, words[j]);
                if (j != wordCount - 1) {
                    strcat(result, " ");
                }
            }
        }
    }
    result[len] = '\0';
    return result;
}