from node import Node
from dictionary import *
from random import randint

def prob(chance):
    i = randint(0, 10000000)
    if chance * 10000000 > i:
        return True
    
    return False
    

def createTree():
    humidityNode = Node('humidity',dictHumidity,None,None,None)
    tempNode = Node('temperature',dictTemp,None,None,None)
    dayNode = Node('day',dictDay,None,None,None)
  
    icyNode = Node('icy',None,[humidityNode, tempNode],dictIcyTrue,None)
    snowNode = Node('snow',None,[humidityNode, tempNode],dictSnowTrue,None)
    cloudyNode = Node('cloudy', None, snowNode,dictCloudTrue,None)
    examNode = Node('exam', None, [snowNode,dayNode],dictExamTrue,None)
    stressNode = Node('stress', None, [snowNode,examNode], dictStressTrue, None)
    nodes = [humidityNode,tempNode,dayNode,icyNode,snowNode,cloudyNode,examNode,stressNode]
    tr= Tree(nodes)
    tr.setGod([humidityNode, tempNode, dayNode])
    return tr
    
class Tree:
    def __init__(self, nodes):
        self.nodes = nodes
    
    #god is the three top nodes of the tree
    def setGod(self, god):
        self.god = god
        
    #def startTree(self):
        
        