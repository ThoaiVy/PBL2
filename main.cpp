#include <cstdlib>
#include <stdlib.h>
#include "Sort.h"
#include "List.h"

int arr[1000000];

void make_random_arr(int arr[], int size){
	srand(time(0));
	for(int i = 0; i < size; i++) arr[i] = rand() % 10001;	
}

int main(){
	int lc;
	do{
		cout << "===============MENU===============" << endl;
		cout << "1. Cac thuat toan sap xep" << endl;
		cout << "2. Cac cau truc du lieu" << endl;
		cout << "Nhap lua chon : "; cin >> lc;
		switch(lc){
			case 1:{
				system("CLS");
				Sort Op1;
				int n;
				cout << "Nhap so luong phan tu cua mang: "; 
				cin >> n;
				int arr[n];
				make_random_arr(arr,n);
				Op1.Time_execution(arr,n);
				cout << endl;
				break;
			}
			case 2:{
				
				break;
			}	
		}
		system("pause");
			
	} while(lc);
	return 0;
}

