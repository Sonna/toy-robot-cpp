C Project template
==================

Usage
-----

To run and build with Docker

```console
$ docker run \
  --workdir=/app \
  --volume "$(pwd)":/app \
  sonna/googletest \
  \
  sh -c "make; make test"
```
