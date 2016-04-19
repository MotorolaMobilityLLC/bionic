Malloc Debug
============

Malloc debug is a method of debugging native memory problems. It can help
detect memory corruption, memory leaks, and use after free issues.

Currently, malloc debug requires root to enable. When it is enabled, it works
by adding a shim layer that replaces the normal allocation calls. The replaced
calls are:

<pre>
malloc
free
calloc
realloc
posix_memalign
memalign
malloc_usable_size
</pre>

On 32 bit systems, these two deprecated functions are also replaced:

<pre>
pvalloc
valloc
</pre>

Any errors detected by the library are reported in the log.

Controlling Malloc Debug Behavior
---------------------------------
Malloc debug is controlled by individual options. Each option can be enabled
individually, or in a group of other options. Every single option can be
combined with every other option.

Option Descriptions
-------------------
### front\_guard[=SIZE\_BYTES]
Enables a small buffer placed before the allocated data. This is an attempt
to find memory corruption occuring to a region before the original allocation.
On first allocation, this front guard is written with a specific pattern (0xaa).
When the allocation is freed, the guard is checked to verify it has not been
modified. If any part of the front guard is modified, an error will be reported
in the log indicating what bytes changed.

If the backtrace option is also enabled, then any error message will include
the backtrace of the allocation site.

If SIZE\_BYTES is present, it indicates the number of bytes in the guard.
The default is 32 bytes, the max bytes is 16384. SIZE\_BYTES will be
padded so that it is a multiple of 8 bytes on 32 bit systems and 16 bytes
on 64 bit systems to make sure that the allocation returned is aligned
properly.

This option adds a special header to all allocations that contains the guard
and information about the original allocation.

Example error:

<pre>
04-10 12:00:45.621  7412  7412 E malloc_debug: +++ ALLOCATION 0x12345678 SIZE 100 HAS A CORRUPTED FRONT GUARD
04-10 12:00:45.622  7412  7412 E malloc_debug:   allocation[-32] = 0x00 (expected 0xaa)
04-10 12:00:45.622  7412  7412 E malloc_debug:   allocation[-15] = 0x02 (expected 0xaa)
</pre>

### rear\_guard[=SIZE\_BYTES]
Enables a small buffer placed after the allocated data. This is an attempt
to find memory corruption occuring to a region after the original allocation.
On first allocation, this rear guard is written with a specific pattern (0xbb).
When the allocation is freed, the guard is checked to verify it has not been
modified. If any part of the rear guard is modified, an error will be reported
in the log indicating what bytes changed.

If SIZE\_BYTES is present, it indicates the number of bytes in the guard.
The default is 32 bytes, the max bytes is 16384.

This option adds a special header to all allocations that contains
information about the original allocation.

Example error:

<pre>
04-10 12:00:45.621  7412  7412 E malloc_debug: +++ ALLOCATION 0x12345678 SIZE 100 HAS A CORRUPTED REAR GUARD
04-10 12:00:45.622  7412  7412 E malloc_debug:   allocation[130] = 0xbf (expected 0xbb)
04-10 12:00:45.622  7412  7412 E malloc_debug:   allocation[131] = 0x00 (expected 0xbb)
</pre>

### guard[=SIZE\_BYTES]
Enables both a front guard and a rear guard on all allocations.

If SIZE\_BYTES is present, it indicates the number of bytes in both guards.
The default is 32 bytes, the max bytes is 16384.

### backtrace[=MAX\_FRAMES]
Enable capturing the backtrace of each allocation site.
This option will slow down allocations by an order of magnitude. If the
system runs too slowly with this option enabled, decreasing the maximum number
of frames captured will speed the allocations up.

Note that any backtrace frames that occur within the malloc backtrace library
itself are not recorded.

If MAX\_FRAMES is present, it indicates the maximum number of frames to
capture in a backtrace. The default is 16 frames, the maximumum value
this can be set to is 256.

This option adds a special header to all allocations that contains the
backtrace and information about the original allocation.

### backtrace\_enable\_on\_signal[=MAX\_FRAMES]
Enable capturing the backtrace of each allocation site. If the
backtrace capture is toggled when the process receives the signal
SIGRTMAX - 19 (which is 45 on most Android devices). When this
option is used alone, backtrace capture starts out disabled until the signal
is received. If both this option and the backtrace option are set, then
backtrace capture is enabled until the signal is received.

If MAX\_FRAMES is present, it indicates the maximum number of frames to
capture in a backtrace. The default is 16 frames, the maximumum value
this can be set to is 256.

This option adds a special header to all allocations that contains the
backtrace and information about the original allocation.

### fill\_on\_alloc[=MAX\_FILLED\_BYTES]
Any allocation routine, other than calloc, will result in the allocation being
filled with the value 0xeb. When doing a realloc to a larger size, the bytes
above the original usable size will be set to 0xeb.

