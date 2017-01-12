#include <iostream>
#include<fstream>
#include<cstdlib>
#include<time.h>
using namespace std;
void initializare (int sudoku[][9])
{
    for(int line = 0; line < 9; line++)
    {
        for(int column = 0; column < 9; column++)
        {
            sudoku[line][column]=0;
        }
    }
}
void display(int sudoku[9][9])
{
    ofstream g ("display.txt");
    g << "Pas nou"<<endl;
    g << endl;
	int line, column, margin;
	for (line = 0; line < 9; line++)
	{
		if (line % 3 == 0)
		{
		    if(line != 0 )
            {
                cout<<endl;
                g << endl;
            }
			for (margin = 0; margin < 25; margin++)
			{
				if (margin % 8 == 0)
				{
					cout << "+";
					g << "+";
				}
				else
				{
					cout << "-";
					g << "-";
				}

			}

		}
		cout << endl;
		g << endl;
		for (column = 0; column < 9; column++)
		{
            if (column %3 ==0)
            {
                cout << "|" << " ";
                g << "|" << " ";
            }
            cout << sudoku[line][column] << " ";
            g << sudoku[line][column] << " ";
		}
        cout<< "|";
        g<<"|";
	}
	cout<<endl;
	g << endl;
    for (margin = 0; margin < 25; margin++)
    {
        if (margin % 8 == 0)
        {
            cout << "+";
            g << "+";
            }
        else
        {
            cout << "-";
            g << "-";
        }

    }
    g << endl;


}
bool checkLine(int line, int val,int sudoku[9][9])
{
    for(int column = 0; column < 9; column++)
    {
        if(sudoku[line][column]==val)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

}
bool checkColumn (int column, int val,int sudoku[9][9])
{
    for(int line = 0; line < 9; line++)
    {
        if(sudoku[line][column]==val)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
}

bool checkSquare (int line, int column, int val,int sudoku[9][9])
{
    int column1 = column %3;
    int line1 = line %3;
    for(int index1 = line-line1; index1 < line-line1+3; index1++)
    {
        for(int index2 = column-column1; index2 < column-column1+3; index2++)
        {
            if(sudoku[index1][index2]==val)
            {
                return false;
            }
            else
            {
                return true;

            }
        }
    }
}
bool valid(int line,int column,int val,int sudoku[9][9])
{
    if(checkLine(line,val,sudoku) && checkColumn(column,val,sudoku) && checkSquare(line,column,val,sudoku))
    {
        return true;
    }
    else
    {
        return false;
    }
}
void random (int sudoku[][9], int number_poz)
{
    int line, column;
    int val,index=0;
    srand(time(NULL));
    while(index < number_poz)
    {

        line = rand()%9 + 1;
        column = rand()%9 + 1;
        val = rand()%9 + 1;
        cout<<line<<" ";
        cout<<column<<" ";
        cout<<val<<endl;
        if(valid(line,column,val,sudoku))
        {
            sudoku[line][column] = val;
            index++;
        }
    }

}
int main()
{
    int sudoku[9][9];
    int number_poz;
    initializare(sudoku);
    random(sudoku,80);
    display(sudoku);
    return 0;
}
