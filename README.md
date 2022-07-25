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

This will attempt to install the [Autotest source code](https://github.com/COMP1511UNSW/autotest) in /usr/local/bin/autotest.

It will also create a symlink at `/usr/local/bin/autotest.sh` to the `autotest.sh` in this repo script so you can run it from anywhere. **Make sure you have `/usr/local/bin` in your `PATH`.**

## Problem Writing

To write a problem, go into the `./problems` directory, copy-paste the `problem_template` folder and rename it. 

- Rename your solution_file.c in problem_template/solution to a suitable name. Implement your solution in this file. It will be used by `autotest --generate_expected_output` to generate expected outputs to your test inputs.It won't be available to students.

To run autotest on your problem, go into the directory containing your solution file and run:

```bash
$ autotest.sh <dirname_containing_autotest>
```

where `<dirname_containing_autotest>` is the name of the directory containing the `autotest` folder for your problem. For example, if your solution file is in `./problems/problem_template/solution/solution_file.c`, then you would run:

```bash
$ cd problems/problem_template/solution_file.c
$ autotest.sh problem_template
```
