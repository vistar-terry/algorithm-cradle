# @Filename :   771.宝石与石头.py
# @Author :     Vistar
# @Language :   Python 3.7.7

def numJewelsInStones(J, S):
    if not J or not S:
        return 
    hashmap={}
    for i in J:
        hashmap[i]=1
    result = 0
    for i in S:
        if i in hashmap:
            result += 1
    return result

def numJewelsInStones_1(J, S):
    s_set = set(S)
    save_dict = dict(zip(s_set, [S.count(s) for s in s_set]))
    return sum([save_dict.get(j, 0) for j in J])
    

J = "aA"
S = "aAAbbbb"
print(numJewelsInStones(J,S))