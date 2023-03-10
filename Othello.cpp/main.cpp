#include <iostream>

int board[10][10] = {};//多次元配列のとき[][]で括る
bool Player = true;


//盤面の制作
void MakeBoard()
{
	//番兵配置
	for (int i = 0; i < 10; i++)
	{
		board[i][0] = 4;
		board[i][9] = 6;
		board[9][i] = 6;
		board[0][i] = 5;	
	}

	//最初の四つ
	board[4][4] = -1;
	board[4][5] = 1;
	board[5][4] = 1;
	board[5][5] = -1;

	//角
	board[0][0] = 6;
	board[0][9] = 6;
	board[9][0] = 6;
	board[9][9] = 6;

}

//盤面表示
//0:何もない 1:黒 -1:白
void SpawnBoard()//盤面をすべて見て、0,1,2,3を記号として表示する
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			switch(board[i][j])
			{
				case 0:
					//std::cout << "-";//何もない
					std::cout << "ー";
					break;
				case 1:
					std::cout << "○";//黒
					break;
				case -1:
					std::cout << "●";//白
					break;
				case 4:
					//std::cout << i;
					printf("%d ", i);
					break;
				case 5:
					//std::cout << j;
					printf("%d ", j);
					break;
				case 6:
					std::cout << "□";
					break;
				default:
					break;
			}
		}
		std::cout << std::endl;
	}
}

void change(int i, int j)
{
	if (Player == true)
	{
		board[i][j] = 1;
		std::cout << std::endl;
	}
	else
	{
		board[i][j] = -1;
		std::cout << std::endl;
	}
}

//方向, ひっくり返す
int PlusDirection(int i, int j, int checki, int checkj, int player)
{
	if (board[i + checki][j] == player)
	{
		for (; checki < 10 - i; checki++)//下
		{
			if (board[i + checki][j] == player)
			{
				continue;
			}
			else if (board[i + checki][j] == player * -1)
			{
				break;
			}
			else
			{
				return 0;
			}
		}
		 return checki;
	}
	else if(board[i][j + checkj] == player)
	{
		for (; checkj < 10 - j; checkj++)//右
		{
			if (board[i][j + checkj] == player)
			{
				continue;
			}
			else if (board[i][j + checkj] == player * -1)
			{
				break;
			}
			else
			{
				return 0;
			}
		}
		return checkj;
	}
	else
	{
		return 0;
	}
	return 0;
}

int MinusDirection(int i, int j, int checki, int checkj, int player)
{
	if (board[i - checki][j] == player)
	{
		for (; checki < i + 1; checki++)//上
		{
			if (board[i - checki][j] == player)
			{
				continue;
			}
			else if (board[i - checki][j] == player * -1)
			{
				break;
			}
			else
			{
				return 0;
			}
		}
		return checki;
	}
	else if (board[i][j - checkj] == player)
	{
		for (; checkj < j + 1; checkj++)//左
		{
			if (board[i][j - checkj] == player)
			{
				continue;
			}
			else if (board[i][j - checkj] == player * -1)
			{
				break;
			}
		else
			{
				return 0;
			}
		}
		return checkj;
	}
	else
	{
		return 0;
	}
	return 0;
}

int ObliqueDirection1(int i, int j, int checki, int checkj, int player)
{
	if (board[i + checki][j + checkj] == player)//右下[+][+]
	{
		if (j <= i)//下
		{
			int a = 1;
			for (; a < 10 - i; a++)
			{
				if (board[i + a][j + a] == player)
				{
					continue;
				}
				else if (board[i + a][j + a] == player * -1)
				{
					break;
				}
				else
				{
					return 0;
				}
			}return a;
		}
		else if (j >= i + 1)//右
		{
			int a = 1;
			for (; a < 10 - j; a++)
			{
				if (board[i + a][j + a] == player)
				{
					continue;
				}
				else if (board[i + a][j + a] == player * -1)
				{
					break;
				}
				else
				{
					return 0;
				}
			}return a;
		}
	}return 0;
}

