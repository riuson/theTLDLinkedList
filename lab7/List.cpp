#include "List.h"


List::List()
{
    this->_head = nullptr;
    this->_tail = nullptr;
}

void List::Add(int value)
{
    if (this->_head == nullptr) {
        Item *newnode = new Item();
        newnode->data = value;

        this->_head = newnode;
        this->_tail = this->_head;

        std::cout << "head = " << newnode->data << std::endl;
    } else {
        Item *newnode = new Item();
        newnode->data = value;

        newnode->prev = this->_tail;
        this->_tail->next = newnode;
        this->_tail = newnode;

        std::cout << "add = " << newnode->data << std::endl;
    }
}

bool List::Remove(int index)
{
    Item *tmp = this->GetItem(index);

    if (tmp == nullptr) {
        return false;
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

    return true;
}

Item *List::GetItem(int index)
{
    Item *tmp = this->_head;

    for (int i = 0; (i < index) && (tmp != nullptr); i++) {
        tmp = tmp->next;
    }

    if (tmp == nullptr) {
        std::cout << index << "element not found" << std::endl;
        return tmp;
    }

    std::cout << index << "element =" << tmp->data << std::endl;
    return tmp;
}

bool List::Insert(int value, int index)
{
    if (index < 0) {
        return false;
    }

    Item *tmp = this->GetItem(index);

    if (tmp == nullptr) {
        this->Add(value);
        return true;
    }

    Item *prev = tmp->prev;
    Item *next = tmp->next;

    Item *newItem = new Item();
    newItem->data = value;
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

    return true;
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
