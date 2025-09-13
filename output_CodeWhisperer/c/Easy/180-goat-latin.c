/**https://leetcode.com/problems/goat-latin/ */
//You are given a string sentence that consist of words separated by spaces. Each word consists of lowercase and uppercase letters only.
//We would like to convert the sentence to "Goat Latin" (a made-up language similar to Pig Latin.) The rules of Goat Latin are as follows:
//	If a word begins with a vowel ('a', 'e', 'i', 'o', or 'u'), append "ma" to the end of the word.
//	
//		For example, the word "apple" becomes "applema".
//	
//	
//	If a word begins with a consonant (i.e., not a vowel), remove the first letter and append it to the end, then add "ma".
//	
//		For example, the word "goat" becomes "oatgma".
//	
//	
//	Add one letter 'a' to the end of each word per its word index in the sentence, starting with 1.
//	
//		For example, the first word gets "a" added to the end, the second word gets "aa" added to the end, and so on.
//	
//	
//Return the final sentence representing the conversion from sentence to Goat Latin.
// 
//Example 1:
//Input: sentence = "I speak Goat Latin"
//Output: "Imaa peaksmaaa oatGmaaaa atinLmaaaaa"
//Example 2:
//Input: sentence = "The quick brown fox jumped over the lazy dog"
//Output: "heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa"
// 
//Constraints:
//	1 <= sentence.length <= 150
//	sentence consists of English letters and spaces.
//	sentence has no leading or trailing spaces.
//	All the words in sentence are separated by a single space.
char* toGoatLatin(char* sentence) {
    int len = strlen(sentence);
    char* result = (char*)malloc(sizeof(char) * (len + 1));
    int index = 0;
    int wordIndex = 1;
    int wordStart = 0;
    int wordEnd = 0;
    while (wordEnd < len) {
        while (wordEnd < len && sentence[wordEnd] != ' ') {
            wordEnd++;
        }
        if (wordStart < wordEnd) {
            if (sentence[wordStart] == 'a' || sentence[wordStart] == 'e' || sentence[wordStart] == 'i' || sentence[wordStart] == 'o' || sentence[wordStart] == 'u' || sentence[wordStart] == 'A' || sentence[wordStart] == 'E' || sentence[wordStart] == 'I' || sentence[wordStart] == 'O' || sentence[wordStart] == 'U') {
                for (int i = wordStart; i < wordEnd; i++) {
                    result[index++] = sentence[i];
                }
            } else {
                for (int i = wordStart + 1; i < wordEnd; i++) {
                    result[index++] = sentence[i];
                }
                result[index++] = sentence[wordStart];
            }
            result[index++] = 'm';
            result[index++] = 'a';
            for (int i = 0; i < wordIndex; i++) {
                result[index++] = 'a';
            }
            if (wordEnd < len) {
                result[index++] = ' ';
            }
        }
        wordStart = wordEnd + 1;
        wordEnd = wordStart;
        wordIndex++;
    }
    result[index] = '\0';
    return result;
    
}