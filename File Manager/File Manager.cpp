#include <direct.h>
#include <iostream>
#include <cstring>  
#include <errno.h>
#include <dirent.h>
#include <fstream>
#include <windows.h>
 
using namespace std;

void dir_make(string full) {
    if (_mkdir(full.c_str()) == 0) {
        cout << "\033[32mDirectory created successfully\033[0m" << endl;
    } else {
        cerr << "\033[31mError creating directory: \033[0m" << strerror(errno) << endl;
    }
}

int list_dir(string path) {
    DIR *d = opendir(path.c_str());
    if (d == nullptr) {
        cerr << "\033[31mCould not open directory: \033[0m" << strerror(errno) << endl;
        return 1;
    }
    int n=1;
    struct dirent *entry;
    while ((entry = readdir(d)) != nullptr) {
    	if(n>=1 && n<=9){
    		cout << n <<".   [" << entry->d_name <<"]"<< endl;
		}
		else
        cout << n <<".  [" << entry->d_name <<"]"<< endl;
        n++;
    }

    closedir(d);
    return 0;
}

void createFiles(string path,string name){
	string File;
	File=path+"\\"+name;
	ofstream file(File.c_str());
	
	file << "Hello World";
	
	file.close();
	cout << "File created successfully\n";
}

void copy_files(string source , string destin){
	if(CopyFile(source.c_str(),destin.c_str(),TRUE)){
		cout << "File copied Successfully "<< endl;
	}
	else{
	
	cerr << "\033[31mFailed to copy file .\033[0m" << GetLastError() << endl;
	}
}
void move_files(string source , string destin){
	if(MoveFile(source.c_str(),destin.c_str())){
		cout << "File moved Successfully "<< endl;
	}
	else{
	
	cerr << "Failed to move file ." << GetLastError() << endl;
	}
}

void head(){
	cout <<"\033[36m*********************************************************************************************\033[0m"<<endl;
	cout <<"\033[33m\t\t\t\tFile Manager\033[0m" <<endl;
	cout <<"\033[36m*********************************************************************************************\033[0m"<<endl;
}
void display(){
	head();
	cout << "\033[32m\n\t\t\t\t1.Create Directory\n";
	cout << "\t\t\t\t2.Open Directory\n";
	cout << "\t\t\t\t3.Create Files\n";
	cout << "\t\t\t\t4.Copy File\n";
	cout << "\t\t\t\t5.Move File\n";
	cout << "\t\t\t\t6.Exit\n\033[0m\n\n";
    cout <<"\033[36m*********************************************************************************************\033[0m"<<endl;
	
}


int main() {
	system ("Color 02");
	int choice;
    string filename, path, full, source,destin;
    
    display();
    cin >> choice;
    while (choice!=6){
	
    switch(choice){
    	case 1:
    		system ("cls");
    		head();
    		cout << "\033[32mEnter directory name : \033[0m";
            cin >> filename;
            cout << "\033[32mEnter path: \033[0m";
            cin >> path;

    
           full = path + "\\" + filename;
           dir_make(full);
           system ("pause");
			system ("cls");
		   display();
		   cin >> choice;  
           break;
    		
    	case 2:
    		system ("cls");
    		head();
    		
    		cout << "\033[32mEnter path to list contents: \033[0m";
            cin.ignore();  
            getline(cin, path);  
            list_dir(path);
            system ("pause");
			system ("cls");
            display();
			cin >> choice;
    		break;
		case 3:
			system ("cls");
			head();
			cout << "\033[32mEnter Filename : " ;
			cin.ignore();
			getline(cin,filename);
			cout << "Enter Path :";
			getline(cin,path);
			createFiles(path,filename);
			system ("pause");
			system ("cls");
			display();
			cin >> choice;
			break;
		case 4:
			system ("cls");
			head();
			cout << "\033[32mEnter Source of file :";
			cin.ignore();
			getline(cin,source);
			
			cout << "\nEnter Destination of file :";
			getline(cin,destin);
			copy_files(source,destin);
			system ("pause");
			system ("cls");
			display();
			cin >> choice;
			
			break;
			
		case 5:
			system ("cls");
			head();
		    cout << "\033[32mEnter Source of file :";
		    cin.ignore();
			getline(cin,source);
			cout << "\nEnter Destination of file :";
			getline(cin,destin);
			move_files(source,destin);
			system ("pause");
			system ("cls");
			display();
			cin >> choice;
			break;	
	}
    
    
    }  

    return 0;
}

