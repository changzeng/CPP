#include<iostream>

using namespace std;

int binarySearchRecursive(int array[],int value,int left,int right);
int binarySearch(int array[],int value,int size);

int main(){
	int array[] = {0,1,2,3,4,5,6,7,8,9};

	cout<<binarySearch(array,9,10)<<endl;

	return 0;
}

int binarySearchRecursive(int array[],int value,int left,int right){
	if(right<left)
		return -1;

	int middle = (left+right)/2;

	if(value < array[middle])
		return binarySearchRecursive(array,value,left,middle-1);
	else if(value > array[middle])
		return binarySearchRecursive(array,value,middle+1,right);

	return middle;
}

int binarySearch(int array[],int value,int size){
	return binarySearchRecursive(array,value,0,size-1);
}