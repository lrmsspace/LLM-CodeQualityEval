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
    int i, j, k, max = 0, count = 0;
    char*** result;
    int* popularity;
    char** creator;
    char** id;
    for (i = 0; i < creatorsSize; i++) {
        for (j = i + 1; j < creatorsSize; j++) {
            if (strcmp(creators[i], creators[j]) == 0) {
                count++;
                if (views[i] < views[j]) {
                    views[i] = views[j];
                    ids[i] = ids[j];
                }
            }
        }
        if (count > max) {
            max = count;
            popularity = (int*)malloc(sizeof(int));
            creator = (char**)malloc(sizeof(char*));
            id = (char**)malloc(sizeof(char*));
            popularity[0] = views[i];
            creator[0] = creators[i];
            id[0] = ids[i];
        } else if (count == max) {
            popularity = (int*)realloc(popularity, (max + 1) * sizeof(int));
            creator = (char**)realloc(creator, (max + 1) * sizeof(char*));
            id = (char**)realloc(id, (max + 1) * sizeof(char*));
            popularity[max] = views[i];
            creator[max] = creators[i];
            id[max] = ids[i];
        }
        count = 0;
    }
    *returnSize = max + 1;
    result = (char***)malloc((*returnSize) * sizeof(char**));
    *returnColumnSizes = (int*)malloc((*returnSize) * sizeof(int));
    for (i = 0; i < *returnSize; i++) {
        result[i] = (char**)malloc(2 * sizeof(char*));
        result[i][0] = creator[i];
        result[i][1] = id[i];
        (*returnColumnSizes)[i] = 2;
    }
    return result;
}