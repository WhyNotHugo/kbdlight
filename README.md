Kbdlight
========

kbdlight is very simple application that changes MacBooks' keyboard
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

Copyright (c) 2013-2015, Hugo Osvaldo Barrera <hugo@barrera.io> and
contributors. See LICENCE for details.
