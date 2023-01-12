# Practice exercises
[Experiment on unimportant files and directories (create those as you need). Apply to
important files after you gain sufficient confidence.]

0. Grow familiarity with Linux shell and Unix commands.
1. Explain the different behaviors of ls -l /usr and ls -l /root.
- Current user has by default, r-x permissions for /usr but has --- permissions for /root directories.

2. Enter the commands man printf and man 3 printf. Why do you get different outputs?
- man 3 printf displays the Section 3 of the printf in the manual. Section 1 by default.

3. How can you enter multiple commands in a single line?
- concatenate the comments with ';'

4. How can you enter one command in multiple lines (like ls in one line and -l in the second)?
- Use escape sequence ('\') 

5. Enter the command wc without any arguments. Write a few lines, and then hit control-d
(with the control button pressed, hit d) at the beginning of a new line. See what happens.
Explain the output. What does control-d do here?
- The programme allows us to enter some text in the terminal, after having at least one line and completes the execution when we enter ctrl-d 

6. Repeat the last exercise with cat (without any arguments).
- Interactive terminal, where the line you enter is echoed in the next line after enter is pressed

7. What happens if you press control-c instead of control-d?
- The process is forcefully exited without it's completion

8. Enter ls -l | wc | wc as a command. Explain the output.
- The wc after first pipe outputs the number of NewLine Characters, Word Count, Number of bytes in a single line. The wc after the second pipe, outputs 1 3 24 in all cases(idk about border cases tho ;[ )

9. [Disk usage] Go to a directory that contains both regular files and subdirectories. Type the
following commands and explain the differences: du, du -a, du -s, du -sk, du -sm,
and du -sh. Explain the outputs.
- check the manual `man du` 

10. Try the command ls -l /dev. What kind of files do you see (look at the first character of
each line)? What are these files?
- The files here are of the type c


    -:  regular file
    d : directory
    c : character device file
    b : block device file
    s : local socket file
    p : named pipe
    l : symbolic link


11. Explain why the count of links to a directory is always > 2 (look at the number appearing
immediately after the permissions, in each line of ls -l).
- It at least links to itself(.) and the parent directory(..)

12. [Symbolic links] Create a non-empty text file testfile.txt. See the directory listing
using ls -l. Then type the command ln -s testfile.txt T. Do ls -l again. What
is the permission of T? Try changing the permission of T as chmod 000 T. What happens?
Why? Remove T. What happens? Create another symbolic link TT to testfile.txt.
Remove testfile.txt. What happens?
- It creates a file T of l: type, which is symbolic link type.

    A symlink is a symbolic Linux/ UNIX link that points to another file or folder on your computer, or a connected file system. This is similar to a Windows shortcut.

    Symlinks can take two forms:

    Soft links are similar to shortcuts, and can point to another file or directory in any file system.

    Hard links are also shortcuts for files and folders, but a hard link cannot be created for a folder or file in a different file system.

13. [Hard links] Create a text file abc.txt. See the directory listing. Then enter the command
ln abc.txt ABC.txt. Again see the directory listing. What are the differences? Explain.
Add some extra lines to abc.txt. Again see the directory listing. Explain the changes.
Remove the original file abc.txt. Explain what the directory listing shows.
- Creates a kind of a hard copy, but it doesnt get deleted or something upon the deletion of original file.

14. Study the commands pwd, chmod -R, chown, chgrp, date, time, strings, and exit.
- DIY.

15. Enter the command cal 1752, and look at September. Can you explain?
- The eleven days referred to here are the 'lost' 11 days of September 1752, skipped when Britain changed over from the Julian calendar to the Gregorian calendar, bringing us into line with most of Europe.

