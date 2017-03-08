#include<iostream>

using namespace std;

//algorithm:
//if there has only one number which can be filled into a zero block
//then filled it in
//else check next zero block
//until none of the zero block which can be filled with a specific number
//then we recusively filled number untile get a solution

class Sudoku{
public:
	Sudoku();
	void solve();
	void display();
private:
	int board[9][9];
	int height;
	int width;
	int safetyNumber(int vertical,int horizontal);
	bool isInSquare(int number,int vertical,int horizontal);
	bool fillIn(int vertical,int horizontal);
	bool isSafety(int number,int vertical,int horizontal);
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

	//low level
	// int tmp[][9] = {{0,0,0,0,1,5,0,9,2},
	// 				{9,0,0,0,0,0,0,8,0},
	// 				{0,1,3,4,0,0,5,0,0},
	// 				{0,0,0,3,0,0,8,4,6},
	// 				{1,0,6,0,8,0,7,0,5},
	// 				{3,8,7,0,0,4,0,0,0},
	// 				{0,0,5,0,0,8,6,7,0},
	// 				{0,9,0,0,0,0,0,0,8},
	// 				{2,7,0,9,5,0,0,0,0}};

	//high level
	int tmp[][9] = {{5,0,9,0,0,0,2,0,7},
					{0,8,0,2,0,0,0,3,0},
					{3,0,0,0,0,0,0,0,8},
					{0,0,0,1,0,5,0,8,0},
					{0,0,0,0,0,0,0,0,0},
					{0,1,0,3,0,2,0,0,0},
					{6,0,0,0,0,0,0,0,5},
					{0,5,0,0,0,3,0,1,0},
					{7,0,2,0,0,0,8,0,9}};


	int i,j;
	for(i=0;i<height;i++)
		for(j=0;j<width;j++)
			board[i][j] = tmp[i][j];

}

bool Sudoku::fillIn(int vertical,int horizontal){
	while(board[vertical][horizontal] != 0){
		horizontal += 1;
		if(horizontal == width){
			vertical += 1;
			horizontal = 0;
		}

		if(vertical == height)
			return true;
	}

	for(int number=1;number<=9;number++){
		if(isSafety(number,vertical,horizontal))
			board[vertical][horizontal] = number;
		else
			continue;

		if(fillIn(vertical,horizontal))
			return true;
		else
			board[vertical][horizontal] = 0;
	}

	return false;
}

void Sudoku::solve(){
	int i,j,safety_number;
	bool is_complete = false;
	while(!is_complete){
		is_complete = true;
		for(i=0;i<height;i++){
			for(j=0;j<width;j++){
				safety_number = safetyNumber(i,j);
				if(safety_number == -1)
					continue;

				board[i][j] = safety_number;
				is_complete = false;
			}
		}
	}

	fillIn(0,0);
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

bool Sudoku::isSafety(int number,int vertical,int horizontal){
	if(isInSquare(number,vertical,horizontal))
		return false;

	for(int i=0;i<width;i++)
		if(board[vertical][i] == number || board[i][horizontal] == number)
			return false;

	return true;
}

int Sudoku::safetyNumber(int vertical,int horizontal){
	if(board[vertical][horizontal] != 0)
			return -1;

	int number,safety_counter=0,safety_number=0;

	for(number=1;number<=9;number++){
		if(isSafety(number,vertical,horizontal)){
			safety_counter += 1;
			safety_number = number;
		}
	}

	if(safety_counter == 1)
		return safety_number;

	return -1;
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