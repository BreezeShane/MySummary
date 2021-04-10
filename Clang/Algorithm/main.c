#include <stdio.h>
/*
 * 此工程用来记录至今为止我所学的算法内容，并将短期内保持更新！
 * todo: -1.Bubble Sort              √
 * todo: -2.Selection Sort           √
 * todo: 3.Insertion Sort           √
 * todo: 4.Merge Sort               √
 * todo: 5.Shell Sort               √
 * todo: 6.Heap Sort
 * todo: -7.Quick Sort              √
 * todo: 8.Bucket Sort
 * todo: 9.Counting Sort
 * todo: 10.Radix Sort
 */

enum { N = 10 };
int DATA[] = {5, 9, 7, 3, 6, 2, 8, 1, 0, 4};

void PRINT(void);
void BubbleSort(void);
void SelectionSort(void);
void InsertionSort(void);
void ShellSort(void);
void MergeSort(int, int);
void Merge(int, int, int);
void QuickSort(int, int);

int main() {
    QuickSort(0,N - 1);
    PRINT();
    return 0;
}

void PRINT(){
    for (int i = 0; i < N; ++i) {
        (!i) && (printf("%d",DATA[i]));
        i && (printf(" %d",DATA[i]));
    }
}

void BubbleSort(void){
    int temp;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N - i - 1; ++j) {
            if (DATA[j] > DATA[j + 1]) {
                temp = DATA[j];
                DATA[j] = DATA[j + 1];
                DATA[j + 1] = temp;
            }
        }
    }
    PRINT();
}

void SelectionSort(void){
    int min_index, temp;
    for (int i = 0; i < N - 1; ++i) {
        min_index = i;
        for (int j = i + 1; j < N; ++j) {
            if (DATA[j] < DATA[min_index])
                min_index = j;
        }
        temp = DATA[i];
        DATA[i] = DATA[min_index];
        DATA[min_index] = temp;
    }
    PRINT();
}

void InsertionSort(void){
    for (int i = 0; i < N; ++i) {
        int PreData = i - 1;
        int Current = DATA[i];
        while (PreData >= 0 && DATA[PreData] < Current){
            DATA[PreData + 1] = DATA[PreData];
            PreData--;
        }
        DATA[PreData + 1] = Current;
    }
    PRINT();
}

void ShellSort(void){
    int gape, current, i ,j;
    for (gape = N >> 1; gape > 0; gape >>= 1) {
        for (i = gape; i < N; ++i) {
            current = DATA[i];
            for (j = i - gape; j >= 0 && DATA[j] > current; j -= gape)
                DATA[j + gape] = DATA[j];
            DATA[j + gape] = current;
        }
    }
    PRINT();
}

void MergeSort(int left, int right){
    if (left >= right){
        return;
    } else{
        int middle = (left + right) / 2;
        MergeSort(left,middle);
        MergeSort(middle + 1, right);
        Merge(left, middle, right);
    }
}
void Merge(int left, int middle, int right){
    int New_DATA[N];
    int i = left, j = middle + 1, k = 0;
    while (i <= middle && j <= right){
        if (DATA[i] < DATA[j]){
            New_DATA[k] = DATA[i];
            i++;k++;
        } else{
            New_DATA[k] = DATA[j];
            j++;k++;
        }
    }
    while (i <= middle){
        New_DATA[k] = DATA[i];
        i++;k++;
    }
    while (j <= right){
        New_DATA[k] = DATA[j];
        j++;k++;
    }
    for (i = left,k = 0;i <= right; i++,k++)
        DATA[i] = New_DATA[k];
}

void QuickSort(int left, int right){
    if (left >= right)
        return;
    int i = left,j = right,temp,standard;
    while (i != j){
        standard = DATA[left];
        while (DATA[j] >= standard && i < j){
            j--;
        }
        while (DATA[i] <= standard && i < j){
            i++;
        }
        if (i < j){
            temp = DATA[i];
            DATA[i] = DATA[j];
            DATA[j] = temp;
        }
    }
    DATA[left] = DATA[i];
    DATA[i] = standard;
    QuickSort(left, i - 1);
    QuickSort(i + 1, right);
}