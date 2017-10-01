# disjoint set algorithm

## 1. disjoint set이란?

- 한글로 직역하면 서로소 집합. 즉, 공통된 원소가 없는 집합들을 말한다. 
- 다시말해 교집합이 공집합이라는 예를 들어서 {1, 2, 3}과 {4, 5, 6} 은 서로소 집합이며 {1, 2, 3}과 {3, 4, 5}는 아니다.

## 2. disjoint set data structure

- 한 집합을 여러 서로소 집합으로 저장하는 데이터 구조다.
- 새 세트를 추가하고 기존 세트를 병합하며 요소가 동일한 세트에 있는지 여부를 판별하는 데 거의 상수 시간 동안 작동한다.
- 그래프의 최소 신장 트리를 찾기위한 크루스컬 알고리즘의 핵심적인 역할을 하는 알고리즘이다.

![time_complexity](https://user-images.githubusercontent.com/16369196/31045546-f9bbe3b6-a620-11e7-8735-212b69dc0225.png)

## 3. 표현

- 각각의 elements 는 아래와 같은 데이터를 저장한다.
  - id
  - parent pointer
  - rank - 더 효율적인 알고리즘에서 사용하는 값
- 각각의 element의 parent pointer는 각각 하나의 집합을 나타내는 하나 이상의 트리를 형성한다.
  - 만약 parent pointer가 다른 element를 가리키고있지 않다면, 해당 element는 해당 set을 표현하고 있는 tree의 root이고, 대표 멤버이다.
- set은 대체로 single element로 표현된다. 그러나 만약 element가 parent를 가지고있으면, 그 element는 parent를 계속 타고 올라가면 만나는 대표멤버(즉, 루트 노드)에 따라 식별되는 집합의 일부임.

![disjoint_set](http://flylib.com/books/2/300/1/html/2/images/14fig11.jpg)

위와 같은 형태를 띄게된다.

### 연산

- MakeSet
  - 고유한 id를 가지고, rank가 0이고 parent pointer는 자기 자신을 가리키는 새로운 요소를 만든다.
  - parent pointer가 자기 자신을 가리키는 요소는 해당 set의 대표멤버(representative member)이다.
  - 시간복잡도: O(1)
- Find
  - Find(x)는 parent가 자기 자신을 가리키는 요소를 찾을때까지 parent 포인터를 따라가서 그 요소를 리턴한다.
  - 즉, 이 함수가 리턴하는 element는 x가 속한 집합의 대표멤버이며 x 자기 자신일수도 있다.
  - Path compression: Find가 사용될때마다 트리 구조를 평평하게 하는 방법이다. 루트로 가기위해 방문한 각각의 요소는 같은 set이므로, 모든 방문된 element는 루트에 연결될수있다. 그러면 tree는 더 평평해지므로, 앞으로의 작업 속도가 더 빨라진다.

![path_compression](https://algocoding.files.wordpress.com/2014/09/uf3_path_compression.png)



- union(x,y)
  - x,y가 속할 트리를 결정하는 연산이다.
  - 만약 루트 노드가 distinct(유일, 뚜렷한, 다른)하다면, 다른 root를 다른 하나의 root에 attach함으로써 트리는 합쳐진다.
    - 이것을 naive하게 항상 x를 y의 자식으로 만든다면, tree의 높이는 O(n)으로 자랄수있다. 이것을 *union by rank*로 해결할수있따.
  - union by rank: 항상 작은 트리를 큰 트리에 붙인다. 따라서, 두 트리의 높이가 같지 않다면, 연산 이후의 트리는 원래 트리의 높이보다 커지지 않는다. 만약 더 크다면, 연산 이후의 트리는 하나의 노드가 높아진다.
    - 이것을 구현하기 위해서는 
    - 각각의 element는 rank와 연결되어야한다. 
    - 처음에 set은 하나의 element와 rank값 0을 갖고있다. 
    - 만약 두개의 set이 union될때 두 set의 rank값을 비교한다.
      - 만약 같다면, rank값은 1이 커진다.
      - 다르다면, rank값은 두 set의 rank값중 더 큰값이 된다.
    - path compression을 사용하는 경우는 트리의 높이를 변경하기 때문에 높이 또는 깊이 대신 rank가 사용된다.

## 용도

- 그래프 연결성 확인(크루스칼 알고리즘)
- 가장 큰 집합 추적

주로 다른 알고리즘의 일부로 사용됨.

