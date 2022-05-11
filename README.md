# 🐍 Monty Interpreter
## By Yuan Fang and Matthew Brinkmann
This is a simple interpreter for the monty coding language.
### About the language
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.
   
### Monty byte code files
   
Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:

## :arrow_down: Installing and Using

Clone the repository into a new directory:

```
$ git clone https://github.com/Matthew-brinkmann/monty
```
Compile with the following:

```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o monty
```

Run the interpreter on a file:

```
./monty file.m
```
## :computer: Technical

* [Ubuntu 20.04 LTS] - operating system

* [GCC 9.4.0] - compiled