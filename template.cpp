// algorithm_4_1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <stdexcept>

using namespace std;

template <typename T>
class Stack 
{
    private:
		vector<T> elems;

    public:
		void push(T const&);
		void pop();
		T top() const;
		bool empty();
};

int main()
{
	try 
	{
	cout << "hello world!" << endl;

	cout << "Please enter some integers (enter 0 to end):" << endl;
	Stack<int> intStack;
	int pushInt;
	do 
	{
		cin >> pushInt;
	    intStack.push(pushInt);
	} while (pushInt);

	//intStack.push(1);

	cout << "Stack Top:  " << intStack.top() << endl;
	
	intStack.pop();
	cout << "Stack Top After Pop:  " << intStack.top() << endl;

    }

	catch (exception const& ex) {
		cerr << "Exception: " << ex.what() << endl;
		return -1;
	}

    return 0;
}

template<typename T>
void Stack<T>::push(T const& elem)
{
	elems.push_back(elem);
}

template<typename T>
void Stack<T>::pop()
{
	if (elems.empty()) 
	{
		cout << "EMPTY" << endl;
        throw out_of_range("pop(): Empty stack");
	}
	return elems.pop_back();
}

template<typename T>
T Stack<T>::top() const
{
	if (elems.empty())
	{
		cout << "EMPTY" << endl;
		throw out_of_range("top(): Empty stack");
	}
	return elems.back();
}

template<typename T>
bool Stack<T>::empty()
{
	return elems.empty();
}
