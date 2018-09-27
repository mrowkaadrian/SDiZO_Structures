#include <iostream>
#include <string>
#include <ctime>
#include <fstream>

#include "List.h"
#include "Array.h"
#include "Heap.h"
#include "RedBlackTree.h"
#include "Timer.h"

using namespace Mrowka;

int mainMenu();

int arrayMenu();
int listMenu();
int heapMenu();
int rbtMenu();

int arrayOperationMenu();
int listOperationMenu();
int structureOperationMenu();

int *generateData(int &size, int *array);
void saveToFile(int size, int array[]);
void pause();

int main() {

	Array * user_array = nullptr;
	List * user_list = nullptr;
	Heap * user_heap = nullptr;
	RedBlackTree * user_rbt = nullptr;

	Timer * timer = new Timer("Test Timer");

	bool exit = false;
	int size = 10;
	int *array = nullptr;

	while (!exit) { // ----- Petla glowna -----

		system("cls");
		int number;
		number = mainMenu();

		switch (number) {
		case 1:

			for (;;) { // ----- Petla tablicy -----
				std::cout << "Wybrales tablice:\n";
				system("cls");

				if (user_array) {
					std::cout << "Aktualnie tablica ma rozmiar: " << user_array->GetSize() << "\n\n";
				}

				number = arrayMenu();

				if (number == 1) {
					//wczytaj z pliku
					user_array = new Array("dane.txt");
					pause();
				}

				if (number == 2) {
					//wyswietl
					if (user_array) {
						user_array->View();
					}
					else {
						std::cout << "Nie utworzono zadnej tablicy\n";
					}
					pause();
				}

				if (number == 3) {

					for (;;) { // ----- Petla operacji listy -----
						number = structureOperationMenu();

						if (number == 1) {
							int key = 0;
							int index = 0;

							std::cout << "Jaka liczbe chcesz dodac?\n->";
							std::cin >> key;

							if (std::cin.good()) {
								std::cin.clear();
								std::cout << "Na jakiej pozycji?\n->";
								std::cin >> index;

								if (std::cin.good()) {
									user_array->AddToPlace(key, index);
									std::cout << "Poprawnie dodano!\n";
									pause();
								}
								else {
									std::cout << "Podales nieprawidlowa wartosc!\n Sprobuj ponownie!\n";
									pause();
								}
							}
							else {
								std::cout << "Podales nieprawidlowa wartosc!\n Sprobuj ponownie!\n";
								pause();
							}
							std::cin.clear();
						}
						if (number == 2) {
							int index = 0;
							std::cout << "Z jakiego indeksu chcesz usunac?\n->";
							std::cin >> index;

							if (std::cin.good()) {
								if (user_array->DeleteFromPlace(index)) {
									std::cout << "Poprawnie usunieto!\n";
								}
								else {
									std::cout << "Nie ma takiego klucza\n";
								}
								pause();
							}
							else {
								std::cout << "Podales nieprawidlowa wartosc!\n Sprobuj ponownie!\n";
								pause();
							}
							std::cin.clear();
						}
						if (number == 3) {
							int key = 0;
							std::cout << "Jaka liczbe chcesz wyszukac?\n->";
							std::cin >> key;
							if (std::cin.good()) {
								timer->StartTimer();
								if (user_array->Search(key)) {
									std::cout << "Taki klucz istnieje w tablicy\n";
								}
								else {
									std::cout << "Nie ma takiego klucza w tablicy\n";
								}
								timer->EndTimer();
								timer->CalculateAndPrintTime();
								pause();
							}
							else {
								std::cout << "Podales nieprawidlowa wartosc!\n Sprobuj ponownie!\n";
								pause();
							}
							std::cin.clear();
						}
						if (number == 0) 
							break;
						
					}
					continue;
				}

				if (number == 0)
					break;
			}
			break;
		case 2:

			for (;;) { // ----- Petla listy -----
				std::cout << "Wybrales liste:\n";
				system("cls");

				if (user_list) {
					std::cout << "Aktualnie lista ma rozmiar: " << user_list->GetSize() << "\n\n";
				}

				number = listMenu();

				if (number == 1) {
					
					user_list = new List("dane.txt");
					pause();
				}

				if (number == 2) {
					
					if (user_list) {
						user_list->View();
					}
					else {
						std::cout << "Nie utworzono zadnej listy\n";
					}
					pause();
				}

				if (number == 3) {
					
					for (;;) { // ----- Petla operacji listy -----
						number = structureOperationMenu();

						if (number == 1) {
							int key = 0;
							int index = 0;

							std::cout << "Jaka liczbe chcesz dodac?\n->";
							std::cin >> key;

							if (std::cin.good()) {
								std::cin.clear();
								std::cout << "Za jaka liczba chcesz ja wstawic?\n->";
								std::cin >> index;

								if (std::cin.good()) {
									user_list->AddToPlace(key, index);
									std::cout << "Poprawnie dodano!\n";
									pause();
								}
								else {
									std::cout << "Podales nieprawidlowa wartosc!\n Sprobuj ponownie!\n";
									pause();
								}
							}
							else {
								std::cout << "Podales nieprawidlowa wartosc!\n Sprobuj ponownie!\n";
								pause();
							}
							std::cin.clear();
						}

						if (number == 2) {
							int key = 0;
							std::cout << "Jaka liczbe chcesz usunac?\n->";
							std::cin >> key;

							if (std::cin.good()) {
								if (user_list->DeleteValue(key)) {
									std::cout << "Poprawnie usunieto!\n";
								}
								else {
									std::cout << "Nie ma takiego klucza\n";
								}
								pause();
							}
							else {
								std::cout << "Podales nieprawidlowa wartosc!\n Sprobuj ponownie!\n";
								pause();
							}
							std::cin.clear();
						}

						if (number == 3) {
							int key = 0;
							std::cout << "Jaka liczbe chcesz wyszukac?\n->";
							std::cin >> key;
							if (std::cin.good()) {

								if (user_list->Search(key)) {
									std::cout << "Taki klucz istnieje w liscie\n";
								}
								else {
									std::cout << "Nie ma takiego klucza w liscie\n";
								}
								pause();
							}
							else {
								std::cout << "Podales nieprawidlowa wartosc!\n Sprobuj ponownie!\n";
								pause();
							}
							std::cin.clear();
						}

						if (number == 0)
							break;
					}
					continue;
				}

				if (number == 0) {
					break;
				}
			}
			break;
		case 3:

			for (;;) { // ----- Petla kopca -----
				std::cout << "Wybrales kopiec:\n";
				system("cls");

				if (user_heap) {
					std::cout << "Aktualnie kopiec ma rozmiar: " << user_heap->GetSize() << "\n\n";
				}

				number = heapMenu();

				if (number == 1) {					
					user_heap = new Heap("dane.txt");
					pause();
				}

				if (number == 2) {
					
					if (user_heap) {
						user_heap->View("","",0);
					}
					else {
						std::cout << "Nie utworzono zadnego kopca\n";
					}
					pause();
				}

				if (number == 3) {

					for (;;) { // ----- Petla operacji kopca -----
						number = structureOperationMenu();

						if (number == 1) {
							int key = 0;
							std::cout << "Jaka liczbe chcesz dodac?\n->";
							std::cin >> key;

							if (std::cin.good()) {
								user_heap->Add(key);
								std::cout << "Poprawnie dodano!\n";
								pause();
							}
							else {
								std::cout << "Podales nieprawidlowa wartosc!\n Sprobuj ponownie!\n";
								pause();
							}
							std::cin.clear();
						}

						if (number == 2) {
							int key = 0;
							std::cout << "Jaka liczbe chcesz usunac?\n->";
							std::cin >> key;

							if (std::cin.good()) {
								user_heap->Delete(key);
								std::cout << "Poprawnie usunieto!\n";
								pause();
							}
							else {
								std::cout << "Podales nieprawidlowa wartosc!\n Sprobuj ponownie!\n";
								pause();
							}
							std::cin.clear();
						}

						if (number == 3) {
							int key = 0;
							std::cout << "Jaka liczbe chcesz wyszukac?\n->";
							std::cin >> key;
							if (std::cin.good()) {
								
								if (user_heap->Search(key)) {
									std::cout << "Taki klucz istnieje w drzewie\n";
								}
								else {
									std::cout << "Nie ma takiego klucza w drzewie\n";
								}
								pause();
							}
							else {
								std::cout << "Podales nieprawidlowa wartosc!\n Sprobuj ponownie!\n";
								pause();
							}
							std::cin.clear();
						}

						if (number == 0)
							break;
					}
					continue;
				}

				if (number == 0) {
					break;
				}
			}
			break;
		case 4:

			for (;;) { // ----- Petla drzewa RBT -----
				std::cout << "Wybrales drzewo czerwono-czarne\n";
				system("cls");

				if (user_rbt) {
					std::cout << "Aktualnie drzewo ma rozmiar: " << user_rbt->GetSize() << "\n\n";
				}

				number = rbtMenu();

				if (number == 1) {
					//wczytaj z pliku
					user_rbt = new RedBlackTree("dane.txt");
					pause();
				}

				if (number == 2) {
					
					if (user_rbt) {
						timer->StartTimer();
						user_rbt->View("", "", user_rbt->GetRoot());
						timer->EndTimer();
						timer->CalculateAndPrintTime();
					}
					else {
						std::cout << "Nie utworzono zadnego drzewa\n";
					}
					pause();
				}

				if (number == 3) {
					
					for (;;) { // ----- Petla operacji RBT -----
						number = structureOperationMenu();

						if (number == 1) {
							int key = 0;
							std::cout << "Jaka liczbe chcesz dodac?\n->";
							std::cin >> key;

							if (std::cin.good()) {
								timer->StartTimer();
								user_rbt->AddElement(key);
								std::cout << "Poprawnie dodano!\n";
								timer->EndTimer();
								timer->CalculateAndPrintTime();
								pause();
							}
							else {
								std::cout << "Podales nieprawidlowa wartosc!\n Sprobuj ponownie!\n";
								pause();
							}
							std::cin.clear();
						}

						if (number == 2) {
							int key = 0;
							std::cout << "Jaka liczbe chcesz usunac?\n->";
							std::cin >> key;

							if (std::cin.good()) {
								user_rbt->DeleteElement(user_rbt->Find(key));
								std::cout << "Poprawnie usunieto!\n";
								pause();
							}
							else {
								std::cout << "Podales nieprawidlowa wartosc!\n Sprobuj ponownie!\n";
								pause();
							}
							std::cin.clear();
						}

						if (number == 3) {
							int key = 0;
							std::cout << "Jaka liczbe chcesz wyszukac?\n->";
							std::cin >> key;
							if (std::cin.good()) {
								
								if (user_rbt->Find(key)) {
									std::cout << "Taki klucz istnieje w drzewie\n";
								}
								else {
									std::cout << "Nie ma takiego klucza w drzewie\n";
								}
								pause();
							}
							else {
								std::cout << "Podales nieprawidlowa wartosc!\n Sprobuj ponownie!\n";
								pause();
							}
							std::cin.clear();
						}

						if (number == 0)
							break;
					}
					continue;
				}

				if (number == 0)
					break;
			}
			break;
		case 5:
			std::cout << "Wybrales generowanie danych\n";
			array = generateData(size, array);
			saveToFile(size, array);
			pause();
			break;
		case 0:
			exit = true;
			break;
		default:
			std::cout << "Cos poszlo nie tak, sprobuj ponownie!\n";
			break;
		}

	}

	pause();
	return 0;
}

	// ----- Funkcje -----

