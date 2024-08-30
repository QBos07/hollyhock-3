# syntax=docker/dockerfile:1
FROM --platform=$BUILDPLATFORM ghcr.io/qbos07/cp-dockercross AS build

RUN --mount=type=bind,source=.,rw make -j && mkdir -p /sdk && cp -Pr sdk.o libsdk.a include/ /sdk

FROM ghcr.io/qbos07/cp-dockercross

COPY --from=build /sdk /sdk

ENV SDK_DIR=/sdk

LABEL org.opencontainers.image.source=https://github.com/QBos07/hollyhock-3
LABEL org.opencontainers.image.authors="qubos@outlook.de"
LABEL org.opencontainers.image.vendor="QBos07"
