**CS4341**

**Assignment \#3**

**Due: 2/17/17 @ 11:59 p.m.**

This assignment will familiarize you with probability, as well as with
using simulations to answer questions.

Part 1: warmup
==============

Given the following probabilities:

P(good quiz grades) = 0.8

P(pass) = 0.9

P(good quiz grades | pass) = 0.8

What is P(pass | good quiz grades)?

What is P(pass \^ good quiz grades)?

Part 2: rejection sampling
==========================

You will implement the rejection sampling algorithm to estimate
probabilities. Reading in arbitrary graphs (as well as their associated
CPTs) is fairly challenging. Therefore, you will only need to implement
rejection sampling on the following graph:

![](media/image01.png){width="4.697916666666667in" height="3.375in"}

With the following CPTs:

Humidity (low, medium, high):

           Probability
  -------- -------------
  Low      0.2
  Medium   0.5
  High     0.3

Temperature (warm, mild, cold):

         Probability
  ------ -------------
  Warm   0.1
  Mild   0.4
  Cold   0.5

Icy (true, false):

  Humidity   Temperature   Probability(icy=true)
  ---------- ------------- -----------------------
  Low        Warm          0.001
  Low        Mild          0.01
  Low        Cold          0.05
  Medium     Warm          0.001
  Medium     Mild          0.03
  Medium     Cold          0.2
  High       Warm          0.005
  High       Mild          0.01
  High       Cold          0.35

Snow (true, false):

  Humidity   Temperature   Probability(snow=true)
  ---------- ------------- ------------------------
  Low        Warm          0.00001
  Low        Mild          0.001
  Low        Cold          0.1
  Medium     Warm          0.00001
  Medium     Mild          0.0001
  Medium     Cold          0.25
  High       Warm          0.0001
  High       Mild          0.001
  High       Cold          0.4

Day (weekend, weekday):

            Probability
  --------- -------------
  weekend   0.2
  weekday   0.8

Cloudy (true, false)

  Snow    Probability(cloudy=true)
  ------- --------------------------
  false   0.3
  true    0.9

Exams (true, false)

  Snow    Day       P(exams=true)
  ------- --------- ---------------
  false   Weekend   0.001
  false   Weekday   0.1
  true    Weekend   0.0001
  true    Weekday   0.3

Stress (high, low)

  Snow    Exams   P(stress=high)
  ------- ------- ----------------
  false   false   0.01
  false   true    0.2
  true    false   0.1
  true    true    0.5

This network is somewhat whimsical, and not guaranteed to correspond to
reality.

Inputs:
-------

Your program should be invoked as follows:

sample &lt;query node&gt; \#iterations &lt;observed nodes&gt;

For example:

sample humidity=low 50000 day=weekday snow=true

sample cloudy=false 1000

sample snow=true 20000 cloudy=true temperature=cold exams=no

The last example would run 20,000 iterations of rejection sampling to
compute the probability that snow=true, given that cloudy=true,
temperature=cold, and exams=no

Your program only needs to handle querying on a single variable, but
must handle an arbitrary number of observed variables. You may assume
the arguments are well structured and only query on nodes that exist in
the graph. However, your program should be case insensitive:

sample cloudy=false 1000

should return the same value as

sample Cloudy=False 1000

Outputs:
--------

Your program should output the total number of samples completed, the
number of non-rejected samples, the estimated probability of the queried
node, the standard deviation (SD) of the values of that node, and the
estimated 95% confidence interval for the query.

For the 95% confidence interval, you can use the formula of mean +/-
2\*SD/sqrt(N)[^1]. For the standard deviation, you can examine all of
the individual outcomes for the variable in your simulation, and compute
the standard deviation of that.

Writeup
=======

You will analyze your network with 4 test cases. One test case should
have no observed nodes; one test case should observe the other nodes in
the network; and the other 3 test cases should fall in between (perhaps
with 2 and 4 observed nodes).

For each test case:

1.  Graph the estimated probability of the node for samples of 100, 500,
    > 1000, 10000, and 100000 samples. How many total samples do you
    > need before the estimates begin to stabilize for each query.

2.  For each test case, how many total samples are needed to get 95%
    > confidence intervals of 0.2, 0.1, 0.05, and 0.01.

Be sure that you use the *total* number of samples rather than the
number of non-rejected samples for your calculations.

What to hand in
===============

1.  Your source code

2.  Your test cases

3.  Your writeup

[^1]: This formula isn’t strictly accurate as probabilities are bounded
    in the range \[0, 1\]. However, it is good enough for this
    assignment.
