#pragma once
#include "Item.h"


class List
{
private:
    Item *_head;
    Item *_tail;
public:
    List();
    void Add(int value);
    void Remove(int index);
    Item *GetItem(int index);
    void Insert(int value, int index);
    int Count();
    void Clear();
    int GetIndex(Item *data);
    void View();
    ~List();
};
