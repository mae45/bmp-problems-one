
# bmp-problems-one

=====================

## Licensing :

We all know the nature of the internet and free information.

Please show your support by referring bak to these materials
if you use them. It would also be nice to give us a heads up
to let us know how and where you may use the material.

Of course time is money, please contact us if you like what
we are doing and wish to donate so that we may continue.

=====================

## Author and contributer list :

Author: 	    Mae Davis

Contributor:	Tou Who

Contributor:	Ebonygeek45

=====================

## File list :

* LICENSE

* README.md

* generateButton.bmp

* logoImage.bmp

* main.cpp

=====================

## Directions(Compiling and runningg the program) :

IDE's verified to run and compile these files are :

* CodeBlocks

* Eclipse Oxygen

* Eclipse Neon

* Visual Studio C++ 2010

=====================

## Directions(Running Program) :

These files create .exe files . That can be in either the
projects debug or release file. It depends on how you have your
IDE set up.

=====================

## Project Overview :

Research - trying tutorial from youtube and it does not work.


It may be simply that I am missing something.

In any case I want to open up the topic to see what can be developed
and expanded on the point of bmp graphics in WinMain.


The video is:

Windows GUI Programming with C/C++ ( Win32 API ) | Part -5 | Working
with Images (Bitmaps)


The Link is:

<p>A <a href="https://www.youtube.com/watch?v=PTjlGiCvYZU">YouTube Tutorial</a>.</p>

Feedback is welcomed. Let me know if there is something else I should
include to help resolve this problem.


Keep in mind that I am in newbie status where Win32 is concerned.

I had worked with QT and did not like it with a passion and forgot
most of it at this point anyway.

I do however think I will like win32.


Some back up on what I am working with.

The IDE I am working with is Codeblocks using the "Win32 GUI Project".
Sometimes I do use the Eclipse CDT in which case the only thing available
to use is the console(It works ok for that purpose).

Thank you, mae45

=====================

## Pending Bugs :

Bug 001	:	.bmp won't show up in the window

Question posed under title....

Win 32 GUI c++ .bmp The image is not showing.

link

<p>A <a href="https://stackoverflow.com/questions/48129169/win-32-gui-c-bmp-the-image-is-not-showing">StackOverflow Submission</a>.</p>

** Bugs Fixed : 

Bug 001 : Issues

            1. Call functions in WM_CREATE iin the correct order. The LoadPicture functions should be first, then menus and controls.
           
            2. Format and save the .bmp to a 24-bit format. 
            
            3. Make sure you are using the right path to the .bmp file. 
  
------------------------------------------

# theDebugging
