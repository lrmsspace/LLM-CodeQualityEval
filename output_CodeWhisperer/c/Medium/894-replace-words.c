/**https://leetcode.com/problems/replace-words/ */
//In English, we have a concept called root, which can be followed by some other word to form another longer word - let's call this word derivative. For example, when the root "help" is followed by the word "ful", we can form a derivative "helpful".
//Given a dictionary consisting of many roots and a sentence consisting of words separated by spaces, replace all the derivatives in the sentence with the root forming it. If a derivative can be replaced by more than one root, replace it with the root that has the shortest length.
//Return the sentence after the replacement.
// 
//Example 1:
//Input: dictionary = ["cat","bat","rat"], sentence = "the cattle was rattled by the battery"
//Output: "the cat was rat by the bat"
//Example 2:
//Input: dictionary = ["a","b","c"], sentence = "aadsfasf absbs bbab cadsfafs"
//Output: "a a b c"
// 
//Constraints:
//	1 <= dictionary.length <= 1000
//	1 <= dictionary[i].length <= 100
//	dictionary[i] consists of only lower-case letters.
//	1 <= sentence.length <= 106
//	sentence consists of only lower-case letters and spaces.
//	The number of words in sentence is in the range [1, 1000]
//	The length of each word in sentence is in the range [1, 1000]
//	Every two consecutive words in sentence will be separated by exactly one space.
//	sentence does not have leading or trailing spaces.
char* replaceWords(char** dictionary, int dictionarySize, char* sentence) {
    int i, j, k;
    char* result = (char*)malloc(sizeof(char) * (strlen(sentence) + 1));
    char* word = (char*)malloc(sizeof(char) * 101);
    char* temp = (char*)malloc(sizeof(char) * 101);
    int* len = (int*)malloc(sizeof(int) * dictionarySize);
    for (i = 0; i < dictionarySize; i++) {
        len[i] = strlen(dictionary[i]);
    }
    i = 0;
    j = 0;
    while (sentence[i] != '\0') {
        if (sentence[i] == ' ') {
            word[j] = '\0';
            j = 0;
            for (k = 0; k < dictionarySize; k++) {
                if (strncmp(word, dictionary[k], len[k]) == 0) {
                    break;
                }
            }
            if (k < dictionarySize) {
                strcpy(temp, dictionary[k]);
                strcat(result, temp);
            } else {
                strcat(result, word);
            }
            strcat(result, " ");
        } else {
            word[j++] = sentence[i];
        }
        i++;
    }
    word[j] = '\0';
    for (k = 0; k < dictionarySize; k++) {
        if (strncmp(word, dictionary[k], len[k]) == 0) {
            break;
        }
    }
    if (k < dictionarySize) {
        strcpy(temp, dictionary[k]);
        strcat(result, temp);
    } else {
        strcat(result, word);
    }
    result[strlen(sentence)] = '\0';
    return result;
}