#include "List.h"


List::List()
{
    this->_head = nullptr;
    this->_tail = nullptr;
}

void List::Add(int data)
{
    if (this->_head == nullptr) {
        Item *newnode = new Item();
        newnode->data = data;

        this->_head = newnode;
        this->_head->data = data;
        this->_tail = this->_head;

        std::cout << "head = " << data << std::endl;
    } else {
        Item *newnode = new Item();
        newnode->data = data;

        newnode->prev = this->_tail;
        this->_tail->next = newnode;
        this->_tail = newnode;

        std::cout << "add = " << data << std::endl;
    }
}

void List::Remove(int index_i)
{
    Item *tmp = this->GetItem(index_i);

    if (tmp == nullptr) {
        return;
    }

    Item *prev = tmp->prev;
    Item *next = tmp->next;

    if (tmp == this->_head) {
        this->_head = next;
    }

    if (tmp == this->_tail) {
        this->_tail = prev;
    }

    if (prev != nullptr) {
        prev->next = next;
    }

    if (next != nullptr) {
        next->prev = prev;
    }

    std::cout << "delete = " << tmp->data << std::endl;

    delete tmp;
}

Item *List::GetItem(int index_i)
{
    Item *tmp = this->_head;

    for (int i = 0; (i < index_i) && (tmp != nullptr); i++) {
        tmp = tmp->next;
    }

    if (tmp == nullptr) {
        std::cout << index_i << "element not found" << std::endl;
        return tmp;
    }

    std::cout << index_i << "element =" << tmp->data << std::endl;
    return tmp;
}

void List::Insert(int data, int index_i)
{
    if (index_i < 0) {
        return;
    }

    Item *tmp = this->GetItem(index_i);

    if (tmp == nullptr) {
        this->Add(data);
        return;
    }

    Item *prev = tmp->prev;
    Item *next = tmp->next;

    Item *newItem = new Item();
    newItem->data = data;
    newItem->next = next;
    newItem->prev = prev;

    if (prev != nullptr) {
        prev->next = newItem;
    } else {
        this->_head = newItem;
    }

    if (next != nullptr) {
        next->prev = newItem;
    } else {
        this->_tail = newItem;
    }
}

int List::Count()
{
    int count_i = 0;
    Item *tmp = this->_head;

    while (tmp != nullptr) {
        tmp = tmp->next;
        count_i++;
    };

    return count_i;
}

void List::Clear()
{
    Item *tmp = this->_head;
    this->_head = nullptr;
    this->_tail = nullptr;

    while (tmp != nullptr) {
        Item *del = tmp;
        tmp = tmp->next;

        std::cout  << "delete element = " << del->data << std::endl;

        delete del;
    }
}

int List::GetIndex(Item *data)
{
    if (this->_head == nullptr) {
        return -1;
    }

    if (data == nullptr) {
        return -1;
    }

    Item *tmp = this->_head;
    int count_i = 0;

    while (tmp != nullptr) {
        if (tmp == data) {
            return count_i;
        }

        tmp = tmp->next;
        count_i++;
    }

    return -1;
}

void List::View()
{
    std::cout << "ALL = " << std::endl;

    if (this->_head == nullptr) {
        std::cout << "empty" << std::endl;
        return;
    }

    Item *tmp = this->_head;

    while (tmp != nullptr) {
        std::cout << tmp->data << std::endl;
        tmp = tmp->next;
    }
}

List::~List()
{
    this->Clear();
}
