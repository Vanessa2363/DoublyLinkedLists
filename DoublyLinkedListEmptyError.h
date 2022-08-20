//
// Created by mfbut on 11/24/2019.
//

#ifndef TESTDOUBLELINKEDLIST_DOUBLYLINKEDLISTEMPTYERROR_H
#define TESTDOUBLELINKEDLIST_DOUBLYLINKEDLISTEMPTYERROR_H
#include "DoublyLinkedListError.h"

//Throws errors
//Grab something and list is empty
class DoublyLinkedListEmptyError : public DoublyLinkedListError {
    const char* what() const noexcept override{
        return "Error: List is Empty";
    }
};



#endif //TESTDOUBLELINKEDLIST_DOUBLYLINKEDLISTEMPTYERROR_H
