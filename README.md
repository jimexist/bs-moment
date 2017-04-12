# bs-moment

[![Build Status](https://travis-ci.org/BuckleTypes/bs-moment.svg?branch=master)](https://travis-ci.org/BuckleTypes/bs-moment)

[BuckleScript](https://github.com/bloomberg/bucklescript) bindings for [Moment.js](https://momentjs.com/).

## Mutations

This binding takes an opinionated approach to mutations, e.g. `moment().add`, `moment().startOf`, and bind them with names like `mutableAdd` and `mutableStartOf`. To compensate that, there's an immutable version named `add` and `startOf` which takes a `moment().clone` first before applying the mutations.

## Deprecations

Deprecated methods (e.g. `moment().days` in favor of `moment().day`) are not included in this binding.
