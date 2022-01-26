﻿#include<iostream>
#include<fstream>
#include<set>
#include<map>
#include<string>
#include<list>

using std::cin;
using std::cout;
using std::endl;

#define tab "\t"

//#define STL_SET
//#define STL_MAP
//#define STL_MAP_PRINT

void print(const std::map<std::string, std::list<std::string>>& dictionary);
void save(const std::map<std::string, std::list<std::string>>& dictionary);
void load(std::map<std::string, std::list<std::string>>& dictionary);

void main()
{
	setlocale(LC_ALL, "");
#ifdef STL_SET
	std::set<int> set = { 50,25,75,16,32,48,64,85,80,50,25,75 };
	for (std::set<int>::iterator it = set.begin(); it != set.end(); it++)cout << *it << tab;
	cout << endl;
	int value;
	cout << "Введите добовляемое значение: "; cin >> value;
	set.insert(value);
	for (std::set<int>::iterator it = set.begin(); it != set.end(); it++)cout << *it << tab;
	cout << endl;
#endif // STL_SET

#ifdef STL_MAP
	std::map<int, std::string> week =
	{
		std::pair<int,std::string>(0,"Sunday"),
		std::pair<int,std::string>(1,"Monday"),
		std::pair<int,std::string>(2,"Tuesday"),
		std::pair<int,std::string>(3,"Wednesday"),
		std::pair<int,std::string>(4,"Thursday"),
		std::pair<int,std::string>(5,"Friday"),
		std::pair<int,std::string>(6,"Saturday"),
		std::pair<int,std::string>(0,"Sunday"),
		std::pair<int,std::string>(1,"Sunday"),
		std::pair<int,std::string>(1,"Sunday"),
		std::pair<int,std::string>(7,"Sunday"),
	};

	for (std::map<int, std::string>::iterator it = week.begin(); it != week.end(); it++)
	{
		//			ключ			   значение
		cout << it->first << tab << it->second << endl;
	}
	cout << week[2] << endl;
	cout << week[8] << endl;
	for (auto& kv : week)
	{
		cout << kv.first << tab << kv.second << endl;
	}
	cout << "\n-------------------------------------------------------\n";
	try
	{
		cout << week.at(9) << endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << endl;
	}
	for (std::pair<int, std::string>i : week)
	{
		cout << i.first << tab << i.second << endl;
	}
#endif // STL_MAP

	std::map<std::string, std::list<std::string>> dictionary /*=
	{
		std::pair<std::string,std::list<std::string>>("asset",{"ценное качество","полезное свойство"}),
		std::pair<std::string,std::list<std::string>>("space",{"космос","пространство"}),
		std::pair<std::string,std::list<std::string>>("distinct",{"отдельный","особый","отличный"}),
		std::pair<std::string,std::list<std::string>>("break",{"тормоз","разбивать","ломать"}),
		std::pair<std::string,std::list<std::string>>("deer",{"олень","лань"})
	}*/;

	load(dictionary);

	print(dictionary);
	//save(dictionary);

#ifdef STL_MAP_PRINT
	/*for (std::pair<std::string, std::list<std::string>>i : dictionary)
{
	cout << i.first << tab;
	for (std::string i : i.second)cout << i << tab; cout << endl;
}*/
/*for (std::map<std::string, std::list<std::string>>::iterator it = dictionary.begin(); it != dictionary.end(); it++)
{
	cout.width(10);
	cout << std::left;
	cout << it->first + ":";
	for (std::list<std::string>::iterator l_it = it->second.begin(); l_it != it->second.end(); l_it++)
	{
		cout << *l_it << ", ";
	}
	cout << "\b\b;\n";
}*/
/*for (std::pair<std::string, std::list<std::string>>i : dictionary)
{
	cout.width(10);
	cout << std::left;
	cout << i.first + ":";
	for (std::string j : i.second)cout << j << ", ";
	cout << "\b\b;\n";
}*/
#endif // STL_MAP_PRINT

}

void print(const std::map<std::string, std::list<std::string>>& dictionary)
{
	for (std::pair<std::string, std::list<std::string>>i : dictionary)
	{
		cout.width(10);
		cout << std::left;
		cout << i.first + ":";
		for (std::string j : i.second)cout << j << ", ";
		cout << "\b\b;\n";
	}
}

void save(const std::map<std::string, std::list<std::string>>& dictionary)
{
	std::ofstream fout("file.txt");
	for (std::pair<std::string, std::list<std::string>>i : dictionary)
	{
		fout.width(10);
		fout << std::left;
		fout << i.first + ":";
		for (std::string j : i.second)fout << j << ", ";
		fout.seekp(-2, std::ios::cur);
		//cur (current) - текущая позиция
		fout << ";\n";
	}
	fout.close();
	system("start notepad file.txt");
}

void load(std::map<std::string, std::list<std::string>>& dictionary)
{
	std::ifstream fin("file.txt");
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			std::string key;
			std::string value;
			std::getline(fin, key, ':');
			dictionary[key];
			std::getline(fin, value);
			for (size_t start = 0, end = 0/*value.find(',')*/; value.find(',', start) != std::string::npos; start = end)
			{
				end = value.find(',', start+1);
				std::string buffer = value.substr(start, end - start);
				buffer.erase(0, buffer.find_first_not_of(','));
				buffer.erase(0, buffer.find_first_not_of(' '));
				buffer.erase(buffer.find_last_not_of(';')+1,buffer.size());
				buffer.erase(buffer.find_last_not_of(' ')+1,buffer.size());
				dictionary[key].push_back(buffer);
			}
		}
		fin.close();
		dictionary.erase("");
	}
	else
	{
		std::cerr << "Error: file not found" << endl;
	}
}


/*
АССОЦИАТИВНЫЕ КОНТЕЙНЕРЫ
Ассоциативные контейнеры хранят данные в виде бинарного дерева к ассоцитивным контейнерам относатся map, set, multimap, multiset
Основным отличием между map и set является то что set хранит просто набор однотипных значений а map хранит пары типа ключ значения pair: key - value
А значит основным отличием между map multimap set multiset заключается в том что map и set это уникальгые контейнеры которые не допускают повторяющехся значений а в multimap multiset ключи значения могут встречаться больше одного раза


*/