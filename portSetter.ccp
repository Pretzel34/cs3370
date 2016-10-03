#include <iostream>
#include <stdio.h>
#include <string>
#include <SFML/Network.hpp>

using namespace std;

int main(){

	string answer;
	
	while (answer == "--help"|| "-p" || "--p" || "-P" || "--P" || "-h" || "--h" || "-H" || "--H"){
		
		return 0;
	}
	
	cout << "Please state port location: "\n<<endl;
	cin >> answer >> endl;
	
	if (answer != "-p" || "--p" || "-P" || "--P" || "-h" || "--h" || "-H" || "--H" ){
		
	}	
	
	else{ 
		
		cout << "Argument must begin with -. Please specify argument:" << endl;
		cin >> answer >> endl;
		
	}
	
}

char usage(char arg, char agr2){
	
	string reply;
	
	cin << reply << endl;
	
	if (arg )
	
}