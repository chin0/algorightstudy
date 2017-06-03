# Chapter4 정리

### 정보은닉(Information hiding)

- 외부에서 클래스 멤버에 직접적으로 접근하지 못하게하는것.
    - 프로그래머의 실수에 대비할수있음.
    - ex) 10~100까지의 너비를 받아야하는데 그 이상을 받지못하게 set함수를 만든다던가..
- 클래스에 멤버에 접근할때 setter,getter함수를 만든다.
    - set - 수정
    - get - 가져오기

const함수
- 함수 뒤에 const를 붙이면 된다.
- 멤버변수의 값을 바꾸지 못한다.
- const함수내에서는 const함수이외의 함수를 호출할수없다.
- 안정성을 높일수있다.

### 캡슐화
- 관련있는 변수와 함수, 클래스를 클래스로 묶는것이다.
- 기본적으로 정보은닉이 포함된다.
    - 즉, 멤버변수는 잘 감춰야한다.


### 생성자
- 클래스가 생성될때 실행되는 함수
- 클래스가 생성될때 초기화해야되는 멤버변수를 초기화하는등의 작업이 필요할때 사용.
- 클래스의 이름과 동일한 함수를 작성하면됨.(단, 리턴형은 명시하지않는다.)
- 생성자도 오버로딩이 가능하다.
- 생성자의 매개변수도 디폴트 값 지정이 가능하다.
- 아무 인자도 주지않는 생성자를 호출할때는
    ```
    SimpleClass sc1;
    SimpleClass * ptr=new SimpleClass;
    SimpleClass * ptr=new SimpleClass();
    ```
    이렇게선언해야한다.

    `SimpleClass sc1();`

    이문장은 함수의 원형선언인지 생성자호출인지 구별할수없기때문에 기본적으로 성립되지않는다. 기본적으로 함수의 원형선언으로 간주한다.

### 멤버 이니셜라이저
```
class Rectangle
{
private:
    Point upLeft;
    Point lowRight;
public:
    Rectangle(const int &x1, const int &y1, const int &x2, const int &y2) : upLeft(x1,y1), lowRight(x2,y2)
    {
        //empty
    }
}
```
- : 부분이 멤버 이니셜라이저다.
- upLeft의 객체를 생성하는 도중에 upLeft의 생성자를 호출하라! 라는 뜻이다. lowRight도 마찬가지다.
- 이 외에도 int같은 기본 자료형을 가진 멤버들도 가능하다.
- const 멤버변수도 이니셜라이저로 초기화가 가능하다.
- 이를통해서 멤버변수로 참조자를 선언할수도 있음.
- 클래스내부에서만 객체의 생성을 허용하고싶으면 private 생성자를 사용하면 된다.


이를통해 객체의 생성과정을 아래와 같이 정리할수있다.
1. 메모리 공간의 할당
2. 이니셜라이저를 이용한 멤버변수의 초기화
3. 생성자의 몸체부분 실행

### 소멸자

- 생성자와 동일하되, 클래스의 이름앞에 ~가 붙는다.
- 반환형이 없고 실제로 반환하지 않는다.
- 매개변수는 void형으로 선언되어야하기때문에 오버로딩도, 디폴트 설정도 불가능하다.

### 객체 배열
- 생각하는데로 사용하면된다.
- 생성자를 별도로 명시하지 못한다.
- 즉, 다른 생성자가 선언되어있는경우 인자없는 디폴트 생성자가 무조건 선언되어야 있어야 한다.


#### 객체 포인터 배열
- 객체의 주소 값 저장이 가능한 포인터 변수로 이루어진 배열이다.

#### this 포인터

- 멤버변수 내에서는 객체 자신을 가리키는 this포인터를 사용할수있다.
- this포인터를 이용하면 멤버변수와 매개변수의 이름이 같아도 this->멤버변수로 해결할수있음.

#### self reference의 반환

```
#include <iostream>
using namespace std;

class SelfRef
{
private:
    int num;
public:
    SelfRef(int n) : num(n)
    {
        //empty
    }
    SelfRef& Adder(int n)
    {
        num+=n;
        return *this;
    }
    SelfRef& ShowTwoNumber()
    {
        cout<<num<<endl;
        return *this;
    }
}

int main(void)
{
    SelfRef obj(3);

    SelfRef &ref=obj.Adder(2);

    obj.ShowTwoNumber();
    ref.ShowTwoNumber();

    ref.Adder(1).ShowTwoNumber().Adder(2).ShowTwoNumber();

    return 0;
}
```
- 감이 올것이다.
