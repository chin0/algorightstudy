# chap9 정리
## 멤버함수동작원리
- 객체 내에는 멤버함수가 존재한다.(객체지향적 논리로는 이것이 옳다. 일단 객체는 여기서 배운 내용과 상관없이 이렇게 인식한다.)
- 하지만 실제로는 멤버함수는 메모리의 한 공간에 위치해서 그 함수를 사용하는 클래스들이 공유하는 방식을 취하고있다. 그리고 객체가 지니고 있는 멤버변수 대상의 연산이 진행되도록 함수를 호출하는것이다.

## 가상함수 동작원리.