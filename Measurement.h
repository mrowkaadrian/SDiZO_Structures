#pragma once
#include <windows.h>

namespace Mrowka {

	class Measurement
	{
		double _PCFreq;
		__int64 _CounterStart;
		double _time;

	public:

		Measurement();
		~Measurement();
		void StartTimer();
		void EndTimer();
		double ReturnTime();

	};

}