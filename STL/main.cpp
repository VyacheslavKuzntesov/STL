#include<iostream>
#include<array>
#include<vector>

//using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"

//#define STL_ARRAY
#define STL_VECTOR

void main()
{
	setlocale(LC_ALL, "");

#ifdef STL_ARRAY
	const int n = 5;
	std::array<int, n> arr{ 3,5,8 };
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	}
#endif // STL_ARRAY

#ifdef STL_VECTOR
	std::vector<int> vec = { 0,1,1,2,3,5,8,13,21,34 };
	cout << "Size:	  " << vec.size() << endl;
	cout << "Capacity:" << vec.capacity() << endl;
	cout << "MaxSize: " << vec.max_size() << endl;

	vec.push_back(55);

	vec.reserve(5);

	//vec.shrink_to_fit();

	try
	{
		for (int i = 0; i < vec.capacity(); i++)
		{
			//cout << vec[i]<<tab;
			//cout << vec[i] << tab;//Метод data() возращает указатель на динамический массив который обварачивает vector
			cout << vec.at(i) << tab;
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << endl << e.what() << endl;
	}

	cout << endl;
	cout << "Size:	  " << vec.size() << endl;
	cout << "Capacity:" << vec.capacity() << endl;
	cout << "MaxSize: " << vec.max_size() << endl;

	/*std::vector<char> d_vec;
	cout << "Size:	  " << d_vec.size() << endl;
	cout << "Capacity:" << d_vec.capacity() << endl;
	cout << "MaxSize: " << d_vec.max_size() << endl;*/
#endif // STL_VECTOR


}





/*
STL - Standart Template Library(стандартная шаблонная библиотека)
STL - представляет собой контейнер, итераторов, предикатов и функциональних объектов
Обсолютно все сущности в STL являються шаблонными
Основным понятием STL является контейнер(Container) - это объект, который организует хранение других объуктов в памяти
Каждый контейнер использует определеную структуру данных массив список или дерево
Кроме того у каждого контейнера есть свой набор итераторов
Большинство алгоритмов STL могут работать обсолютно со всеми контейнерами

Контейнеры бывают:
1.Линейные(Sequence containers):											array, vector, deque, forward_list, list;

2.Ассоциативные (Associative container):									map, set, multimap, multiset;

3.Контейнеры адабтеры(Adaptor container):									stack - стопка LIFO,
																			queue - очередь FIFO - First In - First Out
																			priority_queue	-  очередь с приорететом

4.Неупорядочные ассоциативные контейнеры(Unordered associative containers): unordered_map, unordered_set, unordered_multimap, unordered_multiset;

Для хранения данных последовательные контейнеры используют линейные структуры данных(массив,список)
Ассоциативные контейнеры для хранения данных используют деревъя
Адаптер контейнеры -  это контейнеры которые используют существующие линейные контейнеры
Неупорядочные ассоциативные контейнеры -

Для использывания любого контейнера его нужно подключить

--------------------------------------------------------------------------------------
array - это последовательный контейнер который для хранения данных использует статический массив
	std::array<T,N>
T - тип элементов
N - количество элементов

--------------------------------------------------------------------------------------
vector - это контейнер который хранит данные в виде динамического массива
	std::vector<T>
T - тип элементов
*/