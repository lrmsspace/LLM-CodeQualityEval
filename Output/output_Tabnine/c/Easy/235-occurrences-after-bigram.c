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
    int i, j, k, count = 0;
    char** result = NULL;
    
    text = strcat(strcat(strcpy(malloc(strlen(text) + 1), text), " "), " ");
    
    for (i = 0; text[i]!= '\0'; i++) {
        if (text[i] == first[0] && text[i + 1] == first[1] && text[i + 2] == first[2] && text[i + 3] == second[0] && text[i + 4] == second[1] && text[i + 5] == second[2]) {
            count++;
            result = realloc(result, count * sizeof(char*));
            result[count - 1] = malloc(sizeof(char) * (strlen(&text[i + 6]) + 1));
            strcpy(result[count - 1], &text[i + 6]);
        }
    }
    
    *returnSize = count;
    return result;
}