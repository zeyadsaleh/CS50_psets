def lines(a, b):
    """Return lines in both a and b"""
    lines = []
    for x in a.split("\n"):
        for y in b.split("\n"):
            if x == y:
                lines.append(x)
    lines = list(dict.fromkeys(lines))
    return lines

def sentences(a, b):
    """Return sentences in both a and b"""
    from nltk.tokenize import sent_tokenize
    sentences = []
    for x in sent_tokenize(a):
        for y in sent_tokenize(b):
            if x == y:
                sentences.append(x)
    sentences = list(dict.fromkeys(sentences))
    return sentences

def substrings(a, b, n):
    """Return substrings of length n in both a and b"""
    def sub(s, m):
        subs = []
        k = 0
        for i in range (len(s)):
            subs.append((s[k:(k + m)]))
            k = k + 1
            if((k + m) > len(s)):
                break
        if m > len(s):
           subs.clear()
        return subs
    substrings = []
    for x in sub(a, n):
        for y in sub(b, n):
            if x == y:
                substrings.append(x)
    substrings = list(dict.fromkeys(substrings))
    return substrings
