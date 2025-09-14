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

/**
 * @param {number} n
 * @param {number} k
 * @return {number[]}
 */
var permute = function(n, k) {
    let arr = Array.from({length:n},(v,i)=>i+1);
    let res = [];
    let dfs = (path)=>{
        if(path.length === n){
            res.push(path);
            return;
        }
        for(let i=0;i<arr.length;i++){
            if(path.length%2 === 0 && arr[i]%2 === 1) continue;
            if(path.length%2 === 1 && arr[i]%2 === 0) continue;
            dfs(path.concat(arr[i]));
        }
    }
    dfs([]);
    res.sort((a,b)=>{
        for(let i=0;i<a.length;i++){
            if(a[i] === b[i]) continue;
            return a[i] - b[i];
        }
    });
    return res[k-1] || [];    
};