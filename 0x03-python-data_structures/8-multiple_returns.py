#!/usr/bin/python3
def multiple_returns(sentence):
    """Returns a tuple: (length of sentence, first character or None)."""
    if sentence == "":
        return (0, None)
    return (len(sentence), sentence[0]
