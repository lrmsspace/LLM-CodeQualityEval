/*
 You are given two strings s1 and s2, both of length n, consisting of lowercase English letters.
 You can apply the following operation on any of the two strings any number of times:
 Choose any two indices i and j such that i < j and the difference j - i is even, then swap the two characters at those indices in the string.
 Return true if you can make the strings s1 and s2 equal, and false otherwise.
 Example 1:
 Input: s1 = "abcdba", s2 = "cabdab"
 Output: true
 Explanation: We can apply the following operations on s1:
 - Choose the indices i = 0, j = 2. The resulting string is s1 = "cbadba".
 - Choose the indices i = 2, j = 4. The resulting string is s1 = "cbbdaa".
 - Choose the indices i = 1, j = 5. The resulting string is s1 = "cabdab" = s2.
 Example 2:
 Input: s1 = "abe", s2 = "bea"
 Output: false
 Explanation: It is not possible to make the two strings equal.
 Constraints:
 n == s1.length == s2.length
 1 <= n <= 105
 s1 and s2 consist only of lowercase English letters.
*/

class Solution {
public:
    bool checkStrings(string s1, string s2) {
        vector<char> odd1, odd2, even1, even2;
        for(int i=0;i<s1.size();i++){
            if(i%2==0){
                even1.push_back(s1[i]);
                even2.push_back(s2[i]);
            }
            else{
                odd1.push_back(s1[i]);
                odd2.push_back(s2[i]);
            }
        }
        sort(odd1.begin(),odd1.end());
        sort(odd2.begin(),odd2.end());
        sort(even1.begin(),even1.end());
        sort(even2.begin(),even2.end());
        for(int i=0;i<odd1.size();i++){
            if(odd1[i]!=odd2[i]) return false;
        }
        for(int i=0;i<even1.size();i++){
            if(even1[i]!=even2[i]) return false;
        }
        return true;
        
    }
};