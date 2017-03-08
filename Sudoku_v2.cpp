#include<iostream>

using namespace std;

//algorithm:
//if there has only one number which can be filled into a zero block
//then filled it in
//else check next zero block
//until all of zero block have been filled with a specific number

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
	int safetyNumber(int vertical,int horizontal);
	bool isComplete();
	bool isInSquare(int number,int vertical,int horizontal);
};

int main(){
	Sudoku sudoku;

	sudoku.display();

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

	// int tmp[][9] = {{5,0,9,0,0,0,2,0,7},
	// 				{0,8,0,2,0,0,0,3,0},
	// 				{3,0,0,0,0,0,0,0,8},
	// 				{0,0,0,1,0,5,0,8,0},
	// 				{0,0,0,0,0,0,0,0,0},
	// 				{0,1,0,3,0,2,0,0,0},
	// 				{6,0,0,0,0,0,0,0,5},
	// 				{0,5,0,0,0,3,0,1,0},
	// 				{7,0,2,0,0,0,8,0,9}};


	int i,j;
	for(i=0;i<height;i++)
		for(j=0;j<width;j++)
			board[i][j] = tmp[i][j];

}

void Sudoku::solve(){
	int i,j,safety_number;
	// int input;
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
		// display();
		// cin>>input;
	}
}

bool Sudoku::isInSquare(int number,int vertical,int horizontal){
	int postion = vertical/3 * 3 + horizontal/3;
	int x,y,x_s=postion/3*3,y_s=postion%3*3;
	for(int i=0;i<9;i++){
		x = x_s + i/3;
		y = y_s + i%3;
		if(board[x][y] == number)
			return true;
	}

	return false;
}

int Sudoku::safetyNumber(int vertical,int horizontal){
	if(board[vertical][horizontal] != 0)
			return -1;

	int number,i,safety_counter=0,safety_number=0;
	bool is_safety;
	for(number=1;number<=9;number++){
		is_safety = false;
		for(i=0;i<width;i++){
			if(board[vertical][i] == number || board[i][horizontal] == number || isInSquare(number,vertical,horizontal))
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

	cout<<endl;
}