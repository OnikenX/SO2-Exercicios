#include "f5.h"

#define _CRT_SECURE_NO_WARNINGS // Thanks Microsoft

int f5::ex2() {

	// matriz de handles das threads
	HANDLE hThreads[MAX_THREADS];
	// Matriz de dados para as threads;
	TDados tdados[MAX_THREADS];
	// número efectivo de threads
	int numthreads;
	// limite superior
	unsigned int limsup;
	// variáveis para cronómetro
	__int64 clockticks;
	double duracao;
	unsigned int range;
	unsigned int inter;

	initClock();
	_tprintf(TEXT("\nLimite sup. -> "));
	_tscanf_s(TEXT("%u"), &limsup);
	_tprintf(TEXT("\nNum threads -> "));
	_tscanf_s(TEXT("%u"), &numthreads);
	if (numthreads > MAX_THREADS)
		numthreads = MAX_THREADS;
	// FAZER prepara e cria threads
	//
	//manda as threads começar
		clockticks = startClock();
	// FAZER aguarda / controla as threads
	//
	//manda as threads parar
		duracao = stopClock(clockticks);
	_tprintf(TEXT("\nSegundos=%f\n"), duracao);
	// FAZER apresenta resultados
	// Cód. ref. para aguardar por uma tecla – caso faça falta
	// _tprintf(TEXT("\nCarregue numa tecla"));
	// _gettch();
	return 0;
};


void f5::initClock() {
	LARGE_INTEGER aux;
	if (!QueryPerformanceFrequency(&aux))
		_tprintf(TEXT("\nSorry - No can do em QueryPerfFreq\n"));
	PerfCounterFreq = (double)(aux.QuadPart); // / 1000.0;
	_tprintf(TEXT("\nTicks por sec.%f\n"), PerfCounterFreq);
}

__int64 f5::startClock() {
	LARGE_INTEGER aux;
	QueryPerformanceCounter(&aux);
	return aux.QuadPart;
}
double f5::stopClock(__int64 from) {
	LARGE_INTEGER aux;
	QueryPerformanceCounter(&aux);
	return (double)(aux.QuadPart - from) / PerfCounterFreq;
}
