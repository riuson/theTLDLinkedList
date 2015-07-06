#pragma once
#include "Item.h"


class List
{
private:
    Item *_head;
    Item *_tail;
public:
    List();
    void Add(int data);
    void Remove(int index_i);
    Item *GetItem(int index);
    void Insert(int data, int index);
    int Count();
    void Clear();
    int GetIndex(Item *data);
    void View();
    ~List();
};
