import subprocess

# TODO: This is just a temporary example func. We aim to transition to a true
#       evaluation scheme once the build system is improved.
def build(what, size):
    # popen = subprocess.run(["make", "clean"])
    
    if what == "pectest":
        if size == 16:
            popen = subprocess.run(["make", "pec_16"])
        elif size == 150:
            popen = subprocess.run(["make", "pec_150"])
        elif size == 365:
            popen = subprocess.run(["make", "pec_365"])
    elif what == "serial":
        if size == 16:
            popen = subprocess.run(["make", "serial_16"])
        elif size == 150:
            popen = subprocess.run(["make", "serial_150"])
        elif size == 365:
            popen = subprocess.run(["make", "serial_365"])
    elif what == "simd":
        if size == 16:
            popen = subprocess.run(["make", "simd_16"])
        elif size == 150:
            popen = subprocess.run(["make", "simd_150"])
        elif size == 365:
            popen = subprocess.run(["make", "simd_365"])
    else:
        print(f"Build {what} is not implemented!")
