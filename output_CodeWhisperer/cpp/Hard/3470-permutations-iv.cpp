/*
 Given two integers, n and k, an alternating permutation is a permutation of the first n positive integers such that no two adjacent elements are both odd or both even.
 Return the k-th alternating permutation sorted in lexicographical order. If there are fewer than k valid alternating permutations, return an empty list.
 Example 1:
 Input: n = 4, k = 6
 Output: [3,4,1,2]
 Explanation:
 The lexicographically-sorted alternating permutations of [1, 2, 3, 4] are:
 [1, 2, 3, 4]
 [1, 4, 3, 2]
 [2, 1, 4, 3]
 [2, 3, 4, 1]
 [3, 2, 1, 4]
 [3, 4, 1, 2] ← 6th permutation
 [4, 1, 2, 3]
 [4, 3, 2, 1]
 Since k = 6, we return [3, 4, 1, 2].
 Example 2:
 Input: n = 3, k = 2
 Output: [3,2,1]
 Explanation:
 The lexicographically-sorted alternating permutations of [1, 2, 3] are:
 [1, 2, 3]
 [3, 2, 1] ← 2nd permutation
 Since k = 2, we return [3, 2, 1].
 Example 3:
 Input: n = 2, k = 3
 Output: []
 Explanation:
 The lexicographically-sorted alternating permutations of [1, 2] are:
 [1, 2]
 [2, 1]
 There are only 2 alternating permutations, but k = 3, which is out of range. Thus, we return an empty list [].
 Constraints:
 1 <= n <= 100
 1 <= k <= 1015
*/

class Solution {
public:
    vector<int> permute(int n, long long k) {
        if(n == 1) return {1};
        if(n == 2) return k == 1 ? vector<int>{2, 1} : vector<int>{};
        int half = n / 2;
        long long halfFact = 1;
        for(int i = 1; i <= half; i++) halfFact *= i;
        if(k > halfFact * 2) return vector<int>{};
        if(k <= halfFact) {
            vector<int> res = permute(n - 1, k);
            for(int i = 0; i < res.size(); i++) res[i] += 1;
            res.insert(res.begin(), n);
            return res;
        }
        else {
            vector<int> res = permute(n - 2, k - halfFact);
            for(int i = 0; i < res.size(); i++) res[i] += 2;
            res.insert(res.begin(), n - 1);
            res.insert(res.begin(), n);
            return res;
        }        
    }
};