/**https://leetcode.com/problems/time-needed-to-inform-all-employees/ */
//A company has n employees with a unique ID for each employee from 0 to n - 1. The head of the company is the one with headID.
//Each employee has one direct manager given in the manager array where manager[i] is the direct manager of the i-th employee, manager[headID] = -1. Also, it is guaranteed that the subordination relationships have a tree structure.
//The head of the company wants to inform all the company employees of an urgent piece of news. He will inform his direct subordinates, and they will inform their subordinates, and so on until all employees know about the urgent news.
//The i-th employee needs informTime[i] minutes to inform all of his direct subordinates (i.e., After informTime[i] minutes, all his direct subordinates can start spreading the news).
//Return the number of minutes needed to inform all the employees about the urgent news.
// 
//Example 1:
//Input: n = 1, headID = 0, manager = [-1], informTime = [0]
//Output: 0
//Explanation: The head of the company is the only employee in the company.
//Example 2:
//Input: n = 6, headID = 2, manager = [2,2,-1,2,2,2], informTime = [0,0,1,0,0,0]
//Output: 1
//Explanation: The head of the company with id = 2 is the direct manager of all the employees in the company and needs 1 minute to inform them all.
//The tree structure of the employees in the company is shown.
// 
//Constraints:
//	1 <= n <= 105
//	0 <= headID < n
//	manager.length == n
//	0 <= manager[i] < n
//	manager[headID] == -1
//	informTime.length == n
//	0 <= informTime[i] <= 1000
//	informTime[i] == 0 if employee i has no subordinates.
//	It is guaranteed that all the employees can be informed.
int numOfMinutes(int n, int headID, int* manager, int managerSize, int* informTime, int informTimeSize){
    int i, j, k, l, m, n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, n12, n13, n14, n15, n16, n17, n18, n19, n20, n21, n22, n23, n24, n25, n26, n27, n28, n29, n30, n31,n32, n33, n34, n35, n36, n    = 0;
    int *arr = (int*)malloc(sizeof(int)*n);
    memset(arr, 0, sizeof(int)*n);
    int *arr1 = (int*)malloc(sizeof(int)*n);
    memset(arr1, 0, sizeof(int)*n);
    int *arr2 = (int*)malloc(sizeof(int)*n);
    memset(arr2, 0, sizeof(int)*n);
    for (i = 0; i < n; i++) {
        arr[i] = i;
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (manager[j] == i) {
                arr1[i]++;
            }
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (manager[j] == i) {
                arr2[i] += informTime[j];
            }
        }
    }
    for (i = 0; i < n; i++) {
        if (arr1[i] == 0) {
            n += arr2[i];
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (arr1[j] == 0) {
                continue;
            }
            for (k = 0; k < n; k++) {
                if (arr1[k] == 0) {
                    continue;
                }
                if (arr[j] == manager[k]) {
                    arr1[k]--;
                }
            }
        }
    }
    for (i = 0; i < n; i++) {
        if (arr1[i] == 0) {
            n += arr2[i];
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (arr1[j] == 0) {
                continue;
            }
            for (k = 0; k < n; k++) {
                if (arr1[k] == 0) {
                    continue;
                }
                if (arr[j] == manager[k]) {
                    arr1[k]--;
                }
            }
        }
    }
    for (i = 0; i < n; i++) {
        if (arr1[i] == 0) {
            n += arr2[i];
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (arr1[j] == 0) {
                continue;
            }
            for (k = 0; k < n; k++) {
                if (arr1[k] == 0) {
                    continue;
                }
                if (arr[j] == manager[k]) {
                    arr1[k]--;
                }
            }
        }
    }
    for (i = 0; i < n; i++) {
        if (arr1[i] == 0) {
            n += arr2[i];
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (arr1[j] == 0) {
                continue;
            }
            for (k = 0; k < n; k++) {
                if (arr1[k] == 0) {
                    continue;
                }
                if (arr[j] == manager[k]) {
                    arr1[k]--;
                }
            }
        }
    }
    for (i = 0; i < n; i++) {
        if (arr1[i] == 0) {
            n += arr2[i];
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (arr1[j] == 0) {
                continue;
            }
            for (k = 0; k < n; k++) {
                if (arr1[k] == 0) {
                    continue;
                }
                if (arr[j] == manager[k]) {

                    arr1[k]--;
                }
            }
        }
    }
    for (i = 0; i < n; i++) {
        if (arr1[i] == 0) {
            n += arr2[i];
        }
    }
    free(arr);
    free(arr1);
    free(arr2);
    return n;
}