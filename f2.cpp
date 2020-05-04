#include "f2.h"

int f2::ex2(int argc, LPTSTR argv[]) {
	int const MAX = 300;
	int const TAM = MAX + 100;
	HKEY chave;
	TCHAR chave_nome[TAM], chave_input[MAX], chave_prefix[100] = TEXT("Software\\AULA\\");
	_tprintf(TEXT("Qual chave quer verificar?\n"));
	_fgetts(chave_input, TAM, stdin);
	int size = _tcslen(chave_input);
	chave_input[size - 1] = TEXT('\0');

	_stprintf_s(chave_nome, TAM, TEXT("%s%s"), chave_prefix, chave_input);

	if (ERROR_SUCCESS != RegOpenKey(HKEY_CURRENT_USER, chave_nome, &chave)) {
		_tprintf(TEXT("N�o consigo abrir este a chave %s. Irei criar uma nova chave.\n"), chave_nome);
		if (ERROR_SUCCESS != RegCreateKey(HKEY_CURRENT_USER, chave_nome, &chave)) {
			_tprintf(TEXT("Chave nao foi criada omega oof.\n"));
			return 1;
		}
		else {
			_tprintf(TEXT("Chave criada com sucessu nya.\n"));
		}
	}
	else {
		_tprintf(TEXT("Chave aberta com sucessu nya.\n"));
	}


	RegCloseKey(chave);
	return 0;
}