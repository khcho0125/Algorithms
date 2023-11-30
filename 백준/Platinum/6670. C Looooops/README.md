# [Platinum V] C Looooops - 6670 

[문제 링크](https://www.acmicpc.net/problem/6670) 

### 성능 요약

메모리: 1116 KB, 시간: 0 ms

### 분류

확장 유클리드 호제법, 수학, 정수론

### 제출 일자

2023년 11월 30일 14:20:49

### 문제 설명

<p>A Compiler Mystery: We are given a C-language style for loop of type</p>

<pre>for (variable = A; variable != B; variable += C)
  statement;</pre>

<p>I.e., a loop which starts by setting variable to value A and while variable is not equal to B, repeats statement followed by increasing the variable by C. We want to know how many times does the statement get executed for particular values of A, B and C, assuming that all arithmetics is calculated in a k-bit unsigned integer type (with values 0 <= x < 2<sup>k</sup>) modulo 2<sup>k</sup>.</p>

### 입력 

 <p>The input consists of several instances. Each instance is described by a single line with four integers A, B, C, k separated by a single space. The integer k (1 <= k <= 32) is the number of bits of the control variable of the loop and A, B, C (0 <= A, B, C < 2<sup>k</sup>) are the parameters of the loop.</p>

<p>The input is finished by a line containing four zeros.</p>

### 출력 

 <p>The output consists of several lines corresponding to the instances on the input. The i-th line contains either the number of executions of the statement in the i-th instance (a single integer number) or the word FOREVER if the loop does not terminate.</p>

<p> </p>

