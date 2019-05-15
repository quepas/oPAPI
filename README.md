**DEPRECATED!!!** Instead, please consider using [**mPAPI**](https://github.com/quepas/mPAPI) which works for MATLAB and Octave.

# oPAPI

Simple [**Octave**](https://www.gnu.org/software/octave/) API for [**PAPI**](http://icl.cs.utk.edu/papi/) (Performance Application Programming Interface).

# Installation

1. Install [PAPI >=5.5.1](http://icl.cs.utk.edu/papi/)
2. Install package `liboctave-dev` if you don't have it already
3. Run `octave` in oPAPI directory
4. Compile `oPAPI_register`, `oPAPI_tic`, and `oPAPI_toc` functions from Octave console using _mex_:

```
mex -I/usr/local/include oPAPI_register.c -L/usr/local/lib/ -lpapi -output oPAPI_register
mex -I/usr/local/include oPAPI_tic.c -L/usr/local/lib/ -lpapi -output oPAPI_tic
mex -I/usr/local/include oPAPI_toc.c -L/usr/local/lib/ -lpapi -output oPAPI_toc
```
Where directory ``/usr/local/include`` contains ``papi.h`` header and directory ``/usr/local/lib/`` contains ``libpapi.so`` static library.
## Usage

1. Register hardware performance monitoring counters (PMC) using _preset_ or _native_ events:
```octave
>> oPAPI_register('FP_ARITH:SCALAR_SINGLE', 'L1D:REPLACEMENT', 'PAPI_L2_ICA')
```
2. Start counters:
```octave
>> oPAPI_tic
```
3. Read counters measurements:
```octave
>> oPAPI_toc

ans = [0   355  1698]
```

## Comments

* The number of hardware counters available on the system defines the upper limit of counters you can register using ``oPAPI_register`` function.
* Not all hardware counters can be mixed and used simultaneously.
