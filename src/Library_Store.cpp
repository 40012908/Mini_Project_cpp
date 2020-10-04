#include <vector>
#include <string>
#include <algorithm>
#include "Book_Management.h"
#include "Member_Management.h"
#include "Library_store.h"

Store :: Store() {
    this->members = vector<Member *>();
    this->books = vector<Book *>(); }

Member *Store :: findMemberbyID(string id) {
    for(auto m=this->members.begin(); m!=this->members.end(); m++)
    {
      if((*m)->getId()==id)  {
        auto index=distance(this->members.begin(),m);
        return this->members.at(index);
      }
    }
    return NULL;
}
bool Store::MemberExist(string id)
{
    for(auto member_exist=this->members.begin(); member_exist!=this->members.end(); member_exist++)
    {
        if((*member_exist)->getId()==id)
        {
            return true;
        }
    }
    return false;
}

Book *Store :: findBookbyISBN(string isbn)
{
    for(auto find_book = this->books.begin(); find_book!=this->books.end(); find_book++)
    {
        if((*find_book)->getISBN()==isbn)
        {
            auto index=distance(this->books.begin(),find_book);
            return this->books.at(index);
        }
    }
    return NULL;
}

bool Store :: BookExists(string isbn)
{
    for(auto Bo_exist=this->books.begin(); Bo_exist!=books.end(); Bo_exist++)
    {
        if((*Bo_exist)->getISBN()==isbn)
        {
            return true;
        }
    }
    return false;
}

vector<Book *> Store :: getBooks()
{
    return this->books;
}

vector<Member *> Store :: getMembers()
{
    return this->members;
}

void Store::AddBook(Book *book)
{
    this->books.push_back(book);
}

void Store::AddMember(Member *member)
{
    this->members.push_back(member);
}
