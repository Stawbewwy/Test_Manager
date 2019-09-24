# Test_Manager

*Test Manager* is a bit of an involved tester for Linux/Unix systems. It's
designed to be adaptable to various types of deterministic (i.e, exactly one
output per input) programs. It's designed to allow you to test your programs
most likely *without* needing to change the way your program prints it's
output. This application attempts to figure out (with your help) where it can
test the desired inputs, and where it can see the output of your program to see
if it's what it should be. The way it works is this:

## General Usage
1. You find an application you want to test.
2. With *Test Manager*, you select to create a new tester. You select which
program you want to test, which directory to store it in, what to name the
tester, the sequence of inputs to get to the specific input *you* want to test,
and how many lines down on the program we can begin to find the output (where
you need to get quite involved). 
3. Suppose you create tester `x`.You'll get a new folder named `x.TM`, and inside
of it will contain all data of the tester. Upon creatioin, you'll have a
`x.meta` file, which is used to store the name of the program you are testing,
as well as the number of lines down on the output we are trying to verify is
correct. Also is a `x.input` file, and here contains the input to get to the
exact input we are testing (e.g., we need to get through a switch and some
other general input statements until we get to the one we are trying to test).
4. From here, you can add tests to the tester. After adding records, you'll get a
`.tests` file.
5. Once you have actual tests, you can begin testing your program! Just select to
run a tester, select which one, and bam! *Test_Manager* will begin running your
program and testing the outputs of your desired input.

## Dependencies
C++17, needed for `experimental/filesystem` library.

## Warnings

### Executing Your Program
Be very careful with entering your program name in the metadata file. If you're
going to run the program from the same directory, then you may need to add a
'./' in the front to denote that you are running a program. This may depend on
what shell you are using. Just remember, that it needs to be saved to TM the
same way you would run it from whichever directory you are working in.

### How the Tests Run
There's a few things to consider when running this application. How stdout gets
printed on the screen may not be how it gets written into a buffer/ file
stream. That being said, you may need to adjust the how many lines down
considering this. One way to figure it out quickly is to redirect all of your
output to a separate file when executing the program you want to test, and then
viewing the file after your program runs (you may need to feed it input through
a file as well). This is basically the process *Test Manager* does. It simply
saves the output of your program to a file, and reads the output after
executing the program and feeding it the inputs. 

### How The Tests Get Gaved
The way tests are stored in the `.tests` file is by printing each input line by
line, and then having a '\~z\~' delimiter to indicate the end of the input you
are testing, and then line by line has each correct line of output until a
\~x\~ is encountered. That being said, this program will not work if for
whatever reason, the input you are testing is '\~z\~' or output is '\~x\~'.

### Functions Dependent on Working Directory
Unfortunately, most functions currently depend that you are in the same working
directory as your tester. Fortunately, *Test Manager* will most of the time
tell you what directory you currently are working on. Typically, you'll need to
be in the same directory that your `.TM` folder is in.
