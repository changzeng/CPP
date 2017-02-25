#include<iostream>

using namespace std;

void quickSort(int array[],int left,int right);

int main(){
	int array[] = {3,6,1,9,0,2,4,7,5,8};
	
	quickSort(array,0,9);

	for(int i=0;i<10;i++)
		cout<<array[i]<<" ";
	cout<<endl;

	return 0;
}

void quickSort(int array[],int left,int right){
	int flag = array[(left+right)/2];
	int i=left,j=right;

	while(i<=j){
		while(array[i]<flag)
			i++;
		while(array[j]>flag)
			j--;
		if(i<=j){
			int tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			i++,j--;
		}
	}

	if(j>left)
		quickSort(array,left,j);
	if(i<right)
		quickSort(array,i,right);
}
