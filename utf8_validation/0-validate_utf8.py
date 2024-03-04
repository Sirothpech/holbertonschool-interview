#!/usr/bin/python3


def validUTF8(data):
    """Determine if a given data set represents a valid UTF-8 encoding."""
    # Number of bytes expected for the next UTF-8 character
    expected_bytes = 0

    for num in data:
        # Check if the current byte is a continuation byte
        if expected_bytes == 0:
            if (num >> 7) == 0b0:
                continue
            elif (num >> 5) == 0b110:
                expected_bytes = 1
            elif (num >> 4) == 0b1110:
                expected_bytes = 2
            elif (num >> 3) == 0b11110:
                expected_bytes = 3
            else:
                return False
        else:
            # Check if the current byte is a continuation byte
            if (num >> 6) != 0b10:
                return False
            expected_bytes -= 1

    # Check if there are remaining expected bytes
    return expected_bytes == 0
