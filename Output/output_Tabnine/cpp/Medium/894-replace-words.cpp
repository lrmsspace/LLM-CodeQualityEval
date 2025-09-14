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
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        // Build a Trie for dictionary
        TrieNode* root = new TrieNode();
        for (const auto& word : dictionary) {
            TrieNode* node = root;
            for (char c : word) {
                if (!node->children[c - 'a']) {
                    node->children[c - 'a'] = new TrieNode();
                }
                node = node->children[c - 'a'];
            }
            node->isEndOfWord = true;
        }
        
        // Split the sentence into words
        vector<string> words;
        istringstream iss(sentence);
        string word;
        while (iss >> word) {
            words.push_back(word);
        }
        
        // Replace each word in the sentence with the shortest root form
        for (int i = 0; i < words.size(); ++i) {
            TrieNode* node = root;
            for (char c : words[i]) {
                if (!node->children[c - 'a']) {
                    break;
                }
                node = node->children[c - 'a'];
                if (node->isEndOfWord) {
                    words[i] = node->word;
                    break;
                }
            }
        }
        
        // Join the words back into a sentence
        string result;
        for (const auto& word : words) {
            result += word + " ";
        }
        result.pop_back(); // Remove trailing space
        
        return result;
        
    }
};