cdef extern from "bn_burner.h":
    void hyperion_burner_(double* tstep, double* temp, double* dens, double* xin,
                          double* xout, double* sdotrate, unsigned char* burned_zone, int* size);

    
cdef extern from "init.h":
    void hyperion_init_();

# Theoretical stuff, not yet implemented
cdef extern from "read_values.h":
    void get_x_(double* dest, int size);

cpdef evolve(double tstep, double temp, double dens,
             double[:] xin, double[:] xout, double sdotrate,
             unsigned char burned_zone, int size):
    return hyperion_burner_(&tstep, &temp, &dens, &xin[0], &xout[0], &sdotrate, 
                            &burned_zone, &size)

cpdef init():
    return hyperion_init_();

cpdef get_x(double[:] dest, int size):
    return get_x_(&dest[0], size)