int ObliqueDirection2(int i, int j, int checki, int checkj, int player)
{
	if (board[i - checki][j - checkj] == player)//左上[-][-]
	{
		if (j <= i)//左
		{
			int a = 1;
			for (; a < j + 1; a++)
			{
				if (board[i - a][j - a] == player)
				{
					continue;
				}
				else if (board[i - a][j - a] == player * -1)
				{
					break;
				}
				else
				{
					return 0;
				}
			}return a;
		}
		else if (j >= i + 1)//上
		{
			int a = 1;
			for (; a < i + 1; a++)
			{
				if (board[i - a][j - a] == player)
				{
					continue;
				}
				else if (board[i - a][j - a] == player * -1)
				{
					break;
				}
				else
				{
					return 0;
				}
			}return a;
		}
	}return 0;
}

int ObliqueDirection3(int i, int j, int checki, int checkj, int player)
{
	if (board[i + checki][j - checkj] == player)//左下[+][-]
	{
		if (i + j <= 8)//左
		{
			int a = 1;
			for (; a < j + 1; a++)
			{
				if (board[i + a][j - a] == player)
				{
					continue;
				}
				else if (board[i + a][j - a] == player * -1)
				{
					break;
				}
				else
				{
					return 0;
				}
			}return a;
		}
		else if (i + j >= 9)//下
		{
			int a = 1;
			for (; a < 10 - i; a++)
			{
				if (board[i + a][j - a] == player)
				{
					continue;
				}
				else if (board[i + a][j - a] == player * -1)
				{
					break;
				}
				else
				{
					return 0;
				}
			}return a;
		}
	}return 0;
}

int ObliqueDirection4(int i, int j, int checki, int checkj, int player)
{
	if (board[i - checki][j + checkj] == player)//右上[-][+]
	{
		if (i + j <= 8)//上
		{
			int a = 1;
			for (; a < i + 1; a++)
			{
				if (board[i - a][j + a] == player)
				{
					continue;
				}
				else if (board[i - a][j + a] == player * -1)
				{
					break;
				}
				else
				{
					return 0;
				}
			}return a;
		}
		else if (i + j >= 9)//右
		{
			int a = 1;
			for (; a < 10 - j; a++)
			{
				if (board[i - a][j + a] == player)
				{
					continue;
				}
				else if (board[i - a][j + a] == player * -1)
				{
					break;
				}
				else
				{
					return 0;
				}
			}return a;
		}
	}return 0;
}

void Reverse(int i, int j, int player)
{
	int reverse1 = PlusDirection(i, j, 1, 0, player);//下
	for (int a = 1; a < reverse1; a++)
	{
		board[i + a][j] = player * -1;
	}
	int reverse2 = PlusDirection(i, j, 0, 1, player);//右
	for (int a = 1; a < reverse2; a++)
	{
		board[i][j + a] = player * -1;
	}
	int reverse3 = MinusDirection(i, j, 1, 0, player);//上
	for (int a = 1; a < reverse3; a++)
	{
		board[i - a][j] = player * -1;
	}
	int reverse4 = MinusDirection(i, j, 0, 1, player);//左
	for (int a = 1; a < reverse4; a++)
	{
		board[i][j - a] = player * -1;
	}
	int reverse5 = ObliqueDirection1(i, j, 1, 1, player);//右下
	for (int a = 1; a < reverse5; a++)
	{
		board[i + a][j + a] = player * -1;
	}
	int reverse6 = ObliqueDirection2(i, j, 1, 1, player);//左上
	for (int a = 1; a < reverse6; a++)
	{
		board[i - a][j - a] = player * -1;
	}
	int reverse7 = ObliqueDirection3(i, j, 1, 1, player);//左下
	for (int a = 1; a < reverse7; a++)
	{
		board[i + a][j - a] = player * -1;
	}
	int reverse8 = ObliqueDirection4(i, j, 1, 1, player);//右上
	for (int a = 1; a < reverse8; a++)
	{
		board[i - a][j + a] = player * -1;
	}
}

