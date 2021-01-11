## C for Java Programmers: Linked List Project

This repository contains the shell files, solution, and submission tracking
infrastructure for the linked list project issued during the tutorial series
*C for Java Programmers*.  Before beginning work on this project, please read
these instructions carefully, as they will detail how you can start working on
this project, get help with your code if something goes wrong, and ensure that
you can receive feedback on your work.  If you have any questions about this
document or any part of the project, feel free to open an issue in this
repository so that it can be seen and answered.  Thank you!

### Project overview

In this project, you are tasked with writing an *intrusive* linked list, or a
list in which the data store the linked list pointers, rather than featuring
separate linked list nodes that contain pointers to the data.
This approach to writing a linked list has a number of advantages, some of the
most significant of which are that it allows a linked list to be easily placed
in either static or dynamic memory, and that the list is recursively defined,
permitting random access from any point in the list without the need for an
explicit iterator.
We shall use this linked list, documented in `linked_list.h`, to implement a
simple database of students, documented in `student.h`.
As you work on this project, I encourage you to tackle the linked list functions
first, then move on to implementing functionality specialised for the student
database.

### Getting started
To begin working on this project, **fork this repository** into your own GitHub
account using the "Fork" button in the upper right-hand corner of the GitHub
interface.
Open a terminal and navigate to the directory in which you wish to work on the
project, then run the following command, omitting the leading `$` which is used
to indicate a shell prompt:

```shell
$ git clone https://github.com/your-github-username/c4jp-linked-list.git
```

Following some diagnostic output, you should now see a new directory named
`c4jp-linked-list` in your current directory.
Navigate into that directory, then run the following command to build the
project for the first time:

```shell
$ make run_test
```

If all is well, you should now see a `test.h` transcript containing 21 tests,
most of which are likely failing due to the fact that you haven't implemented
the project yet.
Let's get to work!

### Working on the project
This project was developed with the intent to allow you to work on it in a
[test-driven](https://en.wikipedia.org/wiki/Test-driven_development) style, in
which you can implement functions to ensure that tests pass in a sequential
order.
You certainly don't *have* to implement your functions in the order suggested by
the tests, but doing so may prove to be very helpful.
It is recommended that you test your program frequently, paying attention to the
entirety of the tester output to ensure that subsequent modifications have not
introduced any defects into tests that you were passing at a time in the past.
You can always run `make run_test` to build and run your project; if you need to
use a debugger to step through your program, debug symbols are enabled in the
`Makefile` and `test.h` is fully debugger-compatible.
If at any point you wish to delete any compiled files, run `make clean` to do
so.

### Getting help
If you need some help with your implementation of this project, feel free to
open an issue in the [project root repository](https://github.com/Andrew-William-Smith/c4jp-linked-list/issues/new/choose).
Use the *Help Request* template when you open your issue, both to save yourself
some typing and to provide some uniformity in how help requests are formatted.
Fully fill out the template: failure to do so may result in your issue being
closed without being read.
I may correspond with you about your issue&mdash;please be prompt and courteous
in your responses.
Once your issue is resolved or after a period of one week of inactivity, you
should close your issue or it may be automatically closed for you.

In addition, a full solution to the project is available on the `solution`
branch.
I encourage you to not look at this branch until you have finished your
implementation, but if you are stuck and need some additional help, you can
refer to that branch for ideas.

### Getting feedback
Once you have finished your implementation of the project and made your last
commit to your fork, [open a **pull request**](https://github.com/Andrew-William-Smith/c4jp-linked-list/compare)
from your fork to the `master` branch of the project root repository.
I shall leave some feedback on your submission in the form of a code review, but
then shall ultimately close the pull request to keep the `master` branch clean.
If you have any questions about my feedback, feel free to leave additional
comments on your pull request.
I ask that you please refrain from submitting until you have completely finished
your implementation, meaning that *all tests are passing* and you have performed
a proofreading round on your code to catch any common stylistic or technical
errors.
If you do not meet this threshold, your pull request may be rejected without any
feedback being given.

Good luck on the project!
