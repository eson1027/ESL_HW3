# HW3

```shell
git clone https://github.com/eson1027/ESL_HW3
- cd gaussian_hw3_1
# cd gaussian_hw3_2
# cd gaussian_hw3_3
## SystemC Simulation

- make run

## Stratus

- cd stratus
- make sim_B
# make sim_V_BASIC
```
## 1. High level synthesis of Gaussian Blur Filter

- In this homework, Please design a HLS synthesizable version of the Gaussian Blur Filter module.
- Please follow the system.h, tb.h, tb.cc, dut.h, dut.cc file structure from Stratus labs.

## 2. (40 pt) Base Implementation

- Please write a synthesizable design of SystemC dut modules.
- Make sure to implement a buffer-based "flow" dut, which would cache and reuse inputs.

## 3. (30 pt) Improve coding styles

- Please use bit width to constrain the operators.
- Please simplify and reduce math expressions as much as possible, e.g., removing or simplifying multiplication and division, etc.
- Please compare the improved version with base implementation (area, latency and throughput).

## 4. (30 pt) Optimized Implementation

- Please use Stratus directive of loop pipelining, unrolling, etc. to improve the throughput and latency of your design.
- Please compare the optimized version with previous implementation (area, latency and throughput).
