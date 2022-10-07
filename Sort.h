#include <iostream>
#include <time.h>
#include "List.h"
using namespace std;

class Sort{
	private:
		double time[3][8];
	public:
		void Bubble_sort(int*, int);
		void Selection_sort(int*, int);
		void Insertion_sort(int*, int);
		void Merge_sort(int*, int, int);
		void Heap_sort(int*, int);
		void Quick_sort(int*, int, int);
		void Shell_sort(int*, int);
		void Time_execution(int*, int);
		friend class List;
};