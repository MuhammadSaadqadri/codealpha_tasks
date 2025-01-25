#include<iostream>
#include<ctime>
#include<cstdlib>
#include<windows.h>

using namespace std;

void display(){
	cout << "\033[36m*********************************************************************************************\n\033[33m" ;
	cout << "\033[32m\t\t\t\tNumber Guessing Game\033[33m" << endl;
	cout << "\033[36m*********************************************************************************************\033[33m";
	cout << "\n\033[31m\t\t\t\tSome Rules :\n\n\033[33m" << "\033[33m1. You have 10 turns.\n2. You will get hints on each move.\n3. Screen will clear after 5 sec..\033[33m";
	cout << "\n\n\n\033[36m*********************************************************************************************\n\033[33m";
	}
void check_even(int num , int ans){
	
	if(num % ans == 0){
		cout << "Number is multiple of Input " ;
	}
	else if(ans % num == 0){
		cout << "Number is factor of Input " ;
	}
	else{
	
	string result= (num%2==0 && ans%2==1) ? "Number is Even ." : "Number is Odd.";
    cout << result;
	
	}

}

int main (){
	system("Color 02");
	int num ;
	int ans ;
	srand(time(0));
	num = rand() % 101;
	display();
	
	
	for (int i = 0 ; i < 10 ; i++){
	cout << "\nGuess the number within limit (0-100) :" <<endl;
	cin >> ans;
	
	
	if (ans<=0 || ans>=100 ){
		cout << "Enter between range (1-100) :" ;
		}
	
	else if (ans==num){
		cout << "Congrats the number is " <<num << endl;
		break; 
	}
	
	
	else if(ans<=num+10 && ans>=num-10 ){
		cout << "Hint : You are close! "  ;
		string result= (ans<num) ? "Try Higher ." : "Try Lower.";
        cout << result;
	}
	
	else if(num < ans){
		
			cout << "Hint : Too high !"  ;
			check_even(num ,ans);
			
	}
	else if(num > ans){
		
			cout << "Hint : Too low !"   ;
		    check_even(num ,ans);
	}
	Sleep(5000);
    system("cls");			
}	
}
