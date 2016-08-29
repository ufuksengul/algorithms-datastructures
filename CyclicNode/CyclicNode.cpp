// CyclicNode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

template <typename T>
struct Node
{
    T value;
    Node* next;
};

typedef Node<int> IntList;


IntList* ReturnCyclingNode(IntList* head)
{
    IntList* cyclingNode = nullptr;

    if (head)
    {
        IntList* fast = head;
        IntList* slow = head;

        bool cycleFound = false;

        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
            {
                fast = head;
                while (fast != slow)
                {
                    fast = fast->next;
                    slow = slow->next;
                }

                cyclingNode = fast;

                break;
            }
        }
    }

    return cyclingNode;
}


int main()
{
    IntList i1 = { 1, nullptr };
    IntList i2 = { 2, nullptr };
    IntList i3 = { 3, nullptr };
    IntList i4 = { 4, nullptr };
    IntList i5 = { 5, nullptr };
    IntList i6 = { 6, nullptr };
    IntList i7 = { 7, nullptr };
    IntList i8 = { 8, nullptr };
    i1.next = &i2;
    i2.next = &i3;
    i3.next = &i4;
    i4.next = &i5;
    i5.next = &i6;
    i6.next = &i7;
    i7.next = &i8;
    i8.next = &i5;

    ReturnCyclingNode(&i1);

    return 0;
}

