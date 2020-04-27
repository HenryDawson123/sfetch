sfetch
======

A simple fetch program designed to be fast and small.

<p align="center"><img src="https://github.com/HenryDawson123/SFetch/blob/assets/assets/sfetchexample.png" width="50%"></p>

Why it was made:
----------------

This program was made to be faster and simpler than neofetch, made more for opening in a terminal as the terminal is launched, it had to be fast and small enough to be unobtrusive.


Installation Instructions:
--------------------------

To install:

Go into the SFetch directory:

```$ cd SFetch/```

Then:

```$ sudo make install```

Finally to run the program:

```$ sfetch```

If you wish to uninstall the program:

```$ sudo make uninstall```

TODO:
-----
- ~~Provide a makefile for easier installation~~
- Ascii art at some stage
- ~~Update uptime to include days aswell as hours and minutes~~
- Improve source code readability and notation
- (A very big maybe) Include support for MacOS and Windows

Configuration Instructions:
---------------------------

To configure and change this program you will need to edit the source code and recompile:

You can comment and uncomment the lines in `int main()` to change what information is displayed.

By default the Editor, Visual and Architecture options are commented out, in order to display them you should uncomment them.

Please Note:
------------

Some shells do not define the environmental variables `$EDITOR` or `$VISUAL` by default, if you wish to show these in sfetch, please ensure these are defined in your shell configuration file before uncommenting the lines in `int main()`.

To check whether your shell has these environmental variables defined please enter:

```$ echo $VISUAL && echo $EDITOR```

you should then recieve an output of two lines, with your Visual and Editor on each like so:

`nvim`

`nvim`

If your output has these two variables, your good to go! You can then uncomment the two lines in `int main()`.

If one or both of these lines are blank, please consult the configuration instructions for your specific shell to define environmental variables.
