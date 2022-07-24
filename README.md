# comp2521-revision-session-questions

Practice problems for the 22T2 CSESoc COMP2521 revision session. Includes a mix of theory-based multiple choice questions and practical programming problems.

## Setup

This repository integrates with the [CSE Autotest system](https://github.com/COMP1511UNSW/autotest) as the problems are intended to be run through tests hosted on CSE servers using CSE Autotest.

To set up this repository locally for writing Autotest-compatible tests:

First clone the repository:

```bash
$ git clone https://github.com/dqna64/comp2521-revision-session.git
$ cd comp2521-revision-session
```

Then, run the following command to set up your environment:

```bash
$ ./setup.sh
```

This will attempt to install the Autotest library in /usr/local/bin/autotest.

It will also create a symlink at /usr/local/bin/autotest.sh to the autotest.sh script so you can run it from anywhere. Make sure you have `/usr/local/bin` in your `PATH`.

## Problem Writing

To write a problem, go into the `./problems` directory and copy-paste an existing problem folder.

TODO: Write documentation for testing problems with autotest.

To run autotest on your problem, go into the directory containing your solution file and run:

```bash
$ autotest.sh <dirname_containing_autotest>
```

where `<dirname_containing_autotest>` is the name of the directory containing the `autotest` folder for your problem.