int mainMenu() {
	int number;

	std::cout << "Wybierz z menu:\n";
	std::cout << "1) Tablica\n";
	std::cout << "2) Lista\n";
	std::cout << "3) Kopiec\n";
	std::cout << "4) Drzewo czerwono-czarne\n\n";
	std::cout << "5) Wygeneruj i zapisz dane do pliku\n";
	std::cout << "\n0) Wyjscie\n";
	std::cout << "-------------------------\n->";
	std::cin >> number;

	if (std::cin.fail()) {
		return -1;
	}

	if (number != 1 && number != 2 && number != 3 && number != 4 && number != 5 && number != 0) {
		return -1;
	}
	std::cin.clear();

	return number;
}

int arrayMenu() {
	int number;

	std::cout << "Wybierz menu:\n";
	std::cout << "1) Wczytaj Tablice z Pliku\n";
	std::cout << "2) Wyswietl Tablice\n";
	std::cout << "3) Operacje na Tablicy\n";
	std::cout << "\n0) Powrot\n";
	std::cout << "-------------------------\n->";
	std::cin >> number;

	if (std::cin.fail()) {
		return -1;
	}

	if (number != 1 && number != 2 && number != 3 && number != 4 && number != 0) {
		return -1;
	}
	std::cin.clear();

	return number;
}

