import collections

def groupAnagrams(strs):
        str_dic = collections.defaultdict(list)
        for s in strs:
            str_dic[tuple(sorted(s))].append(s)
        return str_dic.values()


def groupAnagrams0(strs):
        str_dic = collections.defaultdict(list)
        for s in strs:
            count = [0] * 26
            for c in s:
                count[ord(c) - ord('a')] += 1
            str_dic[tuple(count)].append(s)
        return str_dic.values()


def groupAnagrams1(strs):
    str_dic = {}
    for s in strs:
        str_dic[tuple(sorted(s))] = str_dic.get(tuple(sorted(s)), []) + [s]
    return str_dic.values()

# print(groupAnagrams(["eat", "tea", "tan", "ate", "nat", "bat"]))
print(groupAnagrams0(["eat", "tea", "tan", "ate", "nat", "bat"]))
# print(groupAnagrams1(["eat", "tea", "tan", "ate", "nat", "bat"]))