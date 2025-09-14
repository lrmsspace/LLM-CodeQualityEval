/*
 You are given an integer n and an array sick sorted in increasing order, representing positions of infected people in a line of n people.
 At each step, one uninfected person adjacent to an infected person gets infected. This process continues until everyone is infected.
 An infection sequence is the order in which uninfected people become infected, excluding those initially infected.
 Return the number of different infection sequences possible, modulo 109+7.
 Example 1:
 Input: n = 5, sick = [0,4]
 Output: 4
 Explanation:
 There is a total of 6 different sequences overall.
 Valid infection sequences are [1,2,3], [1,3,2], [3,2,1] and [3,1,2].
 [2,3,1] and [2,1,3] are not valid infection sequences because the person at index 2 cannot be infected at the first step.
 Example 2:
 Input: n = 4, sick = [1]
 Output: 3
 Explanation:
 There is a total of 6 different sequences overall.
 Valid infection sequences are [0,2,3], [2,0,3] and [2,3,0].
 [3,2,0], [3,0,2], and [0,3,2] are not valid infection sequences because the infection starts at the person at index 1, then the order of infection is 2, then 3, and hence 3 cannot be infected earlier than 2.
 Constraints:
 2 <= n <= 105
 1 <= sick.length <= n - 1
 0 <= sick[i] <= n - 1
 sick is sorted in increasing order.
*/

class Solution {
public:
    int numberOfSequence(int n, vector<int>& sick) {
        const int MOD = 1e9 + 7;
        int m = sick.size();
        long long result = 1;

        // Calculate the gaps between infected people
        for (int i = 0; i < m - 1; ++i) {
            int gap = sick[i + 1] - sick[i] - 1; // Number of uninfected people between two infected people
            if (gap > 0) {
                result = (result * (gap + 1)) % MOD; // Each gap can be filled in gap + 1 ways
            }
        }

        // Handle the edges: before the first infected and after the last infected
        if (sick[0] > 0) {
            result = (result * (sick[0] + 1)) % MOD; // Before the first infected person
        }
        if (sick[m - 1] < n - 1) {
            result = (result * (n - 1 - sick[m - 1] + 1)) % MOD; // After the last infected person
        }

        return static_cast<int>(result);
        
    }
};