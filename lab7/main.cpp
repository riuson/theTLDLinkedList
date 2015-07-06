#define _CRTDBG_MAP_ALLOC


#if defined(_DEBUG) && defined(_CRTDBG_MAP_ALLOC) && defined(__cplusplus) && !defined(_DEBUG_NEW)

#define _DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new _DEBUG_NEW

#include <crtdbg.h>

#endif




#include "List.h"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF | _CRTDBG_CHECK_ALWAYS_DF | _CRTDBG_DELAY_FREE_MEM_DF);
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDOUT);
	_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDOUT);

	auto a = new List();

	a->Add(123);
	a->Add(256);
	a->Add(1234);
	//a.GetItem(2);
	//
	//auto tmp = new item();
	//tmp->data = 3;
	//a.insert(tmp, 2);
	//a.View();
	delete a;
	system("PAUSE");
}
