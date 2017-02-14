# Author:
#     Khoi Doan
#     Linh Hoang
#     Sam Huang
#     Duong Nguyen


#!/usr/bin/env python3
import argparse
from dictionary import *


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
        
queryList.append(query)
queryCondition.append(condition)
print(queryList)
print(queryCondition)
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
    observedList.append(query)
    observedCondition.append(condition)
    query = ''
    condition = ''
    take = 0
    
print(observedList)
print(observedCondition)

print(dictSnowTrue)
# class Node:
#     def __init__(self, initial, condition):
#         for i in initial:
#             if i == '=':
#                 print('noob')