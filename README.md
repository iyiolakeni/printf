##Algorithm

1. Determine the requirements: Before starting the implementation of the custom printf library, determine the requirements that the library needs to fulfill. This includes identifying the input arguments, output format, supported format specifiers, and other requirements.
Ouptut Formats:
*Standard output stream
Local Buffer of size 1024 to write as little as possible

Supported Format Specifiers:
c, s, %, d, i, b(unsigned int is converted to binary), u, o, x, X, S (string), \x,
p, +, space, #, l, h, 0, -, r(prints the reversed string), R(prints the rot13'ed string)
Input Arguments:
Format- string
Process: diagram for clarity

2. Define the function signature: Once the requirements are identified, define the function signature for the custom printf function. This should include the name of the function, the input arguments, and the output format.
int _printf(const char *format, ....)
3. Include the necessary header files: The custom printf library will require certain header files such as stdio.h, stdarg.h, and string.h. Make sure to include these header files at the beginning of the source code.

4. Initialize a va_list object: The custom printf function must use variable argument lists to receive arguments of different types. The va_list object must be initialized using the va_start() function.

5. Parse the format string: The custom printf function should iterate through the format string to identify the format specifiers. Format specifiers are identified by a percent sign (%) followed by a single character that indicates the type of argument.

6. Handle each format specifier: Once a format specifier is identified, the custom printf function should extract the corresponding argument from the variable argument list using the va_arg() function. Then, it should format the argument according to the specified format and output it to the console using standard output functions such as printf() or putchar().

7. Handle errors: The custom printf function should handle errors such as invalid format specifiers, missing arguments, or invalid input.

8. Clean up: After processing all format specifiers, the va_list object must be cleaned up using the va_end() function.

9. Test the library: Test the custom printf library with different input arguments and format specifiers to ensure that it works as expected.

10. Document the library: Document the custom printf library with clear and concise instructions on how to use it, including the supported format specifiers, input arguments, and output format.

![Printf implementation](https://user-images.githubusercontent.com/86264371/228095940-37008285-de33-451d-a003-47a30d2ceb02.png)

##Contributors

[Iyioluwa Awe](https://github.com/Iyiolakeni)

[TsitsiNdhlovu](https://github.com/TsitsiNdhlovu)

