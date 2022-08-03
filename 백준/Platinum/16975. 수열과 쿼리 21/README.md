# [Platinum IV] 수열과 쿼리 21 - 16975 

[문제 링크](https://www.acmicpc.net/problem/16975) 

### 성능 요약

메모리: 5020 KB, 시간: 100 ms

### 분류

자료 구조(data_structures), 느리게 갱신되는 세그먼트 트리(lazyprop), 세그먼트 트리(segtree)

### 문제 설명

<p>길이가 N인 수열 A<sub>1</sub>, A<sub>2</sub>, ..., A<sub>N</sub>이 주어진다. 이때, 다음 쿼리를 수행하는 프로그램을 작성하시오.</p>

<ul>
	<li><code>1 i j k</code>: A<sub>i</sub>, A<sub>i+1</sub>, ..., A<sub>j</sub>에 k를 더한다.</li>
	<li><code>2 x</code>: A<sub>x</sub> 를 출력한다.</li>
</ul>

### 입력 

 <p>첫째 줄에 수열의 크기 N (1 ≤ N ≤ 100,000)이 주어진다.</p>

<p>둘째 줄에는 A<sub>1</sub>, A<sub>2</sub>, ..., A<sub>N</sub>이 주어진다. (1 ≤ A<sub>i</sub> ≤ 1,000,000)</p>

<p>셋째 줄에는 쿼리의 개수 M (1 ≤ M ≤ 100,000)이 주어진다.</p>

<p>넷째 줄부터 M개의 줄에는 쿼리가 한 줄에 하나씩 주어진다. 1번 쿼리의 경우 1 ≤ i ≤ j ≤ N, -1,000,000 ≤ k ≤ 1,000,000 이고, 2번 쿼리의 경우 1 ≤ x ≤ N이다. 2번 쿼리는 하나 이상 주어진다.</p>

### 출력 

 <p>2번 쿼리가 주어질 때마다 출력한다.</p>

