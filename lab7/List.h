#pragma once
#include "Item.h"


class List
{
private:
    item *_head;
    item *_tail;
public:
    List();
    void Add(int data);
    void Remove(int index_i);
    item *GetItem(int index);
    void Insert(int data, int index);
    int Count();
    void Clear();
    int GetIndex(item *data);
    void View();
    ~List();
};
