#include "GarlandService.h"
#include <tchar.h>
#include <Windows.h>
#include "Garland.h"

int main(int argc, TCHAR** argv) {
	GarlandService::start(const_cast<TCHAR*>(TEXT("NewYearGarland")));
	return 0;
}
