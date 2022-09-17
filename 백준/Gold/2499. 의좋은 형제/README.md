# [Gold I] 의좋은 형제 - 2499 

[문제 링크](https://www.acmicpc.net/problem/2499) 

### 성능 요약

메모리: 66744 KB, 시간: 108 ms

### 분류

다이나믹 프로그래밍(dp), 배낭 문제(knapsack)

### 문제 설명

<p>어떤 N × N 개의 단위 구역으로 구성된 논이 있다. 각 단위 구역에서는 쌀이 생산되는데 구역에 따라서 쌀의 생산량이 다르다. 아래는 5 × 5 = 25개의 단위 구역으로 나누어진 논을 보여주고 있다. 각 구역에 적혀 있는 숫자는 예상되는 쌀의 수확량(가마)이다.</p>

<table class="table table-bordered td-center table-2499">
	<tbody>
		<tr>
			<td>3</td>
			<td>4</td>
			<td>5</td>
			<td>1</td>
			<td>8</td>
		</tr>
		<tr>
			<td>8</td>
			<td>2</td>
			<td>3</td>
			<td>2</td>
			<td>2</td>
		</tr>
		<tr>
			<td>0</td>
			<td>2</td>
			<td>9</td>
			<td>5</td>
			<td>4</td>
		</tr>
		<tr>
			<td>1</td>
			<td>11</td>
			<td>3</td>
			<td>0</td>
			<td>5</td>
		</tr>
		<tr>
			<td>4</td>
			<td>5</td>
			<td>2</td>
			<td>7</td>
			<td>1</td>
		</tr>
	</tbody>
</table>

<p>두 의좋은 형제는 이 N × N의 논을 다음과 같이 두 부분으로 나누어 형은 아래쪽에 있는 땅을 가지고, 동생은 위쪽의 땅을 가지기로 하였다. 전체 구역을 마구잡이로 나누면 기계로 농사를 짓는데 불편하기 때문에 각 형제에게 배분된 구역이 단조 증가하는 계단 모양이 되게 하려고 한다. 즉, 주어진 논을 N × N 행렬로 볼 때 형이 특정 열에서 할당받는 구역의 개수는 바로 왼쪽 열에서 받은 구역의 개수보다 크거나 같아야 한다. 예를 들어 다음 세 그림 중 그림 1과 2는 올바른 배정 방법으로, 회색 지역은 형의 논, 나머지 부분은 동생의 논이다. 그러나 그림 3은 논을 나누는 규칙을 어기는 경우이다.</p>

<p>두 형제는 논을 공평하게 나누기 위해, 위와 같은 방법들 중 각 영역의 예상 수확량의 차이가 되도록 적게 하고자 한다. 예를 들어 그림 1은 형의 예상 수확량이 48, 동생이 49로 최적인 경우이나, 그림 2는 형은 39, 동생은 58로 공평하게 나눠지지 않은 경우이다. 주어진 논을 최대한 공평하게 나누는 방법을 구하는 프로그램을 작성하라. </p>

<table class="table table-bordered td-center table-2499">
	<tbody>
		<tr>
			<td>3</td>
			<td>4</td>
			<td>5</td>
			<td>1</td>
			<td>8</td>
		</tr>
		<tr>
			<td>8</td>
			<td>2</td>
			<td>3</td>
			<td>2</td>
			<td>2</td>
		</tr>
		<tr>
			<td>0</td>
			<td>2</td>
			<td>9</td>
			<td class="b">5</td>
			<td class="b">4</td>
		</tr>
		<tr>
			<td class="b">1</td>
			<td class="b">11</td>
			<td class="b">3</td>
			<td class="b">0</td>
			<td class="b">5</td>
		</tr>
		<tr>
			<td class="b">4</td>
			<td class="b">5</td>
			<td class="b">2</td>
			<td class="b">7</td>
			<td class="b">1</td>
		</tr>
	</tbody>
</table>

<p style="text-align: center;">그림 1</p>

<table class="table table-bordered td-center table-2499">
	<tbody>
		<tr>
			<td>3</td>
			<td>4</td>
			<td>5</td>
			<td>1</td>
			<td class="b">8</td>
		</tr>
		<tr>
			<td>8</td>
			<td>2</td>
			<td>3</td>
			<td>2</td>
			<td class="b">2</td>
		</tr>
		<tr>
			<td>0</td>
			<td>2</td>
			<td>9</td>
			<td class="b">5</td>
			<td class="b">4</td>
		</tr>
		<tr>
			<td>1</td>
			<td>11</td>
			<td>3</td>
			<td class="b">0</td>
			<td class="b">5</td>
		</tr>
		<tr>
			<td>4</td>
			<td class="b">5</td>
			<td class="b">2</td>
			<td class="b">7</td>
			<td class="b">1</td>
		</tr>
	</tbody>
</table>

<p style="text-align: center;">그림 2</p>

<table class="table table-bordered td-center table-2499">
	<tbody>
		<tr>
			<td>3</td>
			<td>4</td>
			<td>5</td>
			<td>1</td>
			<td class="b">8</td>
		</tr>
		<tr>
			<td class="b">8</td>
			<td>2</td>
			<td>3</td>
			<td>2</td>
			<td class="b">2</td>
		</tr>
		<tr>
			<td class="b">0</td>
			<td>2</td>
			<td>9</td>
			<td class="b">5</td>
			<td class="b">4</td>
		</tr>
		<tr>
			<td class="b">1</td>
			<td class="b">11</td>
			<td class="b">3</td>
			<td class="b">0</td>
			<td class="b">5</td>
		</tr>
		<tr>
			<td class="b">4</td>
			<td class="b">5</td>
			<td class="b">2</td>
			<td class="b">7</td>
			<td class="b">1</td>
		</tr>
	</tbody>
</table>

<p style="text-align: center;">그림 3</p>

### 입력 

 <p>첫째 줄에 논의 크기를 나타내는 정수 N (2 ≤ N ≤ 20)이 주어진다. 둘째 줄부터 N+1번째 줄에는 각 단위 구역의 예상 수확량이 0에서 100 사이의 정수로 주어진다. 둘째 줄에는 논의 제 1행의 각 구역의 예상 수확량에 해당하는 N개의 정수가 빈칸을 사이에 두고 주어지며, 셋째 줄에는 제 2행의 각 구역의 예상 수확량에 해당하는 N개의 정수가 빈 칸을 사이에 두고 주어진다. 넷째 줄부터 N+1번째 줄도 같은 형식으로 각 줄마다 N개 정수들이 주어진다.</p>

### 출력 

 <p>첫째 줄에는 최적의 방법으로 영역을 나누었을 때의 예상 수확량 차이를 나타내는 정수를 출력하고, 둘째 줄에는 이 최적의 방법에서 논의 첫 번째 열부터 N번째 열까지 형이 배분받는 구역의 수를 나타내는 N개의 정수를 빈칸을 사이에 두고 출력한다. 방법이 여러 개인 경우 하나만 출력한다.</p>

