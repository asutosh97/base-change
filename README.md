# Base Change Program

A robust C program that converts numbers between different bases (2-20) with a clean, user-friendly interface.

## Features

- **Wide Base Support**: Convert between any bases from 2 to 20
- **Interactive Interface**: User-friendly prompts and error handling
- **Input Validation**: Comprehensive validation for both base and value inputs
- **Multiple Conversions**: Perform multiple conversions in a single session
- **Clean Architecture**: Well-structured, modular code following C best practices

## Supported Bases

- **Bases 2-10**: Standard numeric representation (0-9)
- **Bases 11-20**: Alphanumeric representation (0-9, A-J)

## Quick Start

### Compilation

```bash
gcc -Wall -Wextra -std=c99 -o base_change main.c definitons.c atoi.c
```

### Running the Program

```bash
./base_change
```

## Usage Examples

### Example 1: Binary to Decimal
```
Enter the source base: 2
Enter the value: 1010
Enter the target base: 10
The answer is: 10
```

### Example 2: Decimal to Hexadecimal
```
Enter the source base: 10
Enter the value: 255
Enter the target base: 16
The answer is: FF
```

### Example 3: Hexadecimal to Binary
```
Enter the source base: 16
Enter the value: A3
Enter the target base: 2
The answer is: 10100011
```

## Project Structure

```
base-change/
├── README.md           # Project documentation
├── base_change.h       # Header file with declarations and constants
├── main.c             # Main program with user interface
├── definitons.c       # Base conversion function implementations
├── atoi.c            # Custom string to integer conversion
└── .gitignore        # Git ignore rules
```

## Code Architecture

### Header File (`base_change.h`)
- Constants and configuration
- Function declarations
- Error codes and return values

### Main Program (`main.c`)
- **`main()`**: Program entry point and main loop
- **`get_base_input()`**: Handles base input and validation
- **`get_value_input()`**: Handles value input and validation
- **`convert_to_decimal()`**: Converts input to decimal representation
- **`print_result()`**: Formats and displays the result
- **`clear_input_buffer()`**: Manages input buffer properly
- **`wait_for_enter()`**: User interaction helper

### Conversion Functions (`definitons.c`)
- **`twotonine_to_decimal()`**: Converts bases 2-10 to decimal
- **`decimal_to_twotonine()`**: Converts decimal to bases 2-10
- **`elevenup_to_decimal()`**: Converts bases 11-20 to decimal
- **`decimal_to_elevenup()`**: Converts decimal to bases 11-20
- **`twotonine_check()`**: Validates input for bases 2-10
- **`elevenup_check()`**: Validates input for bases 11-20
- **`strrev()`**: String reversal utility

### Utility Functions (`atoi.c`)
- **`a2i()`**: Custom ASCII to integer conversion with validation

## Input Validation

The program includes comprehensive input validation:

- **Base Range**: Only accepts bases between 2 and 20
- **Character Validation**: Ensures input characters are valid for the specified base
- **Format Checking**: Validates input format and handles edge cases
- **Error Recovery**: Provides clear error messages and retry options

## Error Handling

- **Invalid Base**: Clear messages for out-of-range bases
- **Invalid Characters**: Specific feedback for invalid characters in values
- **Input Buffer Management**: Proper handling of stdin to prevent input issues
- **Graceful Recovery**: User can retry after errors without restarting

## Best Practices Implemented

- **No `goto` Statements**: Uses structured programming with proper loops
- **Modular Design**: Functions have single responsibilities
- **Consistent Naming**: Clear, descriptive variable and function names
- **Input Safety**: Bounds checking and buffer overflow prevention
- **Memory Safety**: Proper string handling and buffer management
- **Portability**: No OS-specific system calls
- **Code Documentation**: Comprehensive comments and documentation

## Contributing

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/amazing-feature`)
3. Commit your changes (`git commit -m 'Add some amazing feature'`)
4. Push to the branch (`git push origin feature/amazing-feature`)
5. Open a Pull Request

## Development

### Compilation with Debug Info
```bash
gcc -Wall -Wextra -std=c99 -g -o base_change main.c definitons.c atoi.c
```

### Running Tests
You can test various scenarios:
```bash
# Test with different bases
echo -e "10\n123\n2\nn" | ./base_change    # Decimal to Binary
echo -e "16\nFF\n10\nn" | ./base_change     # Hex to Decimal
echo -e "2\n1010\n8\nn" | ./base_change     # Binary to Octal
```

## License

This project is open source and available under the MIT License.

## Version History

- **v2.0** (Current): Complete refactoring with modern C practices
  - Eliminated `goto` statements
  - Added modular architecture
  - Improved error handling
  - Enhanced user experience
  
- **v1.0**: Initial implementation with basic functionality