int listMenu() {
	int number;

	std::cout << "Wybierz menu:\n";
	std::cout << "1) Wczytaj Liste z Pliku\n";
	std::cout << "2) Wyswietl Liste\n";
	std::cout << "3) Operacje na Liscie\n";
	std::cout << "\n0) Powrot\n";
	std::cout << "-------------------------\n->";
	std::cin >> number;

	if (std::cin.fail()) {
		return -1;
	}

	if (number != 1 && number != 2 && number != 3 && number != 4 && number != 0) {
		return -1;
	}
	std::cin.clear();

	return number;
}

int heapMenu() {
	int number;

	std::cout << "Wybierz menu:\n";
	std::cout << "1) Wczytaj Kopiec z Pliku\n";
	std::cout << "2) Wyswietl Kopiec\n";
	std::cout << "3) Operacje na Kopcu\n";
	std::cout << "\n0) Powrot\n";
	std::cout << "-------------------------\n->";
	std::cin >> number;

	if (std::cin.fail()) {
		return -1;
	}

	if (number != 1 && number != 2 && number != 3 && number != 4 && number != 0) {
		return -1;
	}
	std::cin.clear();

	return number;
}

int rbtMenu() {
	int number;

	std::cout << "Wybierz menu:\n";
	std::cout << "1) Wczytaj Drzewo z Pliku\n";
	std::cout << "2) Wyswietl Drzewo\n";
	std::cout << "3) Operacje na Drzewie\n";
	std::cout << "\n0) Powrot\n";
	std::cout << "-------------------------\n->";
	std::cin >> number;

	if (std::cin.fail()) {
		return -1;
	}

	if (number != 1 && number != 2 && number != 3 && number != 4 && number != 0) {
		return -1;
	}
	std::cin.clear();

	return number;
}

