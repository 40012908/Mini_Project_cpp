#ifndef LIBRARY_STORE_H_INCLUDED
#define LIBRARY_STORE_H_INCLUDED
#include <vector>
#include <string>
#include "Book_Management.h"
#include "Member_Management.h"
#pragma once

using namespace std;

class Store
{
private:
    vector<Book *> books;
    vector<Member *> members;
    vector<Book *>Borrowedbook;
public:
    Store();
    ~Store();
    Member *findMemberbyID(string id);
    bool MemberExist(string id);
    Book *findBookbyISBN(string isbn);
    bool BookExists(string isbn);
    vector<Book *>getBooks();
    vector<Member *>getMembers();
    void AddBook(Book *book);
    void AddMember(Member *member);
};
#endif // LIBRARY_STORE_H_INCLUDED
