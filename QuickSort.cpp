#include<iostream>

using namespace std;

void quickSortRecursive(int array[],int left,int right);
void quickSort(int array[],int length);

int main(){
	int a[] = {3,1,4,2,9,5,6,8,7,0};
	quickSort(a,10);
	for(int i=0;i<10;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

void quickSortRecursive(int array[],int i,int j){
	if(i >= j)
		return ;

	int left = i,right = j;
	int flag = array[left];
	while(right > left){
		while(array[right]>=flag && right>left)
			right--;
		if(right <= left)
			break;
		array[left++] = array[right];
		while(array[left]<=flag && right>left)
			left++;
		if(right <= left)
			break;
		array[right--] = array[left];
	}
	array[left] = flag;
	
	quickSortRecursive(array,i,left-1);
	quickSortRecursive(array,right+1,j);
}

void quickSort(int array[],int length){
	quickSortRecursive(array,0,length-1);
}
