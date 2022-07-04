#include <iostream>
#include <chrono>
#include <windows.h>
using namespace std;

const int tamanho = 100;
int num[tamanho];

void textcolor (int color)
{
    static int __BACKGROUND;

    HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE );
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;


    GetConsoleScreenBufferInfo(h, &csbiInfo);

    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),
                             color + (__BACKGROUND << 4));
}

void gotoxy(int x, int y){
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int main(){
	srand(time(NULL));
    system("cls");
    system("pause");
    system("cls");
	for(int i = 0;i<tamanho;i++){
		num[i] = rand()%tamanho+1;
	}
	int feitos = tamanho-1;

	while(feitos != 0){
	for(int i = 0;i<feitos;i++){
		//renderizar
		string tela = "";
		gotoxy(0, 0);
		for(int j = 0;j<tamanho;j++){
			if(j == i){
				cout<<tela;
				tela = "";
			}
			for(int k = 0;k<tamanho;k++){
                if(k<num[j])
                tela+="#";
                else
                tela+=" ";
			}
			tela+="\n";
			if(j == i){
                textcolor(10);
				cout<<tela;
				tela = "";
				textcolor(7);
			}
		}
		cout<<tela;
		//swap
		if(num[i]>num[i+1]){
			int temp = num[i];
			num[i] = num[i+1];
			num[i+1] = temp;
		}
	}
	feitos--;
	}

	return 0;
}
