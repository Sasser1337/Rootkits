<h2 align="center">Rootkits.c</h2>

<p align="center"><a href="https://github.com/Sasser1337/Rootkits/stargazers"><img src="https://img.shields.io/github/stars/Sasser1337/Rootkits" alt="Stars Badge"/></a> <a align="center">
<a href="https://github.com/Sasser1337/awesome-github-profile-readme/network/members"><img src="https://img.shields.io/github/forks/Sasser1337/Rootkits" alt="Forks Badge"/></a> <a align="center">
<a href="https://github.com/Sasser1337/Rootkits/blob/master/LICENSE"><img src="https://img.shields.io/github/license/Sasser1337/Rootkits?color=2b9348" alt="License Badge"/></a> <a align="center">

<i> How does this code work? </i>

<h2> Creating the Rootkit File: </h2>

- The program first attempts to create a file named `/etc/rootkit.c,` which will be used to store the rootkit's code. If the file creation fails, the program prints an error message and exits.

<h2> Writing the Rootkit Code: </h2>

<i> The program writes C code that is part of the rootkit into the newly created file. This code attempts to do dangerous things: <i>

- It changes the permissions of the `/etc/rootkit.c` file so that it cannot be read or executed by anyone, with the intention of hiding the rootkit's code.

- It creates a backdoor by using system commands to open a network connection that allows remote high-privileged shell access without authorization.

<h2> Closing the File: </h2>

- After writing the rootkit code into the file, the program closes the file.

<h2> Compiling the Rootkit:  </h2>

- The program attempts to compile the written rootkit code into an executable using the `gcc` command.

<h2> Changing Rootkit Permissions: </h2>

- The program changes the permissions of the rootkit to make it executable by users with the appropriate access rights.

<h2> Executing the Rootkit: </h2>

- Finally, the program runs the created rootkit with the command `system("/etc/rootkit")`.

<i> How to use this? use your :brain: <i>



