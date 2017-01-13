//#include"Header.h";
#include<iostream>
#include<fstream>
#include<string>
#include<sys/stat.h>
using namespace std;
#define MAX_LINII 9
#define MAX_COLOANE 9
struct fill_empty
{
	bool ok;
}matrix1[MAX_LINII][MAX_COLOANE];

/*bool fileExists(const std::string& filename)
{
struct stat buf;
if (stat(filename.c_str(), &buf) != -1)
{
return true;
}
return false;
}

void login()
{
string numeUtilizator;
cout << "If you want to play sudoku , you have to login.Just write your name! Thank you !";
getline(cin, numeUtilizator);
if (!fileExists(numeUtilizator))
{
writefile<<'\n\<<numeUtilizator;
}
ofstream write(numeUtilizator.c_str());

}*/
void write(int matrix[MAX_LINII][MAX_COLOANE])
{
	ofstream write("WriteEasy.txt");
	write << "Pas nou" << endl;
	write << endl;
	for (int line = 0; line < 9; line++)
	{
		if (line % 3 == 0)
		{
			if (line != 0)
			{
				cout << endl;
				write << endl;
			}

			for (int margin = 0; margin < 25; margin++)
			{
				if (margin % 8 == 0)
				{
					cout << "+";
					write << "+";
				}
				else
				{
					cout << "-";
					write << "-";
				}
			}

		}
		cout << endl;
		write << endl;
		for (int column = 0; column < 9; column++)
		{
			if (column % 3 == 0)
			{
				cout << "|" << " ";
				write << "|" << " ";
			}
			cout << matrix[line][column] << " ";
			write << matrix[line][column] << " ";
		}
		cout << "|";
		write << "|";
	}
	cout << endl;
	write << endl;
	for (int margin = 0; margin < 25; margin++)
	{
		if (margin % 8 == 0)
		{
			cout << "+";
			write << "+";
		}
		else
		{
			cout << "-";
			write << "-";
		}

	}

}

void addValue(int matrix[][MAX_COLOANE], int line, int column, int value)
{

	if (matrix1[line][column].ok == false)
	{
		matrix[line][column] = value;
	}

}

void Elimin(int matrix[][MAX_COLOANE], int line, int column)
{
	if (matrix1[line][column].ok == false)
	{
		matrix[line][column] = 0;
	}
}


void readEasySudoku(int matrix[][MAX_COLOANE],int easy[][MAX_COLOANE])
{
	ifstream f1("Easy.txt");
	ifstream f1copy("Easycorrect.txt");
	for (int line = 0; line < 9; line++)
	{
		for (int column = 0; column < 9; column++)
		{
			f1 >> matrix[line][column];
			f1copy >> easy[line][column];
			if (matrix[line][column] == 0)
			{
				matrix1[line][column].ok = 0;
			}
			else
			{
				matrix1[line][column].ok = 1;
			}
		}
	}
	f1.close();
	f1copy.close();

}

bool checkLine(int line, int val, int sudoku[9][9])
{
	for (int column = 0; column < 9; column++)
	{
		if (sudoku[line][column] == val)
		{
			return false;
		}
	}
	return true;
}
bool checkColumn(int column, int val, int sudoku[9][9])
{
	for (int line = 0; line < 9; line++)
	{
		if (sudoku[line][column] == val)
		{
			return false;
		}
	}
	return true;
}

