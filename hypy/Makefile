HYPY_SOURCEDIR := $(ROOTDIR)/hypy
HYPY_BUILDDIR := $(ROOTDIR)/hypy/object

hypy: libhyburn hypy-builddir
	# TODO: This is a horrible hack.
	touch $(HYPY_SOURCEDIR)/hyperion.pyx
	cd $(HYPY_SOURCEDIR) && $(PYTHON) $(HYPY_SOURCEDIR)/hyperion.py \
	build_ext --inplace --verbose

hypy-builddir: 
	mkdir -p $(HYPY_BUILDDIR)
