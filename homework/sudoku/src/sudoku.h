
#include <iostream>
#include <cstring>


class Sudoku {
private:
    int grid[9][9]{};

    bool _solve(int x, int y){
        bool result = false;
        if (grid[y][x] == 0){
           for (int i = 1; i < 10; i++){
               if (numWorks(x, y, i)){
                   grid[y][x] = i;
                   if (x + 1 == 9 && y + 1 == 9){
                       return true;
                   }else if ( x + 1 == 9){
                       result = _solve(0, y + 1);
                       if (result == false){
                           grid[y][x] = 0;
                       }else{
                           return result;
                       }
                   }else{
                       result = _solve(x + 1, y);
                       if (result == false){
                           grid[y][x] = 0;
                       }else{
                           return result;
                       }
                   }
               }
           }
           return result;
        }else{
            if (x + 1 == 9 && y + 1 == 9){
                return true;
            }else if (x + 1 > 8 && y < 8) return _solve(0, y + 1);
            else return _solve(x + 1, y);
        }
    }


    bool numWorks(int x, int y, int num){
        for (int i = 0; i < 9; i++){
            if (grid[y][i] == num || grid[i][x] == num) return false;
        }

        int xLoc = (x / 3) * 3;
        int yLoc = (y / 3) * 3;

        for (int i = 0; i <= 2; i++){
            for (int j = 0; j <= 2; j++){
                if (grid[yLoc + i][xLoc + j] == num) return false;
            }
        }
        return true;
    }

public:
    explicit Sudoku(int (*grid)[9]) {
        memcpy(this->grid, grid, 9 * 9 * sizeof(int));
    }

    bool operator ==(const int (*otherGrid)[9]) {
        for (int i=0; i<9*9; i++) {
            if (grid[i%3][i/3] != otherGrid[i%3][i/3]) {
                return false;
            }
        }
        return true;
    }

    bool operator ==(const Sudoku & other) {
        for (int i = 0; i < 81; i++){
            if (grid[i%3][i/3] != other.grid[i%3][i/3]){
                return false;
            }
        }
        return true;
    }

    int get(int i, int j) {
        if (i >= 0 && i < 9 && j >= 0 && j < 9) {
            return grid[i][j];
        }

        return -1;
    }

    int set(int i, int j, int val) {
        if (i >= 0 && i < 9 && j >= 0 && j < 9) {
            return grid[i][j] = val;
        }
        return -1;
    }

    void print() {
        for (int i=0; i<9; i++) {
            for (int j=0; j<9; j++) {
                std::cout << " [" << get(i, j) << "] ";
                //printf(" [%d] ", get(i, j));
                if (j == 8) {
                    printf("\n");
                    std::cout.flush();
                }
            }
        }
        printf("\n");

    }

    bool solve() {
        bool result = _solve(0, 0);
        return result;
    }
};
