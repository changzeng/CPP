#include <iostream>

using namespace std;

int main(){
	int stu_count;
	int opt_count;

	cin >> stu_count;
	cin >> opt_count;

	int position[stu_count + 1];
	int queue[stu_count + 1];

	for(int i=1;i<=stu_count;i++){
		position[i] = i;
		queue[i] = i;
	}

	int stu,dis,tmp,j;

	for(int i=0;i<opt_count;i++){
		cin >> stu;
		cin >> dis;

		if(dis > 0){
			for(j=0;j<dis;j++){
				tmp = position[stu] + j;
				position[queue[tmp+1]] -= 1;
				queue[tmp] = queue[tmp+1];
			}
		}else if(dis < 0){
			for(j=0;j>dis;j--){
				tmp = position[stu] + j;
				position[queue[tmp-1]] += 1;
				queue[tmp] = queue[tmp-1];
			}
		}
		tmp = position[stu] + j;
		queue[tmp] = stu;
		position[stu] += dis;
	}

	for(int i=1;i<stu_count;i++)
		cout<<queue[i]<<" ";

	cout<<queue[stu_count]<<endl;

	return 0;
}