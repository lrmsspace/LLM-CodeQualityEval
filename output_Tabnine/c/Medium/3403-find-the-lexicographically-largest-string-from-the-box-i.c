/*
 You are given a string word, and an integer numFriends.
 Alice is organizing a game for her numFriends friends. There are multiple rounds in the game, where in each round:
 word is split into numFriends non-empty strings, such that no previous round has had the exact same split.
 All the split words are put into a box.
 Find the lexicographically largest string from the box after all the rounds are finished.
 Example 1:
 Input: word = "dbca", numFriends = 2
 Output: "dbc"
 Explanation: 
 All possible splits are:
 "d" and "bca".
 "db" and "ca".
 "dbc" and "a".
 Example 2:
 Input: word = "gggg", numFriends = 4
 Output: "g"
 Explanation: 
 The only possible split is: "g", "g", "g", and "g".
 Constraints:
 1 <= word.length <= 5 * 103
 word consists only of lowercase English letters.
 1 <= numFriends <= word.length
*/

char* answerString(char* word, int numFriends) {
    int len = strlen(word);
    char* result = (char*)malloc((len + 1) * sizeof(char));
    result[len] = '\0';
    int* ends = (int*)malloc(numFriends * sizeof(int));
    for (int i = 0; i < numFriends; i++) {
        ends[i] = i;
    }
    while (numFriends > 1) {    
        int maxEnd = 0;
        for (int i = 1; i < numFriends; i++) {
            if (ends[i] > ends[maxEnd]) {
                maxEnd = i;
            }
        }
        int splitIndex = ends[maxEnd] + 1;
        if (splitIndex < len) {
            result[splitIndex] = word[splitIndex];
            ends[maxEnd] = splitIndex;
            ends[numFriends - 1] = splitIndex + 1;
            numFriends--;
        }
    }
    for (int i = 0; i < len; i++) {
        result[i] = word[ends[0] + i];
    }
    return result;  


    
}