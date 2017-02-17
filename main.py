#! /usr/bin/env python3

# Author:
#     Khoi Doan
#     Linh Hoang
#     Sam Huang
#     Duong Nguyen



import argparse
import node
import tree
from dictionary import *
from node import Node
from math import sqrt
import time
start_time = time.time()

#parsing option from users
parser = argparse.ArgumentParser(description='Please give mr.weather a needed information')
parser.add_argument('query', help='the query node')
parser.add_argument('iteration', type = int, help='the number of iteration run')
parser.add_argument('observed', nargs=argparse.REMAINDER,help='the observed node')
#parser.add_argument('observed', metavar='N', nargs='+',help='the observed node')
args = parser.parse_args()


queryList = []
queryCondition = []
query = ''
condition = ''
take = 0
for i in args.query:
    if i == '=':
        take = 1
    else:
        if take:
            condition +=i
        else:
            query += i

query = query.lower()
condition = condition.lower()

queryList.append(query)
queryCondition.append(condition)
#print(queryList)
#print(queryCondition)
observedList = []
observedCondition = []
query = ''
condition = ''
take = 0
for i in range(0,len(args.observed)):   
    for j in args.observed[i]:
        if j == '=':
            take = 1
        else:
            if take:
                condition +=j
            else:
                query += j
    query = query.lower()
    condition = condition.lower()
    observedList.append(query)
    observedCondition.append(condition)
    query = ''
    condition = ''
    take = 0

#print(observedList)
#print(observedCondition)
countobserved = 0
countquery = 0
node = Node(None,None,None,None,None)
for i in range(0, args.iteration):
    isobserved = True
    testtree = tree.createTree()
    testtree.startTree()
    for node in testtree.nodes:
        name = node.name
        if name in observedList:
            if observedCondition[observedList.index(name)] != node.status:
                isobserved = False

    if isobserved:
        countobserved += 1
        for node in testtree.nodes:
            if node.name in queryList:
                name = node.name
                if queryCondition[queryList.index(name)] == node.status:
                    countquery += 1

print("Total number of samples: ", str(args.iteration))
print("Number of non-rejected samples: ", str(countobserved))
if (countobserved != 0):
    prob = countquery/countobserved
    print("Probability of the queried node: " + str(prob))
    sd = sqrt(prob*(1-prob) )
    print("Standard deviation: " + str(sd ))
    print("95% confidence interval: " + str(prob) + " + " + str(2*sd/sqrt(countobserved))) 
else:
    print("No node with observed condition found.")
print("Time take to run: " + str(time.time() - start_time) + " s")


# print(dictSnowTrue)
# class Node:
#     def __init__(self, initial, condition):
#         for i in initial:
#             if i == '=':
#                 print('noob')