If MAX\_FILLED\_BYTES is present, it will only fill up to the specified number
of bytes in the allocation. The default is to fill the entire allocation.

### fill\_on\_free[=MAX\_FILLED\_BYTES]
When an allocation is freed, fill it with 0xef.

If MAX\_FILLED\_BYTES is present, it will only fill up to the specified number
of bytes in the allocation. The default is to fill the entire allocation.

### fill[=MAX\_FILLED\_BYTES]
This enables both the fill\_on\_alloc option and the fill\_on\_free option.

If MAX\_FILLED\_BYTES is present, it will only fill up to the specified number
of bytes in the allocation. The default is to fill the entire allocation.

### expand\_alloc[=EXPAND\_BYTES]
Add an extra amount to allocate for every allocation.

If XX is present, it is the number of bytes to expand the allocation by.
The default is 16 bytes, the max bytes is 16384.

### free\_track[=ALLOCATION\_COUNT]
When a pointer is freed, do not free the memory right away, but add it to
a list of freed allocations. In addition to being added to the list, the
entire allocation is filled with the value 0xef, and the backtrace at
the time of the free is recorded. The backtrace recording is completely
separate from the backtrace option, and happens automatically if this
option is enabled. By default, a maximum of 16 frames will be recorded,
but this value can be changed using the free\_track\_backtrace\_num\_frames
option. It can also be completely disabled by setting the option to zero.
See the full description of this option below.

When the list is full, an allocation is removed from the list and is
checked to make sure that none of the contents have been modified since
being placed on the list. When the program terminates, all of the allocations
left on the list are verified.

If ALLOCATION\_COUNT is present, it indicates the total number of allocations
in the list. The default is to record 100 freed allocations, the max
allocations to record is 16384.

This option adds a special header to all allocations that contains
information about the original allocation.

Example error:

<pre>
04-15 12:00:31.304  7412  7412 E malloc_debug: +++ ALLOCATION 0x12345678 USED AFTER FREE
04-15 12:00:31.305  7412  7412 E malloc_debug:   allocation[20] = 0xaf (expected 0xef)
04-15 12:00:31.305  7412  7412 E malloc_debug:   allocation[99] = 0x12 (expected 0xef)
04-15 12:00:31.305  7412  7412 E malloc_debug: Backtrace at time of free:
04-15 12:00:31.305  7412  7412 E malloc_debug:           #00  pc 00029310  /system/lib/libc.so
04-15 12:00:31.305  7412  7412 E malloc_debug:           #01  pc 00021438  /system/lib/libc.so (newlocale+160)
04-15 12:00:31.305  7412  7412 E malloc_debug:           #02  pc 000a9e38  /system/lib/libc++.so
04-15 12:00:31.305  7412  7412 E malloc_debug:           #03  pc 000a28a8  /system/lib/libc++.so
</pre>

In addition, there is another type of error message that can occur if
an allocation has a special header applied, and the header is corrupted
before the verification occurs. This is the error message that will be found
in the log:

<pre>
+++ ALLOCATION 0x12345678 HAS CORRUPTED HEADER TAG 0x1cc7dc00 AFTER FREE
</pre>

### free\_track\_backtrace\_num\_frames[=MAX\_FRAMES]
This option only has meaning if free\_track is set. It indicates how many
backtrace frames to capture when an allocation is freed.

If MAX\_FRAMES is present, it indicates the number of frames to capture.
If the value is set to zero, then no backtrace will be captured when the
allocation is freed. The default is to record 16 frames, the max number of
frames to to record is 256.

### leak\_track
Track all live allocations. When the program terminates, all of the live
allocations will be dumped to the log. If the backtrace option was enabled,
then the log will include the backtrace of the leaked allocations. This
option is not useful when enabled globally because a lot of programs do not
free everything before the program terminates.

This option adds a special header to all allocations that contains
information about the original allocation.

Example leak error found in the log:

<pre>
04-15 12:35:33.304  7412  7412 E malloc_debug: +++ APP leaked block of size 100 at 0x2be3b0b0 (leak 1 of 2)
04-15 12:35:33.304  7412  7412 E malloc_debug: Backtrace at time of allocation:
04-15 12:35:33.305  7412  7412 E malloc_debug:           #00  pc 00029310  /system/lib/libc.so
04-15 12:35:33.305  7412  7412 E malloc_debug:           #01  pc 00021438  /system/lib/libc.so (newlocale+160)
04-15 12:35:33.305  7412  7412 E malloc_debug:           #02  pc 000a9e38  /system/lib/libc++.so
04-15 12:35:33.305  7412  7412 E malloc_debug:           #03  pc 000a28a8  /system/lib/libc++.so
04-15 12:35:33.305  7412  7412 E malloc_debug: +++ APP leaked block of size 24 at 0x7be32380 (leak 2 of 2)
04-15 12:35:33.305  7412  7412 E malloc_debug: Backtrace at time of allocation:
04-15 12:35:33.305  7412  7412 E malloc_debug:           #00  pc 00029310  /system/lib/libc.so
04-15 12:35:33.305  7412  7412 E malloc_debug:           #01  pc 00021438  /system/lib/libc.so (newlocale+160)
04-15 12:35:33.305  7412  7412 E malloc_debug:           #02  pc 000a9e38  /system/lib/libc++.so
04-15 12:35:33.305  7412  7412 E malloc_debug:           #03  pc 000a28a8  /system/lib/libc++.so
</pre>

