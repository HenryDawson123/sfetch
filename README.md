SFetch
======

A simple fetch program designed to be fast and small.

Why it was made:
----------------

This program was made to be faster and simpler than neofetch, made more for opening in a terminal as the terminal is launched, it had to be fast and small enough to be unobtrusive.

Installation Instructions:
--------------------------

To install:

Go into the SFetch directory:

```$ cd SFetch/```

Then:

```$ make install```

If you wish to uninstall the program:

```$ make uninstall```

TODO:
-----

- Provide a makefile for easier installation
- Ascii art at some stage
- Update uptime to include days aswell as hours and minutes
- Improve source code readability and notation
- (A very big maybe) Include support for MacOS and Windows

Configuration Instructions:
---------------------------

To configure and change this program you will need to edit the source code and recompile:

You can comment and uncomment the lines in `int main()` to change what information is displayed.

By default the Visual and Architecture options are commented out, in order to display them you should uncomment them.

Example Images:
---------------
![Void Linux Running SFetch](https://github.com/HenryDawson123/SFetch/blob/assets/assets/sfetchexample.png)

*Void Linux Running the Default SFetch Configuration*

![Debian Linux Running SFetch](https://github.com/HenryDawson123/SFetch/blob/assets/assets/sfetchdebianexample.png)

*Debian Linux Running the Default SFetch Configuration*
