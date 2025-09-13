/**https://leetcode.com/problems/count-ways-to-build-rooms-in-an-ant-colony/ */
//You are an ant tasked with adding n new rooms numbered 0 to n-1 to your colony. You are given the expansion plan as a 0-indexed integer array of length n, prevRoom, where prevRoom[i] indicates that you must build room prevRoom[i] before building room i, and these two rooms must be connected directly. Room 0 is already built, so prevRoom[0] = -1. The expansion plan is given such that once all the rooms are built, every room will be reachable from room 0.
//You can only build one room at a time, and you can travel freely between rooms you have already built only if they are connected. You can choose to build any room as long as its previous room is already built.
//Return the number of different orders you can build all the rooms in. Since the answer may be large, return it modulo 109 + 7.
// 
//Example 1:
//Input: prevRoom = [-1,0,1]
//Output: 1
//Explanation: There is only one way to build the additional rooms: 0 → 1 → 2
//Example 2:
//Input: prevRoom = [-1,0,0,1,2]
//Output: 6
//Explanation:
//The 6 ways are:
//0 → 1 → 3 → 2 → 4
//0 → 2 → 4 → 1 → 3
//0 → 1 → 2 → 3 → 4
//0 → 1 → 2 → 4 → 3
//0 → 2 → 1 → 3 → 4
//0 → 2 → 1 → 4 → 3
// 
//Constraints:
//	n == prevRoom.length
//	2 <= n <= 105
//	prevRoom[0] == -1
//	0 <= prevRoom[i] < n for all 1 <= i < n
//	Every room is reachable from room 0 once all the rooms are built.
class Solution {

public:

    int waysToBuildRooms(vector<int>& prevRoom) {

        int n = prevRoom.size();

        vector<vector<int>> g(n);

        for (int i = 1; i < n; ++i) {

            g[prevRoom[i]].push_back(i);

        }

        vector<int> sz(n);

        function<void(int)> dfs = [&](int u) {

            sz[u] = 1;

            for (int v : g[u]) {

                dfs(v);

                sz[u] += sz[v];

            }

        };

        dfs(0);

        vector<long long> fact(n + 1);

        fact[0] = 1;

        for (int i = 1; i <= n; ++i) {

            fact[i] = fact[i - 1] * i % 1000000007;

        }

        function<long long(int)> modinv = [&](int x) {

            long long ans = 1, base = x, MOD = 1000000007;

            int power = MOD - 2;

            while (power) {

                if (power & 1) {

                    ans = ans * base % MOD;

                }

                base = base * base % MOD;

                power >>= 1;

            }

            return ans;

        };

        function<long long(int, int)> nCr = [&](int n, int r) {

            return fact[n] * modinv(fact[r]) % 1000000007 * modinv(fact[n - r]) % 1000000007;

        };

        long long ans = 1;

        for (int i = 0; i < n; ++i) {

            ans = ans * nCr(sz[i] - 1, g[i].size()) % 1000000007;

        }

        return ans;
        
    }

};