Additional Errors
-----------------
There are a few other error messages that might appear in the log.

### Use After Free
<pre>
04-15 12:00:31.304  7412  7412 E malloc_debug: +++ ALLOCATION 0x12345678 USED AFTER FREE (free)
04-15 12:00:31.305  7412  7412 E malloc_debug: Backtrace of original free:
04-15 12:00:31.305  7412  7412 E malloc_debug:           #00  pc 00029310  /system/lib/libc.so
04-15 12:00:31.305  7412  7412 E malloc_debug:           #01  pc 00021438  /system/lib/libc.so (newlocale+160)
04-15 12:00:31.305  7412  7412 E malloc_debug:           #02  pc 000a9e38  /system/lib/libc++.so
04-15 12:00:31.305  7412  7412 E malloc_debug:           #03  pc 000a28a8  /system/lib/libc++.so
04-15 12:00:31.305  7412  7412 E malloc_debug: Backtrace at time of failure:
04-15 12:00:31.305  7412  7412 E malloc_debug:           #00  pc 00029310  /system/lib/libc.so
04-15 12:00:31.305  7412  7412 E malloc_debug:           #01  pc 00021438  /system/lib/libc.so (newlocale+160)
04-15 12:00:31.305  7412  7412 E malloc_debug:           #02  pc 000a9e38  /system/lib/libc++.so
04-15 12:00:31.305  7412  7412 E malloc_debug:           #03  pc 000a28a8  /system/lib/libc++.so
</pre>

This indicates that code is attempting to free an already freed pointer. The
name in parenthesis indicates that the application called the function
<i>free</i> with the bad pointer.

For example, this message:

<pre>
04-15 12:00:31.304  7412  7412 E malloc_debug: +++ ALLOCATION 0x12345678 USED AFTER FREE (realloc)
</pre>

Would indicate that the application called the <i>realloc</i> function
with an already freed pointer.

### Invalid Tag
<pre>
04-15 12:00:31.304  7412  7412 E malloc_debug: +++ ALLOCATION 0x12345678 HAS INVALID TAG 1ee7d000 (malloc_usable_size)
04-15 12:00:31.305  7412  7412 E malloc_debug: Backtrace at time of failure:
04-15 12:00:31.305  7412  7412 E malloc_debug:           #00  pc 00029310  /system/lib/libc.so
04-15 12:00:31.305  7412  7412 E malloc_debug:           #01  pc 00021438  /system/lib/libc.so (newlocale+160)
04-15 12:00:31.305  7412  7412 E malloc_debug:           #02  pc 000a9e38  /system/lib/libc++.so
04-15 12:00:31.305  7412  7412 E malloc_debug:           #03  pc 000a28a8  /system/lib/libc++.so
</pre>

This indicates that a function (malloc\_usable\_size) was called with
a pointer that is either not allocated memory, or that the memory of
the pointer has been corrupted.

As with the other error message, the function in parenthesis is the
function that was called with the bad pointer.

Examples
========
Enable backtrace tracking of all allocation for all processes:

<pre>
  adb shell stop
  adb shell setprop libc.debug.malloc.options backtrace
  adb shell start
</pre>

Enable backtrace tracking for a specific process (ls):

<pre>
  adb shell setprop libc.debug.malloc.options backtrace
  adb shell setprop libc.debug.malloc.program ls
  adb shell ls
</pre>

Enable backtrace tracking for the zygote and zygote based processes:

<pre>
  adb shell stop
  adb shell setprop libc.debug.malloc.program app_process
  adb shell setprop libc.debug.malloc.options backtrace
  adb shell start
</pre>

Enable multiple options (backtrace and guards):

<pre>
  adb shell stop
  adb shell setprop libc.debug.malloc.options "\"backtrace guards\""
  adb shell start
</pre>

Enable malloc debug when multiple processes have the same name. This method
can be used to enable malloc debug for only a very specific process if
multiple processes have the same name.

Note: The double quotes in the adb shell command are necessary. Otherwise,
the setprop command will fail since the backtrace guards options will look
like two arguments instead of one.

<pre>
  adb shell
  # setprop libc.debug.malloc.env_enabled
  # setprop libc.debug.malloc.options backtrace
  # export LIBC_DEBUG_MALLOC_ENABLE 1
  # ls
</pre>
