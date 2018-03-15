# ts-lib
Make video great again!

## How to run it

```
make
cat test1.ts | ./tsparser
```

## Docker image
To just use the latest image just pull from our private registry/repository @ DockerHub:
```
docker pull heliconwave/circleci:v1
```
To build the image your self:
```
make docker-image
```
To spin-up a container:
```
make docker-bash
```
From here you can use the 3rd-party dependencies like
tstools, clang-format-5.0 etc...

## How to test it
In order to run all unit tests just type:
```
make test
```
This will spin up a docker container with gtest/gmock and execute all tests.

## Continuous integration (CI)
For CI we use CircleCI which will automatically run all unit tests after a commit either
in a branch, pull-request or integration to master. You can check the status tests in any
branch by the portal:
```
[CircleCI](https://circleci.com/gh/skullanbones/ts-lib)
```

## Static code analysis
For static and feedback in pull-requests we use a tool called Codacy which will run different
tools to check for mistakes and coding quality/best practises. You can check that status here:
```
[Codacy](https://app.codacy.com/app/skullanbones/ts-lib/dashboard)
```