/**https://leetcode.com/problems/brace-expansion-ii/ */
//Under the grammar given below, strings can represent a set of lowercase words. Let R(expr) denote the set of words the expression represents.
//The grammar can best be understood through simple examples:
//	Single letters represent a singleton set containing that word.
//	
//		R("a") = {"a"}
//		R("w") = {"w"}
//	
//	
//	When we take a comma-delimited list of two or more expressions, we take the union of possibilities.
//	
//		R("{a,b,c}") = {"a","b","c"}
//		R("{{a,b},{b,c}}") = {"a","b","c"} (notice the final set only contains each word at most once)
//	
//	
//	When we concatenate two expressions, we take the set of possible concatenations between two words where the first word comes from the first expression and the second word comes from the second expression.
//	
//		R("{a,b}{c,d}") = {"ac","ad","bc","bd"}
//		R("a{b,c}{d,e}f{g,h}") = {"abdfg", "abdfh", "abefg", "abefh", "acdfg", "acdfh", "acefg", "acefh"}
//	
//	
//Formally, the three rules for our grammar:
//	For every lowercase letter x, we have R(x) = {x}.
//	For expressions e1, e2, ... , ek with k >= 2, we have R({e1, e2, ...}) = R(e1) ∪ R(e2) ∪ ...
//	For expressions e1 and e2, we have R(e1 + e2) = {a + b for (a, b) in R(e1) × R(e2)}, where + denotes concatenation, and × denotes the cartesian product.
//Given an expression representing a set of words under the given grammar, return the sorted list of words that the expression represents.
// 
//Example 1:
//Input: expression = "{a,b}{c,{d,e}}"
//Output: ["ac","ad","ae","bc","bd","be"]
//Example 2:
//Input: expression = "{{a,z},a{b,c},{ab,z}}"
//Output: ["a","ab","ac","z"]
//Explanation: Each distinct word is written only once in the final answer.
// 
//Constraints:
//	1 <= expression.length <= 60
//	expression[i] consists of '{', '}', ','or lowercase English letters.
//	The given expression represents a set of words based on the grammar given in the description.
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** braceExpansionII(char* expression, int* returnSize) {


    int n = strlen(expression);
    char** result = (char**)malloc(sizeof(char*) * 10000);
    *returnSize = 0;
    result[*returnSize] = (char*)malloc(sizeof(char) * 100);
    strcpy(result[*returnSize], expression);
    (*returnSize)++;
    for (int i = 0; i < n; i++) {
        if (expression[i] == '{') {
            int j = i + 1;
            int count = 1;
            while (count > 0) {
                if (expression[j] == '{') {
                    count++;
                }
                if (expression[j] == '}') {
                    count--;
                }
                j++;
            }
            char* temp = (char*)malloc(sizeof(char) * 100);
            strncpy(temp, expression + i + 1, j - i - 2);
            temp[j - i - 2] = '\0';
            char** tempResult = (char**)malloc(sizeof(char*) * 10000);
            int tempReturnSize = 0;
            braceExpansionII(temp, &tempReturnSize);
            for (int k = 0; k < tempReturnSize; k++) {
                char* temp2 = (char*)malloc(sizeof(char) * 100);
                strcpy(temp2, result[i]);
                strcat(temp2, tempResult[k]);
                strcat(temp2, expression + j);
                result[*returnSize] = (char*)malloc(sizeof(char) * 100);
                strcpy(result[*returnSize], temp2);
                (*returnSize)++;
            }
            i = j - 1;
        }
    }
    for (int i = 0; i < *returnSize; i++) {
        for (int j = i + 1; j < *returnSize; j++) {
            if (strcmp(result[i], result[j]) > 0) {
                char* temp = result[i];
                result[i] = result[j];
                result[j] = temp;
            }
        }
    }

    int k = 1;

    for (int i = 1; i < *returnSize; i++) {
        if (strcmp(result[i], result[i - 1]) != 0) {
            result[k++] = result[i];
        }
    }



    *returnSize = k;

    return result;
    
}