#include <iostream>
#include <cstring> 

using namespace std;

class Book
{
private:
    char *title;
    char *isbn;
    int price;
public:
    Book(char *_title, char *_isbn, int price) 
        : price(price)
    {
        title = new char[strlen(title) + 1];
        isbn = new char[strlen(isbn) + 1];
        strcpy(title,_title);
        strcpy(isbn,_isbn);
    }
    void ShowBookInfo()
    {
        cout << "제목: "<< title << endl;
        cout << "ISBN: "<< isbn << endl;
        cout << "가격: "<< price << endl;
    }
    ~Book()
    {
        delete []title;
        delete []isbn;
    }
};

//is a
class EBook : public Book
{
private:
    char * DRMKey;
public:
    EBook(char *title, char *isbn, int price, char *_DRMKey)
        : Book(title,isbn,price)
    {
        DRMKey = new char[strlen(DRMKey) + 1];
        strcpy(DRMKey,_DRMKey);
    }
    void ShowEBookInfo()
    {
        ShowBookInfo();
        cout << "인증키: " << DRMKey << endl;
    }
    ~EBook()
    {
        delete DRMKey;
    }
};

int main(void)
{
    Book book("good C++", "555-12345-890-0",20000);
    book.ShowBookInfo();
    cout<<endl;
    EBook ebook("good C++ ebook", "555-12345-890-1",10000,"fdx9w0i8kiw");
    ebook.ShowEBookInfo();
    return 0;
}
