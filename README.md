# Test_Manager

*Test Manager* is a bit of an involved tester. It's designed to be adaptable to various types of deterministic (i.e, exactly one output per input) programs. It's designed to allow you to test your programs most likely *without* needing to change the way your program prints it's output. This application attempts to figure out (with your help) where it can test the desired inputs, and where it can see the output of your program to see if it's what it should be. The way it works is this:

1. You find an application you want to test.
2. With *Test Manager*, you select to create a new tester. You select which program you want to test, which directory to store it in, what to name the tester, the sequence of inputs to get to the specific input *you* want to test, and how many lines down on the program we can begin to find the output (where you need to get quite involved). 
3. Suppose you create tester `x`.You'll get a new folder named `x`, and inside of it will contain all data of the tester. Upon creatioin, you'll have a `.meta` file, which is used to store the name of the program you are testing, as well as the number of lines down on the output we are trying to verify is correct. Also is a `.input` file, and here contains the input to get to the exact input we are testing (e.g., we need to get through a switch and some other general input statements until we get to the one we are trying to test).
4. From here, you can add tests to the tester. After adding records, you'll get a `.tests` file.
5. Once you have actual tests, you can begin testing your program! Just select to run a tester, select which one, and bam! *Test_Manager* will begin running your program and testing the outputs of your desired input.
