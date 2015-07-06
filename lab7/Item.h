#include <iostream>

struct Item {
    int data;
    Item *next = nullptr;
    Item *prev = nullptr;

    Item()
    {
        this->next = nullptr;
        this->prev = nullptr;
        this->data = 0;
    }
};
