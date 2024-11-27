<!-- INTRODUCTION -->

## INTRODUCTION 

+ **OBJECTIVE**  
  To create a library that reproduces the printf function.

+ **PROTOTYPE**
  
 `int ft_printf(const char *, ...);`

+ **REQUIREMENTS**
   - Don’t implement the buffer management of the original printf().
   - Your function has to handle the following conversions: cspdiuxX%
   - Your function will be compared against the original printf().
   - You must use the command ar to create your library.  
        Using the libtool command is forbidden.
   - Your libftprintf.a has to be created at the root of your repository.
   - Libft authorized.
   - Authorized external functions: **malloc, free, write, va_start, va_arg, va_copy, va_end**  

+ **MAKEFILE**
  - Must not relink
  - The project will be compiled with the flags **-Wall -Wextra -Werror**
  - Must at least contain the rules **$(NAME), all, clean, fclean and re**

Check the complete [subject](https://github.com/letdummer/42_ft_printf/blob/main/subject/en.subject.pdf) (version 10 - nov/2024).

<!-- !END! INTRODUCTION -->

<!-- HOW TO USE -->

## HOW TO USE  
+ Clone the repository
```
git clone git@github.com:letdummer/42_ft_printf.git
```
+ Access the local file
```
cd 42_ft_printf
```
+ Build the project
```
make
```

<!-- !end!HOW TO USE -->

<!-- TABLE OF SPECIFIERS-->
<br>  

| specifier | conversion |
|------:|---------------|
|     %c| prints a single character |
|     %s| prints a string |
|     %p|prints the address of a pointer |
|     %d|prints a decimal number|
|     %i|prints an integer|
|     %u|prints an unsigned number|
|     %x|prints a number in hexadecimal lowercase format|
|     %X|prints a number in hexadecimal uppercase format|
|     %%|prints a percent sign|

<!-- !end! TABLE OF SPECIFIERS-->

<!-- LIST OF REFERENCIES -->
<br>  

## References

[Variadic functions](https://dev.to/pauljlucas/variadic-functions-in-c-53ml)  
[Tests of paulo-santana](https://github.com/paulo-santana/ft_printf_tester)  
[Tests of tripouille](https://github.com/Tripouille/printfTester)  
</h5></p>
<!-- !end! LIST OF REFERENCIES -->
