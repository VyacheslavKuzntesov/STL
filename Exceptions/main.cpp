﻿#include<iostream>
using namespace std;

#define DIVISION_BY_ZERO

void main()
{
	setlocale(LC_ALL, "");

#ifdef DIVISION_BY_ZERO
	int a;
	int b;
	cout << "Введите два числа: "; cin >> a >> b;
	try
	{
		cout << a / b << endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << endl;
	}
	catch (...)
	{
		std::cerr << "Something happend" << endl;
	}
#endif // DIVISION_BY_ZERO

	int n;
	int f = 1;
	cout << "Введите число для выполнения Факториала: "; cin >> n;
	try
	{
		for (int i = 1; i <= n; i++)
		{
			cout << i << " = ";
			f *= i;
			cout << f << endl;
		}
	}
	catch (const std::exception& e)
	{
		cerr << e.what() << endl;
	}
	catch (...)
	{
		cerr << "Something happend" << endl;
	}
}

/*
ОБРАБОТКА ИСКЛЮЧЕНИЙ
Исключительная ситуация это ошибка возникающая на этапе выполнения программы связаная с ошибкой программиста или с ошибкой пользователя
Например: используется не проинициализированная переменная, выделяется очень большое количество памяти, открывается не существующий файл, запись за пределы выделенной памяти и так далее
Некоторые исключения можно избежать на этапе написания кода то что зависит от программиста но некоторые ошибки зависят от пользователя и программист никак не может на них повлиять
и для того что бы предотвратить аварийное завершение программы единственным способом является обработка исключений

Исключения нужно обрабатывать для того что бы обработать исключения код который может его сгенерировать помещают в блок try
Блок try ловит исключения и передает его обработчику (блоку catch)
Блок catch обрабатывает исключения.
У одного блока try может быть несколько обработчиков исключений тоесть несколько блоков catch каждый из которых обрабатывает свой тип искючений 
У блока try должен быть 1 обработчик(catch) противном случае будет синтаксическая ошибка
Обработчик исключения это самая обычная функция с 1 параметром параметер может быть любого типа у одного блока try не может быть несколько обработчиков одного типа в противном случае будет ошибка на этапе компиляции
Для того что бы поймать исключения его должен кто то бросить это может быть процессор(cpu) операционная система(ОС) либо же функция
Для того что бы обрабатывать системные исключения брошеные ОС или cpu нужен универсальный обработчик catch(...) он обрабатывает все исключения которые не могут обработать остальные обработчики и он не распознает тип исключения
Для того что бы обрабатывать системные исключения нужно добавить параметры компиляции /EHa ?? 

Исключения актуальны при использывании функций по скольку они позволяют раскрутить стэк вызовов когда из функции надо что то вернуть при ошибки а вернуть нечего единственной возможностб остаеться бросить исключение
*/