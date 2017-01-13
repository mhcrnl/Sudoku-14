#include<fstream>
#include<fstream>
#include<string>
#include<sys/stat.h>
#include<cstdlib>
#include<time.h>
#include<iostream>
#include <stdio.h>
#include <windows.h>
using namespace std;
#define MAX_LINII 9
#define MAX_COLOANE 9
struct fill_empty
{
	bool ok;
}matrix1[MAX_LINII][MAX_COLOANE];

void setColor(unsigned short color);
bool fileExists(const std::string& filename);
void login();
void write(int matrix[MAX_LINII][MAX_COLOANE]);
void addValue(int matrix[][MAX_COLOANE], int line, int column, int value, int &spaceFree);
void Elimin(int matrix[][MAX_COLOANE], int line, int column, int &spaceFree);
void readEasySudoku(int matrix[][MAX_COLOANE],int correct[][MAX_COLOANE]);
void readMediumSudoku(int matrix[][MAX_COLOANE],int correct[][MAX_COLOANE]);
void readHardSudoku(int matrix[][MAX_COLOANE],int correct[][MAX_COLOANE]);
void readSudoku(int matrix[][MAX_COLOANE],int correct[][MAX_COLOANE],int nivel);
void random (int matrix[][MAX_COLOANE],int spaceFree);
bool checkLine(int line, int value, int matrix[MAX_LINII][MAX_COLOANE]);
bool checkColumn(int column, int value, int matrix[MAX_LINII][MAX_COLOANE]);
bool checkSquare(int line, int column, int value, int matrix[MAX_LINII][MAX_COLOANE]);
bool valid(int line, int column, int value, int matrix[MAX_LINII][MAX_COLOANE]);
bool checkFinal(int matrix[MAX_LINII][MAX_COLOANE], int correct[MAX_LINII][MAX_COLOANE]);
void click_ADD (int number,int matrix[][MAX_COLOANE],int &spaceFree, int & verif , int &scor);
void click_ELIMINE (int number,int matrix[][MAX_COLOANE],int &spaceFree);
void solveSudoku(int matrix[][MAX_COLOANE], int correct[][MAX_COLOANE],int &spaceFree,int nivel ,int &scor);
void read_menu(int matrix[][MAX_COLOANE],int correct[][MAX_COLOANE],int spaceFree, int scor);
