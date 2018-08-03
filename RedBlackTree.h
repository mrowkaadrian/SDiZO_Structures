#pragma once

#include <iostream>
#include <string>

namespace Mrowka {

	struct ElementRBT
	{
		ElementRBT * up;
		ElementRBT * left;
		ElementRBT * right;
		int key;
		char color;
		int data;
	};

	class RedBlackTree
	{
	private:
		// ===== Pola w klasie 'Tablica' =====
		int _size;
		ElementRBT _sentinel;
		ElementRBT *_root = nullptr;
		std::string _cr, _cl, _cp;

	public:
		// ===== Konstruktor, destruktor =====
		RedBlackTree();
		RedBlackTree(std::string path);
		~RedBlackTree();

		// ===== Funkcje klasy =====
		void Release(ElementRBT * A);

		ElementRBT * Find(int key);
		ElementRBT * Minimum(ElementRBT * A);
		ElementRBT * Succesor(ElementRBT * A);

		void AddElement(int key);
		void DeleteElement(ElementRBT * A);

		void RRotation(ElementRBT * A);
		void LRotation(ElementRBT * A);

		ElementRBT * GetRoot();
		int GetSize();
		void View(std::string sp, std::string sn, ElementRBT *p);
	};

}