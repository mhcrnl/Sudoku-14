
using namespace std;
#define MAX_LINII 9
#define MAX_COLOANE 9
bool checkLine(int line, int value, int matrix[MAX_LINII][MAX_COLOANE]);
bool checkColumn(int column, int value, int matrix[MAX_LINII][MAX_COLOANE]);
bool checkSquare(int line, int column, int value, int matrix[MAX_LINII][MAX_COLOANE]);
bool valid(int line, int column, int value, int matrix[MAX_LINII][MAX_COLOANE]);
bool checkFinal(int matrix[MAX_LINII][MAX_COLOANE], int correct[MAX_LINII][MAX_COLOANE]);
