#pragma once
#include <iostream>
#include <string>

namespace Mrowka {

	struct Element {
		int _value;
		Element * _nextElement;

		Element();
		~Element();
	};

	class List
	{
	private:
		// ===== Pola w klasie 'Tablica' =====
		int _size;
		Element * _head;

	public:
		// ===== Konstruktor, destruktor =====
		List();
		List(std::string path);
		~List();

		// ===== Funkcje klasy =====
		bool AddToStart(int value);
		bool AddToPlace(int value, int index);
		bool AddToEnd(int value);

		bool DeleteFromStart();
		bool DeleteFromPlace(int index);
		bool DeleteFromEnd();
		bool DeleteValue(int value);

		bool Search(int value);
		bool SearchAndReplace(int old_value, int new_value);

		int GetSize();
		void View();
	};
}