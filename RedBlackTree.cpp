#include <fstream>

#include "RedBlackTree.h"

namespace Mrowka {

	RedBlackTree::RedBlackTree() {
		_cr = _cl = _cp = "  ";
		_cr[0] = 218; _cr[1] = 196;
		_cl[0] = 192; _cl[1] = 196;
		_cp[0] = 179; // kod ascii dla graficznego przedstawienia

		_sentinel.color = 'B';
		_size = 0;

		_sentinel.up = &_sentinel;
		_sentinel.left = &_sentinel;
		_sentinel.right = &_sentinel;
		_root = &_sentinel;
	}

	RedBlackTree::RedBlackTree(std::string path) {

		_cr = _cl = _cp = "  ";
		_cr[0] = 218; _cr[1] = 196;
		_cl[0] = 192; _cl[1] = 196;
		_cp[0] = 179; // kod ascii dla graficznego przedstawienia

		_sentinel.color = 'B';
		_size = 0;

		_sentinel.up = &_sentinel;
		_sentinel.left = &_sentinel;
		_sentinel.right = &_sentinel;
		_root = &_sentinel;

		std::fstream file;
		file.open(path, std::ios::in);
		int x;
		int *array;

		if (file.good()) {
			std::cout << "Udalo sie otworzyc plik.\n";
			file >> x;
			array = new int[x];

			for (int i = 0; i < x; ++i) {
				file >> array[i];
			}

			for (int i = 0; i < x; ++i) {
				this->AddElement(array[i]);
			}
		}
		else {
			std::cout << "Nie udalo sie otworzyc pliku.\n";
		}
		file.close();
	}

	RedBlackTree::~RedBlackTree() {
		Release(_root);
	}

	void RedBlackTree::Release(ElementRBT * A) {
		if (A != &_sentinel) { // rekurencyjne usuwanie drzewa
			Release(A->left);
			Release(A->right);
			delete A;
		}
	}

	ElementRBT * RedBlackTree::Find(int key) {
		ElementRBT * element;
		element = _root;

		while ((element != &_sentinel) && (element->key != key)) {
			if (key < element->key) {
				element = element->left;
			}
			else if (key > element->key) {
				element = element->right;
			}
		}

		if (element == &_sentinel) {
			return nullptr;
		}
		return element;
	}

	ElementRBT * RedBlackTree::Minimum(ElementRBT * A) {
		if (A != &_sentinel) {
			while (A->left != &_sentinel) {
				A = A->left;
			}
		}
		return A;
	}

	ElementRBT * RedBlackTree::Succesor(ElementRBT * A) {
		ElementRBT * next;

		if (A != &_sentinel) {

			if (A->right != &_sentinel) {
				return Minimum(A->right);
			}
			else {
				next = A->up;

				while ((next != &_sentinel) && (A == next->right)) {
					A = next;
					next = next->up;
				}
				return next;
			}
		}
		return &_sentinel;
	}

	void RedBlackTree::AddElement(int key) {
		ElementRBT *A;
		ElementRBT *B;

		A = new ElementRBT;
		A->left = &_sentinel;
		A->right = &_sentinel;
		A->up = _root;
		A->key = key;

		if (A->up == &_sentinel) {
			_root = A;
		}
		else {

			for (;;) {

				if (key < A->up->key) {

					if (A->up->left == &_sentinel) {
						A->up->left = A;
						break;
					}
					A->up = A->up->left;
				}
				else {
					if (A->up->right == &_sentinel) {
						A->up->right = A;
						break;
					}
					A->up = A->up->right;
				}
			}
		}
		
		A->color = 'R';

		while ((A != _root) && (A->up->color == 'R')) {

			if (A->up == A->up->up->left) { // przypadki
				B = A->up->up->right;

				if (B->color == 'R') { // Case 1
					A->up->color = 'B';
					B->color = 'B';
					A->up->up->color = 'R';
					A = A->up->up;
					continue;
				}

				if (A == A->up->right) { // Case 2
					A = A->up;
					LRotation(A);
				}

				A->up->color = 'B'; // Case 3
				A->up->up->color = 'R';
				RRotation(A->up->up);
				break;
			}
			else { // lustrzane przypadki
				B = A->up->up->left;

				if (B->color == 'R') { // Case 1M
					A->up->color = 'B';
					B->color = 'B';
					A->up->up->color = 'R';
					A = A->up->up;
					continue;
				}

				if (A == A->up->left) {// Case 2M 
					A = A->up;
					RRotation(A);
				}

				A->up->color = 'B';
				A->up->up->color = 'R';
				LRotation(A->up->up);
				break;
			}
		}
		_root->color = 'B';
		++_size;
	}

