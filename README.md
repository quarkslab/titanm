# Titan M tools
In this repository, we publish the tools we used in our research on the Google Titan M chip.

We presented our results at [Black Hat EU 21](https://www.blackhat.com/eu-21/briefings/schedule/index.html#-a-titan-m-odyssey-24471) and at the [ROOTS](https://roots-conference.org/) workshop within DeepSec.

* [`citadelimgloader`](./citadelimgloader): the Ghidra loader for Titan M firmware files
* [`nugget_toolkit`](./nugget_toolkit): the set of tools to trace messages and communicate with the chip (including an exploit for a known vulnerability and a fuzzer)
* [`bin2rec`](./bin2rec): a set of scripts used to convert firmware files into rec files that can be used with the SPI rescue feature
* [`BHEU_2021`](./BHEU_2021): the materials of our presentation at BlackHat Europe 2021 (the slides and the white paper)

---
**NOTE**

This project uses submodules. So after cloning the repository, do not forget to run:

```bash
$ git submodule update --init --recursive
```

---
