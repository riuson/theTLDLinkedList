#pragma once
#include "Item.h"


class List{
private:
	item* head;
	item* tail;
public:
	List();
	void Add(int data);
	void Delete(int index_i);
	item GetItem(int index);
	item Remove(int index);
	void insert(item* data, int index);
	int Coutn();
	void Clear();
	int GetIndex(item * data);
	void View();
	~List();
};


