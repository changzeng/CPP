#include<iostream>

using namespace std;

class Sudoku{
public:
	Sudoku();
	void solve();
	void display();
private:
	int board[9][9];
	int height;
	int width;
	int blank_counter;
	int safetyNumber(int vertical,int horizental);
	bool isComplete();
};

int main(){
	Sudoku sudoku;

	sudoku.display();

	cout<<endl<<endl;

	sudoku.solve();

	sudoku.display();
}

Sudoku::Sudoku(){
	height = 9;
	width = 9;
	blank_counter = height*width;

	int tmp[][9] = {{0,0,0,0,1,5,0,9,2},
					{9,0,0,0,0,0,0,8,0},
					{0,1,3,4,0,0,5,0,0},
					{0,0,0,3,0,0,8,4,6},
					{1,0,6,0,8,0,7,0,5},
					{3,8,7,0,0,4,0,0,0},
					{0,0,5,0,0,8,6,7,0},
					{0,9,0,0,0,0,0,0,8},
					{2,7,0,9,5,0,0,0,0}};


	int i,j;
	for(i=0;i<height;i++)
		for(j=0;j<width;j++)
			board[i][j] = tmp[i][j];

}

void Sudoku::solve(){
	int i,j,safety_number;
	while(!isComplete()){
		blank_counter = 0;
		for(i=0;i<height;i++){
			for(j=0;j<width;j++){
				safety_number = safetyNumber(i,j);
				if(safety_number == -1){
					if(board[i][j] == 0)
						blank_counter += 1;
					continue;
				}
				board[i][j] = safety_number;
			}
		}
		display();
	}
}

int Sudoku::safetyNumber(int vertical,int horizental){
	if(board[vertical][horizental] != 0)
		return -1;

	int number,i,safety_counter=0,safety_number=0;
	bool is_safety;
	for(number=1;number<=9;number++){
		is_safety = false;
		for(i=0;i<width;i++){
			if(board[vertical][i] == number || board[i][horizental] == number)
				break;
			if(i == 8)
				is_safety = true;
		}
		if(is_safety){
			safety_number = number;
			safety_counter += 1;
		}
	}

	if(safety_counter == 1)
		return safety_number;

	return -1;
}

bool Sudoku::isComplete(){
	return blank_counter == 0;
}

void Sudoku::display(){
	for(int i=0;i<height;i++){
		for(int j=0;j<width;j++)
			if(board[i][j] == 0)
				cout<<"  ";
			else
				cout<<board[i][j]<<" ";

		cout<<endl;
	}

	cout<<endl<<endl;
}