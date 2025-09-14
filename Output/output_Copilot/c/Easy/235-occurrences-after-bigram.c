/**https://leetcode.com/problems/occurrences-after-bigram/ */
//Given two strings first and second, consider occurrences in some text of the form "first second third", where second comes immediately after first, and third comes immediately after second.
//Return an array of all the words third for each occurrence of "first second third".
// 
//Example 1:
//Input: text = "alice is a good girl she is a good student", first = "a", second = "good"
//Output: ["girl","student"]
//Example 2:
//Input: text = "we will we will rock you", first = "we", second = "will"
//Output: ["we","rock"]
// 
//Constraints:
//	1 <= text.length <= 1000
//	text consists of lowercase English letters and spaces.
//	All the words in text are separated by a single space.
//	1 <= first.length, second.length <= 10
//	first and second consist of lowercase English letters.
//	text will not have any leading or trailing spaces.
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** findOcurrences(char* text, char* first, char* second, int* returnSize) {
    int i = 0, j = 0, k = 0, l = 0, m = 0, n = 0;
    int len = strlen(text);
    char *tmp = (char *)malloc(sizeof(char) * 10);
    char **ret = (char **)malloc(sizeof(char *) * 100);
    *returnSize = 0;
    for (i = 0; i < len; i++) {
        if (text[i] == ' ') {
            tmp[j] = '\0';
            if (k == 0) {
                if (strcmp(tmp, first) == 0) {
                    k = 1;
                }
            } else if (k == 1) {
                if (strcmp(tmp, second) == 0) {
                    k = 2;
                } else {
                    k = 0;
                }
            } else if (k == 2) {
                ret[*returnSize] = (char *)malloc(sizeof(char) * 10);
                strcpy(ret[*returnSize], tmp);
                (*returnSize)++;
                k = 0;
            }
            j = 0;
        } else {
            tmp[j++] = text[i];
        }
    }
    tmp[j] = '\0';
    if (k == 2) {
        ret[*returnSize] = (char *)malloc(sizeof(char) * 10);
        strcpy(ret[*returnSize], tmp);
        (*returnSize)++;
    }
    return ret;    
}