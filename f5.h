#pragma once

#include "includes.h"

#define _CRT_SECURE_NO_WARNINGS // Thanks Microsoft

// estrutura de dados para controlar as threads
typedef struct {
	// ...
	int x; // remover este inteiro. Est� aqui apenas para este c�digo compilar
} TDados;
// fun��o da(s) thread(s)
// ...
// n�mero * m�ximo * de threads
// podem (e devem) ser menos

class f5
{
public:
	// funcionalidade relacionada com temporiza��o
	double PerfCounterFreq; // n ticks por seg.

	void initClock();
	__int64 startClock();
	double stopClock(__int64 from);

public:
	int ex2();
};


#define MAX_THREADS 20