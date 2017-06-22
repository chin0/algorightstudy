# 연산자 오버로딩 1

## 연산자 오버로딩이란? ㅇㅅㅇ

연산자 오버로딩은 함수 오버로딩과 비슷하게 이번엔 연산자를 오버로딩해서 기존 연산자와는 다른역할을 하게할수있다.

#### 연산자 오버로딩 하는법
- 예제: FirstOperationOverloading.cpp,OperationOverloading.cpp
- 위 FirstOperationOverloading.cpp 예제를 보면 operator+함수를 이용해서 새 객체를 생성한다. 그리고 그 객체를 리턴한다.
- 그리고 main에서는 그 함수를 호출해서 덧셈 결과를 담고있는객체를 생성한다.
- 하지만 OperationOverloading.cpp에서도 같은 구현된 클래스를 사용하는데, 이번엔 그냥 +연산으로 객체 2개를 더해주고있다.
    - 이것이 바로 연산자 오버로딩이다.
    - operator+() 처럼 operator 연산자 형태를 가지면 된다.
    - 연산자 오버로딩도 const함수로 선언이 가능하다.
    - +함수도 const함수로 선언이 가능하다. +연산자는 피연산자의 값을 변경하는게 아니고, 새로운 연산의 결과를 만들어내는것이기 때문이다.
- +도 결국 operator+()처럼 원래 형태로 변환된다.(다른 연산자 오버로딩들도 다 마찬가지.)

## 연산자 오버로딩을 하는 방법
- 멤버함수에 의한 연산자 오버로딩
    - pos1.operator+(pos2); <-이렇게 해석됨
- 전역함수에 의한 연산자 오버로딩
    - operator+(pos1,pos2); <-이렇게 해석됨.
- 우선순위: 멤버함수>전역함수
- ex) GFunctionOverloading.cpp
    - `friend Point operator+(const Point &pos1, const Point pos2)`
    - 위의 friend선언을 해야 전역함수가 Point의 private영역에 접근할수있다.
- 되도록이면 멤버함수 기반으로 하자.(물론 전역함수기반으로 해야하는 경우가 있음.)

## 오버로딩이 안되는 연산자들

| operator | usage |
| ---------- | :--------- |
| .    | 멤버접근 연산자       |
| . *  | 멤버포인터 연산자|
| ::   | 범위 지정 연산자 |
| ?:   | 삼항 연산자 |
| sizeof | 크기계산 |
| typeid  | rtti관련 연산자|
| static_cast | 형변환 연산자|
| dynamic_cast | 형변환 연산자|
| const_cast | 형변환 연산자|
| reinterpret_cast | 형변환 연산자|

### 멤버함수 기반으로만 오버로딩이 가능한 연산자들

- = 대입연산자
- () 함수호출연산자
- [] 배열접근연산자(인덱스 연산자)(공기?)
- -> 멤버접근포인터연산자자

## 오버로딩 주의사항
- 본래의 의도를 벗어난 형태의 연산자 오버로딩은 하지말것
    - 덧셈 연산자(+)를 예로 들자면 덧셈 연산자를 오버로딩했는데 빼버린다던가..
- 연산자 우선순위와 결합성은 바뀌지않는다.
- 매개변수의 디폴트 값 설정이 불가능하다.
- 연산자의 순수 기능까지 건드릴수는없다.
즉,
```
int operator+(const int num1, const int num2)
{
    return num1*num2;
}
```
이런 오버로딩은 불가능하다.

## 단항 연산자의 오버로딩
- 그냥 멤버기반은 인자가 없고, 전역은 인자가 하나다.
- OneOpndOverloading.cpp참고.
- 증감&증가연산자의 전위 후위 구문.
- ++pos -> pos.operator++()
- pos++ -> pos.operator++(int)
- 증감연산자도 마찬가지다.
- PostOpndOverloading.cpp참고.

#### 반환형에서의 const 선언과 const 객체
- PostOpndOverloading.cpp참고.
- 후위 연산자들로 보면 전부 반환형이 const인것을 알수있다.
- 일단 반환의 대상이 되는 retobj 객체가 const인점은 retobj객체가 반환되면, 반환의 과정에서 새로운 객체가 생성되기때문에 retobj객체의 const 선언유무는 아무런 영향을 미치지 않는다.
- 의미는 바로 operator--함수의 반환으로 인해서 생성되는 임시객체를 const객체로 생성하겠다는 의미이다.
- const객체
    - `const Point pos(3,4)` 와 같이 선언된다.
    - pos객체를 상수화해서 pos객체에 저장된 값의 변경을 허용하지 않겠다는 의미이다.
    - const함수내에서는 const함수의 호출만 허용한다.
    - 참조자도 const여야 참조가 가능하다.
- 후위연산자에서 `(pos--)--`와 같은 구문은 불가능하기 때문에 이를 반영하고자 const를 이용해서 막아준것이다.

## 교환법칙 문제
- 교환법칙이 성립하는 연산자는 그것을 반영해야한다. 대표적으로 덧셈, 곱셈이 있다.
- 기본적으로 연산에 사용되는 두 피연산자는 같은 자료형이여야한다.즉, 같지않을 경우 형변환을 해서 계산한다.
- 하지만, 연산자 오버로딩을 이용하면 이러한 규칙에 예외를 둘수있다.
- PointMultipleOperation.cpp참고.
- 위 예제에서 오버로딩한 * 연산자는 Point객체가 * 연산자의 왼편에 와야한다.
- 하지만 순서를 바꾸면 교환법칙이 성립이 안된다.(곱셈은 교환법칙이 성립된다.)
    - 그래서 전역함수 형식으로 순서를 바꿔서 오버로딩을 해준다.
    - CommuMultipleOperation.cpp

## >>,<<오버로딩.
```
int main(void)
{
    Point pos(3,4);
    cout<<pos<<endl;
    .....
}
//위와같은 연산이 가능하도록 오버로딩해보자.
```
- IterateConsoleOutput.cpp에서도 보았듯이, cout는 ostream의 객체이다.
- ostream은 이름공간 std에 선언되어있고, 이를 사용하기 위해서는 iostream을 포함해야한다.

기본적으로 ostream의 <<연산을 멤버함수형태로 오버로딩하려면 ostream객체를 수정해야한다. 이는 불가능하므로(현실적으로) 전역변수 형태로 오버로딩한다.

- PointConsoleOutput.cpp참고.
- 
