#include "GarlandService.h"
#include <tchar.h>
#include <Windows.h>
#include "Garland.h"

#pragma comment(lib,"MessageDLL")

/*
int main(int argc, TCHAR** argv) {
	Garland newGarland;
	newGarland.start();
	return 0;
} */


int main(int argc, TCHAR** argv) {
	GarlandService::start(const_cast<TCHAR*>(TEXT("NewYearGarland")));
	return 0;
} 

