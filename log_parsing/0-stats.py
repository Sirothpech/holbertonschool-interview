#!/usr/bin/python3
"""
    script that reads stdin line by line and computes metrics
"""
import sys


def print_msg(codes, file_size):
    print("File size: {}".format(file_size))
    for key, val in sorted(codes.items()):
        if val != 0:
            print("{}: {}".format(key, val))


file_size = 0
code = 0
count_lines = 0
codes = {
    "200": 0,
    "301": 0,
    "400": 0,
    "401": 0,
    "403": 0,
    "404": 0,
    "405": 0,
    "500": 0
}

try:
    for line in sys.stdin:
        parsed_line = line.split()
        parsed_line = parsed_line[::-1]

        if len(parsed_line) > 2:
            count_lines += 1

            if count_lines <= 10:
                file_size += int(parsed_line[0])
                code = parsed_line[1]

                if (code in codes.keys()):
                    codes[code] += 1

            if (count_lines == 10):
                print_msg(codes, file_size)
                count_lines = 0

finally:
    print_msg(codes, file_size)


# #!/usr/bin/python3
# """
# Write a script that reads stdin line by line and computes metrics
# """
# import sys

# def print_stats(total_size, status_codes):
#     """
#     Prints the total file size and the count of each status code.
#     """
#     print(f"File size: {total_size}")
#     for code, count in sorted(status_codes.items()):
#         print(f"{code}: {count}")

# if __name__ == "__main__":
#     total_size = 0
#     status_codes = {"200": 0, "301": 0, "400": 0, "401": 0, "403": 0, "404": 0,
#                     "405": 0, "500": 0}
#     line_count = 0

#     try:
#         for line in sys.stdin:
#             parts = line.split()
#             if len(parts) >= 7:
#                 status_code = parts[-2]
#                 if status_code in status_codes:
#                     status_codes[status_code] += 1
#                 total_size += int(parts[-1])
#             line_count += 1

#             if line_count % 10 == 0:
#                 print_stats(total_size, status_codes)

#     except KeyboardInterrupt:
#         print_stats(total_size, status_codes)
#         raise
