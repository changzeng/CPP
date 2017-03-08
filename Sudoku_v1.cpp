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
	bool fillIn(int number,int position);
	bool isSafety(int number,int vertical,int horizontal);
	bool isInSquare(int number,int vertical,int horizontal);
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
	for(int i=1;i<=9;i++){
		for(int j=0;j<9;j++){
			fillIn(i,j);
		}
	}
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

bool Sudoku::fillIn(int number,int position){
	int vertical,horizontal;
	for(int i=0;i<9;i++){
		vertical = position/3 * 3 + i/3;
		horizontal = position%3 * 3 + i%3;

		if(isInSquare(number,vertical,horizontal))
			continue;

		if(isSafety(number,vertical,horizontal)){
			board[vertical][horizontal] = number;

			if(position == 8)
				return true;

			if(!fillIn(number,position+1))
				board[vertical][horizontal] = 0;
			else
				return true;
		}
	}

	return false;
}

bool Sudoku::isSafety(int number,int vertical,int horizontal){
	if(board[vertical][horizontal] != 0)
		return false;

	for(int i=0;i<width;i++)
		if(board[vertical][i] == number || board[i][horizontal] == number)
			return false;

	return true;
}