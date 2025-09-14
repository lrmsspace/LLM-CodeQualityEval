/**https://leetcode.com/problems/sorting-the-sentence/ */
//A sentence is a list of words that are separated by a single space with no leading or trailing spaces. Each word consists of lowercase and uppercase English letters.
//A sentence can be shuffled by appending the 1-indexed word position to each word then rearranging the words in the sentence.
//	For example, the sentence "This is a sentence" can be shuffled as "sentence4 a3 is2 This1" or "is2 sentence4 This1 a3".
//Given a shuffled sentence s containing no more than 9 words, reconstruct and return the original sentence.
// 
//Example 1:
//Input: s = "is2 sentence4 This1 a3"
//Output: "This is a sentence"
//Explanation: Sort the words in s to their original positions "This1 is2 a3 sentence4", then remove the numbers.
//Example 2:
//Input: s = "Myself2 Me1 I4 and3"
//Output: "Me Myself and I"
//Explanation: Sort the words in s to their original positions "Me1 Myself2 and3 I4", then remove the numbers.
// 
//Constraints:
//	2 <= s.length <= 200
//	s consists of lowercase and uppercase English letters, spaces, and digits from 1 to 9.
//	The number of words in s is between 1 and 9.
//	The words in s are separated by a single space.
//	s contains no leading or trailing spaces.


char * sortSentence(char * s){
    int len = strlen(s);
    char* result = (char*)malloc(sizeof(char) * (len + 1));
    int index = 0;
    int wordCount = 0;
    char* word = (char*)malloc(sizeof(char) * (len + 1));
    int wordIndex = 0;
    for (int i = 0; i <= len; i++) {
        if (s[i] == ' ' || s[i] == '\0') {
            word[wordIndex] = '\0';
            wordIndex = 0;
            wordCount++;
            int wordLen = strlen(word);
            int wordNum = word[wordLen - 1] - '0';
            word[wordLen - 1] = '\0';
            int j = 0;
            while (j < wordLen - 1) {
                result[index++] = word[j];
                j++;
            }
            if (wordCount != wordNum) {
                result[index++] = ' ';
            }
        }
        else {
            word[wordIndex++] = s[i];
        }
    }
    result[index] = '\0';
    free(word);
    return result;

}