# 템플릿 2

## Point 클래스 탬플릿과 배열 클래스 탬플릿
```
template <typename T>
class Point
{
private:
    T xpos,ypos;
public:
    Point(T x=0, T y=0);
    void ShowPosition() const;
};

template <typename T>
class BoundCheckArray
{
private:
    T *arr;
    int arrlen;
    BoundCheckArray(const BoundCheckArray& arr) { }
    BoundCheckArray& operatr=(const BoundCheckArray& arr) { }
public:
    BoundCheckArray(int len);
    T& operator[] (int idx);
    T operator[](int idx) const;
    int GetArrLen() const;
    ~BoundCheckArray();
};
```
- 위에 두 클래스탬플릿이 있다. 이 탬플릿을 기반으로 Point<int> 탬플릿 클래스의 객체를 저장할수 있는 객체를 생성하려면
- `BoundCheckArray<Point<int>> oarr(50);` 이렇게 할수있다.
- 그리고 Point<int>형 포인터를 저장할수있는 객체를 생성하려면
- `BoundCheckArray<Point<int>\*>` 이렇게 하면 된다.(typedef해줘도 된다.)

## 특정 템플릿 클래스의 객체를 인자로 받는 일반함수의 정의와 friend 선언
- PointTemplateFriendFunction.cpp참고.
```
friend Point<int> operator+(const Point<int>&, const Point<int>&);
friend ostream& operator<<(ostream &os, const Point<int> &pos);
```
- 이렇게 특정 템플릿 클래스의 객체를 인자로 받는 friend선언을 할수있다. 그리고
```
Point<int> operator+(const Point<int> &pos1, const Point<int> &pos2)
{
    return Point<int>(pos1.xpos+pos2.xpos, pos1.ypos+pos2.ypos);
}

ostream& operator<<(ostream &os, const Point<int> &pos)
{
    os<<'['<<pos.xpos<<", "<<pos.ypos<<']'<<endl;
    return os;
}
```
- 이렇게 특정 템플릿 클래스의 객체를 인자로 받는 일반함수를 만들수있다.

## 클래스 템플릿 특수화
- 함수 템플릿 특수화랑 비슷하다.
```
template <typename T>
class SoSimple
{
public:
    T SimpleFunc(T num) { .... }
};
```
- 위 클래스가 있을때 int형에 대해서 특수화를 하고싶으면
```
template <>
class SoSimple<int>
{
public:
    int SimpleFunc(int num) { .... }
}
```
- 이런식으로 특수화를 하면된다.

## 클래스 부분 특수화
- template <typename T1, typename T2> 로 정의된 템플릿 클래스가 있을때,
- 둘중 한 템플릿만 특수화할때 이것을 부분 특수화라고한다.
<T1,int> 이런식으로

## 템플릿 인자
- `template <typename T1, typename T2>`에서 T1,T2를 템플릿 매개변수라고 한다. 그리고 템플릿 매개변수에 전달되는 자료형 정보를 템플릿 인자라고 한다.

1. 템플릿 매개변수에는 변수의 선언이 올수있다.

```
template<typename T, int len>
class SimpleArray
{
private:
    T arr[len];
public:
    T& operator[](int idx)
    {
        return arr[idx];
    }
};
```
후에 아래와 같이 사용한다.

SimpleArray<int,5> (int형배열 5개할당)

SimpleArray<double,7> (double형 배열 7개 할당)

그리고 위에 2개는 다른 자료형의 클래스로 구분된다.

물론 위에 문법은 생성자로도 구현할수있지만 템플릿만의 이점이 있다.

NonTypeTemplateParam.cpp를 참고하자.

여기서 길이가 다른 배열을 가진 템플릿도 다른 형으로 간주해서 복사를 막는다. 만약 이런 처리가 필요하다면 생성자대신 좋은 선택이 될것이다.

2. 매개변수는 디폴트 값도 설정 가능하다.
- `template <typename T=int, int len=7>` 이런식으로.

## 함수 템플릿과 static 지역변수.
- static 변수는 딱 한번 초기화된 상태에서 그 값을 계속 유지하는 특성을 가지고있다.
```
template <typename T>
void ShowStaticValue(void)
{
    static T num=0;
    num+=1;
    cout<<num<<" ";
}
```
- 함수 템플릿은 이것을 기반으로 다음과 같이 템플릿 함수를 만들게 된다.
```
void ShowStaticValue<int>(void)
{
    static int num;
    num+=1;
    cout<<num<<" ";
}

void ShowStaticValue<long>(void)
{
    static long num;
    num+=1;
    cout<<num<<" ";
}
```
- 그러므로 static 지역변수도 템플릿 함수별로 각각 존재하게된다.
- 클래스템플릿의 static 멤버변수도 마찬가지다.

## 템플릿 static 멤버변수 초기화의 특수화
```
template <typename T>
T SimpleStaticMem<T>::mem=0; //기본적으로 0으로 초기화된다.

template <>
long SimpleStaticMem<long>::mem=5;
```
