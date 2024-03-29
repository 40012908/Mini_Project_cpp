#include <thread>
#include <chrono>
#include "Book_Management.h"
#include "Member_Management.h"
#include "Library_store.h"
#include "Library_utilities.h"
#include <iostream>
using namespace std;

void banner();
void menuHeader();
void help();
int getAction();

void addNewMember(Store *store);
void addNewBook(Store *store);
void borrowBooktoaMember(Store *store);
void takebackbookFromMember(Store *store);
void listmemberBorrowedBooks(Store *store);
void listBoooks(Store *store);
void listMembers(Store *store);

int main()
{
    auto store = new Store();
    banner();
    while(true)
    {
        help();
        int action=0;
        while((action=getAction()) == -1)
        {
            error("Invalid input.");
            error("Enter number of the option you want");
            help(); }

        println();

        switch (action) {
        case 0: { exit(0); }
        case 1:
        {
            addNewMember(store);
            break;
        }
        case 2:
        {
            addNewBook(store);
            break;
        }
        case 3:
        {
            borrowBooktoaMember(store);
            break;
        }
        case 4:
        {
            takebackbookFromMember(store);
            break;
        }
        case 5:
        {
            listmemberBorrowedBooks(store);
            break;
        }
        case 6:
        {
            listBoooks(store);
            break;
        }
        case 7:
        {
            listMembers(store);
            break;
        }
        default:
            break; }
        {
            this_thread::sleep_for(chrono::seconds(4));
        }
    }
    return 0;
}
void banner()
{
    println();
    println(yellow("****************************************************"));
    println(yellow("*                                                  *"));
    println(yellow("*        Welcome to Library Administration         *"));
    println(yellow("*                                                  *"));
    println(yellow("****************************************************"));
}
void menuHeader()
{
    cout << endl
         << endl
         << endl;
    println(red("****************************************************"));
}
void help()
{
    menuHeader();
    println("Choose one the following options:");
    println("[ " + yellow("1") + " ] " + "Add a new member");
    println("[ " + yellow("2") + " ] " + "Add a new book to library");
    println("[ " + yellow("3") + " ] " + "Borrow a book to a member");
    println("[ " + yellow("4") + " ] " + "Take-back a book from a member");
    println("[ " + yellow("5") + " ] " + "Show a list of borrowed books by a member");
    println("[ " + yellow("6") + " ] " + "Show a list of books in the library");
    println("[ " + yellow("7") + " ] " + "Show a list of members in the library");
    println("[ " + grey("0") + " ] " + "Exit");
    cout << endl;
}

int getAction()
{
    auto action = promptInt("What can i do for you:");
    if (cin.fail() || action > 7 || action < 0)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return -1;
    }
    return action;
}

void addNewMember(Store *store)
{
    string firstName, lastName, id;
    uint entranceYear;

    info("Enter new member information:");

    firstName = promptString("First Name:");
    lastName = promptString("Last Name:");
    id = promptString("Student ID:");
    entranceYear = (uint)promptInt("Entrance Year:");

    if (store->MemberExist(id))
    {
        error("Member with ID (" + yellowBold(id) + ") already registered.");
	return;
    }
    auto member = new Member(id);
    member->SetEntranceYear(entranceYear)
        ->SetFirstName(firstName)
        ->SetLastName(lastName)
        ->SetId(id);
    store->AddMember(member);
    println();
    ok("New member with following information was added successfully:");
    printNewMemberInformation(member);
}

