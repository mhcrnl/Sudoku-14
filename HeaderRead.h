#include<fstream>
#include<string>
#include<sys/stat.h>
using namespace std;
#define MAX_LINII 9
#define MAX_COLOANE 9
bool fileExists(const std::string& filename);
void readEasySudoku(int matrix[][MAX_COLOANE],int correct[][MAX_COLOANE]);
void readMediumSudoku(int matrix[][MAX_COLOANE],int correct[][MAX_COLOANE]);
void readHardSudoku(int matrix[][MAX_COLOANE],int correct[][MAX_COLOANE]);
void readSudoku(int matrix[][MAX_COLOANE],int correct[][MAX_COLOANE],int nivel);
