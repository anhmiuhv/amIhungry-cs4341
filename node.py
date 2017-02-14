class Node:
    #parents format: array of ids example: [1,2]
    #cpt format example: {['true', 'true']: 0.2
    #the first element in nature is true used in cpt
    def __init__(self,name, characters = {}, parents, cpt, nature = []):
        self.name = name
        #dictionary for root node, is a string : float array
        self.characters = characters
        #list of node the parents
        self.parents = parents
        #dictionary of string : float
        self.cpt = cpt
        self.status = ''
    
    def __hash__(self):
        return self.name
    
    def setStatus(self, status):
        self.status = status
    
    def translateParent(self):
        str = ''
        for p in self.parents:
            str+=p.status
        
        return str

    