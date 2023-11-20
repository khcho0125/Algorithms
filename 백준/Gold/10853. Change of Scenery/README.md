# [Gold I] Change of Scenery - 10853 

[문제 링크](https://www.acmicpc.net/problem/10853) 

### 성능 요약

메모리: 71676 KB, 시간: 716 ms

### 분류

데이크스트라, 그래프 이론, 최단 경로

### 제출 일자

2023년 11월 20일 12:21:13

### 문제 설명

<p>Every day you drive to work using the same roads as it is the shortest way. This is efficient, but over time you have grown increasingly bored of seeing the same buildings and junctions every day. So you decide to look for different routes. Of course you do not want to sacrifice time, so the new way should be as short as the old one. Is there another way that differs from the old one in at least one street?</p>

### 입력 

 <p>The first line of the input starts with three integers N M and K, where N is the number of junctions and M is the number of streets in your city, and K is the number of junctions you pass every day (1 ≤ K ≤ N ≤ 10 000, 0 ≤ M ≤ 1 000 000).</p>

<p>The next line contains K integers, the (1-based) indices of the junctions you pass every day. The first integer in this line will always be 1, the last integer will always be N. There is a shortest path from 1 to N along the K junctions given.</p>

<p>M lines follow. The i-th of those lines contains three integers a<sub>i</sub> b<sub>i</sub> c<sub>i</sub> and describes a street from junction a<sub>i</sub> to junction b<sub>i</sub> of length c<sub>i</sub> (1 ≤ a<sub>i</sub>, b<sub>i</sub> ≤ N, 1 ≤ c<sub>i</sub> ≤ 10 000). Streets are always undirected.</p>

<p>Note that there may be multiple streets connecting the same pair of junctions. The shortest path given uses for every pair of successive junctions a and b a street of minimal length between a and b.</p>

### 출력 

 <p>Print one line of output containing “yes” if there is another way you can take without losing time, “no” otherwise.</p>

