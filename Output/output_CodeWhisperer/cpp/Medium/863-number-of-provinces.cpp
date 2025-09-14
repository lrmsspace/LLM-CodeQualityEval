/**https://leetcode.com/problems/number-of-provinces/ */
//There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.
//A province is a group of directly or indirectly connected cities and no other cities outside of the group.
//You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.
//Return the total number of provinces.
// 
//Example 1:
//Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
//Output: 2
//Example 2:
//Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
//Output: 3
// 
//Constraints:
//	1 <= n <= 200
//	n == isConnected.length
//	n == isConnected[i].length
//	isConnected[i][j] is 1 or 0.
//	isConnected[i][i] == 1
//	isConnected[i][j] == isConnected[j][i]  
class Solution {
    public:
        int findCircleNum(vector<vector<int>>& isConnected) {
            int n = isConnected.size();
            vector<int> parent(n);
            vector<int> rank(n, 0);
            
            // Initialize each city as its own parent
            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
            
            // Union cities that are connected
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    if (isConnected[i][j] == 1) {
                        unionSets(parent, rank, i, j);
                    }
                }
            }
            
            // Count the number of distinct parents (provinces)
            int provinces = 0;
            for (int i = 0; i < n; i++) {
                if (parent[i] == i) {
                    provinces++;
                }
            }
            
            return provinces;
        }
        
    private:
        int find(vector<int>& parent, int x) {
            if (parent[x] != x) {
                parent[x] = find(parent, parent[x]); // Path compression
            }
            return parent[x];
        }
        
        void unionSets(vector<int>& parent, vector<int>& rank, int x, int y) {
            int rootX = find(parent, x);
            int rootY = find(parent, y);
            
            if (rootX != rootY) {
                if (rank[rootX] < rank[rootY]) {
                    parent[rootX] = rootY;
                } else if (rank[rootX] > rank[rootY]) {
                    parent[rootY] = rootX;
                } else {
                    parent[rootY] = rootX;
                    rank[rootX]++;
                }
            }
        }
    };
    