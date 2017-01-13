#include<cstdlib>
#include<time.h>
#include"HeaderColors.h"
#include"HeaderRead.h"
#include"HeaderCheck.h"
#include"HeaderAddElimine.h"
using namespace std;
#define MAX_LINII 9
#define MAX_COLOANE 9
struct fill_empty
{
	bool ok;
}matrix1[MAX_LINII][MAX_COLOANE];

void login();
void write(int matrix[MAX_LINII][MAX_COLOANE]);
void read_menu(int matrix[][MAX_COLOANE],int correct[][MAX_COLOANE],int spaceFree, int scor);
