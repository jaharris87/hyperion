TESTDIR := $(ROOTDIR)/tests

.PHONY: test
test: libhyburn hypy
	cp $(HYPY_SOURCEDIR)/hyperion.cpython* tests/
	python $(TESTDIR)/test.py
