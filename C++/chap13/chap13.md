# chap13 - 템플릿

## 함수 템플릿
- 함수 템플릿은 함수를 만들어 내는데, 함수의 기능은 결정되어있지만 자료형은 결정되어 있지 않다.
```
template <typename T> // 여기서 템플릿을 정의
T add(T a, T b)
{
    return a + b;
}
```
- template <class T>로도 선언해도 된다.
- 사용예: AddFunctionTemplate.cpp
    - Add<int>(3,5)처럼 타입을 명시하면 그 타입의 함수를 만든다. (T부분을 대체한다고 보면된다.)
    - 이미 만들어진 함수는 나중에 재활용된다.
    - 위와 같이 명시를 안해줘도 자동으로 타입을 추론한다,
        - Add(3.4,1.2)처럼 호출해도 된다. 이 경우에는 double형 함수를 만든다.
    - 이렇게 만들어진 함수는 아래와 같이 표현한다,
```
int Add<int>(int num1, int num2)
{
    return num1+num2;
}
```
    - 그리고 위에 템플릿정의를 함수템플릿이라고 하고, 이 템플릿을 기반으로 만들어진 함수를 템플릿함수라고 한다.

- 템플릿은 컴파일 시간이 조금 늘어나긴 하지만, 실제 실행시간은 늘어나지 않는다.

- 함수템플릿의 안좋은 예: TwoTypeAddFunction.cpp
    - 위와같이 템플릿함수와 일반함수는 확실히 구분되어 호출되기때문에 함수템플릿이랑 일반함수를 같이 사용하는것은 좋지않다.

## 두개 이상의 형에 대한 템플릿 선언
- PrimitiveFunctionTemplate.cpp 참고
- `template <class T1, class T2> //typename으로도 가능`
- 별다른 설명이 필요없다.

## 함수 템플릿의 특수화(Specialization)
- NeedSpecialFunctionTemplate.cpp참고.
    - 위코드의 문제점은 문자열을 대상으로 호출할경우 의미없는 결과를 내놓는다는것이다.
    - 그래서 char* 형은 따로 처리를 해줘야한다.
    - 고로, 이 상황에서 템플릿 함수의 구현에 예외를 두는것을 함수 템플릿의 특수화라고 한다.
    - SpecialFunctionTemplate참고.
```
template <>
char* Max(char *a, char *b)
{
    cout<<"char* max<char*>"<<endl;
    return strlen(a) > strlen(b) ? a : b;
}

template <>
const char* Max(const char *a, const char *b)
{
    cout<<"const char* Max<const char*>"<<endl;
    return strcmp(a,b) > 0 ? a : b;
}
```
    - 이부분이 특수화 부분이다. 사실 위에는 생략된 부분이 있는데,
    - char* Max<char*>(char \*a, char \*b)
    - const char* Max<const char*>(const char \*a, const char \*b)
    - 이렇게 특수화하는 타입을 명시해주는게 더 좋은 습관이다.

## 클래스 템플릿
- 함수 템플릿과 비슷하다. 코드를 보자.
- 참고: PointClassTemplate.cpp
    - 함수탬플릿과 다를게 없고, 동작방식도 똑같다.

## 클래스 탬플릿의 선언과 정의의 분리
- PointClassTemplateFuncDef.cpp 참고
- 파일단위로 나눌때는 해당 구현된 소스파일도 함께 include해주자.(파일단위 컴파일의 원칙때문.)
```
template <typename T>
Point<T>::Point(T x, T y) : xpos(x), ypos(y)
{ }

template <typename T>
void Point<T>::ShowPosition() const
{
    cout<<'['<<xpos<<", "<<ypos<<']'<<endl;
}
```
- 위 코드에서 Point<T>는 T에 대해 템플릿화 된 Point 클래스 탬플릿이라는 의미이다.
    - 이때 위에 `template <typename T>`를 빼먹고 선언하는경우가 있는데, 이 경우 컴파일러에서 에러 메시지를 띄운다.