	void RedBlackTree::DeleteElement(ElementRBT * A) {
		ElementRBT * B;
		ElementRBT * C;
		ElementRBT * D;

		if ((A->left == &_sentinel) || (A->right == &_sentinel)) {
			B = A;
		}
		else {
			B = Succesor(A);
		}

		if (B->left != &_sentinel) {
			C = B->left;
		}
		else {
			C = B->right;
		}

		C->up = B->up;

		if (B->up == &_sentinel) {
			_root = C;
		}
		else if (B == B->up->left) {
			B->up->left = C;
		}
		else {
			B->up->right = C;
		}

		if (B != A) {
			A->key = B->key;
		}

		if (B->color == 'B') {

			while ((C != _root) && (C->color == 'B')) {

				if (C == C->up->left) {
					D = C->up->right;

					if (D->color == 'R') { // Case 1
						D->color = 'B';
						C->up->color = 'R';
						LRotation(C->up);
						D = C->up->right;
					}

					if ((D->left->color == 'B') && (D->right->color == 'B')) { // Case 2
						D->color = 'R';
						C = C->up;
						continue;
					}

					if (D->right->color == 'B') { // Case 3
						D->left->color = 'B';
						D->color = 'R';
						RRotation(D);
						D = C->up->right;
					}

					D->color = C->up->color; // Case 4
					C->up->color = 'B';
					B->right->color = 'B';
					LRotation(C->up);
					C = _root;
				}
				else { // przypadki lustrzane
					D = C->up->left;

					if (D->color == 'R') { // Case 1M
						D->color = 'B';
						C->up->color = 'R';
						RRotation(C->up);
						D = C->up->left;
					}

					if ((D->left->color == 'B') && (D->right->color == 'B')) { // Case 2M
						D->color = 'R';
						C = C->up;
						continue;
					}

					if (D->left->color == 'B') { // Case 3M
						D->right->color = 'B';
						D->color = 'R';
						LRotation(D);
						D = C->up->left;
					}

					D->color = C->up->color; // Case 4M
					C->up->color = 'B';
					D->left->color = 'B';
					RRotation(C->up);
					C = _root;
				}
			}
		}

		C->color = 'B';
		delete B;
	}

	void RedBlackTree::RRotation(ElementRBT * A) {
		ElementRBT *B;
		ElementRBT *p;

		B = A->left;

		if (B != &_sentinel) {
			p = A->up;
			A->left = B->right;

			if (A->left != &_sentinel) {
				A->left->up = A;
			}

			B->right = A;
			B->up = p;
			A->up = B;

			if (p != &_sentinel) {
				if (p->left == A) {
					p->left = B;
				}
				else {
					p->right = B;
				}
			}
			else {
				_root = B;
			}
		}
	}

	void RedBlackTree::LRotation(ElementRBT * A) {
		ElementRBT *B;
		ElementRBT *p;
		
		B = A->right;

		if (B != &_sentinel) {
			p = A->up;
			A->right = B->left;

			if (A->right != &_sentinel) {
				A->right->up = A;
			}

			B->left = A;
			B->up = p;
			A->up = B;

			if (p != &_sentinel) {
				
				if (p->left == A) {
					p->left = B;
				}
				else {
					p->right = B;
				}
			}
			else {
				_root = B;
			}
		}
	}

	ElementRBT * RedBlackTree::GetRoot() {
		return this->_root;
	}

	int RedBlackTree::GetSize() {
		return this->_size;
	}

	void RedBlackTree::View(std::string sp, std::string sn, ElementRBT *p) {
		std::string t;

		if (p != &_sentinel) {
			t = sp;

			if (sn == _cr) {
				t[t.length() - 2] = ' ';
			}

			View((t + _cp), _cr, p->right);
			t = t.substr(0, sp.length() - 2);
			std::cout << t << sn << p->color << ":" << p->key << std::endl;
			t = sp;

			if (sn == _cl) {
				t[t.length() - 2] = ' ';
			}

			View((t + _cp), _cl, p->left);
		}
	}
}