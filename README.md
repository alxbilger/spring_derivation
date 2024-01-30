# Spring Derivation

The repository contains:
- The mathematical development of the expression of physical quantities in a spring based on the Hooke's law. It includes the computation of the elastic potential energy, the resulting force and the Jacobian matrix. The expressions are written in an absolute coordinate system.
- The c++ implementation of the potential energy, the force and the Jacobian matrix. Moreover, the quantities are compared to an approach using finite difference.

## How to build

Use [`cmake`](https://cmake.org/cmake/help/latest/manual/cmake.1.html) or [`cmake-gui`](https://cmake.org/cmake/help/latest/manual/cmake-gui.1.html) to configure the C++ project. It has no dependency other than the STL.

## Output

Example of output:

```
U = 2138.18
Fa = [68.5515 205.654 -616.963]
Fb = [-68.5515 -205.654 616.963]
Finite difference Fa = [-68.5513 -205.654 616.963]
Finite difference Fb = [68.5527 205.655 -616.963]
Stiffness matrix K = [-68.897 -1.03677 3.1103] [-1.03677 -71.6618 9.33089] [3.1103 9.33089 -96.5441]
Finite difference Kaa = [-68.897 -1.03674 3.11036] [-1.03675 -71.6617 9.33085] [3.11032 9.33093 -96.5442]
```
