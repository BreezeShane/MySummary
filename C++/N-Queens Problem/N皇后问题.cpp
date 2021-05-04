#include <iostream>
#include <vector>

int side_length = 0;
int count = 0;

bool Check_True_Or_False(int i, int j, std::vector<std::vector<int>> Board);
void Print_the_Board(std::vector<std::vector<int>> Board);
void Queens(int j, std::vector<std::vector<int>> Board);

int main() {

    std::cout << "Input the side length of checkerboard: " << std::endl;
    std::cin >> side_length;
    std::vector<std::vector<int>> Board(side_length);
    for (int i = 0; i < side_length; ++i) {
        Board[i].resize(side_length);
        for (int j = 0; j < side_length; ++j) {
            Board[i][j] = 0;
        }
    }
    Queens(0, Board);
    std::cout << "共有"<< count << "种方案。" << std::endl;
    return 0;
}

bool Check_True_Or_False(int i, int j, std::vector<std::vector<int>> Board){
    int line, column;

    for (line = i, column = 0; column < side_length; ++column) {
        if (Board[line][column] == 1 && column != j){
            return false;
        }
    }

    for (line = 0, column = j; line < side_length; ++line) {
        if (Board[line][column] == 1 && line != i){
            return false;
        }
    }

    for (line = i + 1, column = j + 1; line < side_length && column < side_length; ++line, ++column) {
        if (Board[line][column] == 1){
            return false;
        }
    }

    for (line = i + 1, column = j - 1; line < side_length && column >= 0; ++line, --column) {
        if (Board[line][column] == 1){
            return false;
        }
    }

    for (line = i - 1, column = j - 1; line >= 0 && column >= 0; --line, --column) {
        if (Board[line][column] == 1){
            return false;
        }
    }

    for (line = i - 1, column = j + 1; line >= 0 && column < side_length; --line, ++column) {
        if (Board[line][column] == 1){
            return false;
        }
    }
    return true;
}

void Print_the_Board(std::vector<std::vector<int>> Board){
    for (int i = 0; i < side_length; ++i) {
        for (int j = 0; j < side_length; ++j) {
            std::cout << Board[i][j] << '\t';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void Queens(int j, std::vector<std::vector<int>> Board){
    if (j == side_length && j != 0){
        Print_the_Board(Board);
        ++count;
        return;
    }
    for (int i = 0; i < side_length; ++i) {
        if ( Check_True_Or_False(i,j,Board) ){
            Board[i][j] = 1;
            Queens(j+1, Board);
            Board[i][j] = 0;
        }
    }
}

