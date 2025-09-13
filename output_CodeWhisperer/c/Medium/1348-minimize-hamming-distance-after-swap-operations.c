/**https://leetcode.com/problems/minimize-hamming-distance-after-swap-operations/ */
//You are given two integer arrays, source and target, both of length n. You are also given an array allowedSwaps where each allowedSwaps[i] = [ai, bi] indicates that you are allowed to swap the elements at index ai and index bi (0-indexed) of array source. Note that you can swap elements at a specific pair of indices multiple times and in any order.
//The Hamming distance of two arrays of the same length, source and target, is the number of positions where the elements are different. Formally, it is the number of indices i for 0 <= i <= n-1 where source[i] != target[i] (0-indexed).
//Return the minimum Hamming distance of source and target after performing any amount of swap operations on array source.
// 
//Example 1:
//Input: source = [1,2,3,4], target = [2,1,4,5], allowedSwaps = [[0,1],[2,3]]
//Output: 1
//Explanation: source can be transformed the following way:
//- Swap indices 0 and 1: source = [2,1,3,4]
//- Swap indices 2 and 3: source = [2,1,4,3]
//The Hamming distance of source and target is 1 as they differ in 1 position: index 3.
//Example 2:
//Input: source = [1,2,3,4], target = [1,3,2,4], allowedSwaps = []
//Output: 2
//Explanation: There are no allowed swaps.
//The Hamming distance of source and target is 2 as they differ in 2 positions: index 1 and index 2.
//Example 3:
//Input: source = [5,1,2,4,3], target = [1,5,4,2,3], allowedSwaps = [[0,4],[4,2],[1,3],[1,4]]
//Output: 0
// 
//Constraints:
//	n == source.length == target.length
//	1 <= n <= 105
//	1 <= source[i], target[i] <= 105
//	0 <= allowedSwaps.length <= 105
//	allowedSwaps[i].length == 2
//	0 <= ai, bi <= n - 1
//	ai != bi
int minimumHammingDistance(int* source, int sourceSize, int* target, int targetSize, int** allowedSwaps, int allowedSwapsSize, int* allowedSwapsColSize) {
    int* parent = (int*)malloc(sourceSize * sizeof(int));
    for (int i = 0; i < sourceSize; i++) {
        parent[i] = i;
    }
    for (int i = 0; i < allowedSwapsSize; i++) {
        int a = allowedSwaps[i][0];
        int b = allowedSwaps[i][1];
        while (parent[a] != a) {
            a = parent[a];
        }
        while (parent[b] != b) {
            b = parent[b];
        }
        if (a != b) {
            parent[b] = a;
        }
    }
    int* count = (int*)calloc(sourceSize, sizeof(int));
    for (int i = 0; i < sourceSize; i++) {
        int p = i;
        while (parent[p] != p) {
            p = parent[p];
        }
        count[p]++;
    }
    int result = 0;
    for (int i = 0; i < sourceSize; i++) {
        if (count[i] > 0) {
            int* freq = (int*)calloc(sourceSize + 1, sizeof(int));
            for (int j = 0; j < sourceSize; j++) {
                if (parent[j] == i) {
                    freq[source[j]]++;
                }
            }
            for (int j = 0; j < sourceSize; j++) {
                if (parent[j] == i) {
                    if (freq[target[j]] > 0) {
                        freq[target[j]]--;
                    } else {
                        result++;
                    }
                }
            }
            free(freq);
        }
    }
    free(parent);
    free(count);
    return result;
}