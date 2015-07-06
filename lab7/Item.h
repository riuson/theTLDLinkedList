#include <iostream>

struct item {
    int data;
    item *next = nullptr;
    item *prev = nullptr;

    item()
    {
        this->next = nullptr;
        this->prev = nullptr;
        this->data = 0;
    }
};
