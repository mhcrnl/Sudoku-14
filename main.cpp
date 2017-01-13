#include"Header.h";



void login()
{
    string numeUtilizator;
    cout << "If you want to play sudoku , you have to login.Just write your name! Thank you !";
    getline(cin, numeUtilizator);
    /*if (!fileExists(numeUtilizator))
    {
        writefile<<"\n\<<numeUtilizator";
    }*/
    ofstream write(numeUtilizator.c_str());

}

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
			if(matrix1[line][column].ok == 0)
            {
                setColor(1);
                cout << matrix[line][column] << " ";
                write << matrix[line][column] << " ";
                setColor(7);
            }
            else
            {
                cout << matrix[line][column] << " ";
                write << matrix[line][column] << " ";
            }
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
    cout << endl;
}

void addValue(int matrix[][MAX_COLOANE], int line, int column, int value, int &spaceFree)
{

	if (matrix1[line][column].ok == false && matrix[line][column] == 0)
	{
		matrix[line][column] = value;
		spaceFree--;
	}

}

void Elimin(int matrix[][MAX_COLOANE], int line, int column, int &spaceFree)
{
	if (matrix1[line][column].ok == false && matrix[line][column] != 0)
	{
		matrix[line][column] = 0;
		spaceFree++;
	}
	else
    {
        cout << "You choose the wrong celule" << endl;
    }
}



void random (int matrix[][MAX_COLOANE],int spaceFree)
{
    int line, column, index = 0;
    srand(time(NULL));
    while(index < spaceFree)
    {

        line = rand()%9;
        column = rand()%9;
        if(matrix[line][column] != 0)
        {
            matrix[line][column] = 0;
            matrix1[line][column].ok = 0;
            index++;
        }
    }

}

bool checkLine(int line, int value, int matrix[MAX_LINII][MAX_COLOANE])
{
	for (int column = 0; column < 9; column++)
	{
		if (matrix[line][column] == value)
		{
			return false;
		}
	}
	return true;
}
bool checkColumn(int column, int value, int matrix[MAX_LINII][MAX_COLOANE])
{
	for (int line = 0; line < 9; line++)
	{
		if (matrix[line][column] == value)
		{
			return false;
		}
	}
	return true;
}

