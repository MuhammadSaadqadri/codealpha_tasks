#include<iostream>
#include<conio.h>
#include <sstream>
using namespace std;

void print_grid(int (*grid)[9]){
    for(int i = 0 ; i < 9 ; i++){
        cout << "\033[36m\t\t\t";
        for(int j = 0 ; j < 9 ; j++){
            cout << grid[i][j];
            cout << " ";
            if(j == 2 || j == 5) {
                cout << " | ";
            }
            if(i == 2 && j == 8 || i == 5 && j == 8){
                cout << "\n\t\t\t-------x--------x------\033[33m";
            }
        }
        cout << endl;
    }
}

bool check_empty(int rows, int col, int (*grid)[9], int num){
    for(int i = 0 ; i < 9 ; i++){
        if (grid[rows][i] == num){
            return false;
        }
    }

    for(int i = 0 ; i < 9 ; i++){
        if (grid[i][col] == num){
            return false;
        }
    }

    int startRow = rows - rows % 3;
    int startCol = col - col % 3;

    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < 3 ; j++){
            if(grid[i+startRow][j+startCol] == num){
                return false;
            }
        }
    }

    return true;
}

bool Sudoku_solved(int (*grid)[9]){
    int num, rows, col;
    bool empty = false;
    for(int i = 0 ; i < 9 ; i++){
        for(int j = 0 ; j < 9 ; j++){
            if(grid[i][j] == 0){
                rows = i;
                col = j;
                empty = true;
                break;
            }
        }
        if (empty) break;
    }

    if (!empty)
        return true;

    for(int num = 1 ; num <= 9 ; num++){
        if(check_empty(rows , col , grid, num)){
            grid[rows][col] = num;
            if (Sudoku_solved(grid)){
                return true;
            }
            grid[rows][col] = 0;
        }
    }
    return false;
}

void display(){
    cout << "\033[33m*************************************************************************\033[0m\n";
    cout << "\t\t\t\033[32mSuduko Solver Application \033[0m\n";
    cout << "\033[33m*************************************************************************\033[0m\n";
}

void choice (){
    display();
    cout <<"\033[33m*\033[0m";
    cout << "\033[36m\t\t\t1.Provided Suduko\033[0m";                   cout <<"\033[33m\t\t\t\t*\033[0m";
    cout <<"\033[33m\t\t\t\t\t\t\n*\033[0m";
    cout << "\033[36m\t\t\t2.Enter Suduko Manually\033[0m";  cout <<"\033[33m     \t\t\t*\033[0m\n";
    cout << "\033[33m*\033[0m" ;
    cout << "\033[36m\t\t\t3.Exit\t\t\t\t\t\t\033[0m";     cout << "\033[33m*\033[0m\n" ;
    cout << "\033[33m*************************************************************************\033[0m\n\n";
}

void inputstr(int (*grid)[9]){
        string input;
		int value,i=0,j=0;
			
 		cout << "\n\033[32mEnter 81 digits manually separated by space(0 at emplty place) .\033[33m"<<endl ;
            getline(cin,input);
            stringstream ss(input);
            while(ss >> value){
            		grid[i][j] = value;
            		j++;
            		if (j==9){
					j = 0; 
            		i++;
					}
				}
				if(j!=0 || i!=9){
					cout << "\n\031[32mIncomplete . You must enter 81 digits....\n\033[33m";
				
				}
}
int main(){
    system ("chcp 437");
    int ch;
    int i = 0, j = 0 ;
    int demo_grid[9][9] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };
    int grid[9][9];

    while(true){
        choice();
        cin >> ch;
        cin.ignore();
        system("cls");
        switch(ch){
            case 1:
                for (int i = 0; i < 9; i++) {
                    for (int j = 0; j < 9; j++) {
                        grid[i][j] = demo_grid[i][j];
                    }
                }
                break;
            case 2:
            	inputstr(grid);
            
                
                break;
            case 3:
                cout << "Exiting Program\t\n";
                return 0;

            default:
            	cout  << "Invalid"<< endl ;
                continue;
        }

        display();
        cout << "\033[31m Unsolved Suduko :\n\033[33m";
        print_grid(grid);

        if(Sudoku_solved(grid)){
            cout << "\n\033[32m Solved Suduko :\n\033[33m";
            print_grid(grid);
            cout << "Press Enter to move to Selection Screen\n";
            if ('\r' == getch())
                system("cls");
        }
        else
            cout << "\033[31mNo Solution for this.\033[33m"<< endl;
    }
    return 0;
}

