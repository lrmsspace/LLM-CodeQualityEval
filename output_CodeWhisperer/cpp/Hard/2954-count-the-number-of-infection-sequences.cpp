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
    const int MOD = 1e9 + 7;
    
    long long power(long long x, int y) {
        long long res = 1;
        while (y) {
            if (y & 1) res = (res * x) % MOD;
            x = (x * x) % MOD;
            y >>= 1;
        }
        return res;
    }
    
    long long modInverse(long long n) {
        return power(n, MOD - 2);
    }
    
    int numberOfSequence(int n, vector<int>& sick) {
        int m = sick.size();
        vector<int> gaps;
        long long ans = 1;
        
        // Calculate initial gap before first sick person
        if (sick[0] > 0) {
            gaps.push_back(sick[0]);
        }
        
        // Calculate gaps between sick people
        for (int i = 1; i < m; i++) {
            int gap = sick[i] - sick[i-1] - 1;
            if (gap > 0) {
                gaps.push_back(gap);
            }
        }
        
        // Calculate final gap after last sick person
        if (sick.back() < n-1) {
            gaps.push_back(n-1 - sick.back());
        }
        
        // Calculate total healthy people
        int total = n - m;
        
        // Calculate combinations
        for (int gap : gaps) {
            ans = (ans * power(2, gap-1)) % MOD;
        }
        
        // Calculate permutations
        long long numerator = 1;
        for (int i = 1; i <= total; i++) {
            numerator = (numerator * i) % MOD;
        }
        
        long long denominator = 1;
        for (int gap : gaps) {
            for (int i = 1; i <= gap; i++) {
                denominator = (denominator * i) % MOD;
            }
        }
        
        ans = (ans * numerator) % MOD;
        ans = (ans * modInverse(denominator)) % MOD;
        
        return ans;
    }
};          