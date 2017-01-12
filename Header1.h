#include<fstream>
#include<iostream>
#include<string>
#include <sys/stat.h>
using namespace std;
#define MAX_LImNII 9;
#define MAX_COLOANE 9;
struct fill_empty
{
	bool ok;
}matrixbool[MAX_LImNII][MAX_COLOANE];

void easySudoku(int matrix[MAX_LImNII][MAX_COLOANE]);
void login();
void input();
void read_menu();