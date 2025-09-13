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
    // Your code here
    // Split the sentence into words
    char *token = strtok(s, " ");
    int wordCount = 0;
    char *words[9]; // Assuming maximum 9 words in the sentence
    
    while (token!= NULL) {
        words[wordCount++] = token;
        token = strtok(NULL, " ");
    }
    
    // Sort the words based on their position
    for (int i = 0; i < wordCount - 1; i++) {
        for (int j = 0; j < wordCount - i - 1; j++) {
            int position = atoi(words[j] + strlen(words[j]) - 1);
            int nextPosition = atoi(words[j + 1] + strlen(words[j + 1]) - 1);
            
            if (position > nextPosition) {
                char *temp = words[j];
                words[j] = words[j + 1];
                words[j + 1] = temp;
            }
        }
    }
    
    // Remove the numbers from the words
    for (int i = 0; i < wordCount; i++) {
        int position = strlen(words[i]) - 1;
        
        while (position >= 0 && words[i][position] >= '0' && words[i][position] <= '9') {
            words[i][position] = '\0';
            position--;
        }
    }
    
    // Combine the sorted words into a sentence
    char *result = malloc(sizeof(char) * (wordCount + 1));
    result[0] = '\0';
    
    for (int i = 0; i < wordCount; i++) {
        strcat(result, words[i]);
        strcat(result, " ");
    }
    
    result[strlen(result) - 1] = '\0'; // Remove the trailing space
    
    return result;

}