void addNewBook(Store *store){
    string name, author, isbn;
    uint publishYear, total;

    info("Enter new Book information:");

    name = promptString("Name:");
    author = promptString("Author name:");
    isbn = promptString("ISBN:");
    publishYear = (uint)promptInt("Publish Year:");
    total = (uint)promptInt("Total Number:");

    if (store->BookExists(isbn))
    {
        error("Book with ISBN (" + yellowBold(isbn) + ") already registered.");
	return;
    }
    auto book = new Book();
    book->setName(name)
        ->setAuthor(author)
        ->setISBN(isbn)
        ->setPublishYear(publishYear)
	->setTotal(total);
    store->AddBook(book);
    println();
    ok("New book with following information was added successfully:");
    printNewbookInformation(book);
}
void borrowBooktoaMember(Store *store)
{
    info("Enter requested items to borrow a book:");

    auto isbn = promptString("Enter book ISBN:");
    auto book = store->findBookbyISBN(isbn);
    if (book == NULL)
    {
        error("Could not find book with entered ISBN.");
        return;
    }

    if (!book->canbeBorrowed())
    {
        error("All books have been borrowed.");
        return;
    }

    auto memberId = promptString("Enter member ID:");
    auto member = store->findMemberbyID(memberId);
    if (member == NULL)
    {
     	error("Member with entered ID is not registerd.");
        return;
    }
        if (!book->canbeBorrowedTo(member))
    {
        error("Member has already borrowed this book.");
        return;
    }

    book->borrowTo(member);

    ok("Book with ISBN (" + yellowBold(book->getISBN()) + ")");
    ok("has been successfully borrowed to member with ID (" + yellowBold(member->getId()) + ").");

    string s = "";
    if (book->getRemainingCount() > 1)
    {
        s = "s";
    }

    ok("Number of remaining book" + s + ": " + yellowBold(to_string(book->getRemainingCount())));
    return;
}

void takebackbookFromMember(Store *store)
{
    info("Enter requested items to take back a book:");

    auto memberId = promptString("Enter member ID:");
    auto member = store->findMemberbyID(memberId);
    if (member == NULL)
    {
        error("Member with entered ID is not registerd.");
        return;
    }

    auto isbn = promptString("Enter book ISBN:");
    auto book = store->findBookbyISBN(isbn);
    if (book == NULL)
    {
        error("Could not find book with entered ISBN.");
        return;
    }

    if (!member->hasborrowedbook(book))
    {
     	error("Book was not borrowed to member.");
        return;
    }
    book->takeBackfrom(member);
    ok("Book with ISBN (" + yellowBold(book->getISBN()) + ")");
    ok("has been successfully taken back from member with ID (" + yellowBold(member->getId()) + ").");
    ok("Number of book in library:" + yellowBold(to_string(book->getRemainingCount())));
    return;
}

void listmemberBorrowedBooks(Store *store)
{
    info("Enter requested items to see a list of books borrowed by a member:");

    auto memberId = promptString("Enter member ID:");
    auto member = store->findMemberbyID(memberId);
    if (member == NULL)
    {
        error("Member with entered ID is not registerd.");
        return;
    }

    println();
    info("Member with ID (" + yellowBold(member->getId()) + ") has borrowed " + yellowBold(to_string(member->getborrowedBooksCount())) + " bo\
oks.");

    auto books = member->getborrowedBooks();
    if (books.size() == 0)
    {
     	println();
        return;
    }
    info("List of books:");
    for (auto book = books.begin(); book != books.end(); book++)
    {
        printBorrowedBookInformation(*book);
    }
    println();
}

void listBoooks(Store *store)
{auto books = store->getBooks();

    if (books.size() == 0)
    {
        info("No book has been registered yet.");
        println();
     	return;
    }

    string plural = "";
    if (books.size() > 1)
    {
        plural = "s";
    }

    info("(" + yellowBold(to_string(books.size())) + ") book" + plural + " has been registered in the library.");
    info("Listing all books:");

    for (auto book = books.begin(); book != books.end(); book++)
    {
        printRegisteredBookInformation(*book);
	println();
    }
}
void listMembers(Store *store)
{
    auto members = store->getMembers();
    if (members.size() == 0)
    {
        info("No member has been registered yet.");
        println();
        return;
    }

    string plural = "";
    if (members.size() > 1)
    {
        plural = "s";
    }

    info("(" + yellowBold(to_string(members.size())) + ") member" + plural + " has been registered in the library.");
    info("Listing all:");

    for (auto member = members.begin(); member != members.end(); member++)
    {
        printRegisteredMemberInformation(*member);
        println();
    }
}

