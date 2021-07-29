Kbdlight
========

kbdlight is very simple application that changes MacBooks' keyboard
backlight level.

While usable standalone, the main goal is for it to be used by other
applications, including things like sxhkd or xbindkeys.


Fork
-----
This fork is intended for a module I've made in waybar to read the percentage of the brightness from the keyboard backlight. Reading from the default `get` was only providing the values between 0 and 255. I wanted the percentage of brightness. I added the `getp` argument to get a percentage from this value. This value is rounded to the nearest integer.

Usage
-----
Usage is quite simple:

    kbdlight up [<percentage>]|down [<percentage>]|off|max|get|getp|set <value>

`getp` **returns the percentage of brightness for the value.** 
`percentage` should be an integer between 0 and 100.
`value` should be an integer between 0 the maximum brightness value (usually
255, but this *may* vary).

Project status
--------------

This project is finshed. It works, and hasn't had any issues in years. Since I
no longer have a MacBook, I can no longer accurately test this either. If it's
broken, you're welcome to maintain this package.

Copyright (c) 2013-2020, Hugo Osvaldo Barrera <hugo@barrera.io> and
contributors. See LICENCE for details.
