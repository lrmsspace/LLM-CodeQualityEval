/*
 You are given an array of strings message and an array of strings bannedWords.
 An array of words is considered spam if there are at least two words in it that exactly match any word in bannedWords.
 Return true if the array message is spam, and false otherwise.
 Example 1:
 Input: message = ["hello","world","leetcode"], bannedWords = ["world","hello"]
 Output: true
 Explanation:
 The words "hello" and "world" from the message array both appear in the bannedWords array.
 Example 2:
 Input: message = ["hello","programming","fun"], bannedWords = ["world","programming","leetcode"]
 Output: false
 Explanation:
 Only one word from the message array ("programming") appears in the bannedWords array.
 Constraints:
 1 <= message.length, bannedWords.length <= 105
 1 <= message[i].length, bannedWords[i].length <= 15
 message[i] and bannedWords[i] consist only of lowercase English letters.
*/

bool reportSpam(char** message, int messageSize, char** bannedWords, int bannedWordsSize) {
    // Create a hash map to store the frequency of each word in the bannedWords array
    int bannedWordCount[101] = {0};
    for (int i = 0; i < bannedWordsSize; i++) {
        bannedWordCount[bannedWords[i]]++;
    }   
    // Iterate through the message array and count the frequency of each word
    int messageWordCount[101] = {0};
    for (int i = 0; i < messageSize; i++) {
        messageWordCount[message[i]]++;
    }   
    // Iterate through the message array and check if any word matches any word in the bannedWords array
    for (int i = 0; i < messageSize; i++) {
        if (bannedWordCount[message[i]] > 0) {
            return true;
        }
    }   
    // If no word in the message array matches any word in the bannedWords array, return false
    return false;   
    
}