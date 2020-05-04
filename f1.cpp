#include "f1.h"



int f1::ex1a(int argc, LPTSTR argv[])
{
	const int MAX = 256;
	TCHAR str[MAX], result[MAX] = TEXT("Olá! Este programa é para aceitar UNICODE. Insira \'fim\' para sair\n");
	unsigned int i, size;
	//UNICODE: Por defeito, a consola Windows não processacaracteres wide. 
	//A maneira mais fácil para ter esta funcionalidade é chamar _setmode:

	do {
		_tprintf(result);
		fflush(stdin);
		_fgetts(str, MAX, stdin);
		//Retirar \nstr[_tcslen(str) -1] = '\0';
		//Maiúsculas

		size = _tcslen(str);
		str[size - 1] = TEXT('\0');
		for (i = 0; i < size; ++i)
			str[i] = _totupper(str[i]);

		_stprintf_s(result, MAX, TEXT("Frase:%s, Tamanho:%d\n"), str, _tcslen(str));

	} while (_tcsicmp(TEXT("FIM"), str));
	return 0;
}


int f1::ex5d(int argc, LPTSTR argv[])
{
	const int MAX = 1000;
	/*
	#ifdef UNICODE
		_setmode(_fileno(stdin), _O_WTEXT);
		_setmode(_fileno(stdout), _O_WTEXT);
	#endif
	*/
	//TCHAR path[MAX]=TEXT("notepad miau.txt");
	TCHAR path[MAX];
	TCHAR numchar[MAX] = {};
	int numint;

	GetModuleFileName(NULL, path, MAX);

	if (argc > 1)
		numint = _tcstof(argv[1], NULL) - 1;
	else
		numint = 4;
	if (numint != 0) {
		_stprintf_s(path, MAX, TEXT("%s %d"), path, numint);
		_tprintf_s(path);
		_tprintf_s(TEXT("\n"));
		STARTUPINFO info = { sizeof(info) };
		PROCESS_INFORMATION processInfo;
		//HANDLE handle = 
		CreateProcess(NULL, path, NULL, NULL, FALSE, 0, NULL, NULL, &info, &processInfo);
		//WaitForSingleObject(handle, INFINITE);
		_tprintf_s(TEXT("Vou terminar.\n"));
	}

	return 0;
}
