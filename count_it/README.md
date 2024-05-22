# Count it

## Description

"Count it" is a Python project that involves writing a recursive function to query the Reddit API, parse the titles of all hot articles, and print a sorted count of given keywords. The function should be case-insensitive and handle duplicates in the keyword list appropriately. The output should be sorted in descending order by count and then alphabetically if counts are equal.

## Requirements

- Prototype: `def count_words(subreddit, word_list)`
- The function must work with just a subreddit and a list of keywords.
- If the keyword list contains duplicates (case-insensitive), the final count should sum each duplicate.
- Results should be printed in descending order by count, and alphabetically (A-Z) if counts are equal.
- Words with no matches should not be printed.
- Words must be printed in lowercase.
- Results are based on keyword occurrences, not the number of titles containing the keyword.
- Keywords followed by punctuation (e.g., `java.`, `java!`, `java_`) should not count as the keyword.
- If no posts match or the subreddit is invalid, print nothing.
- Ensure not to follow redirects for invalid subreddits.
- The function must be recursive.

## Example Usage

```python
#!/usr/bin/python3
"""
0-main
"""
import sys

if __name__ == '__main__':
    count_words = __import__('0-count').count_words
    if len(sys.argv) < 3:
        print("Usage: {} <subreddit> <list of keywords>".format(sys.argv[0]))
        print("Ex: {} programming 'python java javascript'".format(sys.argv[0]))
    else:
        result = count_words(sys.argv[1], [x for x in sys.argv[2].split()])
```

### Sample Outputs

```bash
bob@dylan $ python3 0-main.py programming 'react python java javascript scala no_results_for_this_one'
java: 27
javascript: 20
python: 17
react: 17
scala: 4
bob@dylan $ python3 0-main.py programming 'JavA java'
java: 54
bob@dylan $ python3 0-main.py not_a_valid_subreddit 'python java javascript scala no_results_for_this_one'
bob@dylan $ python3 0-main.py not_a_valid_subreddit 'python java'
bob@dylan $
```

## How to Run

1. Clone the repository to your local machine.
2. Ensure you have Python installed.
3. Install the necessary Python libraries (e.g., `requests` for querying the Reddit API).
4. Use the provided `0-main.py` script to test the function with different subreddits and keyword lists.

## Important Notes

- The function should not follow redirects for invalid subreddits.
- Ensure the function is recursive and not using loops to achieve the required functionality.

## Dependencies

- Python 3.x
- `requests` library for making API calls

## Installation

1. Clone the repository:
   ```bash
   git clone <repository-url>
   ```
2. Navigate to the project directory:
   ```bash
   cd <project-directory>
   ```
3. Install the required Python packages:
   ```bash
   pip install requests
   ```

## Usage

Run the `0-main.py` script with the subreddit and keyword list as arguments:
```bash
python3 0-main.py <subreddit> '<list of keywords>'
```

Example:
```bash
python3 0-main.py programming 'python java javascript'
```
