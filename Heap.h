#pragma once

#include <iostream>
#include <string>

namespace Mrowka {

	class Heap
	{
	private:
		// ===== Pola w klasie 'Tablica' =====
		int _size;
		int *_heap;

	public:
		// ===== Konstruktor, destruktor =====
		Heap();
		Heap(std::string path);
		~Heap();

		// ===== Funkcje klasy =====
		bool Add(int value);
		bool Delete(int value);
		bool Search(int value);

		int GetSize();
		void View(std::string sp, std::string sn, int v);
	};

}
