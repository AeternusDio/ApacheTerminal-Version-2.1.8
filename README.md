This is a small/fast/cool/dumb program I made in C. It replicates a command line/terminal, 
and I did make this before, but I refactored the entire darn thing to make it more modular, cooler, with more 'shell' commands, etc. 
This is version <2.1.8>, but there will definitely be more versions coming out with even more cool programs, features, easter eggs (there are some in there), 'shell' commands, etc. 
You can also type 'help' in the terminal to get command help. Also, if you can make this better, please do.

This Version needs the readline library. If you don't have it downloaded, you can download it by entering: "sudo apt-get install libreadline-dev". 
To compile, make sure you are in the 'src' directory, then type: "gcc -o ApacheTerminal Main.c Functions/Programs/*.h -lm -lreadline".