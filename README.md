</div>

<p align='center'>
    <img src="https://capsule-render.vercel.app/api?type=waving&color=4fa69a&height=300&section=header&text=Philosophers&fontSize=90&animation=fadeIn&fontAlignY=38&desc=The+Dining+Philosophers+problem.&descAlignY=51&descAlign=62"/>

<p align="center">
  <img src="https://img.shields.io/static/v1?label=C&message=Concurrency&color=4fa69a&style=for-the-badge&logo=" alt="Project Overview"/>

</p>
</div>

---

<div align="left">

<h3 align="center">Overview</h3>

Philosophers is a concurrency project in C based on the Dining Philosophers problem.
It focuses on thread synchronization, timing constraints, shared resource protection, and race-condition prevention.

---

<h3 align="center">Repository Layout</h3>

- `philo/`

The implementation and Makefile are inside `philo/`, with separate modules for parsing, simulation, monitor logic, utilities, and cleanup.

---

<h3 align="center">Build</h3>

From inside `philo/`:

```bash
make
```

---

<h3 align="center">Run</h3>

After building:

```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

Example:

```bash
./philo 5 800 200 200
```

---

<h3 align="center">Notes</h3>

- Build flags include strict warnings and thread support.
- Use test inputs with low timings to validate monitor behavior.
- Check for deadlocks, starvation, and clean thread termination.



</div>
