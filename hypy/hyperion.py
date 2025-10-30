from distutils.core import setup
from distutils.extension import Extension
from Cython.Distutils import build_ext
from Cython.Build import cythonize

sourcefiles = ["hyperion.pyx"]

extensions = [
    Extension("hyperion", sourcefiles,
              include_dirs=["../src/core", "../src/parse-data"],
              # libraries=[""],
              # library_dirs=[""],
              extra_link_args=["-L../object", "-l:libhyburn.a"],
              extra_compile_args=["-O2"]),
    # Extension("*", ["*.pyx"],
    #     include_dirs=[...],
    #     libraries=[...],
    #     library_dirs=[...]),
]

# Multithreading is possible for compilation...

setup(
    name="hyperion",
    cmdclass={"build_ext": build_ext},
    ext_modules=cythonize(extensions, build_dir="object"),
)
