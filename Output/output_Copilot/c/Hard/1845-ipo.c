/**https://leetcode.com/problems/ipo/ */
//Suppose LeetCode will start its IPO soon. In order to sell a good price of its shares to Venture Capital, LeetCode would like to work on some projects to increase its capital before the IPO. Since it has limited resources, it can only finish at most k distinct projects before the IPO. Help LeetCode design the best way to maximize its total capital after finishing at most k distinct projects.
//You are given n projects where the ith project has a pure profit profits[i] and a minimum capital of capital[i] is needed to start it.
//Initially, you have w capital. When you finish a project, you will obtain its pure profit and the profit will be added to your total capital.
//Pick a list of at most k distinct projects from given projects to maximize your final capital, and return the final maximized capital.
//The answer is guaranteed to fit in a 32-bit signed integer.
// 
//Example 1:
//Input: k = 2, w = 0, profits = [1,2,3], capital = [0,1,1]
//Output: 4
//Explanation: Since your initial capital is 0, you can only start the project indexed 0.
//After finishing it you will obtain profit 1 and your capital becomes 1.
//With capital 1, you can either start the project indexed 1 or the project indexed 2.
//Since you can choose at most 2 projects, you need to finish the project indexed 2 to get the maximum capital.
//Therefore, output the final maximized capital, which is 0 + 1 + 3 = 4.
//Example 2:
//Input: k = 3, w = 0, profits = [1,2,3], capital = [0,1,2]
//Output: 6
// 
//Constraints:
//	1 <= k <= 105
//	0 <= w <= 109
//	n == profits.length
//	n == capital.length
//	1 <= n <= 105
//	0 <= profits[i] <= 104
//	0 <= capital[i] <= 109


        typedef struct {
            int profit;
            int capital;
        } Project;

        int compareCapital(const void* a, const void* b) {
            return ((Project*)a)->capital - ((Project*)b)->capital;
        }

        int compareProfit(const void* a, const void* b) {
            return *(int*)b - *(int*)a;
        }

        int findMaximizedCapital(int k, int w, int* profits, int profitsSize, int* capital, int capitalSize) {
            Project* projects = (Project*)malloc(profitsSize * sizeof(Project));
            for (int i = 0; i < profitsSize; i++) {
                projects[i].profit = profits[i];
                projects[i].capital = capital[i];
            }

            qsort(projects, profitsSize, sizeof(Project), compareCapital);

            int* maxHeap = (int*)malloc(profitsSize * sizeof(int));
            int heapSize = 0;
            int index = 0;

            for (int i = 0; i < k; i++) {
                while (index < profitsSize && projects[index].capital <= w) {
                    maxHeap[heapSize++] = projects[index].profit;
                    int j = heapSize - 1;
                    while (j > 0 && maxHeap[j] > maxHeap[(j - 1) / 2]) {
                        int temp = maxHeap[j];
                        maxHeap[j] = maxHeap[(j - 1) / 2];
                        maxHeap[(j - 1) / 2] = temp;
                        j = (j - 1) / 2;
                    }
                    index++;
                }

                if (heapSize == 0) {
                    break;
                }

                w += maxHeap[0];
                maxHeap[0] = maxHeap[--heapSize];
                int j = 0;
                while (true) {
                    int left = 2 * j + 1;
                    int right = 2 * j + 2;
                    int largest = j;

                    if (left < heapSize && maxHeap[left] > maxHeap[largest]) {
                        largest = left;
                    }
                    if (right < heapSize && maxHeap[right] > maxHeap[largest]) {
                        largest = right;
                    }
                    if (largest == j) {
                        break;
                    }

                    int temp = maxHeap[j];
                    maxHeap[j] = maxHeap[largest];
                    maxHeap[largest] = temp;
                    j = largest;
                }
            }

            free(projects);
            free(maxHeap);
            return w;
        }

            