#include<iostream>

using namespace std;

//
void heapify(int array[],int i,int length);
void bulidHeap(int array[],int length);
void heapSort(int array[],int length);

int main(){
	int a[] = {1,4,3,5,6,9,8,7};

	heapSort(a,8);

	for(int i=0;i<8;i++)
		cout<<a[i]<<endl;
}

void heapify(int array[],int i,int length){
	int left = 2*(i+1)-1;
	int right = 2*(i+1);
	int max;

	if(left >= 0 && left < length)
		if(array[i] < array[left])
			max = left;
		else
			max = i;
	else
		return;

	if(right >= 0 && right < length)
		if(array[max] < array[right])
			max = right;

	if(max != i){
		int tmp = array[i];
		array[i] = array[max];
		array[max] = tmp;

		heapify(array,max,length);
	}
}

void bulidHeap(int array[],int length){
	for(int i=(length-1)/2;i>=0;i--)
		heapify(array,i,length);
}

void heapSort(int array[],int length){
	bulidHeap(array,length);

	int tmp;
	for(int i=length-1;i>=1;i--){
		tmp = array[i];
		array[i] = array[0];
		array[0] = tmp;

		heapify(array,0,i);
	}
}