bool checkSquare(int line, int column, int val, int sudoku[9][9])
{
	int column1 = column % 3;
	int line1 = line % 3;
	for (int index1 = line - line1; index1 < line - line1 + 3; index1++)
	{
		for (int index2 = column - column1; index2 < column - column1 + 3; index2++)
		{
			if (sudoku[index1][index2] == val)
			{
				return false;
			}
		}
	}
	return true;
}
bool valid(int line, int column, int val, int sudoku[9][9])
{
	if (checkLine(line, val, sudoku) && checkColumn(column, val, sudoku) && checkSquare(line, column, val, sudoku))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool checkFinal(int matrix[MAX_LINII][MAX_COLOANE], int easy[MAX_LINII][MAX_COLOANE])
{
	for (int line = 0; line < 9; line++)
	{
		for (int column = 0; column < 9; column++)
		{
			if (matrix[line][column] == 0 || matrix[line][column] != easy[line][column])
				return false;
		}
	}
	return true;
}
void easySudoku(int matrix[][MAX_COLOANE], int easy[][MAX_COLOANE])
{
	readEasySudoku(matrix,easy);
	write(matrix);
	int number, line, column, value;
	while (!checkFinal)
	{
		int correct1 = 0;
		while (correct1 == 0)
		{
			cout << "Enter < 1 > ADD a value" << "< 2 > Elimine on value " << "< 3 > Replay " << "< 4 > HELP " << endl;
			cin >> number;
			if (number == 1)
			{
				int correct = 0;

				while (correct == 0)
				{
					cout << "Enter the values that you need in order : line , column and value for sudoku ";
					cin >> line >> column >> value;
					if (line >= 1 && line <= 9 && column >= 1 && column <= 9 && value >= 1 && value <= 9)
					{
						addValue(matrix, line, column, value);
						write(matrix);
						correct = 1;
					}
					else
					{
						cout << "Enter numbers from 1 to 9";
					}
				}

			}
			else
			{
				if (number == 2)
				{
					int correct = 0;

					while (correct == 0)
					{
						cout << "Enter the values that you need in order : line and column  ";
						cin >> line >> column;
						if (line >= 1 && line <= 9 && column >= 1 && column <= 9)
						{
							Elimin(matrix, line, column);
							write(matrix);
							correct = 1;
						}
						else
						{
							cout << "Enter numbers from 1 to 9";
						}
					}
				}
				else
				{
					if (number == 3)
					{
						readEasySudoku(matrix, easy);
					}
					else
					{
						if (number == 4)
						{
							cout << "You have to choose the number that doesn't exist on the same line , column or in the same square that you choose them.Try to choose the number which it showes the most of the time :) ! " << endl;
						}
						else
						{
							cout << "Enter the wrong number , please try again..." << endl;
							correct1 = 0;
						}
					}
				}
			}
			correct1 = 1;
		}

	}

}
void read_menu(int matrix[][MAX_COLOANE],int easy[][MAX_COLOANE])
{
	cout << "Enter < 1 > to begin the game" << endl << "< 2 > for more info..." << endl;
	int number;
	cin >> number;
	if (number == 1)
	{
		cout << "Enter < 1 > for easy sudoku" << endl << "< 2 > for medium sudoku " << endl << "< 3 > for hard sudoku" << endl << "< 4 > back to menu" << endl;
		int number;
		cin >> number;
		if (number == 1)
		{
			easySudoku(matrix,easy);
		}
		/*else
		{
			if (number == 2)
			{
				mediumSudoku(matrix);
			}
			else
			{
				if (number == 3)
				{
					hardSudoku(matrix);
				}
				else
				{
					if (number == 4)
					{
						read_menu(matrix);
					}
					else
					{
						cout << "You enter a wrong number , please try again...";
						read_menu(matrix);
					}
				}
			}
		}
	}
	else
	{
		if (number == 2)
		{
			cout << "Number puzzles appered in newspapers in the late 19th century, when French puzzl setters began experimenting with removing numbers from magic squares.It was not a Sudoku because it contained double-digit numbers and require aritmetic rather than logic to solve , but it shared key characteristics: each row, column and sub-square added up to the same number. " << endl;
			cout << "In this game you will choose square by Enter the number of row and space and the number of column . Then you will add a number from 1 to 9." << endl;
			read_menu(matrix);
		}
		else
		{
			cout << "You enter a wrog nmber, please try again...";
			read_menu(matrix);
		}*/
	}

}






int main()
{
	int matrix[MAX_LINII][MAX_COLOANE], easy[MAX_LINII][MAX_COLOANE];
	read_menu(matrix, easy);

	return 0;

}
