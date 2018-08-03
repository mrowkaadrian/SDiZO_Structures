#include <fstream>

#include "Array.h"

namespace Mrowka {

	Array::Array() {
		_size = 0;
		_array = new int[_size];
	}

	Array::Array(std::string path) {
		std::fstream file;
		file.open(path, std::ios::in);

		if (file.good()) {
			std::cout << "Udalo sie otworzyc plik.\n";
			file >> _size;
			_array = new int[_size];
			
			for (int i = 0; i < _size; ++i) {
				file >> _array[i];
			}
		}
		else {
			std::cout << "Nie udalo sie otworzyc pliku.\n";
		}
		file.close();
	}


	Array::~Array()	{
		delete[] this->_array;
		this->_array = nullptr;
	}

	bool Array::AddToStart(int value) {
		int * temp_array;
		temp_array = new int[_size + 1];

		for (int i = 1; i <= this->_size; i++) {
			temp_array[i] = this->_array[i - 1];
		}

		temp_array[0] = value;
		delete[] this->_array;
		this->_array = temp_array;
		++_size;

		return true;
	}

	bool Array::AddToPlace(int value, int index) {

		if (index > 0 && index < _size) {
			int * temp_array;
			temp_array = new int[_size + 1];

			for (int i = 0; i < index; ++i) {
				temp_array[i] = this->_array[i];
			}

			temp_array[index] = value;

			for (int i = index + 1; i < _size + 1; ++i) {
				temp_array[i] = this->_array[i - 1];
			}

			delete[] this->_array;
			this->_array = temp_array;
			++_size;

			return true;
		}
		else {
			return false;
		}
	}

	bool Array::AddToEnd(int value) { 
		int * temp_array;
		temp_array = new int[_size + 1];

		for (int i = 0; i < _size; ++i) {
			temp_array[i] = this->_array[i];
		}

		temp_array[_size] = value;
		delete[] this->_array;
		this->_array = temp_array;
		++_size;

		return true;
	}

	bool Array::DeleteFromStart() { 
		int * temp_array;
		temp_array = new int[_size - 1];
		
		for (int i = 1; i < _size; ++i) {
			temp_array[i - 1] = this->_array[i];
		}

		delete[] this->_array;
		this->_array = temp_array;
		--_size;

		return true;
	}

	bool Array::DeleteFromPlace(int index) { 
		if (index > 0 && index < _size - 1) {
			int * temp_array;
			int buffer;
			temp_array = new int[_size - 1];

			for (int i = index; i < _size - 1; ++i) {
				buffer = this->_array[i];
				this->_array[i] = this->_array[i + 1];
				this->_array[i + 1] = buffer;
			}

			for (int i = 0; i < _size - 1; ++i) {
				temp_array[i] = this->_array[i];
			}

			delete[] this->_array;
			this->_array = temp_array;
			--_size;

			return true;			
		}
		else {
			return false;
		}
	}

	bool Array::DeleteFromEnd() { 
		int * temp_array;
		temp_array = new int[_size - 1];

		for (int i = 0; i < _size - 1; ++i) {
			temp_array[i] = this->_array[i];
		}

		delete[] this->_array;
		this->_array = temp_array;
		--_size;

		return true;
	}

	bool Array::Search(int value) { 

		for (int i = 0; i < _size; ++i) {

			if (this->_array[i] == value) {
				return true;
			}
		}

		return false;
	}

	int Array::GetSize() {
		return _size;
	}

	void Array::View() {
		std::cout << "Rozmiar Tablicy: " << _size << "\n\n";

		for (int i = 0; i < _size; ++i) {
			std::cout << "Element_" << i << " --> " << this->_array[i] << '\n';
		}

		std::cout << "---------\nKoniec Tablicy";
	}
}