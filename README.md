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
  sh -c "make testclean; make; make test"
```

Occasionally you will need to remove compiled objects to recompile them between
systems or on the same system.

```console
$ docker run \
  --workdir=/app \
  --volume "$(pwd)":/app \
  sonna/googletest \
  \
  sh -c "make distclean; make clean; make"

# or for testing

$ docker run \
  --workdir=/app \
  --volume "$(pwd)":/app \
  sonna/googletest \
  \
  sh -c "make testclean; make test"
```
