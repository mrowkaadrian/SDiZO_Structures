#include <iostream>

#include "Measurement.h"

namespace Mrowka {

	Measurement::Measurement() {
		_time = 0;
		_PCFreq = 0.0;
		_CounterStart = 0;
	}

	Measurement::~Measurement() {

	}

	void Measurement::StartTimer() {
		LARGE_INTEGER li;
		if (!QueryPerformanceFrequency(&li))
			std::cout << "QueryPerformanceFrequency failed!\n";

		_PCFreq = double(li.QuadPart) / 1000.0;

		QueryPerformanceCounter(&li);
		_CounterStart = li.QuadPart;
	}

	void Measurement::EndTimer() {
		LARGE_INTEGER li;
		QueryPerformanceCounter(&li);
		_time = double(li.QuadPart - _CounterStart) / _PCFreq;
	}

	double Measurement::ReturnTime() {
		return _time;
	}

}