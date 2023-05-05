# syntax=docker/dockerfile:experimental
FROM debian:bullseye as build

RUN apt update && apt install -y \
    build-essential \
    qtbase5-dev \
    libqt5websockets5-dev 

WORKDIR /app

COPY . /app

RUN qmake -r
RUN make -j$(nproc)

FROM debian:bullseye as app

RUN apt-get update && apt-get install -y libqt5websockets5 \
        libqt5core5a \
        libqt5multimedia5 \
        ca-certificates \
        libqt5network5 

WORKDIR /app

COPY --from=build /app/monitor /app/monitor

CMD [ "./monitor"]

