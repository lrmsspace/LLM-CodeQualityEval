/**https://leetcode.com/problems/uncommon-words-from-two-sentences/ */
//A sentence is a string of single-space separated words where each word consists only of lowercase letters.
//A word is uncommon if it appears exactly once in one of the sentences, and does not appear in the other sentence.
//Given two sentences s1 and s2, return a list of all the uncommon words. You may return the answer in any order.
// 
//Example 1:
//Input: s1 = "this apple is sweet", s2 = "this apple is sour"
//Output: ["sweet","sour"]
//Explanation:
//The word "sweet" appears only in s1, while the word "sour" appears only in s2.
//Example 2:
//Input: s1 = "apple apple", s2 = "banana"
//Output: ["banana"]
// 
//Constraints:
//	1 <= s1.length, s2.length <= 200
//	s1 and s2 consist of lowercase English letters and spaces.
//	s1 and s2 do not have leading or trailing spaces.
//	All the words in s1 and s2 are separated by a single space.
class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> v1, v2, v3;
        stringstream ss1(s1);
        stringstream ss2(s2);
        string word;
        while(ss1 >> word){
            v1.push_back(word);
        }
        while(ss2 >> word){
            v2.push_back(word);
        }
        for(int i = 0; i < v1.size(); i++){
            int count = 0;
            for(int j =0; j < v2.size(); j++){
                if(v1[i] == v2[j]){
                    count++;
                }
            }
        }
        for(int i = 0; i < v1.size(); i++){
            int count = 0;
            for(int j =0; j < v2.size(); j++){
                if(v1[i] == v2[j]){
                    count++;
                }
            }
            if(count == 0){
                v3.push_back(v1[i]);
            }
       }
       for(int i = 0; i < v2.size(); i++){
            int count = 0;
            for(int j =0; j < v1.size(); j++){
                if(v2[i] == v1[j]){
                    count++;
                }
            }
            if(count == 0){
                v3.push_back(v2[i]);
            }
      }
      return v3;
    }
};