def _frequency_gen(s: str) -> dict:
    '''
    generates a character frquency map of the given string
    '''
    freq_map = {}
    for i in s:
        freq_map[i] = freq_map.get(i,0)+1
    return freq_map

def validAnagram(s:str, t:str) -> bool:
    '''
    validates if 2 strings are anagrams of each other
    '''
    s_freq_map = _frequency_gen(s)
    t_freq_map = _frequency_gen(t)

    return s_freq_map == t_freq_map


if __name__ == '__main__':
    print(validAnagram('ollo','lool'))
    print(validAnagram('ollo','ollp'))