//置けるかどうか
bool Check1(int i, int j, int player)
{
	int Down = PlusDirection(i, j, 1, 0, player);
	int Right = PlusDirection(i, j, 0, 1, player);
	int Up = MinusDirection(i, j, 1, 0, player);
	int Left = MinusDirection(i, j, 0, 1, player);
	int LowerRight = ObliqueDirection1(i, j, 1, 1, player);
	int UpperLeft = ObliqueDirection2(i, j, 1, 1, player);
	int LowerLeft = ObliqueDirection3(i, j, 1, 1, player);
	int UpperRight = ObliqueDirection4(i, j, 1, 1, player);

	if (board[i][j] == 0)
	{
		if (Down != 0 || Right != 0 || Up != 0 || Left != 0 ||
			LowerRight != 0 || UpperLeft != 0 || LowerLeft != 0 || UpperRight != 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

//board[1 ~ 8][1 ~ 8]までCheck1
bool Check2(int player)
{
	for (int a = 1; a <= 8; a++)
	{
		for(int b = 1; b <= 8; b++)
			if (board[a][b] == 0)
			{
				if (Check1(a, b, player))
				{
					return true;
				}
			}
			else
			{
				continue;
			}
	}
	return false;
}

//白と黒でそれぞれ置ける場所があるか
bool Finish()
{
	if (Check2(1) || Check2(-1))
	{
		return true;
	}
	else
	{
		return false;
	}
}

//駒の数を数える
void Count()
{
	int countB = 0;
	int countW = 0;
	for (int i = 1; i <= 8; i++)
	{
		for (int j = 1; j <= 8; j++)
		{
			if (board[i][j] == 1)
			{
				countB += 1;
				continue;
			}
			else if (board[i][j] == -1)
			{
				countW += 1;
				continue;
			}
			else
			{
				continue;
			}
		}
	}
	std::cout << "黒:" << countB << " / 白:" << countW << std::endl;
	if (countB < countW && !Finish())
	{
		std::cout << "白の勝ち" << std::endl;
	}
	else if (countB > countW && !Finish())
	{
		std::cout << "黒の勝ち" << std::endl;
	}
	else if (countB == countW && !Finish())
	{
		std::cout << "引き分け" << std::endl;
	}
}


int main() 
{
	std::cout << "◯黒のターンです◯" << std::endl << std::endl;
	MakeBoard();
	while(Finish())
	{
		Count();
		SpawnBoard();
		int i, j;
		std::cout << "左の辺の数字から配置場所を入力してください:";
		std::cin >> i;
		std::cout << "上の辺の数字から配置場所を入力してください:";
		std::cin >> j;
		std::cout << std::endl;

		if(Player == true)//黒
		{
			if (Check1(i, j, -1))
			{
				change(i, j);
				Reverse(i, j, -1);
				if (Check2(1))
				{
					Player = !Player;
					std::cout << "●白のターンです●" << std::endl;
				}
				else if(Finish())
				{
					std::cout << "パス" << std::endl << std::endl << "◯黒のターンです◯" << std::endl;
				}
				else
				{
					std::cout << "終了" << std::endl;
					Count();
					SpawnBoard();
				}
			}
			else
			{			
				std::cout << "置けません" << std::endl << std::endl << "◯黒のターンです◯" << std::endl << std::endl;			
			}

		}
		else//白
		{
			if (Check1(i, j, 1))
			{
				change(i, j);
				Reverse(i, j, 1);
				if (Check2(-1))
				{
					Player = !Player;
					std::cout << "◯黒のターンです◯" << std::endl;
				}
				else if(Finish())
				{
					std::cout << "パス" << std::endl << std::endl << "●白のターンです●" << std::endl;
				}
				else
				{ 
					std::cout << "終了" << std::endl;
					Count();
					SpawnBoard();
				}
			}
			else
			{
				std::cout << "置けません" << std::endl << std::endl << "●白のターンです●" << std::endl << std::endl;
			}

		}

	}
	return 0;
}