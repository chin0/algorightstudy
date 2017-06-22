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
    Book& operator=(const Book &ref)
    {
        delete []title;
        delete []isbn;

        price = ref.price;
        isbn = new char[strlen(ref.title) + 1];
        title = new char[strlen(ref.isbn) + 1];

        strcpy(title, ref.title);
        strcpy(isbn, ref.isbn);

        return *this;
    }
    void ShowBookInfo() const
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
    void ShowEBookInfo() const
    {
        ShowBookInfo();
        cout << "인증키: " << DRMKey << endl;
    }
    EBook& operator=(EBook &ref)
    {
        delete []DRMKey;
        Book::operator=(ref);
        DRMKey = new char[strlen(ref.DRMKey) + 1];
        strcpy(DRMKey,ref.DRMKey);
        return *this;
    }
    ~EBook()
    {
        delete []DRMKey;
    }
};

int main(void)
{
    Book book("good C++", "555-12345-890-0",20000);
    Book book2("fucking C++", "123-45678-890-0",44440);
    book=book2;
    book.ShowBookInfo();
    cout<<endl;
    EBook ebook("good C++ ebook", "555-12345-890-1",10000,"fdx9w0i8kiw");
    EBook ebook2("fucking C++ ebook", "fuck-12345-890-1",30000,"fuckfuckfuc");
    ebook=ebook2;
    ebook.ShowEBookInfo();
    return 0;
}
