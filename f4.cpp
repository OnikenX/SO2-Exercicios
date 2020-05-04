#include "f4.h"

int f4::ex2(int argc, LPTSTR argv[]) {

	DWORD threadId = 0;
	HANDLE hTPares = NULL, hTPrimos = NULL;
	int MAX = 50;
	hTPares = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ThreadPares, &MAX, 0, &threadId);
	hTPrimos= CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ThreadPrimos, &MAX, 0, &threadId);
	//hTpares = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)myThread,  
	if (hTPares != NULL)
		_tprintf(TEXT("A thread foi criada.1\n"));
	else
		_tprintf(TEXT("A thread não foi criada.1\n"));

	if (hTPrimos != NULL)
		_tprintf(TEXT("A thread foi criada.2\n"));
	else
		_tprintf(TEXT("A thread não foi criada.2\n"));

	HANDLE hThreads[2];
	hThreads[0] = hTPares;  
	hThreads[1] = hTPrimos;
	
	
	DWORD returnedvalue = 0;
	DWORD tEnded = 0;


	do {

		returnedvalue = WaitForMultipleObjects(2, hThreads, TRUE, INFINITE);
		tEnded = returnedvalue - WAIT_OBJECT_0;
		switch (returnedvalue) {
			
		}

	} while (1);


	//if (!CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)myThread, NULL, 0, NULL)) {
	//	_tprintf(TEXT("A thread não foi criada.\n"));

	return 0;
}


DWORD WINAPI ThreadPrimos(LPVOID param) {
	int i = 2;
	Sleep(5000);
	int contador = 1;
	const int MAX = *(int*)param;
	_tprintf(TEXT("O número %d é primo.\n"), i);
	for (i = 3; i <= MAX; ++i)
		for (contador = 2; contador < i; ++contador) {
			if (i % contador)
				break;
			if (contador == i - 1)
				_tprintf(TEXT("O número %d é primo.\n"), i);
		}
	_tprintf(_TEXT("[Thread %d] Vou começar a trabalhar (cálculo de números pares)%d.\n"), GetCurrentThreadId(), i);
	ExitThread(0);
}

DWORD WINAPI ThreadPares(LPVOID param) {
	int i = 2;
	int contador = 1;
	Sleep(5000);
	const int MAX = *(int*)param;
	_tprintf(TEXT("O número %d é par.\n"), i);
	for (i = 3; i <= MAX; ++i) {
		if (i % contador)
			continue;
		_tprintf(TEXT("O número %d é par.\n"), i);
	}
	_tprintf(_TEXT("[Thread %d] Vou começar a trabalhar (cálculo de números pares)%d.\n"), GetCurrentThreadId(), i);
	ExitThread(0);

}