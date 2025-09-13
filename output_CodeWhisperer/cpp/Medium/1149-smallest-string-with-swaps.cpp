/**https://leetcode.com/problems/smallest-string-with-swaps/ */
//You are given a string s, and an array of pairs of indices in the string pairs where pairs[i] = [a, b] indicates 2 indices(0-indexed) of the string.
//You can swap the characters at any pair of indices in the given pairs any number of times.
//Return the lexicographically smallest string that s can be changed to after using the swaps.
// 
//Example 1:
//Input: s = "dcab", pairs = [[0,3],[1,2]]
//Output: "bacd"
//Explaination: 
//Swap s[0] and s[3], s = "bcad"
//Swap s[1] and s[2], s = "bacd"
//Example 2:
//Input: s = "dcab", pairs = [[0,3],[1,2],[0,2]]
//Output: "abcd"
//Explaination: 
//Swap s[0] and s[3], s = "bcad"
//Swap s[0] and s[2], s = "acbd"
//Swap s[1] and s[2], s = "abcd"
//Example 3:
//Input: s = "cba", pairs = [[0,1],[1,2]]
//Output: "abc"
//Explaination: 
//Swap s[0] and s[1], s = "bca"
//Swap s[1] and s[2], s = "bac"
//Swap s[0] and s[1], s = "abc"
// 
//Constraints:
//	1 <= s.length <= 10^5
//	0 <= pairs.length <= 10^5
//	0 <= pairs[i][0], pairs[i][1] < s.length
//	s only contains lower case English letters.
class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) 
    {
        int n = s.size();
        vector<int> parent(n);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
        for (auto pair : pairs)
        {
            int x = pair[0];
            int y = pair[1];
            int px = find(parent, x);
            int py = find(parent, y);
            if (px != py)
            {
                parent[px] = py;
            }
        }
        vector<vector<int>> groups(n);
        for (int i = 0; i < n; i++)
        {
            groups[find(parent, i)].push_back(i);
        }
        string res(n, ' ');
        for (auto group : groups)
        {
            vector<char> chars;
            for (auto i : group)
            {
                chars.push_back(s[i]);
            }
            sort(chars.begin(), chars.end());
            for (int i = 0; i < group.size(); i++)
            {
                res[group[i]] = chars[i];
            }
        }
        return res;
        
    }
};