int *generateData(int &size, int *array) {

	std::cout << "Jak duzy ma byc zbior elementow?: ";
	std::cin.clear();
	std::cin >> size;

	array = new int[size];
	srand((unsigned int)time(NULL));
	std::cout << "Wylosowano:\n";

	for (int i = 0; i < size; ++i) {
		array[i] = rand() % 10000 + 1;
		std::cout << array[i] << '\n';
	}

	return array;
}

void saveToFile(int size, int array[]) {
	std::fstream file;
	file.open("dane.txt", std::ios::out);

	if (file.good()) {
		file << size;
		file << '\n';

		for (int i = 0; i < size; ++i) {
			file << array[i];
			file << '\n';
		}

		std::cout << "-->  Udalo sie zapisac do pliku!  <--\n";
	}
	else {
		std::cout << "--> BLAD ZAPISU <--";
	}

	file.close();
}

void pause() {
	std::cout << "\n\n. . . wcisnij ENTER, aby kontynuowac . . .\n";
	std::cin.get();
	std::cin.get();
}

int arrayOperationMenu() {
	// ===== TODO ===== !!!!!!!!!!!!!!!
	return 0;
}

int listOperationMenu() {
	// ===== TODO ===== !!!!!!!!!!!!!!!
	return 0;
}

int structureOperationMenu() {
	int number;

	system("cls");
	std::cout << "Wybierz z menu:\n";
	std::cout << "1) Dodaj Element\n";
	std::cout << "2) Usun Element\n";
	std::cout << "3) Wyszukaj Element\n";
	std::cout << "0) Powrot\n";
	std::cout << "-------------------------\n->";
	std::cin >> number;

	if (std::cin.fail()) {
		return -1;
	}

	if (number != 1 && number != 2 && number != 3 && number != 0) {
		return -1;
	}
	std::cin.clear();

	return number;
}