#include "List.h"


List::List()
{

    head = nullptr;
    tail = nullptr;
}

void List::Add(int data)
{
    if (head == nullptr) {
        head = new item();
        head->data = data;
        head->next = head;
        head->prev = head;
        tail = head;
        std::cout << "head = " << data << std::endl;
    } else {
        item *newnode = new item();
        newnode->data = data;
        tail->next = newnode;
        std::cout << "add = " << data << std::endl;
        tail = tail->next;
        tail->next = head;
        tail->prev = head;
    }
}

void List::Delete(int index_i)
{
    if (head == nullptr ) {
        return;
    }

    if (head->next == head) {
        delete head;
        head = nullptr;
    } else {
        item *tmp = head;

        for (int i = index_i; i > 1; i--, tmp = tmp->next);

        tmp->prev->next = tmp->next;
        tmp->next->prev = tmp->prev;
        int k = tmp->data;
        std::cout << "delete = " << k << std::endl;
        delete tmp;
    }
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

item List::Remove(int index_i)
{
    //if (head == nullptr) return ;
    if (head->next == head) {
        return *head;
    } else {
        item *tmp = head;

        for (auto i = index_i; i > 1; i--, tmp = tmp->next);

        tmp->prev->next = tmp->next;
        tmp->next->prev = tmp->prev;
        int k = tmp->data;
        std::cout << "delete = " << k << std::endl;
        //delete tmp;
        return *tmp;
    }
}

void List::insert(item *data, int index_i)
{
    item *tmp = head;

    for (int i = index_i; i > 1; i--, tmp = tmp->next);

    data->next = tmp->next;
    data->prev = tmp;
    tmp->next = data;
}

int List::Coutn()
{
    int coutn_i = 0;

    if (head == nullptr) {
        return 0;
    }

    item *tmp = head;

    do {
        coutn_i++;
        tmp = tmp->next;
    } while (tmp != head);

    return coutn_i;
}

void List::Clear()
{
    if (head == nullptr) {
        return;
    }

    for (item *tmp = head->next; tmp != head; tmp = tmp->next) {
        delete tmp;
    }

    delete head;
    head = nullptr;
}

int List::GetIndex(item *data)
{
    if (head == nullptr) {
        return 0;
    }

    item *tmp = head;
    int coutn_i = 1;

    do {
        if (tmp == data) {
            return coutn_i;
        }

        tmp = tmp->next;
        coutn_i++;
    } while (tmp != tail);

    return 0;
}

void List::View()
{
    std::cout << "ALL =" << std::endl;

    if (head == nullptr) {
        return;
    }

    item *tmp = head;

    do {
        std::cout << tmp->data << std::endl;
        tmp = tmp->next;
    } while (tmp != head);
}

List::~List()
{
    while (head != tail) {
        item *tmp = head;
        std::cout << "delete " << tmp->data << std::endl;
        head = head->next;
        delete tmp;
    }

    item *tmp = head;
    std::cout << "delete " << tmp->data << std::endl;
    delete tmp;
    head = nullptr;
    tail = nullptr;
}
