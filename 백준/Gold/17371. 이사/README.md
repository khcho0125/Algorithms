# [Gold I] 이사 - 17371 

[문제 링크](https://www.acmicpc.net/problem/17371) 

### 성능 요약

메모리: 1140 KB, 시간: 4 ms

### 분류

기하학(geometry), 그리디 알고리즘(greedy)

### 문제 설명

<p>혜아는 답답한 3차원 세계를 벗어나 자유로운 2차원 좌표계 위로 집을 옮길 계획이다. 이 좌표계에는 그 어떤 위치에도 주거할 수 있는 시설이 있기 때문에 혜아는 두 실수 <em>H<sub>x</sub></em>, <em>H<sub>y </sub></em>를 골라 좌표 (<em>H<sub>x</sub></em>, <em>H<sub>y</sub></em>)로 이사할 것이다.</p>

<p>이사할 집의 위치를 결정하기 위해 절대적으로 중요한 것은 편의시설이 집으로부터 얼마나 멀리 떨어져 있느냐는 점이다. 좌표계에는 <em>N</em>개의 편의시설이 있는데, 좌표계의 주거지역 정책에 따라 <em>x</em>, <em>y</em> 좌표가 모두 정수인 곳에만 편의시설이 있다.</p>

<p>혜아는 <em>N</em>개의 편의시설로 이동하는 데 드는 거리의 평균값이 최소가 되는 좌표로 이사를 가고 싶었지만, 이런 좌표를 찾는 것이 너무 어렵다는 것을 깨달았다. 그래서 그나마 좌표를 찾기 쉽도록 가장 가까운 편의시설까지의 거리와 가장 먼 편의시설까지의 거리의 평균이 최소가 되는 좌표로 이사하려고 한다. 이 좌표계에서 거리는 유클리드 거리를 사용하여, 두 좌표 (<em>A<sub>x</sub></em>, <em>A<sub>y</sub></em>)와 (<em>B<sub>x</sub></em>, <em>B<sub>y</sub></em>) 사이의 거리는 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-msqrt><mjx-sqrt><mjx-surd><mjx-mo class="mjx-sop"><mjx-c class="mjx-c221A TEX-S1"></mjx-c></mjx-mo></mjx-surd><mjx-box style="padding-top: 0.08em;"><mjx-mo class="mjx-n"><mjx-c class="mjx-c28"></mjx-c></mjx-mo><mjx-msub><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D434 TEX-I"></mjx-c></mjx-mi><mjx-script style="vertical-align: -0.15em;"><mjx-mi class="mjx-i" size="s"><mjx-c class="mjx-c1D465 TEX-I"></mjx-c></mjx-mi></mjx-script></mjx-msub><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-c2212"></mjx-c></mjx-mo><mjx-msub space="3"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D435 TEX-I"></mjx-c></mjx-mi><mjx-script style="vertical-align: -0.15em;"><mjx-mi class="mjx-i" size="s"><mjx-c class="mjx-c1D465 TEX-I"></mjx-c></mjx-mi></mjx-script></mjx-msub><mjx-msup><mjx-mo class="mjx-n"><mjx-c class="mjx-c29"></mjx-c></mjx-mo><mjx-script style="vertical-align: 0.289em;"><mjx-mn class="mjx-n" size="s"><mjx-c class="mjx-c32"></mjx-c></mjx-mn></mjx-script></mjx-msup><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-c2B"></mjx-c></mjx-mo><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-c28"></mjx-c></mjx-mo><mjx-msub><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D434 TEX-I"></mjx-c></mjx-mi><mjx-script style="vertical-align: -0.15em;"><mjx-mi class="mjx-i" size="s"><mjx-c class="mjx-c1D466 TEX-I"></mjx-c></mjx-mi></mjx-script></mjx-msub><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-c2212"></mjx-c></mjx-mo><mjx-msub space="3"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D435 TEX-I"></mjx-c></mjx-mi><mjx-script style="vertical-align: -0.15em;"><mjx-mi class="mjx-i" size="s"><mjx-c class="mjx-c1D466 TEX-I"></mjx-c></mjx-mi></mjx-script></mjx-msub><mjx-msup><mjx-mo class="mjx-n"><mjx-c class="mjx-c29"></mjx-c></mjx-mo><mjx-script style="vertical-align: 0.289em;"><mjx-mn class="mjx-n" size="s"><mjx-c class="mjx-c32"></mjx-c></mjx-mn></mjx-script></mjx-msup></mjx-box></mjx-sqrt></mjx-msqrt></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><msqrt><mo stretchy="false">(</mo><msub><mi>A</mi><mi>x</mi></msub><mo>−</mo><msub><mi>B</mi><mi>x</mi></msub><msup><mo stretchy="false">)</mo><mn>2</mn></msup><mo>+</mo><mo stretchy="false">(</mo><msub><mi>A</mi><mi>y</mi></msub><mo>−</mo><msub><mi>B</mi><mi>y</mi></msub><msup><mo stretchy="false">)</mo><mn>2</mn></msup></msqrt></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$\sqrt{(A_x-B_x)^2+(A_y-B_y)^2}$</span></mjx-container>으로 나타난다고 할 때, 혜아를 도와 가능한 위치 중 하나를 구해 주는 프로그램을 작성해보자.</p>

### 입력 

 <p>첫 번째 줄에 편의시설의 개수 <em>N</em>(1 ≤ <em>N</em> ≤ 10<sup>3</sup>)이 주어진다.</p>

<p>다음 <em>N</em>개의 줄의 각 줄에는 두 정수 <em>x</em>와 <em>y</em>(-10<sup>4</sup> ≤ <em>x</em>, <em>y</em> ≤ 10<sup>4</sup>)가 공백 하나를 사이에 두고 주어진다. 이는 (<em>x</em>, <em>y</em>)에 편의시설이 하나 존재한다는 뜻이다.</p>

### 출력 

 <p>첫 번째 줄에 혜아가 이사할 곳의 좌표 (<em>H<sub>x</sub></em>, <em>H<sub>y</sub></em>)를 나타내는 두 실수 <em>H<sub>x</sub></em>, <em>H<sub>y</sub></em>를 공백 하나로 구분하여 출력한다. 가장 가까운 편의시설까지의 거리와 가장 먼 편의시설까지의 거리의 평균을 정답과 비교했을 때 절대오차 혹은 상대오차가 10<sup>-6</sup> 이하면 정답으로 인정한다.</p>

