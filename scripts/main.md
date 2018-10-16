---
title: The Note of RB system
author: Houchen Li
date: October 2, 2018
output:
    pdf_document:
        pdf_engine: pdflatex
        #toc: 1
        number_sections: 1
header-includes:
    #\usepackage{ctex}
    \usepackage{indentfirst}
    \usepackage{geometry}
    \usepackage{amsmath}
    \usepackage{amssymb}
    \setlength{\parindent}{2em}
    \geometry{a4paper,landscape,top=0.5in,bottom=0.5in,left=0.5in,right=0.5in}
---

# Definition

Eigenvalue Equation:

\[{\left(q^2-a^2\right)}^3=-a^2R\]

Two types of solutions are

\[\begin{matrix}
    W_e &=& A_0\cos\left(q_0 z\right) &+& A_1\cosh\left(q_\text{r} z\right)\cos\left(q_\text{i} z\right) &-& A_2\sinh\left(q_\text{r} z\right)\sin\left(q_\text{i} z\right);\\
    W_o &=& A_0\sin\left(q_0 z\right) &+& A_1\sinh\left(q_\text{r} z\right)\cos\left(q_\text{i} z\right) &+& A_2\cosh\left(q_\text{r} z\right)\sin\left(q_\text{i} z\right). \\
\end{matrix}\]

Thus, the even modes yield

\[\begin{matrix}
    \mathrm{D}W_e &=& -q_0 A_0\sin\left(q_0 z\right) &+& \left(q_\text{r}A_1-q_\text{i}A_2\right)\sinh\left(q_\text{r} z\right)\cos\left(q_\text{i} z\right) &-& \left(q_\text{r}A_2+q_\text{i}A_1\right)\cosh\left(q_\text{r} z\right)\sin\left(q_\text{i} z\right); \\
    \mathrm{D}^2W_e &=& -q_0^2A_0\cos\left(q_0 z\right) &+& \left[\left(q_\text{r}^2-q_\text{i}^2\right)A_1-2q_\text{r}q_\text{i}A_2\right]\cosh\left(q_\text{r} z\right)\cos\left(q_\text{i} z\right) &-& \left[\left(q_\text{r}^2-q_\text{i}^2\right)A_2+2q_\text{r}q_\text{i}A_1\right]\sinh\left(q_\text{r} z\right)\sin\left(q_\text{i} z\right); \\
    \tfrac{\left(\mathrm{D}^2-a^2\right)W_e}{\left(q_0^2+a^2\right)} &=& -A_0\cos\left(q_0 z\right) &+& \left(\frac{1}{2}A_1-\frac{\sqrt{3}}{2}A_2\right)\cosh\left(q_\text{r} z\right)\cos\left(q_\text{i} z\right) &-& \left(\frac{1}{2}A_2+\frac{\sqrt{3}}{2}A_1\right)\sinh\left(q_\text{r} z\right)\sin\left(q_\text{i} z\right); \\
    \tfrac{\mathrm{D}\left(\mathrm{D}^2-a^2\right)W_e}{\left(q_0^2+a^2\right)} &=& q_0A_0\sin\left(q_0z\right) &+& \left[q_\text{r}\left(\frac{1}{2}A_1-\frac{\sqrt{3}}{2}A_2\right)-q_\text{i}\left(\frac{1}{2}A_2+\frac{\sqrt{3}}{2}A_1\right)\right]\sinh\left(q_\text{r}z\right)\cos\left(q_\text{i}z\right) &-& \left[q_\text{i}\left(\frac{1}{2}A_1-\frac{\sqrt{3}}{2}A_2\right)+q_\text{r}\left(\frac{1}{2}A_2+\frac{\sqrt{3}}{2}A_1\right)\right]\cosh\left(q_\text{r}z\right)\sin\left(q_\text{i}z\right); \\
    \tfrac{\left(\mathrm{D}^2-a^2\right)^2W_e}{\left(q_0^2+a^2\right)^2} &=& A_0\cos\left(q_0z\right) &+& \left(-\frac{1}{2}A_1-\frac{\sqrt{3}}{2}A_2\right)\cosh\left(q_\text{r} z\right)\cos\left(q_\text{i} z\right) &-& \left(-\frac{1}{2}A_2+\frac{\sqrt{3}}{2}A_1\right)\sinh\left(q_\text{r} z\right)\sin\left(q_\text{i} z\right). \\
    \tfrac{\mathrm{D}\left(\mathrm{D^2}-a^2\right)^2W_e}{\left(q_0^2+a^2\right)^2} &=& -q_0A_0\cos\left(q_0z\right) &+& \left[q_\text{r}\left(-\frac{1}{2}A_1-\frac{\sqrt{3}}{2}A_2\right)-q_\text{i}\left(-\frac{1}{2}A_2+\frac{\sqrt{3}}{2}A_1\right)\right]\sinh\left(q_\text{r} z\right)\cos\left(q_\text{i} z\right) &-& \left[q_\text{i}\left(-\frac{1}{2}A_1-\frac{\sqrt{3}}{2}A_2\right)+q_\text{r}\left(-\frac{1}{2}A_2+\frac{\sqrt{3}}{2}A_1\right)\right]\cosh\left(q_\text{r} z\right)\sin\left(q_\text{i} z\right). \\
\end{matrix}\]

