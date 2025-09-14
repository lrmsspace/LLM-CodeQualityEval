/*
 You are given a 0-indexed integer array nums.
 A subsequence of nums having length k and consisting of indices i0 < i1 < ... < ik-1 is balanced if the following holds:
 nums[ij] - nums[ij-1] >= ij - ij-1, for every j in the range [1, k - 1].
 A subsequence of nums having length 1 is considered balanced.
 Return an integer denoting the maximum possible sum of elements in a balanced subsequence of nums.
 A subsequence of an array is a new non-empty array that is formed from the original array by deleting some (possibly none) of the elements without disturbing the relative positions of the remaining elements.
 Example 1:
 Input: nums = [3,3,5,6]
 Output: 14
 Explanation: In this example, the subsequence [3,5,6] consisting of indices 0, 2, and 3 can be selected.
 nums[2] - nums[0] >= 2 - 0.
 nums[3] - nums[2] >= 3 - 2.
 Hence, it is a balanced subsequence, and its sum is the maximum among the balanced subsequences of nums.
 The subsequence consisting of indices 1, 2, and 3 is also valid.
 It can be shown that it is not possible to get a balanced subsequence with a sum greater than 14.
 Example 2:
 Input: nums = [5,-1,-3,8]
 Output: 13
 Explanation: In this example, the subsequence [5,8] consisting of indices 0 and 3 can be selected.
 nums[3] - nums[0] >= 3 - 0.
 Hence, it is a balanced subsequence, and its sum is the maximum among the balanced subsequences of nums.
 It can be shown that it is not possible to get a balanced subsequence with a sum greater than 13.
 Example 3:
 Input: nums = [-2,-1]
 Output: -1
 Explanation: In this example, the subsequence [-1] can be selected.
 It is a balanced subsequence, and its sum is the maximum among the balanced subsequences of nums.
 Constraints:
 1 <= nums.length <= 105
 -109 <= nums[i] <= 109
*/

#define MAX_N 100001
#define ll long long

// 线段树节点结构
typedef struct {
    ll max;  // 区间最大值
} SegTree;

// 更新线段树节点
void update(SegTree* tree, int node, int start, int end, int idx, ll val) {
    if (start == end) {
        tree[node].max = val;
        return;
    }
    
    int mid = (start + end) / 2;
    if (idx <= mid) {
        update(tree, node * 2 + 1, start, mid, idx, val);
    } else {
        update(tree, node * 2 + 2, mid + 1, end, idx, val);
    }
    
    tree[node].max = tree[node * 2 + 1].max > tree[node * 2 + 2].max ? 
                     tree[node * 2 + 1].max : tree[node * 2 + 2].max;
}

// 查询区间最大值
ll query(SegTree* tree, int node, int start, int end, int l, int r) {
    if (r < start || l > end) return -1e18;
    if (l <= start && end <= r) return tree[node].max;
    
    int mid = (start + end) / 2;
    ll left = query(tree, node * 2 + 1, start, mid, l, r);
    ll right = query(tree, node * 2 + 2, mid + 1, end, l, r);
    
    return left > right ? left : right;
}

// 比较函数，用于排序
int compare(const void* a, const void* b) {
    int* pa = *(int**)a;
    int* pb = *(int**)b;
    return pa[0] - pb[0];
}

long long maxBalancedSubsequenceSum(int* nums, int numsSize) {
    // 创建差值数组并排序
    int** diffs = (int**)malloc(numsSize * sizeof(int*));
    for (int i = 0; i < numsSize; i++) {
        diffs[i] = (int*)malloc(2 * sizeof(int));
        diffs[i][0] = nums[i] - i;  // 差值
        diffs[i][1] = i;  // 原始索引
    }
    
    // 按差值排序
    qsort(diffs, numsSize, sizeof(int*), compare);
    
    // 创建并初始化线段树
    SegTree* tree = (SegTree*)calloc(4 * numsSize, sizeof(SegTree));
    for (int i = 0; i < 4 * numsSize; i++) {
        tree[i].max = -1e18;
    }
    
    // 动态规划
    ll result = nums[0];
    for (int i = 0; i < numsSize; i++) {
        int idx = diffs[i][1];
        ll val = nums[idx];
        
        // 查询前面所有可能的结果
        ll prev = query(tree, 0, 0, numsSize - 1, 0, idx);
        ll curr = prev > 0 ? prev + val : val;
        
        // 更新结果
        result = result > curr ? result : curr;
        
        // 更新线段树
        update(tree, 0, 0, numsSize - 1, idx, curr);
    }
    
    // 释放内存
    for (int i = 0; i < numsSize; i++) {
        free(diffs[i]);
    }
    free(diffs);
    free(tree);
    
    return result;
}
