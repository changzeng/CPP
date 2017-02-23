#include<iostream>

using namespace std;

class PriorityQueue{
public:
	PriorityQueue(int length);
	~PriorityQueue();
	void insert(int value);
	int extractMax();
	void changeValue(int i,int value);
private:
	int *array;
	int size;
	int max_size;
	void floating(int i);
	void sinking(int i);
};

int main(){
	PriorityQueue queue = PriorityQueue(15);

	for(int i=0;i<15;i++)
		queue.insert(i+1);

	for(int i=0;i<15;i++)
		cout<<queue.extractMax()<<endl;
}

PriorityQueue::PriorityQueue(int length){
	array = new int[length+1];
	size = 0;
	max_size = length;
}

PriorityQueue::~PriorityQueue(){
	delete []array;
}

void PriorityQueue::insert(int value){
	if(size >= max_size)
		return ;

	array[++size] = value;

	floating(size);

}

int PriorityQueue::extractMax(){
	int tmp = array[1];

	if(size > 1){
		array[1] = array[size];
		size--;
		sinking(1);
	}

	return tmp;
}

void PriorityQueue::changeValue(int i,int value){
	int tmp = array[i];
	array[i] = value;
	if(value > tmp)
		floating(i);
	else if(value < tmp)
		sinking(i);
}

void PriorityQueue::floating(int i){
	int p = i/2,s=i,value=array[i];
	while(p>=1 && p<size && value>array[p])
		array[s] = array[p],s = p,p = p/2;
	array[s] = value;
}

void PriorityQueue::sinking(int i){
	int left = 2*i;
	int right = 2*i+1;
	int max;

	if(left>=1 && left<=size)
		if(array[left]>array[i])
			max = left;
		else
			max = i;
	else
		return ;

	if(right>=1 && right<=size)
		if(array[right] > array[max])
			max = right;

	if(max != i){
		int tmp = array[max];
		array[max] = array[i];
		array[i] = tmp;

		sinking(max);
	}
}