While the odd modes yield

\[\begin{matrix}
    \mathrm{D}W_o &=& q_0 A_0\cos\left(q_0 z\right) &+& \left(q_\text{r}A_1+q_\text{i}A_2\right)\cosh\left(q_\text{r} z\right)\cos\left(q_\text{i} z\right) &+& \left(q_\text{r}A_2-q_\text{i}A_1\right)\sinh\left(q_\text{r} z\right)\sin\left(q_\text{i} z\right); \\
    \mathrm{D}^2W_o &=& -q_0^2A_0\sin\left(q_0 z\right) &+& \left[\left(q_\text{r}^2-q_\text{i}^2\right)A_1+2q_\text{r}q_\text{i}A_2\right]\sinh\left(q_\text{r} z\right)\cos\left(q_\text{i} z\right) &+& \left[\left(q_\text{r}^2-q_\text{i}^2\right)A_2-2q_\text{r}q_\text{i}A_1\right]\cosh\left(q_\text{r} z\right)\sin\left(q_\text{i} z\right); \\
    \tfrac{\left(\mathrm{D}^2-a^2\right)W_o}{\left(q_0^2+a^2\right)} &=& -A_0\sin\left(q_0 z\right) &+& \left(\frac{1}{2}A_1+\frac{\sqrt{3}}{2}A_2\right)\sinh\left(q_\text{r} z\right)\cos\left(q_\text{i} z\right) &+& \left(\frac{1}{2}A_2-\frac{\sqrt{3}}{2}A_1\right)\cosh\left(q_\text{r} z\right)\sin\left(q_\text{i} z\right); \\
    \tfrac{\mathrm{D}\left(\mathrm{D}^2-a^2\right)W_o}{\left(q_0^2+a^2\right)} &=& -q_0A_0\cos\left(q_0z\right) &+& \left[q_\text{r}\left(\frac{1}{2}A_1+\frac{\sqrt{3}}{2}A_2\right)+q_\text{i}\left(\frac{1}{2}A_2-\frac{\sqrt{3}}{2}A_1\right)\right]\cosh\left(q_\text{r}z\right)\cos\left(q_\text{i}z\right) &+& \left[-q_\text{i}\left(\frac{1}{2}A_1+\frac{\sqrt{3}}{2}A_2\right)+q_\text{r}\left(\frac{1}{2}A_2-\frac{\sqrt{3}}{2}A_1\right)\right]\sinh\left(q_\text{r}z\right)\sin\left(q_\text{i}z\right); \\
    \tfrac{\left(\mathrm{D}^2-a^2\right)^2W_o}{\left(q_0^2+a^2\right)^2} &=& A_0\sin\left(q_0z\right) &+& \left(-\frac{1}{2}A_1+\frac{\sqrt{3}}{2}A_2\right)\sinh\left(q_\text{r} z\right)\cos\left(q_\text{i} z\right) &+& \left(-\frac{1}{2}A_2-\frac{\sqrt{3}}{2}A_1\right)\cosh\left(q_\text{r} z\right)\sin\left(q_\text{i} z\right). \\
    \tfrac{\mathrm{D}\left(\mathrm{D}^2-a^2\right)^2W_o}{\left(q_0^2+a^2\right)^2} &=& q_0A_0\cos\left(q_0z\right) &+& \left[q_\text{r}\left(-\frac{1}{2}A_1+\frac{\sqrt{3}}{2}A_2\right)+q_\text{i}\left(-\frac{1}{2}A_2-\frac{\sqrt{3}}{2}A_1\right)\right]\cosh\left(q_\text{r} z\right)\cos\left(q_\text{i} z\right) &+& \left[-q_\text{i}\left(-\frac{1}{2}A_1+\frac{\sqrt{3}}{2}A_2\right)+q_\text{r}\left(-\frac{1}{2}A_2-\frac{\sqrt{3}}{2}A_1\right)\right]\sinh\left(q_\text{r} z\right)\sin\left(q_\text{i} z\right). \\
\end{matrix}\]

