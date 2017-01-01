/* 분할 정복 알고리즘을 이용한 정렬방법중 하나다. 데이터셋을 가장 작은단위까지 나눈후 다 나눠지면 정렬하면서
 * 합치는 방법이다.
 */
#include <stdio.h>
#include <stdlib.h>

void Merge(int DataSet[],int StartIndex,int MiddleIndex,int EndIndex){
    int i;
    int LeftIndex = StartIndex;
    int RightIndex = MiddleIndex + 1;
    int DestIndex = 0;
    int* Destination = (int*)malloc(sizeof(int) * (EndIndex - StartIndex + 1));
    while(LeftIndex <= MiddleIndex && RightIndex <= EndIndex){
        if(DataSet[LeftIndex] < DataSet[RightIndex]){ //크기를 비교하면서 큰것을 결과 인덱스에 넣는다.
            Destination[DestIndex] = DataSet[LeftIndex];
            LeftIndex++;
        } else {
            Destination[DestIndex] = DataSet[RightIndex];
            RightIndex++;
        }
        DestIndex++;
   }
    while(LeftIndex <= MiddleIndex)//이런식으로 하면 배열에 남는 값이 생기는데,남는걸 이제 채워준다.
        Destination[DestIndex++] = DataSet[LeftIndex++];
    while(RightIndex <= EndIndex)
        Destination[DestIndex++] = DataSet[RightIndex++];
    DestIndex = 0;
    for(i = StartIndex;i<=EndIndex;i++){
        DataSet[i] = Destination[DestIndex++];
    }
    free(Destination);
}

void MergeSort(int DataSet[],int StartIndex,int EndIndex){
    int MiddleIndex;
    if(EndIndex - StartIndex < 1)
        return;
    MiddleIndex = (StartIndex + EndIndex) / 2;//중간부터 나누기 시작한다.(재귀 함수를 이용)
    MergeSort(DataSet,StartIndex,MiddleIndex);
    MergeSort(DataSet,MiddleIndex + 1,EndIndex);

    Merge(DataSet,StartIndex, MiddleIndex,EndIndex);
}
int main(void){
    int n = 0;
    scanf("%d",&n);
    int array[n];
    for(int i = 0; i<n;i++){
        scanf("%d",&array[i]);
    }
    MergeSort(array,0,n-1);
    for(int i = 0;i<n;i++){
        printf("%d\n",array[i]);
    }
}
