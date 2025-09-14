/**https://leetcode.com/problems/search-suggestions-system/ */
//You are given an array of strings products and a string searchWord.
//Design a system that suggests at most three product names from products after each character of searchWord is typed. Suggested products should have common prefix with searchWord. If there are more than three products with a common prefix return the three lexicographically minimums products.
//Return a list of lists of the suggested products after each character of searchWord is typed.
// 
//Example 1:
//Input: products = ["mobile","mouse","moneypot","monitor","mousepad"], searchWord = "mouse"
//Output: [["mobile","moneypot","monitor"],["mobile","moneypot","monitor"],["mouse","mousepad"],["mouse","mousepad"],["mouse","mousepad"]]
//Explanation: products sorted lexicographically = ["mobile","moneypot","monitor","mouse","mousepad"].
//After typing m and mo all products match and we show user ["mobile","moneypot","monitor"].
//After typing mou, mous and mouse the system suggests ["mouse","mousepad"].
//Example 2:
//Input: products = ["havana"], searchWord = "havana"
//Output: [["havana"],["havana"],["havana"],["havana"],["havana"],["havana"]]
//Explanation: The only word "havana" will be always suggested while typing the search word.
// 
//Constraints:
//	1 <= products.length <= 1000
//	1 <= products[i].length <= 3000
//	1 <= sum(products[i].length) <= 2 * 104
//	All the strings of products are unique.
//	products[i] consists of lowercase English letters.
//	1 <= searchWord.length <= 1000
//	searchWord consists of lowercase English letters.
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char*** suggestedProducts(char** products, int productsSize, char* searchWord, int* returnSize, int** returnColumnSizes) {
    int i, j, k, n = strlen(searchWord);
    char ***res = (char ***)malloc(n * sizeof(char **));
    *returnSize = n;
    *returnColumnSizes = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        res[i] = (char **)malloc(3 * sizeof(char *));
        (*returnColumnSizes)[i] = 0;
        for (j = 0; j < productsSize; j++) {
            if (strncmp(products[j], searchWord, i + 1) == 0) {
                res[i][(*returnColumnSizes)[i]] = products[j];
                (*returnColumnSizes)[i]++;
            }
        }
        qsort(res[i], (*returnColumnSizes)[i], sizeof(char *), cmp);
        if ((*returnColumnSizes)[i] > 3) {
            (*returnColumnSizes)[i] = 3;
        }
    }
    return res;    
}