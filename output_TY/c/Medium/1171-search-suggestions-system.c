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
char *** suggestedProducts(char ** products, int productsSize, char * searchWord, int* returnSize, int** returnColumnSizes){
    int i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z;
    int len=strlen(searchWord);
    char ***ans=(char***)malloc(len*sizeof(char**));
    int *cols=(int*)malloc(len*sizeof(int));
    for(i=0;i<len;i++){
        ans[i]=(char**)malloc(3*sizeof(char*));
    }
    for(i=0;i<len;i++){
        cols[i]=0;
    }
    for(i=0;i<productsSize;i++){
        for(j=0;j<len;j++){
            if(products[i][j]==searchWord[j]){
                continue;
            }
            else{
                break;
            }
        }
        if(j==len){
            for(k=0;k<cols[i];k++){
                if(strcmp(ans[i][k],products[i])==0){
                    break;
                }
            }
        }
    }
    for(i=0;i<len;i++){
        for(j=0;j<productsSize;j++){
            for(k=0;k<len;k++){
                if(products[j][k]==searchWord[k]){
                    continue;
                }
                else{
                    break;
                }
            }
            if(k==i){
                for(l=0;l<cols[i];l++){
                    if(strcmp(ans[i][l],products[j])==0){
                        break;
                    }
                }
            }
        }
    }
    for(i=0;i<len;i++){
        for(j=0;j<productsSize;j++){
            for(k=0;k<len;k++){
                if(products[j][k]==searchWord[k]){
                    continue;
                }
                else{
                    break;
                }
            }
            if(k==i){
                for(l=0;l<cols[i];l++){
                    if(strcmp(ans[i][l],products[j])==0){
                        break;
                    }
                }
            }
        }
    }
    for(i=0;i<len;i++){
        for(j=0;j<productsSize;j++){
            for(k=0;k<len;k++){
                if(products[j][k]==searchWord[k]){
                    continue;
                }
                else{
                    break;
                }
            }
        }
    }
    *returnSize=len;
    *returnColumnSizes=cols;
    return ans;
}