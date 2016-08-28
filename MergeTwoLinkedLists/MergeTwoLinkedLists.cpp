// MergeTwoLinkedLists.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

template <typename T>
struct Node
{
    Node()
    {
        next = nullptr;
    }

    Node(T val, Node* nextNode = nullptr)
    {
        value = val;
        next = nextNode;
    }

    T value;
    Node* next;
};

typedef Node<int> IntListNode;
typedef IntListNode* IntList;

IntList MergeTwoIntLists(IntList first, IntList second)
{
    if (first == nullptr || second == nullptr)
    {
        return first ? first : second;
    }

    IntList firstItr = first;
    IntList secondItr = second;
    IntList last = nullptr;
    IntList head = nullptr;

    while (firstItr && secondItr)
    {
        IntList choosed = nullptr;

        if (firstItr->value > secondItr->value)
        {
            choosed = secondItr;
            secondItr = secondItr->next;
        }
        else
        {
            choosed = firstItr;
            firstItr = firstItr->next;
        }

        choosed->next = nullptr;

        if (last)
        {
            last->next = choosed;
            last = choosed;
        }
        else
        {
            head = choosed;
            last = choosed;
        }
    }

    last->next = firstItr ? firstItr : secondItr;

    return head;
}

void PrintIntList(IntList intlist)
{
    while (intlist)
    {
        std::cout << intlist->value << " ";
        intlist = intlist->next;
    }

    std::cout << std::endl;
}

int main()
{
    IntList first = new IntListNode(4);
    first->next = new IntListNode(8);
    first->next->next = new IntListNode(10);
    first->next->next->next = new IntListNode(15);

    IntList second = new IntListNode(3);
    second->next = new IntListNode(5);
    second->next->next = new IntListNode(6);
    second->next->next->next = new IntListNode(9);

    PrintIntList(MergeTwoIntLists(first, second));

    return 0;
}

