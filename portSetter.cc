//Preston Hrubes
//CS3370
//09/07/2016
//portSetter exe

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <cstdlib>
#include <cstddef>
#include <vector>
#include <regex>
using namespace std;

//documented requirements
const int PORT_MAX = 65535;
const int PORT_MIN = 1;

enum {
	NO_LANG,
	DO_SOMETHING,
	TOO_MANY_PARAMETERS,
	INCORRECT_FLAG,
	HELP,
	ABOUT,
};

string en[] = {
	"No specified languge. Using English",
	"Listening on port: ",
	"Error. Correct arguments needed: ",
	"is an invalid argument for ",
	"Help Menu: \n'-p' or '--port' to call portsetter\n'-h' or '-help' for additional help",
	"Preston Hrubes""\nCS 3370, Section 003\nCO3r\nBelow is a  modified program for portSetter.",
};

string es[] = {
	"No hay idioma specifacado. Usando Espanol",
	"Escuchando sobre puerto: ",
	"Error. Nessasita argumentos correcto: ",
	"es un argumento incorrecto para ",
	"Optionas de ayuda: \n'-p' o '--port' para llamar portsetter\n'-h' o '-help' por mas instrucctiones",
	"Preston Hrubes""\nCS 3370, Section 003\nCO3r\nPor abjo esta una programa modifacado para portSetter.",
};

// defaults to english
//vector<string> msg;
string* msg = en; 

void msg_process() {
	cout << msg[NO_LANG] << endl;
	cout << msg[TOO_MANY_PARAMETERS] << endl;
	cout << msg[INCORRECT_FLAG] << endl;
	cout << "-----------" << endl;
}

//about()
void about(){
	
	cout <<msg[ABOUT] << endl;
	cout << "-----------" << endl;
}
//usage()
void usage(){
	
	cout << "Usage:" << endl;
	cout << msg[TOO_MANY_PARAMETERS] << endl;
	cout << msg[HELP]<< endl;
	cout << "-----------" << endl;
}

void setEnv(int port, char* varName) {
	char buffer[80] = "export ";
	strcat(buffer, varName);
	strcat(buffer, "=");
	
	string strPort = to_string(port);
	strcat(buffer, strPort.c_str());
	
	system(buffer);

}

int main(int argc, char *args[]){

	string envals[] = {"es", "es_MX","es_AR","es_UTC-8","en", "en_USA", "en_CA", "en_NZ", "en_FR" };
	//string englan[] = {"en", "en_USA", "en_CA", "en_NZ", "en_FR"};
	//look for first identied charachter "e" then "s" or "n"
	regex txt_regex("^e|s|n.");
	smatch base_match;
	
	//1. LANGUAGE
	//2. LC_ALL
	//3. LC_MESSAGES, (LC_TIME, ...)
	//4. LANG
	
	// char lan1 = system("printenv LANGUAGE");
	// char lan2 = system("printenv LC_ALL");
	// char lan3 = system("printenv LC_MESSAGES");
	// char lan4 = system("printenv LANG");
	
	
	// if(strcmp(lan1, "es")==0){
	// 	cout << "here" << endl;
	// }
	// for (const auto &enval : envals) {
	// 	if (regex_match(enval,lan1, txt_regex)) {
	// 		cout << "HERE" << endl;
	// 	}
	// }
	
	while(true){
		msg = es;
		break;
	}
	//get the locale value from env vars in this order
	//Usage of 

	char* arg_one;
	// char* arg_two;
	// char* arg_three;
	
	int inarg;
	
	if ((argc > 1) && (argc < 5)) {
		arg_one = args[1];
	}
	// else {
	// 	cout << "Error: Arguments Required" << endl;
	// 	return 1;
	// }
	
	if ((strcmp(arg_one, "-v")==0) || strcmp(arg_one, "-version")==0) {
		cout << " version: 1.1.3" << endl;
		return 1;
	}
	if (strcmp(arg_one, "-?")==0) {
		usage();
		return 1;
	}
	if (strcmp(arg_one, "-!")==0) {
		about();
		return 0;
	}
	if ((strcmp(arg_one, "-h") == 0) || (strcmp(arg_one, "--help") == 0)) { 
		usage();
		return 1;
	}
	
	if ((strcmp(arg_one, "-p") == 0) || (strcmp(arg_one, "--port") == 0)) {

		char sysCall[40] = "printenv ";
		char arg_three[40] = "MY_PORT";;

		if (argc > 3) {
			if (strcmp(args[2], "-e") == 0) {
			
				strcpy (arg_three, args[3]);
				strcat(sysCall, arg_three);
				
				system(sysCall);
				// cout << system(sysCall) << endl;
			}
		}
		else if ((argc > 2) && (strcmp(args[2], "-e") != 0)) {
			string arg_two = args[2];
			size_t sz;
		
			try {
				inarg = stoi(arg_two, &sz);
			}
			catch(...){
				cout << arg_two << msg[INCORRECT_FLAG]<< arg_one << endl;
				return 1;
			}
		}
		else {
			cout << msg[TOO_MANY_PARAMETERS] << endl;
			return 1;
		}
		
		if ((inarg > 0) && (inarg < PORT_MAX)) {
			setEnv(inarg, arg_three);
			cout << msg[DO_SOMETHING] << inarg << endl;
			
			return 0;
		}
		return 0;

	}
	usage();
	
	// msg = en;
	// msg_process();
	
	// msg = es;
	// msg_process();
	
 return 0;	
}
