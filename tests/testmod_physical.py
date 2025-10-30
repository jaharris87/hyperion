import hyperion as hypy
import numpy as np

# Reasonable settings for a physicality test.
float_tol = 1e-3

size = 150
tstep = 1e-8
temp = 5e09
dens = 1e08
xin = np.zeros(size)
xout = np.zeros(size)
sdotrate = 0.0
burned_zone = True

# Returns the number of failures found.
def run():
    hypy.init()
    hypy.get_x(xin, size)
    hypy.evolve(tstep, temp, dens, xin, xout, sdotrate,
                burned_zone, size)

    failures = 0

    if xout.min() < 0:
        print("Test failure.")
        print("Non-physical value found in result")
        print("Input:", xin)
        print("Output:", xout)
        failures = failures + 1

    if xout.sum() > (1 + float_tol) or xout.sum() < (1 - float_tol):
        print("Test failure.")
        print("Mass-Fraction sum outside of reasonable bounds.")
        print("X sum:", xout.sum())
        failures = failures + 1

    return failures
