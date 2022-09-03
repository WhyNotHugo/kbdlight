Kbdlight
========

kbdlight is very simple application that changes MacBooks'(<=10.13) keyboard
backlight level.

While usable standalone, the main goal is for it to be used by other
applications, including things like sxhkd or xbindkeys.

Usage
-----
Usage is quite simple:

    kbdlight up [<percentage>]|down [<percentage>]|off|max|get|set <value>

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
