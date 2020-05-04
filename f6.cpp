#include "f6.h"


 int f6::ex2() {

	 HANDLE hMapFile;
	 HANDLE hFich;
	 char* pBuf; // 8 bit chars
	 char aux;

	 _tprintf(TEXT("File Inverter - 8 bits chars\n"));
	 _tprintf(TEXT("CreateFile\n"));

	 hFich = CreateFile(FILENAME,
		 GENERIC_READ | GENERIC_WRITE,
		 FILE_SHARE_READ | FILE_SHARE_WRITE,
		 NULL,
		 OPEN_EXISTING,
		 FILE_ATTRIBUTE_NORMAL,
		 NULL
	 );

	 if (hFich == INVALID_HANDLE_VALUE) {
		 _tprintf(TEXT("Error: CreateFile(%d)\n"), GetLastError());
		 return 1;
	 };
	 
	 _tprintf(TEXT("CreateFileMapping\n"));

	 hMapFile = CreateFileMapping(
		 hFich,
		 NULL,
		 PAGE_READWRITE,
		 0,
		 NUMBER_LETTERS,
		 NULL);

	 if (hMapFile == NULL) {
		 _tprintf(TEXT("Error: CreateFileMapping(%d)\n"), GetLastError());
		 CloseHandle(hFich);
		 return 1;
	 }
	 
	 _tprintf(TEXT("MapViewOfFile\n"));

	 pBuf = (char*)MapViewOfFile(
		 hMapFile,
		 FILE_MAP_READ | FILE_MAP_WRITE,
		 0,
		 0,
		 NUMBER_LETTERS);
	 
	 if (pBuf == NULL) {
		 _tprintf(TEXT("Error: MapViewOfFile (%d)\n"), GetLastError());
		 CloseHandle(hMapFile);
		 CloseHandle(hFich);
		 return 1;
	 }


	_tprintf(TEXT("Updating file in memory\n"));

	for (unsigned int i = 0; i < NUMBER_LETTERS / 2; ++i) {
		aux = pBuf[i];
		pBuf[i] = pBuf[NUMBER_LETTERS - 1 - i];
		pBuf[NUMBER_LETTERS - 1 - i] = aux;
	}

	_tprintf(TEXT("Showing inverted file contents\n"));

	for (unsigned int i = 0; i < NUMBER_LETTERS; ++i) 
		_tprintf(TEXT("%c"), (TCHAR)pBuf[i]);
	
	_tprintf(TEXT("\nDone\n"));

	UnmapViewOfFile(pBuf);

	CloseHandle(hMapFile);
	CloseHandle(hFich);

	return 0;
}

 int f6::ex3(void) {
	
	 HANDLE hMapFile;
	 int MEMORYSIZE = sizeof(int) * 10;

	 _tprintf(TEXT("CreateFileMapping\n"));

	 hMapFile = CreateFileMapping(
		 INVALID_HANDLE_VALUE, //Cria memoria partilhada sem ligacao a qualquer ficheiro
		 NULL,	
		 PAGE_READWRITE,
		 0,
		 sizeof(int)*10,
		 TEXT("SO2_procon"));

	 if (hMapFile == NULL) {
		 _tprintf(TEXT("Error: CreateFileMapping(%d)\n"), GetLastError());
		 return 1;
	 }

	 _tprintf(TEXT("Clique em qualquer tecla para parar a partilha de memoria SO2_procon"));
	 _gettchar();
	 CloseHandle(hMapFile);
	 
	 return 0;
 }