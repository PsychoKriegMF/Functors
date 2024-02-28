#include <iostream>
#include <string>
#include <functional>
#include <vector>
#include <algorithm>


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



int mainEX() {
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

#include <random>

bool More(int a, int b)
{
	return a > b;
}

struct Runner 
{
	int id;
	double result;
	std::string Name;
};

int main() {
	std::vector<int> arr;
	for (int i = 0; i < 20; i++)
	{
		arr.push_back(i + 1);
	}
	std::shuffle(arr.begin(), arr.end(), std::random_device());  //алгоритм который перемешивает коллекцию
	for (auto& i : arr)                   // печать массива заполненного рандомно
	{
		std::cout << i << ", ";
	}
	std::cout << "\b\b " << std::endl;

	std::sort(arr.begin(), arr.end());   // сортировака по возврастанию
	for (auto& i : arr)
	{
		std::cout << i << ", ";
	}
	std::cout << "\b\b " << std::endl;

	std::sort(arr.begin(), arr.end(), More); // сортировка по убыванию
	for (auto& i : arr)
	{
		std::cout << i << ", ";
	}
	std::cout << "\b\b " << std::endl;

	std::vector<Runner>lBoard
	{
		{7,131.2,"Tomas"},
		{1,123.4,"Joe"},
		{6,129.3,"Alex"},
		{5,125.6,"Alexandr"},
		{3,122.6,"Ken"}
	};

	for (const auto& i : lBoard)
	{
		std::cout << "ID: " << i.id << ' ';
		std::cout << "Name: " << i.Name << ' ';
		std::cout << "Result: " << i.result << '\n';
	}
	std::cout << std::endl;

	// анонимные функции(лямбда выражения)
	//[захват контекста](перечень аргументов)->предписываемый тип возврата{тело функции}   

	//без предписанного типа возврата
	/*auto funk = [](int a) {
		if (a % 2) { return true; }
		else { return false; }
		};*/

	// с предписанным типом
	
	//std::function<bool(int)>funk = [](int a)->bool { 
	auto funk = [](int a)->bool {
		if (a % 2) { return a % 2; }
		else { return false; }
		};
	std::cout << funk(4) << "\n\n\n";

	std::sort(lBoard.begin(), lBoard.end(), 
		[](const Runner& a, const Runner& b)->bool {return a.Name < b.Name; });
	for (const auto& i : lBoard)
	{
		std::cout << "ID: " << i.id << ' ';
		std::cout << "Name: " << i.Name << ' ';
		std::cout << "Result: " << i.result << '\n';
	}
	std::cout << std::endl;

	auto func2 = [](const Runner& a, const Runner& b)->bool{return a.id < b.id; };

	std::sort(lBoard.begin(), lBoard.end(), func2);

	for (const auto& i : lBoard)
	{
		std::cout << "ID: " << i.id << ' ';
		std::cout << "Name: " << i.Name << ' ';
		std::cout << "Result: " << i.result << '\n';
	}
	std::cout << std::endl;






	return 0;
}