#!/usr/bin/python3
"""
0-count
"""
import requests


def count_words(subreddit, word_list, after='', word_count=None):
    """
    Recursively queries the Reddit API, parses the titles of all hot articles,
    and prints a sorted count of given keywords.

    :param subreddit: The subreddit to search.
    :param word_list: A list of keywords to count.
    :param after: The after parameter for pagination in the Reddit API.
    :param word_count: A dictionary to keep track of keyword counts.
    """
    if word_count is None:
        word_count = {word.lower(): 0 for word in word_list}

    url = f'https://www.reddit.com/r/{subreddit}/hot.json'
    headers = {'User-Agent': 'Mozilla/5.0'}
    params = {'after': after, 'limit': 100}
    response = requests.get(url, headers=headers, params=params)

    if response.status_code != 200:
        return

    data = response.json().get('data', {})
    posts = data.get('children', [])

    for post in posts:
        title = post['data']['title'].lower()
        for word in word_list:
            word_lower = word.lower()
            word_count[word_lower] += title.split().count(word_lower)

    after = data.get('after')
    if after:
        count_words(subreddit, word_list, after, word_count)
    else:
        sorted_word_count = sorted(word_count.items(),
                                   key=lambda item: (-item[1], item[0]))
        for word, count in sorted_word_count:
            if count > 0:
                print(f'{word}: {count}')


if __name__ == "__main__":
    import sys
    if len(sys.argv) < 3:
        print("Usage: {} <subreddit> <list of keywords>".format(sys.argv[0]))
        print("Ex: {} programming 'python java javascript'"
              .format(sys.argv[0]))
    else:
        subreddit = sys.argv[1]
        word_list = [x for x in sys.argv[2].split()]
        count_words(subreddit, word_list)
