/**https://leetcode.com/problems/maximum-average-pass-ratio/ */
//There is a school that has classes of students and each class will be having a final exam. You are given a 2D integer array classes, where classes[i] = [passi, totali]. You know beforehand that in the ith class, there are totali total students, but only passi number of students will pass the exam.
//You are also given an integer extraStudents. There are another extraStudents brilliant students that are guaranteed to pass the exam of any class they are assigned to. You want to assign each of the extraStudents students to a class in a way that maximizes the average pass ratio across all the classes.
//The pass ratio of a class is equal to the number of students of the class that will pass the exam divided by the total number of students of the class. The average pass ratio is the sum of pass ratios of all the classes divided by the number of the classes.
//Return the maximum possible average pass ratio after assigning the extraStudents students. Answers within 10-5 of the actual answer will be accepted.
// 
//Example 1:
//Input: classes = [[1,2],[3,5],[2,2]], extraStudents = 2
//Output: 0.78333
//Explanation: You can assign the two extra students to the first class. The average pass ratio will be equal to (3/4 + 3/5 + 2/2) / 3 = 0.78333.
//Example 2:
//Input: classes = [[2,4],[3,9],[4,5],[2,10]], extraStudents = 4
//Output: 0.53485
// 
//Constraints:
//	1 <= classes.length <= 105
//	classes[i].length == 2
//	1 <= passi <= totali <= 105
//	1 <= extraStudents <= 105
double maxAverageRatio(int** classes, int classesSize, int* classesColSize, int extraStudents) {
    double result = 0;
    typedef struct {
        int pass;
        int total;
        double diff;
    } Class;
    Class* c = (Class*)malloc(sizeof(Class) * classesSize);
    for (int i = 0; i < classesSize; i++) {
        c[i].pass = classes[i][0];
        c[i].total = classes[i][1];
        c[i].diff = (double)(c[i].pass + 1) / (c[i].total + 1) - (double)c[i].pass / c[i].total;
    }
    int* heap = (int*)malloc(sizeof(int) * classesSize);
    int heapSize = 0;
    for (int i = 0; i < classesSize; i++) {
        heap[heapSize++] = i;
        int j = heapSize - 1;
        while (j > 0) {
            int k = (j - 1) / 2;
            if (c[heap[j]].diff < c[heap[k]].diff) {
                break;
            }
            int temp = heap[j];
            heap[j] = heap[k];
            heap[k] = temp;
            j = k;
        }
    }
    for (int i = 0; i < extraStudents; i++) {
        int j = heap[0];
        result += c[j].diff;
        c[j].pass++;
        c[j].total++;
        c[j].diff = (double)(c[j].pass + 1) / (c[j].total + 1) - (double)c[j].pass / c[j].total;
        int k = 0;
        while (2 * k + 1 < heapSize) {
            int l = 2 * k + 1;
            int r = 2 * k + 2;
            if (r < heapSize && c[heap[r]].diff > c[heap[l]].diff) {
                l = r;
            }
            if (c[heap[k]].diff > c[heap[l]].diff) {
                break;
            }
            int temp = heap[k];
            heap[k] = heap[l];
            heap[l] = temp;
            k = l;
        }
    }
    for (int i = 0; i < classesSize; i++) {
        result += (double)c[i].pass / c[i].total;
        }
        free(c);
        free(heap);
        return result / classesSize;    
}