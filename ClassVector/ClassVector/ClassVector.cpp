// ClassVector.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
template <typename T>


class Vector {
private:
	T* m_arr = nullptr;
	int m_size = 0;
	int m_capacity = 0;

public:
	Vector()
	{
		re_alloc(2);
	}

	Vector(int m_size)
	{
		m_arr = (T*)new T[m_size];
	}

	int size()
	{
		return m_size;
	}

	void push_back(const T& x)
	{
		/*if (m_size >= m_capacity)
		{
			re_alloc(m_capacity + m_capacity/2);
		}*/    //Error!!!

		m_arr[m_size] = x;
		++m_size;
	}

	void pop_back()
	{
		if (m_size == 0)
		{
			throw std::exception("pop back on empty vector");
		}
		--m_size;
	}

	bool empty()
	{
		return m_size == 0;
	}

	const T& operator[](int index)
	{

		return m_arr[index];
	}

	T& At(int index)
	{
		if ((index < 0) || (index >= m_size))
		{

			throw std::exception("index out of range");
		}

		return m_arr[index];
	}

	bool operator==(const Vector& other)
	{
		if (m_size != other.m_size)return false;

		for (int i = 0; i < m_size; ++i)
		{
			if (m_arr[i] != other.m_arr[i])
			{
				return false;
			}
		}

		return true;
	}

	bool operator!=(const Vector& other)
	{
		return !(*this == other);
	}

        
	void Function(int (*lambda)(int))
	{
		for(int i=0; i<m_size; ++i)
		{
		if (lambda(m_arr[i]))
			std::cout << m_arr[i];
		}
	}
	T& Front()
	{
		return m_arr[0];
	}

	T& Back()
	{
		return m_arr[m_size - 1];
	}

	void Clear()
	{
		m_size = 0;
	}


	void print_arr(int index)
	{
		std::cout << m_arr[index];
	}

	void re_alloc(int newCapacity)
	{
		if (newCapacity < m_size)
			return;

		T* newArray = new T[newCapacity];

		if (newCapacity < m_size)
		{
			m_size = newCapacity;
		}

		for (int k = 0; k < m_size; ++k)
			newArray[k] = m_arr[k];

		m_capacity = newCapacity;
		m_arr = newArray;
		delete[] newArray;
	}

	void Erase(int index)
	{
		if ((index < 0) || (index >= m_size))
		{

			throw std::exception("Erase - index out of range");
		}

		for (int i = index; i < m_size - 1; ++i)
		{
			m_arr[i] = m_arr[i + 1];
		}
		--m_size;
	}

	void Insert(int index, int value)
	{
		if ((index < 0) || (index >= m_size))
		{

			throw std::exception("Insert - index out of range");
		}

		if (m_size != m_capacity)
		{
			for (int i = m_size - 1; i >= index; --i)
			{
				m_arr[i + 1] = m_arr[i];
			}
			m_arr[index] = value;
			++m_size;
		}
		else {
			m_capacity *= 2;

			T* newArray = new T[m_capacity];

			for (int k = 0; k < m_size; ++k)
				newArray[k] = m_arr[k];

			m_arr = newArray;
			delete[] newArray;
		}
	}

	~Vector()
	{
		delete[]m_arr;
		m_arr = nullptr;
	}
};

	
int main()
{
	Vector<int> arr(4);
	arr.push_back(3);
	arr.push_back(3);
	arr.push_back(5);
	arr.push_back(3);

	for (int i = 0; i < arr.size(); ++i)
		arr.print_arr(i);

	std::cout << "\n";
	arr.pop_back();

	std::cout << "\n";

	for (int i = 0; i < arr.size(); ++i)
		arr.print_arr(i);

	std::cout << "\n";

	std::cout << arr.At(2) << std::endl;
	std::cout << arr[0] << std::endl;
	std::cout << arr.empty() << std::endl;

	Vector<int> arr1(3);
	Vector<int>arr2(3);

	arr1.push_back(1);
	arr1.push_back(2);
	arr1.push_back(3);
	arr2.push_back(1);
	arr2.push_back(2);
	arr2.push_back(1);

	if (arr1 == arr2)
	{
		std::cout << "Yes";
	}
	else {
		std::cout << "No";
	}

	std::cout << "\n";
	std::cout << arr.Back() << std::endl;
	std::cout << arr.Front() << "\n";
	arr.Erase(0);

	for (int i = 0; i < arr.size(); ++i)
		arr.print_arr(i);

	std::cout << "\n";

	arr.Insert(0, 6);
	for (int i = 0; i < arr.size(); ++i)
		arr.print_arr(i);
	
	std::cout << "\n";
	auto Lambda = [](int number) {
		return !(number % 2);
	};
	arr.Function(Lambda);  // even numbers for example
	
	
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
