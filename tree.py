from node import Node
from dictionary import *


    
class Tree:
    def __init__(self, nodes):
        self.nodes = nodes
    
    def createTree(self):
        humidityNode = Node('humidity',dictHumidity,None,None,None)
        tempNode = Node('temperature',dictTemp,None,None,None)
        dayNode = Node('day',dictDay,None,None,None)
        
        icyNode = Node('icy',None,[humidityNode, tempNode],dictIcyTrue,None)
        snowNode = Node('snow',None,[humidityNode, tempNode],dictSnowTrue,None)
        cloudyNode = Node('cloudy', None, snowNode,dictCloudTrue,None)
        examNode = Node('exam', None, [snowNode,dayNode],dictExamTrue,None)
        stressNode = Node('stress', None, [snowNode,examNode], dictStressTrue, None)
        nodes = [humidityNode,tempNode,dayNode,icyNode,snowNode,cloudyNode,examNode,stressNode]
    #     humidity = node.Node("humidity", characters = {"low": 0.2, "medium": 0.5, "high": 0.3})
    #     temperature = node.Node("temperature", characters= {"warm": 0.1, "mild": 0.4, "cold": 0.5})
    #     nodes = [humidity, temperature]
    #     icycpt = {"lowwarm": 0.001,
    #               "lowmild": 0.01,
    #               "lowcold": 0.05,
    #               "mediumwarm": 0.001,
    #               "mediummild": 0.03,
    #               "mediumcold": 0.2,
    #               "highwarm": 0.005,
    #               "highmild": 0.01,
    #               "highcold": 0.35
    #         }
    #     icy = node.Node("icy", parents=[humidity, temperature], cpt=icycpt,nature = ["true", "false"])
    #     snowcpt = {"lowwarm": 0.00001,
    #                "lowmild": 0.001,
    #                "lowcold": 0.1,
    #                "mediumwarm": 0.00001,
    #                "mediummild": 0.0001,
    #                "mediumcold": 0.25,
    #                "highwarm": 0.0001,
    #                "highmild": 0.001,
    #                "highcold": 0.4 
    #                }
    #     snow = node.Node("snow",parents= [humidity, temperature], cpt=snowcpt, nature=["true", "false"])
        
        
        return Tree(nodes)
    #god is the three top nodes of the tree
    def setGod(self, god):
        self.god = god
        