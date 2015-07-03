#include "List.h"

int main()
{
	auto a = List();
	a.Add(123);
	a.Add(256);
	a.Add(1234);
	a.GetItem(2);
										  
	auto tmp = new item();
	tmp->data = 3;
	a.insert(tmp, 2);
	a.View();
	system("PAUSE");
}