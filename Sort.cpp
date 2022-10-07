#include <iomanip>
#include "Sort.h"

using namespace std;

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void Sort::Bubble_sort(int arr[], int size){
	for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

void Sort::Insertion_sort(int arr[], int size){
	int i, j, key;
    for (i = 1; i < size; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void Sort::Selection_sort(int arr[], int size){
	int i, j, minIndex;
    for (i = 0; i < size - 1; i++)
    {
        minIndex = i;
        for (j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            swap(&arr[i], &arr[minIndex]);
        }
    }
}

void merge(int arr[], int l, int m, int r){
        int sleft = m-l+1;
        int sright = r-m;
        int leftArr[sleft], rightArr[sright];
        for (int i = 0; i < sleft; i++) leftArr[i] = arr[l+i];
        for (int i = 0; i < sright; i++) rightArr[i] = arr[m+1+i];
        int iMerge = l, ileft = 0, iright = 0;
        while (ileft<sleft && iright < sright){
           if (leftArr[ileft] > rightArr[iright]){
               arr[iMerge] = rightArr[iright];
               iright++;
           }
           else{
               arr[iMerge] = leftArr[ileft];
               ileft++;
           }
           iMerge++;
        }
        while(ileft<sleft){
            arr[iMerge] = leftArr[ileft];
            ileft++;
            iMerge++;
        }
        while(iright<sright){
            arr[iMerge] = rightArr[iright];
            iright++;
            iMerge++;
        }
}
void Sort::Merge_sort(int arr[], int l, int r){
	if (l>=r) return;
        int m;
        m = l+(r-l)/2;
        Merge_sort(arr,l,m);
        Merge_sort(arr,m+1,r);
        merge(arr,l,m,r);
}

void heapify(int arr[], int n, int i){
    int i_max = i;
    int l = 2*i+1;
    int r = 2*i+2;
    if (l<n && arr[l]>arr[i_max]) i_max = l;
    if (r<n && arr[r]>arr[i_max]) i_max = r;
    if (i_max!=i){
        swap(arr[i],arr[i_max]);
        heapify(arr,n,i_max);
    }
}
void buildHeap(int arr[], int n){ 
    for (int i = n/2 - 1; i>=0; i--)
        heapify(arr,n,i);
}
void Sort::Heap_sort(int arr[], int size){
	buildHeap(arr,size);
    for (int i = size - 1; i > 0; i--){
        swap(arr[0],arr[i]);
        heapify(arr,i,0);    
    }
}

int partition(int arr[], int left, int right){
    int i = left - 1, pivot = arr[right];
    int j;
    for (j = left; j < right; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[right]);
    return (i + 1);
}
void Sort::Quick_sort(int arr[], int left, int right){
	if (left < right)
    {
        int index = partition(arr, left, right);
        Quick_sort(arr, left, index - 1);
        Quick_sort(arr, index + 1, right);
    }
}

void Sort::Shell_sort(int arr[], int size){
	int i, j, gap, key;
    for (gap = size / 2; gap > 0; gap /= 2)
    {
        for (i = gap; i < size; i++)
        {
            key = arr[i];
            for (j = i; j >= gap && arr[j - gap] > key; j -= gap)
            {
                arr[j] = arr[j - gap];
            }
            arr[j] = key;
        }
    }
}

void Print_table(double t[][8]){
	cout << left << setw(3) << "|" << left << setw(5) << "STT" << left << setw(3) << "|" << left << setw(28) << "Cac thuat toan sap xep" << left << setw(3) << "|" << left << setw(15) << "Do phuc tap" << left << setw(3) << "|" << left << setw(15) << "Thoi gian chay" << left << setw(3) << "|" << endl;
	for (int i = 1; i < 8; i++){
		if(t[2][i] == 1) cout << left << setw(3) << "|" << left << setw(5) << i << left << setw(3) << "|" << left << setw(28) << "Bubble sort" << left << setw(3) << "|" << left << setw(15) << "O(n^2)" << left << setw(3) << "|" << left << setw(15) << t[1][i] << left << setw(3) << "|" << endl;
		else if(t[2][i] == 2) cout << left << setw(3) << "|" << left << setw(5) << i << left << setw(3) << "|" << left << setw(28) << "Selection sort" << left << setw(3) << "|" << left << setw(15) << "O(n^2)" << left << setw(3) << "|" << left << setw(15) << t[1][i] << left << setw(3) << "|" << endl;
		else if(t[2][i] == 3) cout << left << setw(3) << "|" << left << setw(5) << i << left << setw(3) << "|" << left << setw(28) << "Insertion sort" << left << setw(3) << "|" << left << setw(15) << "O(n^2)" << left << setw(3) << "|" << left << setw(15) << t[1][i] << left << setw(3) << "|" << endl;
		else if(t[2][i] == 4) cout << left << setw(3) << "|" << left << setw(5) << i << left << setw(3) << "|" << left << setw(28) << "Merge sort" << left << setw(3) << "|" << left << setw(15) << "O(nlog(n))" << left << setw(3) << "|" << left << setw(15) << t[1][i] << left << setw(3) << "|" << endl;
		else if(t[2][i] == 5) cout << left << setw(3) << "|" << left << setw(5) << i << left << setw(3) << "|" << left << setw(28) << "Heap sort" << left << setw(3) << "|" << left << setw(15) << "O(nlog(n))" << left << setw(3) << "|" << left << setw(15) << t[1][i] << left << setw(3) << "|" << endl;
		else if(t[2][i] == 6) cout << left << setw(3) << "|" << left << setw(5) << i << left << setw(3) << "|" << left << setw(28) << "Quick sort" << left << setw(3) << "|" << left << setw(15) << "O(nlog(n))" << left << setw(3) << "|" << left << setw(15) << t[1][i] << left << setw(3) << "|" << endl;
		else if (t[2][i] == 7)cout << left << setw(3) << "|" << left << setw(5) << i << left << setw(3) << "|" << left << setw(28) << "Shell sort" << left << setw(3) << "|" << left << setw(15) << "O(nlog(n))" << left << setw(3) << "|" << left << setw(15) << t[1][i] << left << setw(3) << "|" << endl;
	}
}
void Arrange_time(double t[][8]){
	int i, j;
	double key1, key2;
    for (i = 2; i < 8; i++){
       	key1 = t[1][i];
        key2 = t[2][i];
        j = i - 1;
        while (j >= 1 && t[1][j] > key1){
            t[1][j + 1] = t[1][j];
            t[2][j + 1] = t[2][j];
            j--;
        }
        t[1][j + 1] = key1;
        t[2][j + 1] = key2;	
	}
}
void Sort::Time_execution(int arr[], int size){
	int tmp[size];
	clock_t start, end;
	double duration;
	
	for (int i = 0; i < size; i++) tmp[i] = arr[i];
	start = clock();
	Bubble_sort(tmp,size);
	end = clock();
	duration = (double)(end - start) / CLOCKS_PER_SEC * 1e9;
	time[1][1] = duration; time[2][1] = 1;

	for (int i = 0; i < size; i++) tmp[i] = arr[i];
	start = clock();
	Selection_sort(tmp,size);
	end = clock();
	duration = (double)(end - start) / CLOCKS_PER_SEC * 1e9;
	time[1][2] = duration; time[2][2] = 2;
	
	for (int i = 0; i < size; i++) tmp[i] = arr[i];
	start = clock();
	Insertion_sort(tmp,size);
	end = clock();
	duration = (double)(end - start) / CLOCKS_PER_SEC * 1e9;
	time[1][3] = duration; time[2][3] = 3;		

	for (int i = 0; i < size; i++) tmp[i] = arr[i];
	start = clock();
	Merge_sort(tmp,0,size-1);
	end = clock();
	duration = (double)(end - start) / CLOCKS_PER_SEC * 1e9;
	time[1][4] = duration; time[2][4] = 4;
	
	for (int i = 0; i < size; i++) tmp[i] = arr[i];
	start = clock();
	Heap_sort(tmp,size);
	end = clock();
	duration = (double)(end - start) / CLOCKS_PER_SEC * 1e9;
	time[1][5] = duration; time[2][5] = 5;
	
	for (int i = 0; i < size; i++) tmp[i] = arr[i];
	start = clock();
	Quick_sort(tmp,0,size-1);
	end = clock();
	duration = (double)(end - start) / CLOCKS_PER_SEC * 1e9;
	time[1][6] = duration; time[2][6] = 6;
	
	start = clock();
	Shell_sort(arr,size);
	end = clock();
	duration = (double)(end - start) / CLOCKS_PER_SEC * 1e9;
	time[1][7] = duration; time[2][7] = 7;
	
	Arrange_time(time);
	Print_table(time);
}
