/**https://leetcode.com/problems/maximum-elegance-of-a-k-length-subsequence/ */
//You are given a 0-indexed 2D integer array items of length n and an integer k.
//items[i] = [profiti, categoryi], where profiti and categoryi denote the profit and category of the ith item respectively.
//Let's define the elegance of a subsequence of items as total_profit + distinct_categories2, where total_profit is the sum of all profits in the subsequence, and distinct_categories is the number of distinct categories from all the categories in the selected subsequence.
//Your task is to find the maximum elegance from all subsequences of size k in items.
//Return an integer denoting the maximum elegance of a subsequence of items with size exactly k.
//Note: A subsequence of an array is a new array generated from the original array by deleting some elements (possibly none) without changing the remaining elements' relative order.
// 
//Example 1:
//Input: items = [[3,2],[5,1],[10,1]], k = 2
//Output: 17
//Explanation: In this example, we have to select a subsequence of size 2.
//We can select items[0] = [3,2] and items[2] = [10,1].
//The total profit in this subsequence is 3 + 10 = 13, and the subsequence contains 2 distinct categories [2,1].
//Hence, the elegance is 13 + 22 = 17, and we can show that it is the maximum achievable elegance. 
//Example 2:
//Input: items = [[3,1],[3,1],[2,2],[5,3]], k = 3
//Output: 19
//Explanation: In this example, we have to select a subsequence of size 3. 
//We can select items[0] = [3,1], items[2] = [2,2], and items[3] = [5,3]. 
//The total profit in this subsequence is 3 + 2 + 5 = 10, and the subsequence contains 3 distinct categories [1,2,3]. 
//Hence, the elegance is 10 + 32 = 19, and we can show that it is the maximum achievable elegance.
//Example 3:
//Input: items = [[1,1],[2,1],[3,1]], k = 3
//Output: 7
//Explanation: In this example, we have to select a subsequence of size 3. 
//We should select all the items. 
//The total profit will be 1 + 2 + 3 = 6, and the subsequence contains 1 distinct category [1]. 
//Hence, the maximum elegance is 6 + 12 = 7.  
// 
//Constraints:
//	1 <= items.length == n <= 105
//	items[i].length == 2
//	items[i][0] == profiti
//	items[i][1] == categoryi
//	1 <= profiti <= 109
//	1 <= categoryi <= n 
//	1 <= k <= n 
// Compare function for sorting items by profit in descending order
int compareItems(const void* a, const void* b) {
    int* itemA = *(int**)a;
    int* itemB = *(int**)b;
    
    // Sort by profit in descending order
    return itemB[0] - itemA[0];
}

long long findMaximumElegance(int** items, int itemsSize, int* itemsColSize, int k) {
    // Sort items by profit in descending order
    qsort(items, itemsSize, sizeof(int*), compareItems);
    
    // Use a hash set to track categories we've seen
    bool* seen = (bool*)calloc(itemsSize + 1, sizeof(bool)); // +1 because categories are 1-indexed
    
    // Stack to store profits of duplicate categories
    int* duplicateProfits = (int*)malloc(k * sizeof(int));
    int duplicateCount = 0;
    
    long long totalProfit = 0;
    int distinctCategories = 0;
    
    // First, take the k most profitable items
    for (int i = 0; i < k; i++) {
        int profit = items[i][0];
        int category = items[i][1];
        
        totalProfit += profit;
        
        if (!seen[category]) {
            seen[category] = true;
            distinctCategories++;
        } else {
            // If we've seen this category before, add its profit to the duplicates stack
            duplicateProfits[duplicateCount++] = profit;
        }
    }
    
    // Calculate initial elegance
    long long maxElegance = totalProfit + (long long)distinctCategories * distinctCategories;
    
    // Try to replace duplicate categories with less profitable items that introduce new categories
    for (int i = k; i < itemsSize; i++) {
        int profit = items[i][0];
        int category = items[i][1];
        
        // If we've already seen this category or we don't have any duplicates to replace, skip
        if (seen[category] || duplicateCount == 0) {
            continue;
        }
        
        // Replace the least profitable duplicate with this new category item
        int leastProfitableDuplicate = duplicateProfits[--duplicateCount];
        
        // Update total profit and distinct categories
        totalProfit = totalProfit - leastProfitableDuplicate + profit;
        distinctCategories++;
        seen[category] = true;
        
        // Calculate new elegance
        long long elegance = totalProfit + (long long)distinctCategories * distinctCategories;
        
        // Update max elegance if needed
        if (elegance > maxElegance) {
            maxElegance = elegance;
        }
    }
    
    // Free allocated memory
    free(seen);
    free(duplicateProfits);
    
    return maxElegance;
}
