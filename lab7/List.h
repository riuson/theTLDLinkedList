#pragma once
#include "Item.h"


class List
{
private:
    Item *_head;
    Item *_tail;

public:
    List();
    ~List();

    void Add(int value);
    bool Remove(int index);
    Item *GetItem(int index);
    bool Insert(int value, int index);
    int Count();
    void Clear();
    int GetIndex(Item *data);
    void View();
};
