# 포인터와 함수

## 함수의 인자로 배열 전달하기

배열의 각 요소를 출력하거나 특정 계산을 수행하는 함수가 있을 때, 해당 함수로 배열을 전달 하려고 합니다. 함수를 선언할 때, 함수의 인자 값에는 전달 받으려는 자료형을 선언해줘야 합니다. 마찬가지로, 배열을 전달하려 할 때, 배열을 받기 위한 자료형을 선언해줘야 합니다.

```c
#include <stdio.h>

void showArr(int * arr, int len){ // int * arr 대신, int arr[] 도 가능
	for(int i=0; i<len; i++){
		printf("%d ", arr[i]);
	}
    printf("\n");
}

int main(void)
{
    int arr[5] = {11, 22, 33, 44, 55};
    showArr(arr, sizeof(arr)/sizeof(int));

    return 0;
}
/*
11 22 33 44 55
*/
```

위 함수의 경우 배열을 전달받기 위한 인자는 `int * arr` 형태로 정의되어 있습니다. 그 이유는 배열의 이름이 배열의 첫 번째 요소를 가리키는 주소이기 때문입니다.

위 코드에서 `int len` 은 배열의 길이를 나타냅니다. 배열의 길이를 전달하는 이유는 함수 내에서 인자로 전달된 배열의 길이를 계산할 수 없기 때문입니다. 더 자세히 설명하자면, 배열이 함수에 전달될 때 ‘값에 의한 전달’이 아닌 ‘주소에 의한 전달’로 이루어지기 때문입니다. 따라서, 함수에 배열을 전달하면 실제로 전달되는 것은 배열의 첫 번째 요소의 주소를 전달하고 함수 내부에서는 이 주소만을 이용하여 배열을 조작할 수 있습니다.

## Call-by-Value, Call-by-Reference

### Call-By-Value

Call-by-Value 방식은 함수를 호출할 때 인자로 변수의 값을 복사하여 전달하는 방식입니다. 이 방법에서는 복사된 인자를 함수 내에서 처리하기 때문에 원래 변수의 값이 변경되지 않습니다. 따라서 함수 내부에서 인자의 값이 변경되더라도 호출자의 실제 인자 값에는 영향을 미치지 않습니다.

> 배열을 이용한 Call-by-Value는 실제로 가능하지 않습니다. 배열 이름은 배열의 첫 번째 요소를 가리키는 주소이며, 함수에 배열 이름을 전달하면 주소가 전달되므로, 이는 Call-by-Reference와 같습니다.
> 

```c
#include <stdio.h>

void changeValue(int x) // Call-by-Value
{
    x = 20;
}

int main(void)
{
    int x = 10;

    printf("Before function call, x = %d\n", x);
    changeValue(x);
    printf("After function call, x = %d\n", x);

    return 0;
}

/*
Before function call, x = 10
After function call, x = 10
*/
```

### Call-By-Reference

Call-by-Reference 방식은 함수를 호출할 때 인자로 변수의 주소를 전달하는 방식입니다. 이 방법에서는 함수 내에서 원래 변수의 메모리에 접근하므로 원래 변수의 값이 변경될 수 있습니다. 따라서 함수 내부에서 인자 값이 변경되면 호출자의 실제 인자 값도 변경됩니다.

> 배열의 이름이 배열의 첫 번째 요소를 가리키는 주소이므로, 배열을 함수의 인자로 전달하면 Call-by-Reference가 됩니다. 함수 내에서 이 주소를 이용하여 배열의 요소를 변경하면 원래 배열의 값도 변경됩니다.
> 

```c
#include <stdio.h>

void changeValue(int* pX) // Call-by-Reference
{
    *pX = 20;
}

int main(void)
{
    int x = 10;

    printf("Before function call, x = %d\n", x);
    changeValue(&x);
    printf("After function call, x = %d\n", x);

    return 0;
}

/*
Before function call, x = 10
After function call, x = 20
*/

```

# 예제 출력

```bash
$ gcc -o pointer_and_function.o pointer_and_function.c
$ ./pointer_and_function.o
[*] 함수의 인자 값으로 배열을 전달
11 22 33 44 55 

[*] Call-by-Value
Before function call, x = 10
After function call, x = 10

[*] Call-by-Reference
Before function call, x = 10
After function call, x = 20

[*] Call-by-Reference with Array
Before modification: 10 20 30 40 
After modification: 11 21 31 41 
```