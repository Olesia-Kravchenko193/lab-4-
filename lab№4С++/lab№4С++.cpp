#include <iostream>
#include <cstring>
#include <string>

using namespace std;

void Task1()
{
	char ch[100];
	string str = "He likes to eat";
	strcpy_s(ch, str.c_str());//перевод массив чаров в строку
	ch[1] = ' ';
	ch[3] = ' ';
	str = ch;
	cout << str;
}

///////////////////////////////////

void Task2()
{
	string str;
	for (int i = 'a'; i <= 'z'; i++)
	{
		str += i;
		str += "  ";
	}
	cout << str;
}

/////////////////////////////////////

void Task3()
{
	string inp = "Work hard to get what you like, otherwise you'll be forced to just like what you get", out = "";//out - наша строка с готовым "продуктом"
	int endfirst = 0;
	char inp_mas[500], first[10], last[10];
	strcpy_s(inp_mas, inp.c_str());
	int last_spacepos;
	for (int i = 0; i < strlen(inp_mas); i++)
	{
		if (inp_mas[i] == ' ') last_spacepos = i;// находим место, где находится последний пробел в строке
	}

	for (int i = last_spacepos + 1; i < strlen(inp_mas); i++)//записываем последнее слово в начало строки новой
	{
		out += inp_mas[i];
	}

	for (int i = 0; i < last_spacepos; i++)
	{
		if (isalpha(inp_mas[i]))//проверка,является ли буквой
		{
			endfirst = i;
		}
		else { break; }//как только встречаем пробел - заканчиваем цикл
	}

	for (int i = endfirst + 1; i < last_spacepos; i++)//записываем все элементы от конца первого слова до конца последнего
	{
		out += inp_mas[i];
	}

	out += ' ';//добавляем пробел потому что он теряется после считывания
	for (int i = 0; i < last_spacepos; i++)//записываем первое слово в конец
	{
		if (isalpha(inp_mas[i]))
		{
			out += inp_mas[i];
		}
		else { break; }
	}
	cout << inp << "\n\n";
	cout << endl << out;

}

int main()
{
	int numTask;
	cout << "Enter num of task: ";
	cin >> numTask;

	switch (numTask)
	{
	case 1:
		Task1();
		break;
	case 2:
		Task2();
		break;
	case 3:
		Task3();
		break;
	
	}
}