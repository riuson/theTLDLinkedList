#include "List.h"


List::List()
{

    head = nullptr;
    tail = nullptr;
}

void List::Add(int data)
{
    if (head == nullptr) {
        item *newnode = new item();
        newnode->data = data;

        head = newnode;
        head->data = data;
        tail = head;

        std::cout << "head = " << data << std::endl;
    } else {
        item *newnode = new item();
        newnode->data = data;

        newnode->prev = tail;
        tail->next = newnode;
        tail = newnode;

        std::cout << "add = " << data << std::endl;
    }
}

void List::Remove(int index_i)
{
    item *tmp = this->GetItem(index_i);

    if (tmp == nullptr) {
        return;
    }

    item *prev = tmp->prev;
    item *next = tmp->next;

    if (tmp == head) {
        head = next;
    }

    if (tmp == tail) {
        tail = prev;
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

item *List::GetItem(int index_i)
{
    item *tmp = head;

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

    item *tmp = this->GetItem(index_i);

    if (tmp == nullptr) {
        this->Add(data);
        return;
    }

    item *prev = tmp->prev;
    item *next = tmp->next;

    item *newItem = new item();
    newItem->data = data;
    newItem->next = next;
    newItem->prev = prev;

    if (prev != nullptr) {
        prev->next = newItem;
    } else {
        head = newItem;
    }

    if (next != nullptr) {
        next->prev = newItem;
    } else {
        tail = newItem;
    }
}

int List::Count()
{
    int count_i = 0;
    item *tmp = head;

    while (tmp != nullptr) {
        tmp = tmp->next;
        count_i++;
    };

    return count_i;
}

void List::Clear()
{
    item *tmp = head;
    this->head = nullptr;
    this->tail = nullptr;

    while (tmp != nullptr) {
        item *del = tmp;
        tmp = tmp->next;

        std::cout  << "delete element = " << del->data << std::endl;

        delete del;
    }
}

int List::GetIndex(item *data)
{
    if (head == nullptr) {
        return -1;
    }

    if (data == nullptr) {
        return -1;
    }

    item *tmp = head;
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

    if (head == nullptr) {
        std::cout << "empty" << std::endl;
        return;
    }

    item *tmp = head;

    while (tmp != nullptr) {
        std::cout << tmp->data << std::endl;
        tmp = tmp->next;
    }
}

List::~List()
{
    this->Clear();
}
