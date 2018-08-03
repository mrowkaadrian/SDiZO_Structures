#include <fstream>

#include "List.h"

namespace Mrowka {

	Element::Element() {
		this->_value = 0;
		this->_nextElement = nullptr;
	}

	Element::~Element() {

	}

	List::List() {
		this->_size = 0;
		this->_head = nullptr;
	}

	List::List(std::string path) {
		std::fstream file;
		file.open(path, std::ios::in);

		if (file.good()) {
			std::cout << "Udalo sie otworzyc plik.\n";
			file >> _size;

			for (int i = 0; i < _size; ++i) {

				Element *new_element;
				new_element = new Element;
				file >> new_element->_value;

				if (_head == nullptr) {
					_head = new_element;
				}
				else {
					Element *temp;
					temp = _head;

					while (temp->_nextElement) {
						temp = temp->_nextElement;
					}

					temp->_nextElement = new_element;
					new_element->_nextElement = nullptr;
				}
			}
		}
		else {
			std::cout << "Nie udalo sie otworzyc pliku.\n";
		}

		file.close();
	}


	List::~List() {
		Element *element_to_delete;
		Element *temp;
		element_to_delete = _head;

		while (element_to_delete->_nextElement) {
			temp = element_to_delete->_nextElement;
			delete element_to_delete;
			element_to_delete = temp;
		}

		delete element_to_delete;
	}

	bool List::AddToStart(int value) {
		Element *new_element;
		new_element = new Element;
		new_element->_nextElement = this->_head;
		_head = new_element;
		new_element->_value = value;
		++_size;
		
		return true;
	}

	bool List::AddToPlace(int value, int index) {
		Element *new_element;
		Element *temp;
		new_element = new Element;
		temp = _head;
		bool found = false;
		/*
		for (int i = 0; i < index - 2; ++i) {
			temp = temp->_nextElement;
		}
		*/

		while (temp->_nextElement && !found) {
			if (temp->_value != index) {
				temp = temp->_nextElement;
			}
			else {
				found = true;
			}
		}
		if (!found) {
			AddToStart(value);
			return true;
		}
		new_element->_nextElement = temp->_nextElement;
		temp->_nextElement = new_element;
		new_element->_value = value;
		++_size;

		return true;
	}

	bool List::AddToEnd(int value) {
		
		Element *new_element;
		new_element = new Element;

		if (_head == nullptr) {
			_head = new_element;
			new_element->_value = value;
			++_size;
		}
		else {
			Element *temp;
			temp = this->_head;
			while (temp->_nextElement) {
				temp = temp->_nextElement;
			}
			temp->_nextElement = new_element;
			new_element->_value = value;
			++_size;
		}
		
		return true;
	}

	bool List::DeleteFromStart() {
		Element *temp;
		temp = _head->_nextElement;
		delete _head;
		_head = temp;
		--_size;

		return true;
	}

	bool List::DeleteFromPlace(int index) {
		Element *temp;
		Element *element_to_delete;
		temp = _head;

		for (int i = 0; i < index - 3; ++i) {
			temp = temp->_nextElement;
		}

		element_to_delete = temp->_nextElement;
		temp->_nextElement = element_to_delete->_nextElement;
		delete element_to_delete;
		--_size;

		return true;
	}

	bool List::DeleteFromEnd() {
		Element *temp = nullptr;
		Element *element_to_delete;
		element_to_delete = _head;

		while (element_to_delete->_nextElement) {
			temp = element_to_delete;
			element_to_delete = element_to_delete->_nextElement;
		}

		temp->_nextElement = nullptr;
		delete element_to_delete;
		--_size;

		return true;
	}

	bool List::DeleteValue(int value) {
		Element *temp;
		Element *element_to_delete;
		temp = _head;

		if (value == _head->_value) {
			DeleteFromStart();

			return true;
		}

		while (temp->_nextElement) {

			if (temp->_nextElement->_value == value) {
				element_to_delete = temp->_nextElement;
				temp->_nextElement = temp->_nextElement->_nextElement;
				delete element_to_delete;
				_size--;

				return true;
			}
			temp = temp->_nextElement;
		}

		return false;
	}

	bool List::Search(int value) {
		Element *temp;
		temp = _head;

		if (_head->_value == value) {
			return true;
		}

		while (temp->_nextElement) {

			if (temp->_value == value) {
				return true;
			}

			temp = temp->_nextElement;
		}

		if (temp->_value == value) {
			return true;
		}

		return false;
	}

	bool List::SearchAndReplace(int old_value, int new_value) {
		Element *temp;
		temp = _head;

		if (_head->_value == old_value) {
			_head->_value = new_value;

			return true;
		}

		while (temp->_nextElement) {
			if (temp->_value == old_value) {
				temp->_value = new_value;
			}

			return true;
		}

		return false;
	}

	int List::GetSize() {
		return _size;
	}

	void List::View() {
		std::cout << "Rozmiar Listy: " << _size << "\n\n";

		Element *temp;
		temp = _head;

		for (int i = 0; i < _size; ++i) {
			std::cout << "Element_" << i + 1 << " --> " << temp->_value << '\n';
			temp = temp->_nextElement;
		}

		std::cout << "---------\nKoniec Listy";
	}
}