# chap8 정리

## 객체 포인터 변수: 객체의 주소값을 저장하는 포인터 변수.
- 선언:
    - Person이라는 클래스가 있을때;
```
Person \*ptr; // 포인터 변수 선언
ptr = new Person(); //포인터변수의 객체 참조
```
    - Person 포인터 변수는 Person 객체뿐만 아니라, Person을 상속하는 유도 클래스의 객체도 가리킬수있다.
    - 뿐만아니라, Person을 상속하는 유도클래스의 유도클래스까지 Person과 직접적인 관계가 아닌, 간접적인 관계에 놓여있는 객체도 가리킬수있다.
    - ObjectPointer.cpp 확인.

### 왜 이런게 되는것인가?
- 객체는 IS-A 관계를 나타내는데 가장 좋은 요소이다.(사실 그것을 위해서 있는것이기도 하고.)
- 고로 위에 ObjdectPointer.cpp를 아래와 같이 생각해보자.
    - Student는 Person이다.
    - PartTimeStudent(근로학생)은 Student이다.
    - 그러므로, PartTimeStudent는 person이다.
- 이 말을 조금 바꿔서,
    - Student는 Person의 일종이다.
    - PartTimeStudent는 Student의 일종이다.
    - 그러므로, PartTimeStudent는 Person의 일종이다.
- IS-A관계다. 위와 같은 문장들이 성립함으로 인해서, Student와 PartTimeStudent 객체를 Person 객체의 일종으로 간주한다.
    - 그리고, PartTimeStudent는 Student 객체의 일종으로 간주한다.
- 그러므로 Person이 Student, PartTimeStudent를 가리킬수있는것이다.

## 예제 - 직원관리 프로그램에서
- EmployeeManager2 참고.
- 일단 54,56행과 62,63행은 에러가 나서 주석처리를 했는데, 이는 가상함수에서 설명한다.
- 먼저, 핸들러클래스를 보면 기본클래스 Employee의 주소를 담는데, 위에 설명한 특징을 이용하면 객체가 달라도 기본 클래스만 같으면 핸들러 클래스를 수정할필요가 없을것이다! 이는 좀있다 볼 함수 오버라이딩에서 빛을 발한다.

## 함수 오버라이딩
- EmployeeManager3 참고.
- 상속받는 클래스의 멤버함수를 덮어씌우는(이름이 같다!)기능이다.
- 기초 클래스의 멤버함수에서 새로 만들어진 멤버함수로 대체된다.
- 오버라이딩된 기초클래스의 함수를 호출하려면,
    - `기초클래스::오버라이딩된메소드();`와 같은 방식으로 사용하면 된다.
- 추가로 아래와 같은 방법도 가능하다.
- AAA가 BBB의 유도클래스이고 AAA의 오버라이딩된 BBB의 멤버함수 sleep을 호출할때,
    - AAA.BBB::sleep();
    - 뭐 자주사용되진 않으니 이런게 있구나!라고만 알아두자.
### 추가내용
- EmployeeManager3에서 SalesWorker클래스의 ShowSalaryInfo 멤버함수는 PermanentWorker의 ShowSalaryInfo함수의 내용과 완전히 똑같은데 왜 오버라이딩을 했을까?
    - 오버라이딩을 하지않았다면, ShowSalaryInfo의 GetPay()함수는 SalesWorker의 GetPay()가 아닌, 기초클래스인 PermanentWorker의 GetPay()함수가 호출된다. 그러므로 오버라이딩해서 이를 명시해줘야한다.
- 참고로 GetPay에서도 기초클래스의 GetPay()를 먼저 호출해서 그 값을 이용해 연산을 하는것이 나중에 기초클래스의 GetPay가 수정되었을 경우에 유연하게 대처할수있다.

## 가상함수
Q. 아래와 같은 코드에서 두 포인터가 가리키는 객체의 자료형은 무엇이겠는가?
```
int main(void)
{
    Simple *sim1 = new ~~;
    Simple *sim2 = new ~~;
}
```
A. sim1, sim2가 기리키는 객체는 Simple클래스의 객체이거나, Simple클래스를 상속하는 클래스의 객체이다.

- 이는 컴파일러가 포인터 변수를 바라보는 방식이다.
- 자, 아래와 같은 경우를 생각해보자.

```
class Base
{
public:
    void BaseFunc() { cout<<"Base Function"<<endl; }
};

class Derived : public Base
{
public:
    void DerivedFunc() { cout << "Derived Function" << endl;}
}
```
- 위와같은 경우 다음 main함수는 컴파일이 불가능하다.

```
int main(void)
{
    Base *bptr=new Derived();
    bptr->DerivedFunc(); // Error
}
```
 - 왜냐하면 Base클래스는 DerivedFunc라는 멤버를 갖고있지않기때문이다.(bptr은 Base형 포인터)
     - C++컴파일러는 포인터 연산의 가능성 여부를 포인터의 자료형을 기준으로 판단한다. 실제 가리키는 객체의 자료형으로 판단하지 않는다.
 - 이와 같은 문제를 해결할수있다. 바로 가상함수와 오버라이딩으로!

### 가상함수의 선언.
- 가상함수로 선언되면 해당 함수호출시 포인터의 자료형을 기본으로 호출대상을 결정하지않고, 포인터 변수가 실제로 가리키는 객체를 참조하여 호출의 대상을 결정함.
- 함수 선언앞에 virtual을 붙이면 된다.
- 오버라이딩시에 자동으로 가상함수가 되지만, 명시적으로 가상함수라는것을 알리는것이 좋다.
- FunctionVirtualOverride.cpp
- 실행해보면 포인터의 자료형이 아닌, 가리키는 객체의 자료형을 기준으로 함수를 호출한다는것을 알수있다.