And the corresponding boundary conditions are

* Rigid Layers / Fixed Temperature

* Rigid Layers / Prescribed Heat

* Free Layers / Fixed Temperature

* Free Layers / Prescribed Heat

---

# Boundary Conditions

## Rigid Layers / Fixed Temperature

\[\begin{cases}\left.W\right|_{z=\pm\frac{1}{2}}&=0 \\ \left.\mathrm{D}W\right|_{z=\pm\frac{1}{2}}&=0 \\ \left.\left(\mathrm{D}^2-a^2\right)^2W\right|_{z=\pm\frac{1}{2}}&=0\end{cases}\quad\text{and}\quad\begin{cases}\left.\theta\right|_{z=\pm\frac{1}{2}}&=0 \\ \left.\left(\mathrm{D}^2-a^2\right)\theta\right|_{z=\pm\frac{1}{2}}&=0 \\ \left.\mathrm{D}\left(\mathrm{D}^2-a^2\right)\theta\right|_{z=\pm\frac{1}{2}}&=0\end{cases}.\]

---

## Rigid Layers / Prescribed Heat

\[\begin{cases}\left.W\right|_{z=\pm\frac{1}{2}}&=0 \\ \left.\mathrm{D}W\right|_{z=\pm\frac{1}{2}}&=0 \\ \left.\mathrm{D}\left(\mathrm{D}^2-a^2\right)^2W\right|_{z=\pm\frac{1}{2}}&=0\end{cases}\quad\text{and}\quad\begin{cases}\left.\mathrm{D}\theta\right|_{z=\pm\frac{1}{2}}&=0 \\ \left.\left(\mathrm{D}^2-a^2\right)\theta\right|_{z=\pm\frac{1}{2}}&=0 \\ \left.\mathrm{D}\left(\mathrm{D}^2-a^2\right)\theta\right|_{z=\pm\frac{1}{2}}&=0\end{cases}.\]

---

## Free Layers / Fixed Temperature

\[\begin{cases}\left.W\right|_{z=\pm\frac{1}{2}}&=0 \\ \left.\mathrm{D}^2W\right|_{z=\pm\frac{1}{2}}&=0 \\ \left.\left(\mathrm{D}^2-a^2\right)^2W\right|_{z=\pm\frac{1}{2}}&=0\end{cases}\quad\text{and}\quad\begin{cases}\left.\theta\right|_{z=\pm\frac{1}{2}}&=0 \\ \left.\left(\mathrm{D}^2-a^2\right)\theta\right|_{z=\pm\frac{1}{2}}&=0 \\ \left.\mathrm{D}\left(\mathrm{D}^2-a^2\right)\theta\right|_{z=\pm\frac{1}{2}}&=0\end{cases}.\]

---

## Free Layers / Prescribed Heat

\[\begin{cases}\left.W\right|_{z=\pm\frac{1}{2}}&=0 \\ \left.\mathrm{D}^2W\right|_{z=\pm\frac{1}{2}}&=0 \\ \left.\mathrm{D}\left(\mathrm{D}^2-a^2\right)^2W\right|_{z=\pm\frac{1}{2}}&=0\end{cases}\quad\text{and}\quad\begin{cases}\left.\mathrm{D}\theta\right|_{z=\pm\frac{1}{2}}&=0 \\ \left.\left(\mathrm{D}^2-a^2\right)\theta\right|_{z=\pm\frac{1}{2}}&=0 \\ \left.\mathrm{D}\left(\mathrm{D}^2-a^2\right)\theta\right|_{z=\pm\frac{1}{2}}&=0\end{cases}.\]

---