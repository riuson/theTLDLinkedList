#pragma once
#include "Item.h"


class List
{
private:
    item *head;
    item *tail;
public:
    List();
    void Add(int data);
    void Remove(int index_i);
    item *GetItem(int index);
    void insert(item *data, int index);
    int Coutn();
    void Clear();
    int GetIndex(item *data);
    void View();
    ~List();
};
