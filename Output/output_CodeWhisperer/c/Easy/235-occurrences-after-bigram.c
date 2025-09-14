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
    int len = strlen(text);
    int count = 0;
    char* token = strtok(text, " ");
    while (token != NULL) {
        if (count >= 2) {
            if (strcmp(token, third) == 0) {
                result = realloc(result, (count - 1) * sizeof(char*));
                result[count - 2] = strdup(token);
            }
        }
        if (count >= 1) {
            third = second;
        }
        second = first;
        first = token;
        token = strtok(NULL, " ");
        count++;
    }
    *returnSize = count - 1;
    return result;
    
}