/*
 You are given an array arr of size n consisting of non-empty strings.
 Find a string array answer of size n such that:
 answer[i] is the shortest substring of arr[i] that does not occur as a substring in any other string in arr. If multiple such substrings exist, answer[i] should be the lexicographically smallest. And if no such substring exists, answer[i] should be an empty string.
 Return the array answer.
 Example 1:
 Input: arr = ["cab","ad","bad","c"]
 Output: ["ab","","ba",""]
 Explanation: We have the following:
 - For the string "cab", the shortest substring that does not occur in any other string is either "ca" or "ab", we choose the lexicographically smaller substring, which is "ab".
 - For the string "ad", there is no substring that does not occur in any other string.
 - For the string "bad", the shortest substring that does not occur in any other string is "ba".
 - For the string "c", there is no substring that does not occur in any other string.
 Example 2:
 Input: arr = ["abc","bcd","abcd"]
 Output: ["","","abcd"]
 Explanation: We have the following:
 - For the string "abc", there is no substring that does not occur in any other string.
 - For the string "bcd", there is no substring that does not occur in any other string.
 - For the string "abcd", the shortest substring that does not occur in any other string is "abcd".
 Constraints:
 n == arr.length
 2 <= n <= 100
 1 <= arr[i].length <= 20
 arr[i] consists only of lowercase English letters.
*/

class Solution {
public:
    vector<string> shortestSubstrings(vector<string>& arr) {
        int n = arr.size();
        vector<string> ans;
        for(int i = 0; i < n; i++){
            string s = arr[i];
            int len = s.size();
            for(int j = 0; j < len; j++){
                string temp = s.substr(j, len - j);
                bool flag = true;
                for(int k = 0; k < n; k++){
                    if(k == i) continue;
                    if(arr[k].find(temp) != string::npos){
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    ans.push_back(temp);
                    break;
                }
            }
        }
        return ans.size() ? ans[0] : "None";
        
    }
};