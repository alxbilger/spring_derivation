# Spring Derivation

## Spring definition

Let us examine a linear spring, defined in its coordinate system, i.e. one extremity is the origin of the space, and the other extremity is located at the position $\mathbf{x} \in \mathbb{R}$.

A linear spring is characterized by the following physical properties:
- `k`: a constant factor called stiffness
- `c`: a damping coefficient

### Elastic potential energy

The elastic potential energy arises from the deformation of the spring away from its equilibrium position. When a spring is stretched or compressed, it stores potential energy due to the work done on it to cause that deformation.

The potential energy stored in a spring is a result of the displacement of the spring from its equilibrium position.

$$
U_{elastic}(\mathbf{x}) = \frac{1}{2} k |\mathbf{x} - \mathbf{X}|^2
$$

- $U_{elastic}$ is the elastic potential energy of the spring as a function of its position vector $\mathbf{x}$ in the N-dimensional space
- $\mathbf{X}$ is the equilibrium position of the spring. It refers to the configuration where the spring is neither stretched nor compressed. In other words, it is the position at which the spring experiences no force and is at rest.

The unit for energy in the International System of Units (SI) is the joule (symbol J).

### Damping potential energy

$$
U_{damping}(\mathbf{x}) = \frac{1}{2} c |\mathbf{v}|^2
$$

- $\mathbf{v}$ is the velocity of the spring, i.e. the extremity located at position $\mathbf{x}$.

### Potential Energy

$$
U(\mathbf{x}) = U_{elastic}(\mathbf{x}) + U_{damping}(\mathbf{x}) = \frac{1}{2} k |\mathbf{x} - \mathbf{X}|^2 + \frac{1}{2} c |\mathbf{v}|^2
$$

## Force

## Elastic Force

The spring force is conservative: it can be expressed as:

$$
F_{elastic}(\mathbf{x}) = - \nabla U_{elastic}(\mathbf{x})
$$

where $\nabla$ is the gradient operator.

In a N-dimensional space, $F$ is denoted:

$$
F_\text{elastic}(x) = -\frac{\partial U_\text{elastic}}{\partial x} ^T= \begin{bmatrix}
-\frac{\partial U_{elastic}(\mathbf{x})}{\partial x_1} \\
-\frac{\partial U_{elastic}(\mathbf{x})}{\partial x_2} \\
\vdots \\
-\frac{\partial U_{elastic}(\mathbf{x})}{\partial x_N} \\
\end{bmatrix}
$$

where $\mathbf{x_1}$ is the first coordinate of the position $\mathbf{x}$, $\mathbf{x_2}$ is the second, etc.

Let's compute the gradient:

$$
\frac{\partial U_{elastic}(x)}{\partial x_1} = \frac{1}{2} k \frac{\partial |\mathbf{x} - \mathbf{X}|^2}{\partial x_1} \\
=  k |\mathbf{x} - \mathbf{X}| \frac{\partial |\mathbf{x} - \mathbf{X}|}{\partial x_1} \\
= k |\mathbf{x} - \mathbf{X}| \frac{\mathbf{x_1} - \mathbf{X}_1}{|\mathbf{x} - \mathbf{X}|} \\
$$

So,

$$
\frac{\partial U_{elastic}(x)}{\partial x} = k  (\mathbf{x} - \mathbf{X})
$$

And finally:

$$
F_{elastic} = - k  (\mathbf{x} - \mathbf{X})
$$

## Stiffness Matrix

In numerical simulations, the derivative of force with respect to displacement, called the stiffness matrix, is a key component. It is involved in many solvers. Let's compute it.

The derivative of the force with respect to displacement is denoted

$$
\frac{\partial F}{\partial x}
$$

It is expressed as a second-order tensor:

$$
\frac{\partial F}{\partial x} = 
\begin{bmatrix}
\frac{\partial F_1(x)}{\partial x_1} & \dots & \frac{\partial F_1(x)}{\partial x_N}\\
\frac{\partial F_2(x)}{\partial x_1} & \dots & \frac{\partial F_2(x)}{\partial x_N}\\
\vdots & \ddots & \vdots \\
\frac{\partial F_N(x)}{\partial x_1} & \dots & \frac{\partial F_N(x)}{\partial x_N}\\
\end{bmatrix}
$$

Therefore:

$$
\frac{\partial F}{\partial x} = -k I_N
$$

with $I_N$ the identity matrix of size $N \times N$.

## Change of coordinate system

Until then, the expressions were expressed in the basis of the spring. Let's express the physical quantities in a space where the extremities $a$ and $b$ are located at position $\mathbf{x_a}$ and $\mathbf{x_b}$.

Let us start with the positions:

$$
\mathbf{x} = ||\mathbf{x_b} - \mathbf{x_a} ||_2
$$

- $||\cdot||_2$ is the $L^2$-norm, defining a distance function. It can be written using the dot product: $||\mathbf{x}|| = \sqrt{\mathbf{x} \cdot \mathbf{x}}$.

The equilibrium position could be defined similarly depending on the the equilibrium position of $a$ and $b$:

$$
\mathbf{X} = ||\mathbf{X_b} - \mathbf{X_a} ||_2
$$

with $\mathbf{X_a}$ and $\mathbf{X_b}$ the equilibrium position of $a$ and $b$.
But there is potentially an infinite number of equilibrium positions. Instead, we will consider $\mathbf{X}$ as a parameter of the spring, its rest length. It is the length of a spring at which no forces are created. To differentiate this length as a parameter compared to the variable $\mathbf{X}$ defined in a one-dimensional space, let's call the parameter $L$.

### Elastic Potential Energy

Let us rewrite $U_{\text{elastic}}$ as a function of $\mathbf{x_a}$ and $\mathbf{x_b}$:

