/**https://leetcode.com/problems/most-popular-video-creator/ */
//You are given two string arrays creators and ids, and an integer array views, all of length n. The ith video on a platform was created by creators[i], has an id of ids[i], and has views[i] views.
//The popularity of a creator is the sum of the number of views on all of the creator's videos. Find the creator with the highest popularity and the id of their most viewed video.
//	If multiple creators have the highest popularity, find all of them.
//	If multiple videos have the highest view count for a creator, find the lexicographically smallest id.
//Note: It is possible for different videos to have the same id, meaning that ids do not uniquely identify a video. For example, two videos with the same ID are considered as distinct videos with their own viewcount.
//Return a 2D array of strings answer where answer[i] = [creatorsi, idi] means that creatorsi has the highest popularity and idi is the id of their most popular video. The answer can be returned in any order.
// 
//Example 1:
//Input: creators = ["alice","bob","alice","chris"], ids = ["one","two","three","four"], views = [5,10,5,4]
//Output: [["alice","one"],["bob","two"]]
//Explanation:
//The popularity of alice is 5 + 5 = 10.
//The popularity of bob is 10.
//The popularity of chris is 4.
//alice and bob are the most popular creators.
//For bob, the video with the highest view count is "two".
//For alice, the videos with the highest view count are "one" and "three". Since "one" is lexicographically smaller than "three", it is included in the answer.
//Example 2:
//Input: creators = ["alice","alice","alice"], ids = ["a","b","c"], views = [1,2,2]
//Output: [["alice","b"]]
//Explanation:
//The videos with id "b" and "c" have the highest view count.
//Since "b" is lexicographically smaller than "c", it is included in the answer.
// 
//Constraints:
//	n == creators.length == ids.length == views.length
//	1 <= n <= 105
//	1 <= creators[i].length, ids[i].length <= 5
//	creators[i] and ids[i] consist only of lowercase English letters.
//	0 <= views[i] <= 105
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char*** mostPopularCreator(char** creators, int creatorsSize, char** ids, int idsSize, int* views, int viewsSize, int* returnSize, int** returnColumnSizes) {
    int i, j;
    struct {
        char* creator;
        int maxView;
        char* id;
    } *hashTable = (struct {
        char* creator;
        int maxView;
        char* id;
    }*)malloc(100000 * sizeof(struct {
        char* creator;
        int maxView;
        char* id;
    }));
    for (i = 0; i < 100000; i++) {
        hashTable[i].creator = NULL;
        hashTable[i].maxView = 0;
        hashTable[i].id = NULL;
    }
    for (i = 0; i < creatorsSize; i++) {
        int key = (creators[i][0] - 'a') * 26 * 26 * 26 + (creators[i][1] - 'a') * 26 * 26 + (creators[i][2] - 'a') * 26 + (creators[i][3] - 'a');
        if (hashTable[key].creator == NULL) {
            hashTable[key].creator = creators[i];
            hashTable[key].maxView = views[i];
            hashTable[key].id = ids[i];
        } else if (hashTable[key].maxView < views[i]) {
            hashTable[key].maxView = views[i];
            hashTable[key].id = ids[i];
        } else if (hashTable[key].maxView == views[i]) {
            if (strcmp(hashTable[key].id, ids[i]) > 0) {
                hashTable[key].id = ids[i];
            }
        }
    }
    int count = 0;
    for (i = 0; i < 100000; i++) {
        if (hashTable[i].creator != NULL) {
            count++;
        }
    }
    *returnSize = count;
    *returnColumnSizes = (int*)malloc(count * sizeof(int));
    for (i = 0; i < count; i++) {
        (*returnColumnSizes)[i] = 2;
    }
    char*** res = (char***)malloc(count * sizeof(char**));
    count = 0;
    for (i = 0; i < 100000; i++) {
        if (hashTable[i].creator != NULL) {
            res[count] = (char**)malloc(2 * sizeof(char*));
            res[count][0] = hashTable[i].creator;
            res[count][1] = hashTable[i].id;
            count++;
        }
    }
    free(hashTable);
    return res;
}