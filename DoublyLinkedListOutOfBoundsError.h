//
// Created by mfbut on 11/24/2019.
//

#ifndef TESTDOUBLELINKEDLIST_DOUBLYLINKEDLISTOUTOFBOUNDSERROR_H
#define TESTDOUBLELINKEDLIST_DOUBLYLINKEDLISTOUTOFBOUNDSERROR_H
#include "DoublyLinkedListError.h"
class DoublyLinkedListOutOfBoundsError : public DoublyLinkedListError {
public:
    //Insert when out of bounds
    //Index being inserted is larger than size-1
    const char* what() const noexcept override{
        return "Error: Out of Bounds";
    }
};

#endif //TESTDOUBLELINKEDLIST_DOUBLYLINKEDLISTOUTOFBOUNDSERROR_H
