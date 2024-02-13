#!/usr/bin/python3
import sys

def print_stats(total_size, status_codes):
    print(f"File size: {total_size}")
    for code, count in sorted(status_codes.items()):
        print(f"{code}: {count}")

def main():
    total_size = 0
    status_codes = {"200": 0, "301": 0, "400": 0, "401": 0, "403": 0, "404": 0, "405": 0, "500": 0}
    line_count = 0

    try:
        for line in sys.stdin:
            parts = line.split()
            if len(parts) >= 7:
                status_code = parts[-2]
                if status_code in status_codes:
                    status_codes[status_code] += 1
                total_size += int(parts[-1])
            line_count += 1

            if line_count % 10 == 0:
                print_stats(total_size, status_codes)

    except KeyboardInterrupt:
        print_stats(total_size, status_codes)
        raise

if __name__ == "__main__":
    main()
