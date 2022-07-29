#!/bin/sh

parameters="
	default_compilers = {'c' : [['clang', '-Werror', '-std=gnu11', '-g', '-lm']]}
	upload_url = https://example.com/autotest.cgi
"

exec "/import/ravel/2/z5416829/csesoc_edu/comp2521-revision-session/autotest.sh" --exercise_directory "/import/ravel/2/z5416829/csesoc_edu/comp2521-revision-session/problems" --parameters "$parameters" "$@"


