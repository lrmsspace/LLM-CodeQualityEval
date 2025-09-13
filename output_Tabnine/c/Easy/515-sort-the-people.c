/**https://leetcode.com/problems/sort-the-people/ */
//You are given an array of strings names, and an array heights that consists of distinct positive integers. Both arrays are of length n.
//For each index i, names[i] and heights[i] denote the name and height of the ith person.
//Return names sorted in descending order by the people's heights.
// 
//Example 1:
//Input: names = ["Mary","John","Emma"], heights = [180,165,170]
//Output: ["Mary","Emma","John"]
//Explanation: Mary is the tallest, followed by Emma and John.
//Example 2:
//Input: names = ["Alice","Bob","Bob"], heights = [155,185,150]
//Output: ["Bob","Alice","Bob"]
//Explanation: The first Bob is the tallest, followed by Alice and the second Bob.
// 
//Constraints:
//	n == names.length == heights.length
//	1 <= n <= 103
//	1 <= names[i].length <= 20
//	1 <= heights[i] <= 105
//	names[i] consists of lower and upper case English letters.
//	All the values of heights are distinct.
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** sortPeople(char** names, int namesSize, int* heights, int heightsSize, int* returnSize) {
    // Create a temporary array to store the names and heights
    struct Person {
        char* name;
        int height;
    } *persons = malloc(namesSize * sizeof(struct Person));
    
    // Copy the given arrays into the temporary array
    for (int i = 0; i < namesSize; i++) {
        persons[i].name = malloc((strlen(names[i]) + 1) * sizeof(char));
        strcpy(persons[i].name, names[i]);
        persons[i].height = heights[i];
    }
    
    // Sort the temporary array by height in descending order
    qsort(persons, namesSize, sizeof(struct Person), compare);
    
    // Allocate memory for the sorted names array
    char** sortedNames = malloc(namesSize * sizeof(char*));
    
    // Copy the sorted names from the temporary array into the sortedNames array
    for (int i = 0; i < namesSize; i++) {
        sortedNames[i] = persons[i].name;
    }
    
    // Free the temporary array
    for (int i = 0; i < namesSize; i++) {
        free(persons[i].name);
    }
    free(persons);
    
    // Set the returnSize pointer to the number of names
    *returnSize = namesSize;
    
    // Return the sorted names array
    return sortedNames;
    
}