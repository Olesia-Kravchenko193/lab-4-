#include <iostream>
#include <cstring>
#include <string>

using namespace std;

void Task1()
{
	char ch[100];
	string str = "He likes to eat";
	strcpy_s(ch, str.c_str());//перевод массив чаров в строку
	for (int i = 1; i < strlen(ch); i++)
	{
		ch[i] = ch[i + 1];
	}
	for (int i = 2; i < strlen(ch); i++)
	{
		ch[i] = ch[i + 1];
	}
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
	string inp = "    Work  hard to get what you like, otherwise you'll be forced to just like what you  get    ", out = "";//out - наша строка с готовым "продуктом"
	int endfirst = 0, beginfirst = 0, beginlast = 0, endlast = 0;

	char inp_mas[500];

	strcpy_s(inp_mas, inp.c_str());

	for (size_t i = 0; i < strlen(inp_mas); i++)
	{
		if (inp_mas[i] == ' ' && (isalpha((unsigned char)inp_mas[i - 1]) || inp_mas[i - 1] == '`')) endlast = i;
	}

	for (int i = 0; i < endlast; i++)
	{
		if (inp_mas[i] == ' ' && (isalpha((unsigned char)inp_mas[i + 1]) || inp_mas[i + 1] == '`')) beginlast = i + 1;
	}


	for (int i = 0; i < beginlast; i++)
	{
		if ((isalpha((unsigned char)inp_mas[i]) || inp_mas[i] == '`') && inp_mas[i + 1] == ' ')
		{
			endfirst = i + 1;
			break;
		}
	}

	for (int i = 0; i < endfirst; i++)
	{
		if (inp_mas[i] = ' ' && (isalpha((unsigned char)inp_mas[i + 1]) || inp_mas[i + 1] == '`'))
		{
			beginfirst = i + 1;
			break;
		}
	}



	for (int i = beginlast; i < endlast; i++)
	{
		out += inp_mas[i];
	}
	for (int i = endfirst; i < beginlast; i++)
	{
		out += inp_mas[i];
	}
	for (int i = beginfirst; i < endfirst; i++)
	{
		out += inp_mas[i];
	}
	cout << inp << endl;
	cout << out;

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