# DP (Dynamic Programming)

## **개념**

동적 프로그래밍  
이름에 특별한 의미는 없음  

- 답을 기억하는 프로그래밍 기법
- 기존에 구했던 정답을 이용해서 현재 정답을 구하는 것

---

## **구현**

index 에는 N번 째 문제  
value 에는 값을 저장한다  

점화식을 구할 수 있어야 구현이 가능하다. 

## **DP를 푸는 2가지 방법**

0. dp 테이블을 디버깅을 위해서 미리 써놓기

1. Top-Down
   - N 문제 시작
   - 풀 수 있는 하위 문제까지 답을 기록 (memoization)
     - 백트래킹에 memoization을 더한 것으로 볼 수도 있다
   - 하위의 답들을 취합하여 답을 구한다
     - 재귀로 구현한다
     - 정석적인 방법
2. Bottom-Up
   - 풀 수 있는 가장 하위문제부터 시작
   - 바로 상위의 문제들을 하위문제들을 통해서 푼다
   - 가장 하위의 문제부터 더 상위 문제를 해결하는 기법
   - DP의 테이블을 채워간다 (Tabulation)
     - **점화식**을 생성할 수 있어야 한다
     - 가장 작은 문제에 대한 해답을 구해야 한다

## **Top-Down / Bottom-Up 방식의 장단점**

1. Top-Down
   - 장점
     - 설계하기 더 쉽다
     - 가지치기, backtracking, retun 조건 등만 생각하고 구성하면 된다
   - 단점
     - 재귀호출, return 취합 등으로 비교적 느리다
     - 모든 문제를 풀지 않는다 (내가 풀어야 하는 문제만 푼다)
2. Bottom-Up
   - 장점
     - 최하위 문제로부터 N까지 모든 문제를 푼다
   - 단점
     - 점화식 구성이 필요하므로 상대적으로 어렵다

---

## 예제 #1
> ### **피보나치 수열**
> N번째 피보나치 수열을 구해라  

- 본 문제를 재귀로 풀면 중복된 연산을 반복하게 된다

*cf) 피보나치 수열*  
`1 1 2 3 5 8 13 21`  
*점화식 : fib_(n) = fib_(n-1) + fib_(n-2)*

### 재귀만으로 구현

``` C++
int fibo(int now) {
	if (now <= 2)
		return 1;

  int a = fibo(now - 1);
  int b = fibo(now - 2);

	return a + b;
}

int main()
{
	int N;
	cin >> N;
	cout << fibo(N);

	return 0;
}
```

**40 이상의 수를 구할때 계산이 오래 걸린다**

### top-down로 구현

``` C++
int dp[101];

int fibo(int now) {
	if (now <= 2)
		return 1;

	if(dp[now] != 0)
		return dp[now];

	int a = fibo(now - 1);
  int b = fibo(now - 2);

  dp[now] = a + b;

	return a + b;
}

int main()
{
	int N;
	cin >> N;
	cout << fibo(N);

	return 0;
}
```

### botton-up로 구현

``` C++
int dp[101];

int main()
{
	int N;

	cin >> N;

	dp[1] = 1;
	dp[2] = 1;

	for (int i = 3; i <= N; i++)
		dp[i] = dp[i - 2] + dp[i - 1];

	cout << dp[N];

	return 0;
}
```

---

## 예제 #2

> ### **거스름돈 문제**
>
> 거스름돈 1200원을 5가지의 동전  
> 10 / 50 / 100 / 400 / 500을 통해  
> 최소한의 개수로 돌려주는 방법

### top-down로 구현

기저조건
- 정답인 경우 (now == 0)
  - 0원은 동전 0개가 필요
  - 정답에 영향을 주지 않는 값을 리턴
- 오답인 경우 (now < 0)
  - 동전 21e+08개
  - 정답에 영향을 주는 값을 리턴
    - 정답이 될 수 없는 값

``` C++
int dp[10001];
int target;
int N;
int coins[100];

int func(int now) {
	if (now == 0)
		return 0;
	if (now < 0)
		return 21e+08;

	if (dp[now] != 0)
		return dp[now];

	int MIN = 21e+08;
	for (int i = 0; i < N; i++)
	{
		int temp = func(now - coins[i]) + 1;
		if (temp < MIN)
			MIN = temp;
	}

	return dp[now] = MIN;
}

int main()
{
	cin >> target >> N;

	for (int i = 0; i < N; i++)
		cin >> coins[i];

	cout << func(target);

	return 0;
}
```

### bottom-up로 구현

``` C++
int dp[10001];
int target;
int N;
int coins[100];

int main()
{
	cin >> target >> N;

	for (int i = 0; i < N; i++)
		cin >> coins[i];
	
	for (int i = 0; i <= target; i++)
		dp[i] = 21e+08;

	dp[0] = 0;

	for (int i = 0; i < N; i++)
	{
		int now = coins[i];
		for (int j = now; j <= target; j++)
		{
			if (dp[j - now] + 1 < dp[j])
				dp[j] = dp[j - now] + 1;
		}
	}
	
	cout << dp[target];

	return 0;
}
```

---

## 예제 #3

> ### **지게차 문제**