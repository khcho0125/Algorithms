# [Platinum V] Bonus Cards - 9580 

[문제 링크](https://www.acmicpc.net/problem/9580) 

### 성능 요약

메모리: 80428 KB, 시간: 188 ms

### 분류

조합론, 다이나믹 프로그래밍, 수학

### 제출 일자

2023년 11월 21일 15:46:15

### 문제 설명

<p>Dmitry loves programming competitions very much. The Finals of the famed Champions League are taking place in Dmitry’s home city, so he wants to visit the competition. The competition is very popular, but most tickets to the competition are reserved for VIPs and for sponsors.</p>

<p>For the general public tickets to the Champions League Finals are distributed in the following way. Spectators, that want to see the competition, submit their request that states the payment method they want to use to pay for their ticket. Suppose there are n seats available. Several draw round are conducted. In each round every request that is not yet fulfilled receives some number of slots depending on the payment method. Then one of those slots is selected uniformly at random. The request to which this slot belongs is considered fulfilled and does not take part in subsequent drawing rounds. Draw ends after n rounds or when there are no more unfulfilled requests, whichever occurs first. An International Card Processing Corporation (ICPC) is a sponsor of the Champions League. Those who chose ICPC card as a payment method receive two slots in each draw round, while users of other payment methods receive only one.</p>

<p>Dmitry has a card from ICPC, but he also has a card from Advanced Credit Merchandise (ACM), which offers him a bonus on all his spendings. His brother Petr works in a company that conducts draw to distribute tickets, so he told Dmitry in advance how many people had already decided to use ICPC card and how many had decided to use other methods. Now Dmitry want to know the probabilities he would get a ticket if he would use his ICPC card or if he would use his ACM card, so that he can make an informed choice. His request is going to be in addition to the number of requests Petr had told him about.</p>

<p>Can you help?</p>

### 입력 

 <p>The first and the only line of the input contains 3 integer numbers — the number of seats available for a draw n (1 ≤ n ≤ 3000), the number of requests with ICPC card as a payment method a, and the number of requests with other payment methods b (0 ≤ a, b ≤ 10<sup>9</sup>).</p>

### 출력 

 <p>On the first line output the probability of getting a ticket using ICPC card. On the second line output the probability of getting a ticket using ACM card. Answers should have an absolute error of no more than 10<sup>-9</sup>.</p>

