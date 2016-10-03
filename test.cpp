#include <iostream>
#include <stdio.h>
#include <cstring>
#include <cstdlib>
#include <cstddef>

using namespace std;

int main(){
  
  system("./portSetter.cc.o");
  system("./portSetter.cc.o -h");

  
  //Should return usage()
  system("././portSetter.cc.o --help");
  
  // Should say "listening on port 4040"
  system("././portSetter.cc.o -p 4040");
  system("././portSetter.cc.o --port 4040");
  
  // Should generte an error message/ print usage /  return 0
  system("././portSetter.cc.o help");
  system("././portSetter.cc.o --h");
  system("././portSetter.cc.o hs");
  system("././portSetter.cc.o -p --port 9");
  system("././portSetter.cc.o -p 77 33");
  system("././portSetter.cc.o -p -21");
  system("././portSetter.cc.o -p -21");
  system("././portSetter.cc.o -p 0");
  system("././portSetter.cc.o --port");
  system("././portSetter.cc.o -p 90642");
  system("././portSetter.cc.o -x 45321");
  system("././portSetter.cc.o help");
  system("././portSetter.cc.o help");
  
  return 0;
}
