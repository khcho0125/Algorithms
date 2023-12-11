# [Platinum V] RSA - 13618 

[문제 링크](https://www.acmicpc.net/problem/13618) 

### 성능 요약

메모리: 1148 KB, 시간: 0 ms

### 분류

오일러 피 함수, 분할 정복을 이용한 거듭제곱, 확장 유클리드 호제법, 수학, 모듈로 곱셈 역원, 정수론

### 제출 일자

2023년 12월 11일 18:37:58

### 문제 설명

<p>O algoritmo RSA é um dos algoritmos de criptografia mais utilizados e é considerado uma das alternativas mais seguras existentes. Seu funcionamento básico é descrito a seguir.</p>

<p>Dois números primos ímpares P e Q são escolhidos e calcula-se N = PQ. A seguir é calculada a função totiente φ(N) = (P − 1)(Q − 1) e um inteiro e satisfazendo 1 < E < φ(N) é escolhido de forma que mdc(φ(N), e) = 1. Finalmente é calculado o inteiro D, o inverso multiplicativo de e módulo φ(N), ou seja, o inteiro D satisfazendo DE = 1 (mod φ(N)).</p>

<p>Assim obtemos a chave pública, formada pelo par de inteiros N e E, e a chave secreta, formada<br>
pelos inteiros N e D.</p>

<p>Para criptografar uma mensagem M, com 0 < M < N, calcula-se C = M<sup>e</sup> (mod N), e C é a mensagem criptografada. Para descriptografá-la, ou seja, para recuperar a mensagem original, basta calcular M = C<sup>d</sup> (mod n). Note que, para isso, a chave secreta deve ser conhecida, não sendo suficiente o conhecimento da chave pública. Note ainda que a expressão x = 1 (mod y) usada acima equivale a dizer que y é o menor natural tal que o resto da divisão de x por y é 1.</p>

<p>Neste problema você deve escrever um programa para quebrar a criptografia RSA.</p>

### 입력 

 <p>A única linha da entrada contém três inteiros N, E, e C, onde 15 ≤ N ≤ 10<sup>9</sup> , 1 ≤ E < N e 1 ≤ C < N, de forma que N e E constituem a chave pública do algoritmo RSA descrita acima e C é uma mensagem criptografada com essa chave pública.</p>

### 출력 

 <p>Seu programa deve produzir uma única linha, contendo um único inteiro M, 1 ≤ M < N , a mensagem original.</p>

