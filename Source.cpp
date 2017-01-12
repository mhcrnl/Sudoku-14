#include"Header1.h";


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
void read_menu(int matrix[MAX_LINII][MAX_COLOANE])
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
			easySudoku(matrix);
		}
		else
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
						read_menu();
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
			read_menu();
		}
	}

}
void input()
{
	
	
}

int main()
{
	int matrix[MAX_LINII][MAX_COLOANE];
	read_menu(matrix);
	system("pause");
	return 0;
}