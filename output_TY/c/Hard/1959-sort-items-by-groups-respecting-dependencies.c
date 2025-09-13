/**https://leetcode.com/problems/sort-items-by-groups-respecting-dependencies/ */
//There are n items each belonging to zero or one of m groups where group[i] is the group that the i-th item belongs to and it's equal to -1 if the i-th item belongs to no group. The items and the groups are zero indexed. A group can have no item belonging to it.
//Return a sorted list of the items such that:
//	The items that belong to the same group are next to each other in the sorted list.
//	There are some relations between these items where beforeItems[i] is a list containing all the items that should come before the i-th item in the sorted array (to the left of the i-th item).
//Return any solution if there is more than one solution and return an empty list if there is no solution.
// 
//Example 1:
//Input: n = 8, m = 2, group = [-1,-1,1,0,0,1,0,-1], beforeItems = [[],[6],[5],[6],[3,6],[],[],[]]
//Output: [6,3,4,1,5,2,0,7]
//Example 2:
//Input: n = 8, m = 2, group = [-1,-1,1,0,0,1,0,-1], beforeItems = [[],[6],[5],[6],[3],[],[4],[]]
//Output: []
//Explanation: This is the same as example 1 except that 4 needs to be before 6 in the sorted list.
// 
//Constraints:
//	1 <= m <= n <= 3 * 104
//	group.length == beforeItems.length == n
//	-1 <= group[i] <= m - 1
//	0 <= beforeItems[i].length <= n - 1
//	0 <= beforeItems[i][j] <= n - 1
//	i != beforeItems[i][j]
//	beforeItems[i] does not contain duplicates elements.
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortItems(int n, int m, int* group, int groupSize, int** beforeItems, int beforeItemsSize, int* beforeItemsColSize, int* returnSize){  
    int *res = (int *)malloc(sizeof(int) * n);
    *returnSize = 0;
    if (n == 0) {
        return res;
    }
    int *group_id = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        if (group[i] == -1) {
            group[i] = m++;
        }
        group_id[i] = group[i];
    }
    int *group_size = (int *)malloc(sizeof(int) * m);
    memset(group_size, 0, sizeof(int) * m);
    for (int i = 0; i < n; i++) {
        group_size[group_id[i]]++;
    }
    int *group_head = (int *)malloc(sizeof(int) * m);
    memset(group_head, -1, sizeof(int) * m);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            if (group_size[j] == 0 && group_head[i] == -1) {
                group_head[i] = j;
                break;
            }
        }
        if (group_head[i] == -1) {
            return NULL;
        }
   }
   int *group_tail = (int *)malloc(sizeof(int) * m);
   memset(group_tail, -1, sizeof(int) * m);
   for (int i = 0; i < m; i++) {
       for (int j = 0; j < m; j++) {
           if (group_size[j] > 0 && group_tail[i] == -1) {
               group_tail[i] = j;
               break;
           }
       }
       if (group_tail[i] == -1) {
           returnNULL;
       }
   }
   int *group_in = (int *)malloc(sizeof(int) * m);
   memset(group_in, 0, sizeof(int) * m);
   for (int i = 0; i < n; i++) {
       for (int j = 0; j < beforeItemsSize[i]; j++) {
           if (group_id[i] != group_id[beforeItems[i][j]]) {
               group_in[group_id[beforeItems[i][j]]]++;
           }
       }
   }
   int *group_out = (int *)malloc(sizeof(int) * m);
   memset(group_out, 0, sizeof(int) * m);
   for (int i = 0; i < m; i++) {
       group_out[i] = group_size[i] - 1;
   }
   while (1) {
      int flag = 0;
      for (int i = 0; i < m; i++) {
          if (group_head[i] != -1) {
              int head = group_head[i];
              for (int j = 0; j < m; j++) {
                  if (group_tail[j] != -1) {
                      int tail = group_tail[j];
                      if (group_in[tail] ==0 && group_out[head] > 0) {
                          group_out[head]--;
                      }
                  }
              }
          }
      }
   }
   return res;
}