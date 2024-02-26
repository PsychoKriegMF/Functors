#include <iostream>
#include <string>
#include <functional>


//Функторы - классы, объекты которых можно использовать вместо функций
/*
0 - pointer
system -memory
programm - memory
BSS/BRS
HEAP
STACK
PROGRAMM- ARGS
*/

int Summ(int a, int b) { return a + b; }
int Multiply(int Jack, int Joe) { return Jack * Joe; }

using FunctionName = int (*)(int, int); //переопределение типа данных функции
typedef int (*NewName)(int, int);

void PrintOperation(int Jane, int Jacob, FunctionName Alg)
{
	std::cout << "Our operation take params:\n" << 
		"\tJane - " << Jane << '\n' << 
		"\tJacob - " << Jacob << '\n' << 
		"With result " << Alg(Jane, Jacob);
}

class Functor {
public:
	Functor(int val) : num(val){}
	void operator()(int & val)
	{
		val = num;
	}
private:
	int num;
};

void OperateArray(int* arr, int length, std::function<void(int&)> alg)
{
	for (int i = 0; i < length; i++)
	{
		alg(arr[i]);
	}
}

void F02(int& j)
{
	j = 9;
}

int main() {
	setlocale(LC_ALL, "ru");
	int a{ 5 }, b{ 9 };
	std::cout << Summ << " with " << a << " " << b << " args - " << Summ(a, b) << '\n';
	std::cout << Multiply << " with " << a << " " << b << " args - " << Multiply(a, b) << '\n';

	auto pFunc = Summ;
	std:: cout << pFunc << '\n';
	int (*pFunc2)(int, int); // создаем указатель на функцию с передачей аргументов, которые функция должна получать 
	pFunc = Multiply;
	pFunc2 = Summ;

	PrintOperation(2, 5, Multiply);
	std::cout << '\n';

	PrintOperation(a, b, pFunc2);
	std::cout << '\n';

	//пример работы функтора	
	int* arr = new int[6] {};
	OperateArray(arr, 6, F02);// есть массив, из 6 элементов, заполнить по методу F02
	for (size_t i = 0; i < 6; i++)
	{
		std::cout << arr[i] << ' ';
	}
	std::cout << std::endl;

	Functor funtic(4);
	OperateArray(arr, 6, funtic);// есть массив, из 6 элементов, заполнить объектом функтора
	for (size_t i = 0; i < 6; i++)
	{
		std::cout << arr[i] << ' ';
	}
	std::cout << std::endl;

	return 0;
}