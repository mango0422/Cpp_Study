#include <iostream>
#include <cstring>
using namespace std;

class Book{
    private:
        char * title;
        char * isbn;
        int price;
    public:
        Book(const char * t1, const char * i1, int p1) : price(p1){
            this->title = new char[strlen(t1) + 1];
            strcpy(this->title, t1);
            this->isbn = new char[strlen(i1) + 1];
            strcpy(this->isbn, i1);
        }
        Book(const Book& ref){
            title = new char[strlen(ref.title) + 1];
            isbn = new char[strlen(ref.title) + 1];
            strcpy(title, ref.title);
            strcpy(isbn, ref.isbn);
        }
        Book& operator=(const Book& ref){   // 대입 연산자
            delete []title;
            delete []isbn;

            cout<<"Book operator=()"<<endl;
            title = new char[strlen(ref.title) + 1];
            isbn = new char[strlen(ref.isbn) + 1];
            strcpy(title, ref.title);
            strcpy(isbn, ref.isbn);
            return *this;
        }
        void ShowBookInfo() const {
            cout<<"제목: "<<title<<endl;
            cout<<"ISBN: "<<isbn<<endl;
            cout<<"가격: "<<price<<"원"<<endl;
        }
        ~Book(){
            delete []title;
            delete []isbn;
        }
};

class EBook : public Book{
    private:
        char* DRMKey;
    public:
        EBook(const char * t1, const char * i1, int p1, const char * d1) : Book(t1, i1, p1){
            DRMKey = new char[strlen(d1) + 1];
            strcpy(DRMKey, d1);
        }
        EBook(const EBook& ref) : Book(ref){
            DRMKey = new char[strlen(ref.DRMKey) + 1];
            strcpy(DRMKey, ref.DRMKey);
        }
        EBook& operator=(const EBook& ref){ // 대입 연산자
            Book::operator=(ref);
            delete []DRMKey;
            cout<<"EBook operator=()"<<endl;
            DRMKey = new char[strlen(ref.DRMKey) + 1];
            strcpy(DRMKey, ref.DRMKey);
            return *this;
        }
        void ShowBookInfo() const{
            Book::ShowBookInfo();
            cout<<"인증키: "<<DRMKey<<endl<<endl;
        }
        ~EBook(){
            delete []DRMKey;
        }
};

int main(){
    EBook book1("윤성우의 열혈 C++ 프로그래밍", "978-89-960940-4-3",27000, "2QW6-EDYD-SQB7-MZLZ");
    book1.ShowBookInfo();
    
    EBook book2 = book1;
    book2.ShowBookInfo();
    
    EBook book3("","",0,"");
    book3 = book1;
    book3.ShowBookInfo();

    return (0);
}

/*
 * quiz11-2의 핵심
 * 1. 피상속 클래스의 멤버값 복사 생성자를 사용자가 직접 정의하여 사용한다.
 * 2. 상속 클래스는 피상속 클래스 멤버값 복사생성자를 불러와 사용한다.
 */