from typing import List

from test_framework import generic_test


def h_index(citations: List[int]) -> int:
    citations.sort(reverse=True)
    h_index = 0
    for c in citations:
        if h_index + 1 > c:
            break
        h_index += 1
    return h_index


if __name__ == '__main__':
    exit(generic_test.generic_test_main('h_index.py', 'h_index.tsv', h_index))
