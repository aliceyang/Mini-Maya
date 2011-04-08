#include "objLoader.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


/*CONSTRUCTORS*/

//Default constructor
objLoader::objLoader(){
	//nothing to see here
}

//Takes in a file in order to output a Mesh file
objLoader::objLoader(char *fn){
	filename = fn;
}

/*FUNCTIONS*/

//Reads through and parses the file
void objLoader::parse(){
	string line;
	ifstream myFile(filename);

	if(myFile.is_open()){
		while(!myFile.eof()){ //eof = end of file
			std::getline(myFile,line);
			if(line != ""){
				parseLine(line);
			}
		}
	}
}

//Parses a line in the file
void objLoader::parseLine(string line){
	//do something here



}



