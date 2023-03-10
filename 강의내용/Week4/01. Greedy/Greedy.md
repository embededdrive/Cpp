# Greedy (탐욕법 / 탐욕 알고리즘)

눈 앞에 놓인 상황에서 가장 좋아보이는 선택  
상식적인 생각의 접근 기법  

그리디는 Approximation Algorithm (근사치 알고리즘)  

**정답이 나오지 않을 수 있다**

그러므로 수학적 검증이 필요하다  
단 이론적으로 접근하면 어렵다  

n 값이 매우 클 경우
1. 그리디
2. DP

## 그리디로 풀 수 있는지? (이론)

1. Greedy Choice Property (탐욕 선택 속성)
   - 탐욕 기준이 중간에 바뀌면 안된다.
2. Optimal substructure (최상적인 하위구조)
   - 하위 파트에서 일부 정답이 가능해야 한다.

## 그리디로 풀 수 있는지? (실전)

### SVIP 접근

1. Selection
   - 선택 기준을 선정한다
2. Validation
   - 테스트 케이스를 통해 검증한다
3. Implementation
   - 구현한다
4. Pray
   - 기도한다
   - 오답일 경우
     1. 기준의 우선순위를 바꿔보기
     2. Greedy 성립 X

> **예외 케이스를 계속 생각하면서 구현한다**

## 예제

> 동전을 최소한으로 사용하여 거스름돈을 주는 방법
1. 각 동전이 배수관계 -> 그리디
2. 배수관계 X -> DP