bool checkSquare(int line, int column, int value, int matrix[MAX_LINII][MAX_COLOANE])
{
	int column1 = column % 3;
	int line1 = line % 3;
	for (int index1 = line - line1; index1 < line - line1 + 3; index1++)
	{
		for (int index2 = column - column1; index2 < column - column1 + 3; index2++)
		{
			if (matrix[index1][index2] == value)
			{
				return false;
			}
		}
	}
	return true;
}
bool valid(int line, int column, int value, int matrix[MAX_LINII][MAX_COLOANE])
{
	if (checkLine(line, value, matrix) && checkColumn(column, value, matrix) && checkSquare(line, column, value, matrix))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool checkFinal(int matrix[MAX_LINII][MAX_COLOANE], int correct[MAX_LINII][MAX_COLOANE])
{
	for (int line = 0; line < 9; line++)
	{
		for (int column = 0; column < 9; column++)
		{
			if (matrix[line][column] == 0 || matrix[line][column] != correct[line][column])
				return false;
		}
	}
	return true;
}
void click_ADD (int number,int matrix[][MAX_COLOANE],int &spaceFree, int & verif , int &scor)
{
    int line, column, value, number1;
    int correct = 0;
    while (correct == 0 &&  spaceFree > 0)
    {
        cout << "Enter the values that you need in order : line , column and value for sudoku " << endl;
        cin >> line >> column >> value;
        if (line >= 1 && line <= 9 && column >= 1 && column <= 9 && value >= 1 && value <= 9)
        {
            cout << "You have " << spaceFree << " more free space " << endl;
            cout << "If you want to check if you number is good for sudoku , enter < 1 > , You have " << verif <<" check ! else enter < 2 > continue." << endl;
            cin >> number1;
            if(number1 == 1)
            {
                if( verif > 0)
                {
                    verif--;
                    if(valid(line-1,column-1,value,matrix))
                    {
                        setColor(5);
                        cout <<"GOOD JOB" << endl;
                        setColor(7);
                    }
                    else
                    {
                        setColor(4);
                        cout<<"NO, the number is not correct. You have to elimine the number put in sudoku :D" << endl;
                        setColor(7);
                    }
                }
                else
                {
                    setColor(5);
                    cout << "Sorry , you can not use check because you had 3 checks ." << endl;
                    setColor(7);
                }
                scor = scor - 5;
            }
            addValue(matrix, line-1, column-1, value,spaceFree);
            write(matrix);
            correct = 1;
          }
          else
          {
              setColor(4);
              cout << "Enter numbers from 1 to 9";
              setColor(7);
          }
    }
}
void click_ELIMINE (int number,int matrix[][MAX_COLOANE],int &spaceFree)
{
    int line, column;
    int correct = 0;

    while (correct == 0)
    {
        cout << "Enter the values that you need in order : line and column  ";
        cin >> line >> column;
        if (line >= 1 && line <= 9 && column >= 1 && column <= 9)
        {
            Elimin(matrix, line-1, column-1,spaceFree);
            write(matrix);
            correct = 1;
        }
        else
        {
            setColor(4);
            cout << "Enter numbers from 1 to 9";
            setColor(7);
        }
    }
}
void solveSudoku(int matrix[][MAX_COLOANE], int correct[][MAX_COLOANE],int &spaceFree,int nivel ,int &scor)
{
    int index = 1;
	solveSudoku:
	    readSudoku(matrix,correct,nivel);
        write(matrix);
        random(matrix,spaceFree+index);
        index++;
        write(matrix);
        int number, number1 , line, column, value, verif = 3;
        while (!checkFinal(matrix,correct))
        {
         _begin:cout << "Enter < 1 > ADD a value" << "< 2 > Elimine on value " << "< 3 > Replay " << "< 4 > HELP " << endl;
                cin >> number;
                if (number == 1)
                {
                    click_ADD(number,matrix,spaceFree,verif,scor);
                }
                else
                {
                    if (number == 2)
                    {
                        click_ELIMINE(number,matrix,spaceFree);
                        scor--;
                    }
                    else
                    {
                        if (number == 3)
                        {
                            readSudoku(matrix,correct,nivel);
                            write(matrix);
                            scor = 415;

                        }
                        else
                        {
                            if (number == 4)
                            {
                                setColor(6);
                                cout << "You have to choose the number that doesn't exist on the same line , column or in the same square that you choose them.Try to choose the number which it showes the most of the time :) ! " << endl;
                                setColor(7);

                            }
                            else
                            {
                                setColor(4);
                                cout << "Enter the wrong number , please try again..." << endl;
                                setColor(7);
                                goto _begin;
                            }
                        }
                    }
                }

        }
        setColor(5);
        cout << "Congration!" << endl;
        if(scor > 0)
        {
            cout << "You have " << scor <<"points :)" << endl;
        }
        setColor(7);
        cout << "If you want to play more , enter < 1 >";
        int number2;
        cin >> number2;
        if(number2 == 1)
        {
            goto solveSudoku;
        }
}
void read_menu(int matrix[][MAX_COLOANE],int correct[][MAX_COLOANE],int spaceFree, int scor)
{
    read_menu:
        scor = 415;
        cout<<"            SUDOKU"<<endl;
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
                spaceFree = 17;
                solveSudoku(matrix,correct,spaceFree,1,scor);
            }
            else
            {
                if (number == 2)
                {
                    spaceFree = 32;
                    solveSudoku(matrix,correct,spaceFree,2,scor);
                }
                else
                {
                    if (number == 3)
                    {
                        spaceFree = 50;
                        solveSudoku(matrix,correct,spaceFree,3,scor);
                    }
                    else
                    {
                        if (number == 4)
                        {
                            goto read_menu;
                        }
                        else
                        {
                            setColor(4);
                            cout << "You enter a wrong number , please try again..." << endl;
                            setColor(7);
                            goto read_menu;
                        }
                    }
                }
            }
        }
        else
        {
            if (number == 2)
            {
                setColor(3);
                cout << "Number puzzles appered in newspapers in the late 19th century," << endl;
                cout << "when French puzzl setters began experimenting with removing numbers from magic squares.It was not a Sudoku because it contained double-digit numbers and require aritmetic" << endl;
                cout << "rather than logic to solve , but it shared key characteristics: each row, column and sub-square added up to the same number. " << endl;
                cout << "In this game you will choose square by Enter the number of row and space and the number of column . Then you will add a number from 1 to 9." << endl;
                setColor(7);
                goto read_menu;
            }
            else
            {
                setColor(4);
                cout << "You enter a wrog nmber, please try again..." << endl;
                setColor(7);
                goto read_menu;
            }
        }
}
int main()
{
	int matrix[MAX_LINII][MAX_COLOANE], correct[MAX_LINII][MAX_COLOANE];
	int spaceFree,scor;
	login();
	read_menu(matrix, correct,spaceFree,scor);

	return 0;

}
