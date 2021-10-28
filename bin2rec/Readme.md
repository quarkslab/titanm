# bin2rec

Convert Citadel binary images into rec file that can be used for SPI rescue.

# Usage

* rec file to binary image

```bash
$ python bin2rec.py -r ec-2020-02-07.rec ./rw_a-2020-02-10.bin
```

* binary image to rec file

```bash
$ python extart-rw_a.py ec-2019-06-25.bin rw_a-2019-06-25.bin
$ python bin2rec.py rw_a-2019-06-25.bin  ./rw_a-2019-06-25.rec
```

Note that the rec file contains a single binary image (RW A) and not the full firmware.
