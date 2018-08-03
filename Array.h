#pragma once
#include <iostream>
#include <string>

namespace Mrowka {

	class Array
	{
	private:
		// ===== Pola w klasie 'Tablica' =====
		int _size;
		int *_array;
	public:
		// ===== Konstruktor, destruktor =====
		Array();
		Array(std::string path);
		~Array();

		// ===== Funkcje klasy =====

		bool AddToStart(int value);
		bool AddToPlace(int value, int index);
		bool AddToEnd(int value);

		bool DeleteFromStart();
		bool DeleteFromPlace(int index);
		bool DeleteFromEnd();

		bool Search(int value);

		int GetSize();
		void View();
	};

}
