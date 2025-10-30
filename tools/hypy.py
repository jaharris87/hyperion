import hyperion as hypy

import numpy as np
import matplotlib.pyplot as plt

size = 150
hypy.init()

tstep = 1e-8
temp = 5e09
dens = 1e08
xin = np.zeros(size)
xout = np.zeros(size)
sdotrate = 0.0

burned_zone = True

ymin = 0
ymax = 1


def plot_abundances(temp, dens):
    hypy.get_x(xin, size)
    hypy.evolve(tstep, temp, dens, xin, xout, sdotrate,
                burned_zone, size)
    print(xin)
    print(xout)
    ax.cla()
    # For now xin is const, copied to xout for comp in bn_burner
    ax.bar(range(1, size+1), xin, color="Black", linestyle="--")
    ax.bar(range(1, size+1), xout, color="#ff8200", linestyle="-")
    ax.set_xlabel("Atomic Mass Number")
    ax.set_ylabel("Mass Fraction")
    ax.set_title("Hyperion Computed X")
    ax.set_ylim(ymin=ymin, ymax=ymax)


fig, ax = plt.subplots()

scale_sliders_max = 1e1
scale_sliders_min = 1e-2

# add_axes takes a tuple (rect) that represents its size and positioning
# rect: (left, bottom, width, height)
slideraxis_temp = fig.add_axes([0.25, 0.05, 0.65, 0.02])
slider_temp = plt.Slider(slideraxis_temp, label="Temperature",
                         valmin=temp*scale_sliders_min, valmax=temp*scale_sliders_max, valinit=temp, orientation="horizontal")

slideraxis_dens = fig.add_axes([0.05, 0.20, 0.02, 0.65])
slider_dens = plt.Slider(slideraxis_dens, label="Density",
                         valmin=dens*scale_sliders_min, valmax=dens*scale_sliders_max, valinit=dens, orientation="vertical")

# Must be defined after the sliders are known to the interpreter.
# We just dump the value passed...


def update(dump):
    plot_abundances(slider_temp.val, slider_dens.val)
    # Draw idle reduces the need for processing (the figure is updated
    # because of the slider). I don't fully understand this, and long-term
    # this obviously needs to be buffered when the kernel is time-hungry.
    fig.canvas.draw_idle()


slider_temp.on_changed(update)
slider_dens.on_changed(update)

# Move the main plot a to make room for sliders.
fig.subplots_adjust(left=0.20, bottom=0.15)
plt.grid(True)
update(0)
plt.show(block=True)
