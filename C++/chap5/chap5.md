# chap5 - 복사 생성자

### C++ 스타일 초기화

```
int num=20;
int &ref=num;

C++에서는 아래와 같은 방법으로도 가능하다.

int num(20);
int &ref(num);
```

이제 객체로 대상을 바꿔보자.

```
class SoSimple
{
private:
    int num1;
    int num2;
public:
    SoSimple(int n1,int n2) : num(n1), num2(n2)
    {}
    void ShowSimpleData()
    {
        cout<<num1<<endl;
        cout<<num2<<endl;
    }
};

int main(void)
{
    SoSimple sim1(15,20);
    SoSimple sim2=sim1;
    sim2.ShowSimpleData();
    return 0;
}
```
이 경우 클래스의 대입연산은 sim2의 객체가 생성된후 sim1과 멤버 대 멤버 복사가 일어난다.

그리고 이 경우 맨 처음에도 봤듯이 아래의 문장도 가능하다.

```
SoSimple sim2=sim1;
SoSimple sim2(sim1);
```

여기서 C++의 모든 객체는 생성자의 호출을 동반한다. 그러면 sim2의 생성자 호출에 대해서는 아직 언급하지 않았다. 그러면 sim2는 어떠한 과정을 거쳐서 생성될까?

여기서 `Sosimple sim2(sim1)`은 아래와 같은 의미를 가지고있다.
- SoSimple형 객체를 생성해라.
- 객체의 이름은 sim2다.
- sim1을 인자로 받을 수 있는 생성자의 호출을 통해서 객체생성을 완료한다.

위의 객체생성문에서 호출하고자 하는 생성자는 SoSimple 객체를 인자로 받을 수 있는 생성자이다.

```
Sosimple(SoSimple &copy)
{
    ....
}
```

그리고 사실 `SoSimple sim2=sim1`도 사실은

`SoSimple sim2(sim1)`으로 묵시적 변환이 된다.

그럼 복사 연산자를 일단 정의해보면

```
class SoSimple
{
private:
    int num1;
    int num2;
public:
    SoSimple(int n1,int n2) : num(n1), num2(n2)
    {}

    SoSimple(const SoSimple& copy)
        : num1(copy.num1), num2(copy.num2)
    {
        // empty
    }

    void ShowSimpleData()
    {
        cout<<num1<<endl;
        cout<<num2<<endl;
    }
};

int main(void)
{
    SoSimple sim1(15,20);
    SoSimple sim2=sim1;
    sim2.ShowSimpleData();
    return 0;
}
```
```
SoSimple(const SoSimple& copy)
    : num1(copy.num1), num2(copy.num2)
{
    // empty
}
```

이 부분이 복사연산자이다. 이 복사연산자가 호출됨으로써 객체의 복사가 생성시 이루어진다.

그리고 이와같은 복사시에 호출되는 생성자를 복사연산자라고 한다.

복사연산자를 만들때는 앞에 const를 붙여 원본의 값의 변화가 일어나지 않게하자.

그리고 복사생성자는 이렇게 직접정의하지않아도 기본적으로 삽입된다. 하지만 특정한 상황에서는 무조건 정의해야하는 경우가 있다.

그리고 복사생성자 앞에 explicit키워드를 붙이면 대입연산자를 이용한 초기화가 불가능하다.

그리고 묵시적 연산은 아래와 같은 사례에서도 발생한다.

```
class AAA
{
private:
    int num;
public:
    AAA(int n) : num(n) {}
    ......
}

이런경우
AAA obj=3은 AAA obj(3)으로 변환된다.
```

이런일도 explicit를 생성자 앞에 붙이면 불가능하게 할수있다.

### 깊은 복사와 얕은 복사.

- 얕은 복사 - 멤버 대 멤버의 복사.
    - 이 경우 멤버변수가 힙의 메모리공간을 참조하는 경우 문제가 됨.
    - 멤버변수를 단순히 복사만 하기때문에 두 멤버변수가 같은 공간을 가리킨다. 이 경우 심각한 문제가 생길수있다...
- 깊은 복사 - 복사 생성자를 정의해 직접 복사를 진행한다.
    - 문자열의 경우 새 힙공간을 할당해서 거기에 문자열을 복사하고 그것을 가리키게 할수 있겠다.

### 복사 생성자의 호출시점

복사 생성자가 호출되는 시점은 크게 세가지로 구분할수 있다.

1. 기존에 생성된 객체를 이용해서 새로운 객체를 초기화하는경우.
2. Call-by-value 방식의 함수호출 과정에서 객체를 인자로 전달하는 경우.
3. 객체를 반환하되, 참조형으로 반환하지 않는경우.

- 이 세가지에는 객체를 생성함과 동시에 동일한 자료형의 객체로 초기화해야한다! 라는 공통점이 있다.
- 복사 생성자의 호출횟수는 프로그램의 성능과에도 관계가 있다!

#### case 1: 메모리 공간의 할당과 초기화가 동시에 일어나는 상황.

`int num1=num2`

위와 같은 경우에는 num1의 메모리공간의 할당과 동시에 num2의 저장된 값으로 초기화된다.

#### case 2 : call-by-value 방식의 함수호출 과정에서 객체를 인자로 전달하는 경우.
```
int SimpleFunc(int n)
{
    ...
}

int main(void)
{
    int num=10;
    SimpleFunc(num);
}
```

이 경우, 매개변수 n이 할당과 동시에 초기화된다.

#### case 3: 객체를 반환하되, 참조형으로 반환하지 않는경우.

그리고 함수의 값을 리턴할때도 메모리공간을 할당후 반환한다.

증거는 바로, SimpleFunc가 값을 리턴한다고 하자. 그러면

`cout << SimpleFunc(123) << endl`

만약 반환값이 어딘가에 저장이 되어있지않다면, cout에 의한 출력이 불가능하다.

값이 출력되기 위해서는 그 값을 참조할 수 있어야 하고,

참조가 가능 하려면 메모리 공간의 어딘가에 저장되어야한다.

즉, 함수가 값을 반환하면 별도의 메모리 공간이 할당되고, 이 공간에 반환값이 저장된다.(반환값으로
초기화된다.)
