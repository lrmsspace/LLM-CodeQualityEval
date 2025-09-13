/**https://leetcode.com/problems/similar-string-groups/ */
//Two strings, X and Y, are considered similar if either they are identical or we can make them equivalent by swapping at most two letters (in distinct positions) within the string X.
//For example, "tars" and "rats" are similar (swapping at positions 0 and 2), and "rats" and "arts" are similar, but "star" is not similar to "tars", "rats", or "arts".
//Together, these form two connected groups by similarity: {"tars", "rats", "arts"} and {"star"}.  Notice that "tars" and "arts" are in the same group even though they are not similar.  Formally, each group is such that a word is in the group if and only if it is similar to at least one other word in the group.
//We are given a list strs of strings where every string in strs is an anagram of every other string in strs. How many groups are there?
// 
//Example 1:
//Input: strs = ["tars","rats","arts","star"]
//Output: 2
//Example 2:
//Input: strs = ["omv","ovm"]
//Output: 1
// 
//Constraints:
//	1 <= strs.length <= 300
//	1 <= strs[i].length <= 300
//	strs[i] consists of lowercase letters only. 
//	All words in strs have the same length and are anagrams of each other.
class Solution {
    public:
        int numSimilarGroups(vector<string>& strs) {
            int n = strs.size();
            
            // Initialize Union-Find data structure
            UnionFind uf(n);
            
            // Check each pair of strings
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    // If the strings are similar, union their groups
                    if (isSimilar(strs[i], strs[j])) {
                        uf.unite(i, j);
                    }
                }
            }
            
            // Count the number of distinct groups
            return uf.count();
        }
        
    private:
        // Check if two strings are similar
        bool isSimilar(const string& a, const string& b) {
            if (a == b) return true;
            
            int diffCount = 0;
            vector<int> diffPositions;
            
            for (int i = 0; i < a.length(); i++) {
                if (a[i] != b[i]) {
                    diffCount++;
                    diffPositions.push_back(i);
                    
                    // If more than 2 positions differ, they can't be similar
                    if (diffCount > 2) {
                        return false;
                    }
                }
            }
            
            // If exactly 2 positions differ, check if swapping makes them equal
            if (diffCount == 2) {
                return a[diffPositions[0]] == b[diffPositions[1]] && 
                       a[diffPositions[1]] == b[diffPositions[0]];
            }
            
            // If only 1 position differs, they can't be made equal by swapping
            return diffCount == 0;
        }
        
        // Union-Find data structure
        class UnionFind {
        public:
            UnionFind(int n) {
                parent.resize(n);
                rank.resize(n, 0);
                count_ = n;
                
                // Initialize each element as its own parent
                for (int i = 0; i < n; i++) {
                    parent[i] = i;
                }
            }
            
            // Find the root of the set containing element x
            int find(int x) {
                if (parent[x] != x) {
                    parent[x] = find(parent[x]); // Path compression
                }
                return parent[x];
            }
            
            // Union the sets containing elements x and y
            void unite(int x, int y) {
                int rootX = find(x);
                int rootY = find(y);
                
                if (rootX == rootY) return;
                
                // Union by rank
                if (rank[rootX] < rank[rootY]) {
                    parent[rootX] = rootY;
                } else if (rank[rootX] > rank[rootY]) {
                    parent[rootY] = rootX;
                } else {
                    parent[rootY] = rootX;
                    rank[rootX]++;
                }
                
                count_--; // Decrease the count of distinct sets
            }
            
            // Get the number of distinct sets
            int count() const {
                return count_;
            }
            
        private:
            vector<int> parent;
            vector<int> rank;
            int count_;
        };
    };
    