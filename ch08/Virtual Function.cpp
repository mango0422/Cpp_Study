/*
int main(void){
    Simple * sim1=new ...;
    Simple * sim2=new ...;
}

// sim1, sim2가 가리키는 객체는 Simple 클래스, 또는 Simple 클래스를 상속하는 클래스의 객체이다.

class Base{
    public:
        void BaseFunc() {
            cout<<"Base Function"<<endl;
        }
};

class Derived : public Base{
    public:
        void DerivedFunc(){
            cout<<"Derived Function"<<endl;
        }
};

int main(void){
    Base * bptr=new Derived();  // 컴파일 OK!
    bptr->DerivedFunc();        // 컴파일 Error!
}
// "Derived Func는 Base의 멤버가 아닙니다" 라는 메시지 전달하며 컴파일 에러 -> bptr은 Base형 포인터이기 때문.

int main(void){
    Base * bptr=new Derived();  // 컴파일 OK!
    Derived * dptr=bptr;        // 컴파일 Error!
}
// "Derived 클래스는 Base의 유도 클래스이니까 Base 클래스의 포인터 변수로 Derived 객체의참조가 가능하다! 그러니 문제없이 컴파일이 가능해!"
// "bptr은 Base형 포인터이니까, bptr이 가리키는 대상은 Base 객체일 수도 있는 거잖아! 그럴 경우에는 이 문장이 성립하지 않으니까, 컴파일 에러를 발생시켜야겠다."

int main(void){
    Derived * dptr=new Derived();  // 컴파일 OK!
    Base * bptr=dptr;        // 컴파일 OK!
}

--------------------------------------------------------------------------------------------------------------------------------------------------------------------

class First{
    public:
        void FirstFunc(){
            cout<<"FirstFunc"<<endl;
        }
};

class Second{
    public:
        void SecondFunc(){
            cout<<"SecondFunc"<<endl;
        }
};

class Third{
    public:
        void ThirdFunc(){
            cout<<"ThirFunc"<<endl;
        }
};

int main(void){
    Third * tprt = new Third();
    Second * sptr=tptr;
    First * fptr = sptr;

    tptr->FirstFunc();  //  (O)
    tptr->SecondFunc(); //  (O)
    tptr->ThirdFunc();  //  (O)

    sptr->FirstFunc();  //  (O)
    sptr->SecondFunc(); //  (O)
    sptr->ThirdFunc();  //  (X)

    fptr->FirstFunc();  //  (O)
    fptr->SecondFunc(); //  (X)
    fptr->ThirdFunc();  //  (X)
}


--------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/