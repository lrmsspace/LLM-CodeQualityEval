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
    *returnSize = strlen(searchWord);
    *returnColumnSizes = malloc(sizeof(int) * *returnSize);
    char*** result = malloc(sizeof(char**) * *returnSize);
    
    for (int i = 0; i < *returnSize; ++i) {
        (*returnColumnSizes)[i] = 3;
        result[i] = malloc(sizeof(char*) * 3);
        for (int j = 0; j < 3; ++j) {
            result[i][j] = malloc(sizeof(char) * (strlen(searchWord) + 1));
        }
    }
    
    int count = 0;
    qsort(products, productsSize, sizeof(char*), compare);
    
    for (int i = 0; i < strlen(searchWord); ++i) {
        char prefix[i + 2];
        strncpy(prefix, searchWord, i + 1);
        prefix[i + 1] = '\0';
        
        for (int j = 0; j < productsSize && count < 3; ++j) {
            if (strstr(products[j], prefix)!= NULL) {
                strncpy(result[i][count], products[j], strlen(products[j]) + 1);
                count++;
            }
        }
    }
    
    return result;
    
}