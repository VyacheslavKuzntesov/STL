#include<iostream>
#include<array>
#include<vector>
#include<deque>
#include<forward_list> //односвязный список
#include<list> // двусвязный список

//using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"

//#define STL_ARRAY
//#define STL_VECTOR
//#define STL_HOMEWORK
//#define STL_DEQUE
//#define STL_FORWARD_LIST
//#define STL_LIST

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

	int value;
	int count;
	int index;
	/*cout << "Введите индекс добовляемого элемента: "; cin >> index;
	cout << "Введите количество добавлений: "; cin >> count;
	cout << "Введите значение добовляемого элемента: "; cin >> value;

	if (index <= vec.size())vec.insert(vec.begin() + index, count ,value);
	else std::cerr << "Error: out of range." << endl;*/

	vec.insert(vec.begin() + 11, { 256,512,768 });

	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		cout << *it << tab;
	}
	cout << endl;

	for (std::vector<int>::reverse_iterator it = vec.rbegin(); it != vec.rend(); ++it)
	{
		cout << *it << tab;
	}
	cout << endl;

#endif // STL_VECTOR

#ifdef STL_HOMEWORK
	std::vector<int> vec = { 0,1,1,2,3,5,8,13,21,34 };
	int value;
	int index;
	cout << "Введите индекс добовляемого значения: "; cin >> index;
	cout << "Введите добовляемое значение: "; cin >> value;
	vec.insert(vec.cbegin() + index, value);

	for (int i = 0; i < vec.capacity(); i++)
	{
		cout << vec.data()[i] << tab;
	}

	cout << endl << "Введите индекс удаляемого значения: "; cin >> index;
	vec.erase(vec.cbegin() + index);

	for (int i = 0; i < vec.capacity(); i++)
	{
		cout << vec.data()[i] << tab;
	}
#endif // STL_HOMEWORK

#ifdef STL_DEQUE
	std::deque<int> deque = { 3,5,8,13,21 };
	deque.push_back(34);
	deque.push_back(55);

	deque.push_front(2);
	deque.push_front(1);
	deque.push_front(1);
	deque.push_front(0);

	for (std::deque<int>::iterator it = deque.begin(); it != deque.end(); ++it)
	{
		cout << *it << tab;
	}
	cout << endl;

	for (std::deque<int>::reverse_iterator it = deque.rbegin(); it != deque.rend(); ++it)
	{
		cout << *it << tab;
	}
	cout << endl;


#endif // STL_DEQUE

#ifdef STL_FORWARD_LIST
	std::forward_list<int> list1 = { 3,5,8,13,21 };
	list1.push_front(2);
	list1.push_front(1);
	list1.insert_after(list1.begin(),1);
	list1.insert_after(list1.before_begin(),0);

	list1.reverse();
	list1.push_front(34);
	list1.reverse();

	for (std::forward_list<int>::iterator it = list1.begin(); it != list1.end(); ++it)
	{
		cout << *it << tab;
	}
	cout << endl;

	std::forward_list<int> list2 = { 256,512,768 };
	for (int i : list2)cout << i << tab; cout << endl;

	list1.swap(list2);
	for (int i : list1)cout << i << tab; cout << endl;
	for (int i : list2)cout << i << tab; cout << endl;
#endif // STL_FORWARD_LIST

#ifdef STL_LIST
	std::list<int> list = { 3,5,8,13,21 };
	for (std::list<int>::iterator it = list.begin(); it != list.end(); ++it)
	{
		cout << *it << tab;
	}
	cout << endl;
	for (std::list<int>::reverse_iterator it = list.rbegin(); it != list.rend(); ++it)
	{
		cout << *it << tab;
	}
	cout << endl;

	int index;
	int value;
	cout << "Введите индекс добовляемого элемента: "; cin >> index;
	cout << "Введите значение добовляемого элемента: "; cin >> value;

	std::list<int>::iterator position = list.begin();
	//for (int i = 0; i < index; i++)position++;
	if (index <= list.size())
	{
		std::advance(position, index);
		list.insert(position, value);
	}
	else cout << "Error: out of range\n";

	for (int i : list)cout << i << tab; cout << endl;

#endif // STL_LIST


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

--------------------------------------------------------------------------------------
deque(double-ended queue или двунаправленная очередь) - это линейный контейнер который хранит данные в виде списка динамических массивов(списка векторов).
Это не много ускоряет операции добавление и удаление элементов но немного замедляет доступ к элементам
В отличии от вектора deque позволяет добавлять элементы не только в конец но и в начало контейнера

--------------------------------------------------------------------------------------
*/