/**https://leetcode.com/problems/maximum-number-of-groups-getting-fresh-donuts/ */
//There is a donuts shop that bakes donuts in batches of batchSize. They have a rule where they must serve all of the donuts of a batch before serving any donuts of the next batch. You are given an integer batchSize and an integer array groups, where groups[i] denotes that there is a group of groups[i] customers that will visit the shop. Each customer will get exactly one donut.
//When a group visits the shop, all customers of the group must be served before serving any of the following groups. A group will be happy if they all get fresh donuts. That is, the first customer of the group does not receive a donut that was left over from the previous group.
//You can freely rearrange the ordering of the groups. Return the maximum possible number of happy groups after rearranging the groups.
// 
//Example 1:
//Input: batchSize = 3, groups = [1,2,3,4,5,6]
//Output: 4
//Explanation: You can arrange the groups as [6,2,4,5,1,3]. Then the 1st, 2nd, 4th, and 6th groups will be happy.
//Example 2:
//Input: batchSize = 4, groups = [1,3,2,5,2,2,1,6]
//Output: 4
// 
//Constraints:
//	1 <= batchSize <= 9
//	1 <= groups.length <= 30
//	1 <= groups[i] <= 109
int maxHappyGroups(int batchSize, int* groups, int groupsSize) {
    int happyGroups = 0;
    int* count = calloc(batchSize, sizeof(int));
    for (int i = 0; i < groupsSize; i++) {
        count[groups[i] % batchSize]++;
    }
    happyGroups += count[0];
    for (int i = 1; i < batchSize / 2; i++) {
        int min = count[i] < count[batchSize - i] ? count[i] : count[batchSize - i];
        happyGroups += min;
        count[i] -= min;
        count[batchSize - i] -= min;
    }
    if (batchSize % 2 == 0) {
        happyGroups += count[batchSize / 2] / 2;
        count[batchSize / 2] %= 2;
    }
    for (int i = 1; i <= batchSize / 2; i++) {
        int j = batchSize - i;
        while (count[i] > 0 && count[j] > 0) {
            happyGroups++;
            count[i]--;
            count[j]--;
        }
    }
    int min = count[1];
    for (int i = 2; i < batchSize; i++) {
        if (count[i] < min) {
            min = count[i];
        }
    }
    return happyGroups + min;
}