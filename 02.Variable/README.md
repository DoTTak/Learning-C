# 변수

## 변수란?

변수는 데이터를 저장할 수 있는 공간을 의미합니다. 그리고 프로그램에서 사용되는 데이터를 임시로 저장하고 참조하는 데 사용됩니다.

```c
int main(void)
{
	int num; // num이라는 변수 선언
}
```

위 코드에서 `int num;` 로 선언된 부분이 변수의 선언입니다. 

여기서 `int` 는 정수를 의미하는 자료형을 가리키며, `num` 은 변수의 이름을 나타냅니다. 따라서 `num` 이라는 이름의 정수형 변수를 선언한 것이고 이 변수는 이후에 정수 값을 저장하거나 참조하는 데 사용할 수 있습니다.

> 변수의 자료형은 정수형 변수와 실수형 변수가 있습니다.
> 
> - 정수형 변수(크기 순) `char` < `short` < `int` < `long`
>     - `char`: 1바이트, `short`: 2바이트, `int`: 4바이트, `long`: 4바이트 (32비트 시스템), 8바이트 (64비트 시스템)
> - 실수형 변수(크기 순) `float` < `double`
>     - `float`: 4바이트, `double`: 8바이트

## 변수의 선언과 초기화

방금 위에서 본 `int num;` 은 변수를 선언한 것입니다. 이 선언된 변수에 처음 값을 저장하는 것을 ‘초기화’ 라고 하며, 이후에 값을 변경할 땐 ‘대입’ 이라고 합니다.

```c
int main(void)
{
	int num; // 변수 num 선언
	num = 10; // 변수 num을 10으로 초기화
	num = 20; // 변수 num에 20을 대입
}
```

변수는 동시에 여러개의 변수 선언이 가능하며, 선언과 동시에 초기화도 가능합니다.

```c
int num1, num2; // 두 개의 변수 선언
int num3=10, num4=20; // 두 개의 변수의 선언 및 초기화
```

## 변수 이름 정의 규칙

1. 변수 이름은 영문 대/소문자, 숫자, 밑줄(_) 사용 가능합니다.
    - 공백과 특수 문자를 사용 불가능합니다.
2. 변수 이름은 숫자로 시작할 수 없습니다.
3. C 언어의 키워드를 변수 이름으로 사용할 수 없습니다.

# 예제 출력

```bash
$ gcc -o variable.o variable.c
$ ./variable.o
num1: 20
num2: 20
num3: 30
num4: 40
num5: 50
```