$$
U_{\text{elastic}}(\mathbf{x_a}, \mathbf{x_b}) = \frac{1}{2} k | \|\mathbf{x_b} - \mathbf{x_a} \|_2 - L|^2
$$

### Elastic Force

The force is defined as

$$
F_{elastic}(\mathbf{x}) = - \nabla U_{\text{elastic},x}(\mathbf{x})
$$

Let's write the force $F_{\text{elastic}}^a(x_a, x_b)$ applied on $a$ using chain rule:

$$
F_{\text{elastic}}^a(x_a, x_b) = - \nabla U_{\text{elastic},x_a}(\mathbf{x}) \\
= - \frac{\partial U_{\text{elastic}}}{\partial x_a} \\
= - \frac{\partial U_{\text{elastic}}}{\partial x} \frac{\partial x}{\partial x_a} \\
=  -k  (\|\mathbf{x_b} - \mathbf{x_a} \|_2 - L) \frac{\partial x}{\partial x_a}
$$

Similarly, the force applied on $x_b$:

$$
F_{\text{elastic}}^b(x_a, x_b) = -k  (\|\mathbf{x_b} - \mathbf{x_a} \|_2 - L) \frac{\partial x}{\partial x_b}
$$

We need to compute the derivation of the $L^2-norm$ in order to get $\frac{\partial x}{\partial x_a}$ and $\frac{\partial x}{\partial x_b}$:


$$\frac{\partial x}{\partial x_a} = - \frac{\mathbf{x_b} - \mathbf{x_a}}{\|\mathbf{x_b} - \mathbf{x_a} \|_2}$$

$$\frac{\partial x}{\partial x_b} =  \frac{\mathbf{x_b} - \mathbf{x_a}}{\|\mathbf{x_b} - \mathbf{x_a} \|_2}$$

Both quantities involve the direction from $x_a$ to $x_b$. It is a unit vector. Let's call it $d$.

Finally:

$$
F_{\text{elastic}}^a(x_a, x_b) = k  (\|\mathbf{x_b} - \mathbf{x_a} \|_2 - L) \cdot d
$$

$$
F_{\text{elastic}}^b(x_a, x_b) = -k  (\|\mathbf{x_b} - \mathbf{x_a} \|_2 - L) \cdot d
$$

And we can notice that $F_{\text{elastic}}^b(x_a, x_b) = -F_{\text{elastic}}^a(x_a, x_b)$, as expected by the Newton's third law of motion.

### Stiffness Matrix

We now have two forces compared to the stiffness matrix computed only using $x$. And each of these forces depends on two variables $x_a$ and $x_b$. Therefore, it is possible to compute 4 second-order tensor terms:

- $$\frac{\partial F_{\text{elastic}}^a(x_a, x_b)}{\partial x_a} $$
- $$\frac{\partial F_{\text{elastic}}^b(x_a, x_b)}{\partial x_b} $$
- $$\frac{\partial F_{\text{elastic}}^a(x_a, x_b)}{\partial x_b} $$
- $$\frac{\partial F_{\text{elastic}}^b(x_a, x_b)}{\partial x_a} $$

In some contexts, the 4 terms are assembled in a larger matrix representing the entire mechanical system:

$$
\begin{bmatrix}
\ddots & & \\
& \frac{\partial F_{\text{elastic}}^a(x_a, x_b)}{\partial x_a} & \dots & \frac{\partial F_{\text{elastic}}^a(x_a, x_b)}{\partial x_b} & \dots \\
& \vdots \\
& \frac{\partial F_{\text{elastic}}^b(x_a, x_b)}{\partial x_a} & \dots & \frac{\partial F_{\text{elastic}}^b(x_a, x_b)}{\partial x_b} & \dots \\
& \vdots & & &\ddots 
\end{bmatrix}
$$

Let's compute $\frac{\partial F_{\text{elastic}}^a(x_a, x_b)}{\partial x_a}$:

$$
\frac{\partial F_{\text{elastic}}^a(x_a, x_b)}{\partial x_a}=
k \left( 
    \frac{\partial}{\partial x_a} \|\mathbf{x_b} - \mathbf{x_a} \|_2 \cdot d^\top + (\|\mathbf{x_b} - \mathbf{x_a} \|_2-L)\frac{\partial d}{\partial x_a}
\right) \\
= k \left(-d \cdot d^\top + (\|\mathbf{x_b} - \mathbf{x_a} \|_2-L)\frac{\partial d}{\partial x_a} \right)
$$

We have 

$$
\frac{\partial d}{\partial x_a} = \frac{1}{\|x_b-x_a\|_2}\cdot \left( d\cdot d^\top - \mathbb{I} \right)
$$

All together:

$$
\frac{\partial F_{\text{elastic}}^a(x_a, x_b)}{\partial x_a}=
k \left[ \left( \frac{\|\mathbf{x_b} - \mathbf{x_a} \|_2-L}{\|x_b-x_a\|_2} - 1 \right) d\cdot d^\top - \frac{\|\mathbf{x_b} - \mathbf{x_a} \|_2-L}{\|x_b-x_a\|_2}\cdot \mathbb{I}\right]
$$

Similarly, we have:

$$
\frac{\partial F_{\text{elastic}}^b(x_a, x_b)}{\partial x_b} = \frac{\partial F_{\text{elastic}}^a(x_a, x_b)}{\partial x_a}
$$

$$
\frac{\partial F_{\text{elastic}}^a(x_a, x_b)}{\partial x_b} = -\frac{\partial F_{\text{elastic}}^a(x_a, x_b)}{\partial x_a}
$$

$$
\frac{\partial F_{\text{elastic}}^b(x_a, x_b)}{\partial x_a} = -\frac{\partial F_{\text{elastic}}^a(x_a, x_b)}{\partial x_a}
$$
